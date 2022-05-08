#include "TheSplit.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"

void TheSplit::addKnob (IGraphics* pGraphics, IRECT b, float l, float h, float v, ISVG svg, IColor textColor, int idx, bool showParamLabel, bool longDisplay)
{
  const float textSize = ((longDisplay ? 65.f : 80.f) / 250.f) * l;
  const float textSizeLabel = (35.f / 250.f) * l;

  pGraphics->AttachControl(new ITextControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v + 0.2 * l), GetParam(idx)->GetName(), IText(textSizeLabel, textColor), DEFAULT_BGCOLOR, true), -1, GetParam(idx)->GetGroup())->SetParamIdx(idx);
  pGraphics->AttachControl(new ICaptionControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v), idx, IText(textSize, textColor), DEFAULT_BGCOLOR, showParamLabel), -1, GetParam(idx)->GetGroup());
  pGraphics->AttachControl(new ISVGKnobControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v), svg, idx), idx, GetParam(idx)->GetGroup());
}

TheSplit::TheSplit(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
    int paramIdx = 0;

  const auto& parameterProperties = DSP::getParameterProperties();
  for (int i = 0; i < kNumParams; ++i) {

    const auto& p = parameterProperties[i]; 

    int flags = 0;
    flags |= !p.isAutomatable ? IParam::EFlags::kFlagCannotAutomate : 0;
    flags |= CStringHasContents(p.textValues) ? IParam::EFlags::kFlagStepped : 0;

    if (std::string (p.unit).compare("Hz") == 0)
        GetParam(paramIdx)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group, IParam::ShapeExp());
    else if (paramIdx == 3 || paramIdx == 4 || paramIdx == 7)
        GetParam(paramIdx)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, p.unit, flags, p.group, IParam::ShapeExp());
    else
        GetParam(paramIdx)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, p.unit, flags, p.group, IParam::ShapeLinear());
    if(CStringHasContents(p.textValues))
    {
      WDL_String vals {p.textValues};
      char* pChar = strtok(vals.Get(), "|");
      int tokIdx = 0;
      while (pChar != nullptr) {
        GetParam(paramIdx)->SetDisplayText(static_cast<double>(tokIdx++), pChar);
        pChar = strtok(nullptr, "|");
      }
    }
    else if (p.step > 0.f)
      GetParam(paramIdx)->SetDisplayPrecision(int (-log10(p.step)));
    ++paramIdx;
  }

  //modify specific parameters (set 'showParamLabel' to false when calling 'addKnob')
  GetParam(2)->SetDisplayFunc(
      [](double v, WDL_String& str)
      {
          if (v < 1000.0)
              str.SetFormatted(7, "%.0f Hz", v);
          else
              str.SetFormatted(7, "%.0f kHz", v * (1.0/1000.0));
      }
  );

  GetParam(3)->SetDisplayFunc(
      [](double v, WDL_String& str)
      {
        str.SetFormatted(3, "%.0f", v + 4.0);
      }
  );

  #if IPLUG_DSP
    mSOULParams = mDSP.createParameterList();
  #endif
  
  #if IPLUG_EDITOR
    mMakeGraphicsFunc = [&]() {
      return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen(PLUG_WIDTH, PLUG_HEIGHT));
    };

    mLayoutFunc = [&](IGraphics* pGraphics) {
      const IRECT b = pGraphics->GetBounds();
      pGraphics->EnableMultiTouch(true);
      pGraphics->AttachCornerResizer(new ICornerResizerNoDblClickControl (b, 20));
      pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);

      //layout constants
      const int columns = 5;
      const float mar = 20;
      const float l = (PLUG_WIDTH) / float(columns) -  2 * mar;

      //attach non-parameters
      pGraphics->AttachPanelBackground(IPattern(COLOR_PANEL_BACKGROUND));

      //attach parameters
      const ISVG knob = pGraphics->LoadSVG(KNOB_FN);
      const ISVG knobD = pGraphics->LoadSVG(KNOB_D_FN);

      addKnob(pGraphics, b, l, mar, mar, knobD, COLOR_KNOB, 0);
      addKnob(pGraphics, b, l, 3 * mar + l, mar, knobD, COLOR_KNOB, 1);

      addKnob(pGraphics, b, l, 5 * mar + 2 * l, mar, knobD, COLOR_KNOB, 2);

      addKnob(pGraphics, b, l, 5 * mar + 2 * l, mar, knob, COLOR_KNOB, 3);
      addKnob(pGraphics, b, l, 7 * mar + 3 * l, mar, knob, COLOR_KNOB, 4);
      addKnob(pGraphics, b, l, 9 * mar + 4 * l, mar, knob, COLOR_KNOB, 5);

      addKnob(pGraphics, b, l, 5 * mar + 2 * l, mar, knob, COLOR_KNOB, 6);
      addKnob(pGraphics, b, l, 7 * mar + 3 * l, mar, knob, COLOR_KNOB, 7);
      addKnob(pGraphics, b, l, 9 * mar + 4 * l, mar, knob, COLOR_KNOB, 8);

      pGraphics->GetControlWithTag(0)->SetActionFunction(
          [pGraphics, this](IControl* pControl)
          {
              const std::string activeGroup = std::string (GetParam(0)->GetDisplayText(GetParam(0)->Value()));

              for (int i = 2; i < kNumParams; ++i)
                  pGraphics->HideControl(i, true);

              pGraphics->ForControlInGroup(
                  activeGroup.c_str(),
                  [](IControl* c)
                  {
                      c->Hide(false);
                  }
              );
          }
      );

     const std::string activeGroup = std::string(GetParam(0)->GetDisplayText(GetParam(0)->Value()));

      for (int i = 2; i < kNumParams; ++i)
          pGraphics->HideControl(i, true);

      pGraphics->ForControlInGroup(
          activeGroup.c_str(),
          [](IControl* c)
          {
              c->Hide(false);
          }
      );
    };
  #endif // IPLUG_EDITOR
}

#if IPLUG_DSP
void TheSplit::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{

    //prologue
    DISABLE_DENORMALS

    assert(NInChansConnected() <= DSP::numAudioInputChannels);
    assert(NOutChansConnected() <= DSP::numAudioOutputChannels);

    int paramIdx;
    while (mParamsToUpdate.Pop(paramIdx))
        mSOULParams[paramIdx].setValue(GetParam(paramIdx)->Value());

    //renderCtx
    DSP::RenderContext<sample> renderCtx;

    for (auto i = 0; i < DSP::numAudioInputChannels; ++i)
        renderCtx.inputChannels[i] = inputs[i];

    for (auto i = 0; i < 2; ++i)
        renderCtx.outputChannels[i] = outputs[i];

    std::unique_ptr<sample[]> nul(new sample[GetBlockSize()]);

    for (auto i = 2; i < DSP::numAudioOutputChannels; ++i)
    {
        if (IsChannelConnected(ERoute::kOutput, i))
            renderCtx.outputChannels[i] = outputs[i];
        else
            renderCtx.outputChannels[i] = nul.get();
    }

    renderCtx.numFrames = nFrames;

    //render
    mDSP.render(renderCtx);

    RESTORE_DENORMALS
}


void TheSplit::OnReset()
{
    if (mNeedInit)
    {
        mNeedInit = false;
        mDSP.init(GetSampleRate(), 1);
    }
}

void TheSplit::OnParamChange(int paramIdx)
{
  mParamsToUpdate.Push(paramIdx);
}
#endif // IPLUG_DSP
