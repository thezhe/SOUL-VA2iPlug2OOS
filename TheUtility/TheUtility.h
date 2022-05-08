#if !defined(__clang__)
#error Clang required with -Wno-c++11-narrowing 
#endif

#if (defined (_M_X64) || defined (_M_AMD64) || defined (__x86_64__)) //x64
#if defined (_WIN64) //Windows Intel (x86)
#define __building_module(x) 0 //Clang <immintrin.h> compatibility
#include <immintrin.h>

#define DISABLE_DENORMALS	\
							volatile auto oldMXCSR = _mm_getcsr();    \
							_mm_setcsr(oldMXCSR | _MM_FLUSH_ZERO_ON | _MM_DENORMALS_ZERO_ON);		\

#define RESTORE_DENORMALS _mm_setcsr(oldMXCSR);
#else //Apple Intel (x86)
#include <fenv.h>
#define DISABLE_DENORMALS   \
							fenv_t fenv;                \
							fegetenv(&fenv);        \
							fesetenv(FE_DFL_DISABLE_SSE_DENORMS_ENV);

#define RESTORE_DENORMALS fesetenv(&fenv);
#endif
#else //Apple M1 (ARM NEON)
#define DISABLE_DENORMALS
#define RESTORE_DENORMALS
#endif

#include "IPlug_include_in_plug_hdr.h"
#include "DSP.h"
#include "ICornerResizerControl.h"
#include "ISender.h"
#include "IControls.h"

using namespace iplug;
using namespace igraphics;
using DSP = main__Processor;

//Constants
const int kNumPresets = 1, kNumParams = DSP::numParameters;
constexpr int kGuiCtrlTagL = kNumParams + 1, kGuiCtrlTagR = kGuiCtrlTagL + 1;

//Color Palette
const IColor COLOR_CONTROL = COLOR_BLACK, COLOR_CONTROL_MO = COLOR_CONTROL.WithOpacity(0.4);

//Text Palette
const IText TEXT_GROUP = IText(19, COLOR_CONTROL), TEXT_GRID = IText(14, COLOR_CONTROL), TEXT_LABEL = TEXT_GROUP.WithVAlign(EVAlign::Bottom).WithSize(20), TEXT_SPEC = TEXT_GROUP.WithVAlign(EVAlign::Middle);

//Style Palette
const IVStyle STYLE_THEZHE{ true, true, {COLOR_TRANSPARENT, COLOR_CONTROL, COLOR_TRANSPARENT, COLOR_CONTROL, COLOR_TRANSPARENT, DEFAULT_SHCOLOR, COLOR_TRANSPARENT, COLOR_TRANSPARENT, COLOR_TRANSPARENT}, DEFAULT_LABEL_TEXT, DEFAULT_VALUE_TEXT, true, true, false, false, 0, 1 };

//Inherited from iPlug2 
class ICornerResizerControlNoDblClick final : public ICornerResizerControl
{
public:
	ICornerResizerControlNoDblClick(const IRECT& graphicsBounds, float size, const IColor& color = COLOR_TRANSLUCENT, const IColor& mouseOverColour = COLOR_CONTROL, const IColor& dragColor = COLOR_CONTROL)
		: ICornerResizerControl(graphicsBounds, size, color, mouseOverColour, dragColor) {}
	void OnMouseDblClick(float x, float y, const IMouseMod& mod) override {}
};

class ITextToggleControlMouseOver final : public ITextToggleControl
{
public:
	ITextToggleControlMouseOver(const IRECT& bounds, int paramIdx = kNoParameter, const char* offText = "Off", const char* onText = "On", const IText& text = DEFAULT_TEXT, const IColor& BGColor = DEFAULT_BGCOLOR, const IColor& MOColor = COLOR_CONTROL_MO)
		: ITextToggleControl(bounds, paramIdx, offText, onText, text, BGColor)
		, mOriginalColor(text.mFGColor)
		, mMOColor(MOColor)
	{
		mIgnoreMouse = false;
	}

	void Draw(IGraphics& g) override;
protected:
	const IColor mOriginalColor, mMOColor;
};

class IVPlotControlGrid final : public IVPlotControl
{
public:
	IVPlotControlGrid(const IRECT& bounds, const std::initializer_list<Plot>& funcs, int numPoints, const char* label = "", const IVStyle& style = DEFAULT_STYLE, float min = -1.f, float max = 1.f, bool useLayer = false, int horizontalDivisions = 10, int verticalDivisions = 10)
		: IVPlotControl(bounds, funcs, numPoints, label, style, min, max, useLayer)
	{
		mHorizontalDivisions = horizontalDivisions;
		mVerticalDivisions = verticalDivisions;
	}

	void Draw(IGraphics& g) override;
};

//Layout helpers
class Utility final
{
public:
	template <typename Type>
	static Type dBtoGain(Type x)
	{
		return x > Type(kNoiseFloor_dB)
			? std::pow(Type(10.0), x * Type(0.05))
			: Type(0.0);
	}

	template <typename Type>
	static Type gainTodB(Type x)
	{
		return x > Type(kNoiseFloor)
			? std::log10(x) * Type(20.0)
			: kNoiseFloor_dB;
	}

	template <typename Type>
	static Type lerp(Type a, Type b, Type t)
	{
		return a + t * (b - a);
	}

private:
	static constexpr double kNoiseFloor_dB = -100.0, kNoiseFloor = 0.00001;
};

enum class Fs : int32_t
{
	fs_441_48, //DS0
	fs_882_96, //DS2
	fs_1764_192 //DS4
};

//mLayoutFunc Helper Class
//Only declare in scope of mLayoutFunc
//if AnimationFunctions change at runtime, declare the control with the dynamic Animation last (only 1 for now)
class Layout final
{
public:
	void init(float width, IEditorDelegate* dlg, IGraphics* pGraphics, DSP::span<const DSP::ParameterProperties> parameterProperties, IColor panelBackground);

	void attachKnob(float h, float v, int paramIdx, bool unsmoothed = false);
	void attachToggle(float h, float v, int paramIdx, bool longValue = false);
	void attachDropDown(float h, float v, int paramIdx, IAnimationFunction animationFunc = nullptr);

	void attachMeter(float h, float v, const char* label, float min = -54.f, float max = 12.f, int divisions = 11); //attach last
	void attachPlot(float h, float v, const char* label, IVPlotControl::IPlotFunc plotFunc, int numPoints, std::vector<int> dirtyParams, int xMin = -70, int xMax = 0, int yMin = -60, int yMax = 10, int xDivisions = 7, int yDivisions = 7); //attach last

	void attachExtras();

	void hideParameter(int paramIdx, bool hide);

	float getUnitWidth() { return mWidth; }
	float getUnitHeight() { return mHeight; }
	float getHorizontalGroupMargin() { return TEXT_GROUP.mSize; }
	float getTopBottomMargin() { return getHorizontalGroupMargin() / 2.f; }

private:
	//init
	IEditorDelegate* mD;
	IGraphics* mG;
	IRECT mB;
	ISVG mKnob{ nullptr }, mKnobD{ nullptr };
	std::vector<std::string> mGroupVector;
	float mWidth, mMargin, mHeight, mCore, mVisualizationCoreHeight, mValue;
	IText mValueText, mToggleText;
	IColor mPanelBackgroundColor;

	//attach funcs
	IControl* mPlotControl{ nullptr };
	std::vector<std::vector<IControl*>> mParameters;
};

//Plugin Class
class TheUtility final : public Plugin
{
public:
	TheUtility(const InstanceInfo& info);
	void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
	void OnReset() override;
	void OnParamChange(int paramIdx) override;
#ifdef VA_OUT_GUI
	void OnIdle() override;
#endif
private:
	DSP mDSP;
	bool mNeedInit = true;
	IPlugQueue<int> mParamsToUpdate{ DSP::numParameters };
	DSP::ParameterList mSOULParams;
	Layout mLayout;
#ifdef VA_OUT_GUI
	IPeakSender<1> mGuiPeakSenderL, mGuiPeakSenderR;
#endif
};