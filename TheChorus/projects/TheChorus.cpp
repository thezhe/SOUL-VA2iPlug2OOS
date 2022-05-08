#include "TheChorus.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"

#ifdef ZHE_DEMO
void TheChorus::demoInit()
{
    srand(time(NULL));

    demoStartTime = time(NULL);
    demoLengthSecs = double(rand() % ((maxDemoLengthMins - minDemoLengthMins) * 60) + minDemoLengthMins * 60);

    int paramIdx;
    while (mParamsToUpdate.Pop(paramIdx)) {}

    for (int i = 0; i < kNumParams; ++i)
    {
        GetParam(i)->SetToDefault();
        mSOULParams[i].setValue(GetParam(i)->GetDefault());
    }
}

void TheChorus::demoRender()
{
    if (difftime(time(NULL), demoStartTime) > demoLengthSecs)
    {
        demoStartTime = time(NULL);
        demoLengthSecs = double(rand() % ((maxDemoLengthMins - minDemoLengthMins) * 60) + minDemoLengthMins * 60);

        int paramIdx;
        while (mParamsToUpdate.Pop(paramIdx)) {}

        for (int i = 0; i < kNumParams; ++i)
        {
            GetParam(i)->SetToDefault();
            mSOULParams[i].setValue(GetParam(i)->GetDefault());
        }
    }
}
#endif // ZHE_DEMO

void TheChorus::addKnob (IGraphics* pGraphics, IRECT b, float l, float h, float v, ISVG svg, IColor textColor, int idx, bool showParamLabel, bool longDisplay)
{
  const float textSize = ((longDisplay ? 65.f : 80.f) / 250.f) * l;
  const float textSizeLabel = (35.f / 250.f) * l;

  pGraphics->AttachControl(new ITextControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v + 0.2 * l), GetParam(idx)->GetName(), IText(textSizeLabel, textColor), DEFAULT_BGCOLOR, true));
  pGraphics->AttachControl(new ICaptionControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v), idx, IText(textSize, textColor), DEFAULT_BGCOLOR, showParamLabel));
  pGraphics->AttachControl(new ISVGKnobControl(b.GetFromTLHC(l, l).GetHShifted(h).GetVShifted(v), svg, idx));
}

bool TheChorus::strEq (const char* x0, const char* x1) const
{
    return (strncmp(x0, x1, std::max(int(strlen(x0)), int(strlen(x1)))) == 0 ? true : false);
}


TheChorus::TheChorus(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
  int paramIdx = 0;

  const auto& parameterProperties = DSP::getParameterProperties();
  for (int i = 0; i < kNumParams; ++i) {

    const auto& p = parameterProperties[i]; 

    mParamMap.insert(std::make_pair(p.name, paramIdx));

    int flags = 0;
    flags |= !p.isAutomatable ? IParam::EFlags::kFlagCannotAutomate : 0;
    flags |= CStringHasContents(p.textValues) ? IParam::EFlags::kFlagStepped : 0;

    if (strEq (p.unit, "Hz"))
        GetParam(paramIdx)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group, IParam::ShapeExp());
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
  GetParam(1)->SetDisplayFunc(
      [](double v, WDL_String& str)
      {
          if (v < 1000.0)
              str.SetFormatted(7, "%.0f Hz", v);
          else
              str.SetFormatted(7, "%.0f kHz", v * (1.0/1000.0));
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
      pGraphics->AttachCornerResizer();
      pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);

      //layout constants
      const int columns = 3;
      const float mar = 21;
      const float l = (PLUG_WIDTH - mar) / float(columns) -  mar;

      //attach non-parameters
      pGraphics->AttachPanelBackground(IPattern(COLOR_PANEL_BACKGROUND));

      //attach parameters
      const ISVG knob = pGraphics->LoadSVG(KNOB_FN);
      const ISVG knobD = pGraphics->LoadSVG(KNOB_D_FN);

      //pGraphics->GetControl(1)->

      addKnob(pGraphics, b, l, mar, mar, knobD, COLOR_KNOB, 0);
      addKnob(pGraphics, b, l, mar, 2 * mar + l, knob, COLOR_KNOB, 1, false);
      addKnob(pGraphics, b, l, mar, 3 * mar + 2 * l, knobD, COLOR_KNOB, 2);

      addKnob(pGraphics, b, l, 2 * mar + l, mar, knob, COLOR_KNOB, 3);
      addKnob(pGraphics, b, l, 2 * mar + l, 2 * mar + l, knob, COLOR_KNOB, 4);
      addKnob(pGraphics, b, l, 2 * mar + l, 3 * mar + 2 * l, knob, COLOR_KNOB, 5);

    /*  for (int i = 1; i < kNumParams; ++i)
          pGraphics->GetControl*/

       
    };
  #endif // IPLUG_EDITOR
}

#if IPLUG_DSP
void TheChorus::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  DISABLE_DENORMALS

  assert(NInChansConnected() <= DSP::numAudioInputChannels);
  assert(NOutChansConnected() <= DSP::numAudioOutputChannels);

  int paramIdx;
  while (mParamsToUpdate.Pop(paramIdx)) 
      mSOULParams[paramIdx].setValue(GetParam(paramIdx)->Value());

#ifdef ZHE_DEMO
  demoRender();
#endif

  DSP::RenderContext<sample> renderCtx;

  if constexpr (DSP::numAudioInputChannels > 0) {
    for (auto i=0; i<DSP::numAudioInputChannels; ++i) {
      renderCtx.inputChannels[i] = inputs[i];
    }
  }
  
  for (auto i=0; i<DSP::numAudioOutputChannels; ++i) {
    memset(outputs[i], 0, nFrames * sizeof(sample));
    renderCtx.outputChannels[i] = outputs[i];
  }
  
  renderCtx.numFrames = nFrames;
  
  mDSP.setTempo(GetTempo());
  mDSP.setPosition(mTimeInfo.mSamplePos, mTimeInfo.mPPQPos, mTimeInfo.mLastBar);
  mDSP.setTimeSignature(mTimeInfo.mNumerator, mTimeInfo.mDenominator);
  mDSP.setTransportState(mTimeInfo.mTransportIsRunning ? 1 : 0);
  
  if(mIncomingMIDIMessages.size()) {
    renderCtx.incomingMIDI.messages = std::addressof (mIncomingMIDIMessages[0]);
    renderCtx.incomingMIDI.numMessages = static_cast<uint32_t>(mIncomingMIDIMessages.size());
  }
  
  mDSP.render(renderCtx);
  mIncomingMIDIMessages.clear();

  RESTORE_DENORMALS
}

void TheChorus::ProcessMidiMsg(const IMidiMsg& msg)
{
  mIncomingMIDIMessages.push_back({static_cast<uint32_t>(msg.mOffset), msg.mStatus, msg.mData1, msg.mData2});
}

void TheChorus::OnReset()
{
#ifdef ZHE_DEMO
    demoInit();
#endif

    if (mNeedInit)
    {
        mNeedInit = false;
        mDSP.init(GetSampleRate(), 1);
    }

  mIncomingMIDIMessages.reserve(GetBlockSize());
}

void TheChorus::OnParamChange(int paramIdx)
{
  mParamsToUpdate.Push(paramIdx);
}
#endif // IPLUG_DSP
