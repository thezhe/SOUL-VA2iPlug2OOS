#pragma once

#if !defined(__clang__)
#error Clang required with -Wno-c++11-narrowing 
#endif

#if (defined (_M_X64) || defined (_M_AMD64) || defined (__x86_64__)) //x64
	#if defined (_WIN64)
		#define __building_module(x) 0 //Clang <immintrin.h> compatibility
		#include <immintrin.h>

		#define DISABLE_DENORMALS	\
							auto oldMXCSR = _mm_getcsr();    \
							_mm_setcsr(oldMXCSR | (_MM_FLUSH_ZERO_ON | _MM_DENORMALS_ZERO_ON)); //DAZ is SSE3 only, but assume all users have SSE3

		#define RESTORE_DENORMALS _mm_setcsr(oldMXCSR);
	#elif defined (__APPLE__)
		#include <fenv.h>
		#define DISABLE_DENORMALS   \
							fenv_t fenv;                \
							fegetenv(&fenv);        \
							fesetenv(FE_DFL_DISABLE_SSE_DENORMS_ENV);

		#define RESTORE_DENORMALS fesetenv(&fenv);
	#else
		#define DISABLE_DENORMALS
		#define RESTORE_DENORMALS
		#error Mac/Win64 required
	#endif

#else //arm
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

//Constants
const int kNumPresets = 1, kNumParams = DSP::numParameters;
const double kNoTail = 0.5, kTailSeconds = kNoTail;
constexpr int kGuiCtrlTagL = kNumParams + 1, kGuiCtrlTagR = kGuiCtrlTagL + 1;

//Color Palette
const IColor COLOR_CONTROL = COLOR_BLACK, COLOR_CONTROL_MO = COLOR_CONTROL.WithOpacity(0.5), COLOR_PANEL_BACKGROUND = IColor(255, 191, 215, 234); //beau blue

//Text Palette
const IText TEXT_GROUP = IText(17, COLOR_CONTROL), TEXT_GRID = IText(14, COLOR_CONTROL), TEXT_LABEL = TEXT_GROUP.WithVAlign(EVAlign::Bottom).WithSize(20);

//Style Palette
const IVStyle STYLE_THEZHE{ true, true, {COLOR_TRANSPARENT, COLOR_CONTROL, COLOR_TRANSPARENT, COLOR_CONTROL, COLOR_TRANSPARENT, DEFAULT_SHCOLOR, COLOR_TRANSPARENT, COLOR_TRANSPARENT, COLOR_TRANSPARENT}, DEFAULT_LABEL_TEXT, DEFAULT_VALUE_TEXT, true, true, false, false, 0, 1};

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

//mLayoutFunc Helper Class
//Only declare in scope of mLayoutFunc
class Layout final
{
public:
	Layout(float width, IEditorDelegate& dlg, IGraphics& pGraphics, DSP::span<const DSP::ParameterProperties> parameterProperties)
		:mD(dlg),
		mG(pGraphics),
		mB(mG.GetBounds()),
		mKnob(mG.LoadSVG(KNOB_FN)),
		mKnobD(mG.LoadSVG(KNOB_D_FN)),
		mGroupVector(
			[&parameterProperties]() -> std::vector<std::string>
			{ 
				std::vector<std::string> groups;

				for (auto i = 0; i < parameterProperties.size(); ++i)
				{
					const auto& p = parameterProperties[i];
					if (std::find(groups.begin(), groups.end(), std::string(p.group)) == groups.end())
						groups.push_back(std::string(p.group));
				}

				return groups;
			}()
				),
		mWidth(width),
				mMargin(0.15f * mWidth),
				mHeight(mWidth + mMargin),
				mCore(mWidth - 2.f * mMargin),
				mVisualizationCoreHeight(2 * mHeight - 3 * mMargin),
				mValue(mCore * 63.f / 250.f),
				mLabel(TEXT_LABEL.mSize),
				mValueText(IText(mValue, COLOR_CONTROL)),
				mToggleText(IText(mCore * 0.65, COLOR_CONTROL))
	{}
	~Layout(); //attach groups 

	void attachKnob(float h, float v, int paramIdx, bool unsmoothed = false, bool longValue = false);
	void attachToggle(float h, float v, int paramIdx);
	void attachMeter(float h, float v, const char* label, float min = -54.f, float max = 12.f, int divisions = 11); //attach last
	void attachPlot(float h, float v, const char* label, IVPlotControl::IPlotFunc plotFunc, int numPoints, std::vector<int> dirtyParams, int xMin = -70, int xMax = 0, int yMin = -60, int yMax = 10, int xDivisions = 7, int yDivisions = 7); //attach last

	float getUnitWidth() { return mWidth; }
	float getUnitHeight() { return mHeight; }
	float getHorizontalGroupMargin() { return TEXT_GROUP.mSize;  }
	float getTopBottomMargin() { return getHorizontalGroupMargin() / 2.f; }

private:
	IEditorDelegate& mD;
	IGraphics& mG;
	const IRECT mB;
	const ISVG mKnob{ nullptr }, mKnobD{ nullptr };

	const std::vector<std::string> mGroupVector;

	const float mWidth, mMargin, mHeight, mCore, mVisualizationCoreHeight, mValue, mLabel;

	const IText mValueText, mToggleText;

	IControl* mPlotControl{ nullptr };
};

//Plugin Class
class TheChorus final : public Plugin
{
public:
  TheChorus(const InstanceInfo& info);
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  void OnReset() override;
  void OnParamChange(int paramIdx) override;
#ifdef VA_OUT_GUI
  void OnIdle() override;
#endif
private:
	int mSessionID = -1;
  DSP mDSP;
  bool mNeedInit = true;
  IPlugQueue<int> mParamsToUpdate {DSP::numParameters};
  DSP::ParameterList mSOULParams;
#ifdef VA_OUT_GUI
  IPeakSender<1> mGuiPeakSenderL, mGuiPeakSenderR;
#endif
};