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
#include <map>
#include "ICornerResizerControl.h"


using namespace iplug;
using namespace igraphics;
using DSP = main__Processor;

constexpr int kNumPresets = 1;
constexpr int kNumParams = DSP::numParameters;

//Color palette
const IColor COLOR_PANEL_BACKGROUND = COLOR_WHITE;
const IColor COLOR_KNOB = COLOR_BLACK;

class TheSplit final : public Plugin
{
public:
  TheSplit(const InstanceInfo& info);
#if IPLUG_DSP
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  void OnReset() override;
  void OnParamChange(int paramIdx) override;
private:
  DSP mDSP;
  bool mNeedInit = true, mNeedRunOnce = true;
  IPlugQueue<int> mParamsToUpdate {DSP::numParameters};
  DSP::ParameterList mSOULParams;
#endif
  void addKnob(IGraphics* pGraphics, IRECT b, float l, float h, float v, ISVG svg, IColor textColor, int idx, bool showParamLabel = true, bool longDisplay = false);
};

class ICornerResizerNoDblClickControl : public ICornerResizerControl
{
public:
	ICornerResizerNoDblClickControl (const IRECT& graphicsBounds, float size, const IColor& color = COLOR_TRANSLUCENT, const IColor& mouseOverColour = COLOR_BLACK, const IColor& dragColor = COLOR_BLACK)
		: ICornerResizerControl(graphicsBounds, size, color, mouseOverColour, dragColor) {}
	void OnMouseDblClick(float x, float y, const IMouseMod& mod) override {}
};
