#include "TheChorus.h"
#include "IPlug_include_in_plug_src.h"

//Inherited from iPlug2 
void ITextToggleControlMouseOver::Draw(IGraphics& g)
{
    if (mMouseIsOver)
        mText.mFGColor = mMOColor;
    else
        mText.mFGColor = mOriginalColor;

    ITextControl::Draw(g);
}

void IVPlotControlGrid::Draw(IGraphics& g)
{
    DrawBackground(g, mRECT);
    DrawLabel(g);

    float hdiv = mWidgetBounds.W() / static_cast<float>(mHorizontalDivisions);
    float vdiv = mWidgetBounds.H() / static_cast<float>(mVerticalDivisions);

    IRECT plotsRECT = mWidgetBounds;

    auto drawFunc = [&]() {
        g.DrawGrid(GetColor(kSH), mWidgetBounds, hdiv, vdiv, &mBlend);

        for (int p = 0; p < mPlots.size(); p++)
        {
            for (int i = 0; i < mPoints.size(); i++)
            {
                auto v = mPlots[p].func((static_cast<float>(i) / static_cast<float>(mPoints.size() - 1)));
                v = (v - mMin) / (mMax - mMin);
                mPoints[i] = static_cast<float>(v);
            }

            g.DrawData(mPlots[p].color, plotsRECT, mPoints.data(), static_cast<int>(mPoints.size()), nullptr, &mBlend, mTrackSize);
        }

        if (mStyle.drawFrame)
            g.DrawRect(GetColor(kFR), mWidgetBounds, &mBlend, mStyle.frameThickness);
    };

    if (mUseLayer)
    {
        if (!g.CheckLayer(mLayer))
        {
            g.StartLayer(this, mRECT);
            drawFunc();
            mLayer = g.EndLayer();
        }

        g.DrawLayer(mLayer, &mBlend);
    }
    else
        drawFunc();
}

//mLayoutFunc Helper Class
Layout::~Layout()
{
    for (auto i = 0; i < mGroupVector.size(); ++i)
        mG.AttachControl(new IVGroupControl(mGroupVector[i].c_str(), mGroupVector[i].c_str(), 0, 0, 0, -getTopBottomMargin(), STYLE_THEZHE.WithLabelText(TEXT_GROUP)), -1, mGroupVector[i].c_str());
}

void Layout::attachKnob(float h, float v, int paramIdx, bool unsmoothed, bool longValue)
{
    const IRECT core = mB.GetFromTLHC(mCore, mCore).GetHShifted(h + mMargin).GetVShifted(v + mMargin).GetScaledAboutCentre(0.9f);
    const IRECT bounds = mB.GetFromTLHC(mWidth, mHeight).GetHShifted(h).GetVShifted(v);

    ISVG svg = (unsmoothed ? mKnobD : mKnob);

    mG.AttachControl(new IPanelControl(bounds, COLOR_TRANSPARENT), -1, mD.GetParam(paramIdx)->GetGroup()); //group
    mG.AttachControl(new ITextControl(bounds.GetReducedFromBottom(mMargin), mD.GetParam(paramIdx)->GetName(), TEXT_LABEL, COLOR_TRANSPARENT), -1, mD.GetParam(paramIdx)->GetGroup()); //group
    mG.AttachControl(new ICaptionControl(core, paramIdx, TEXT_LABEL.WithVAlign(EVAlign::Middle).WithSize(longValue ? 0.85 * TEXT_LABEL.mSize : TEXT_LABEL.mSize), COLOR_TRANSPARENT), -1, mD.GetParam(paramIdx)->GetGroup()); //group, paramIdx
    mG.AttachControl(new ISVGKnobControl(core, svg, paramIdx), paramIdx, mD.GetParam(paramIdx)->GetGroup()); //group, paramIdx, ctrlTag
}

void Layout::attachToggle(float h, float v, int paramIdx)
{
    const IRECT core = mB.GetFromTLHC(mCore, mCore).GetHShifted(h + mMargin).GetVShifted(v + mMargin);
    const IRECT bounds = mB.GetFromTLHC(mWidth, mHeight).GetHShifted(h).GetVShifted(v);

    mG.AttachControl(new IPanelControl(bounds, COLOR_TRANSPARENT), -1, mD.GetParam(paramIdx)->GetGroup()); //group
    mG.AttachControl(new ITextControl(bounds.GetReducedFromBottom(mMargin), mD.GetParam(paramIdx)->GetName(), TEXT_LABEL, COLOR_TRANSPARENT), -1, mD.GetParam(paramIdx)->GetGroup()); //group
    mG.AttachControl(new ITextToggleControlMouseOver(core, paramIdx, mD.GetParam(paramIdx)->GetDisplayText(0.0), mD.GetParam(paramIdx)->GetDisplayText(1.0), mToggleText), paramIdx, mD.GetParam(paramIdx)->GetGroup()); //group, paramIdx, ctrlTag
}

void Layout::attachMeter(float h, float v, const char* label, float min, float max, int divisions)
{
    const IRECT core = mB.GetFromTLHC(mCore, mVisualizationCoreHeight).GetHShifted(h + mMargin).GetVShifted(v + getTopBottomMargin());
    
    //grid
    const auto rangeValue = max - min;
    const auto stepValue = rangeValue / static_cast<float>(divisions);
    for (int i = static_cast<int>(stepValue); i < static_cast<int>(rangeValue); i += static_cast<int>(stepValue))
       mG.AttachControl(new IVLabelControl(core.GetFromTop(core.H() * static_cast<float>(i) / rangeValue), "", STYLE_THEZHE.WithColor(EVColor::kFR, DEFAULT_SHCOLOR) ));

    //grid labels
    const auto step = core.H() / static_cast<float>(divisions);
    for (int i = static_cast<int>(max - stepValue), j = 0; i > static_cast<int>(min); i -= static_cast<int>(stepValue), ++j)
        mG.AttachControl(new ITextControl(core.SubRectVertical(divisions, j).GetVShifted(step/2.f), std::to_string(i).c_str(), DEFAULT_TEXT.WithVAlign(EVAlign::Middle), COLOR_PANEL_BACKGROUND, true));
  
    //core frame and label
    mG.AttachControl(new IVLabelControl(core, "", STYLE_THEZHE));
    mG.AttachControl(new ITextControl(core.GetReducedFromBottom(-2.f * mMargin + getTopBottomMargin()), label, TEXT_LABEL, COLOR_TRANSPARENT));

    //core
    mG.AttachControl(new IVMeterControl<1>(mB.GetFromTLHC(mCore / 7.f, mVisualizationCoreHeight).GetHShifted(h + mMargin + mCore / 7.f).GetVShifted(v + getTopBottomMargin()), "", STYLE_THEZHE.WithDrawFrame(false), EDirection::Vertical, { }, 0, min, max), kGuiCtrlTagL);
    mG.AttachControl(new IVMeterControl<1>(mB.GetFromTLHC(mCore / 7.f, mVisualizationCoreHeight).GetHShifted(h + mMargin + mCore * 5.f / 7.f).GetVShifted(v + getTopBottomMargin()), "", STYLE_THEZHE.WithDrawFrame(false), EDirection::Vertical, { }, 0, min, max), kGuiCtrlTagR);
}

void Layout::attachPlot(float h, float v, const char* label, IVPlotControl::IPlotFunc plotFunc, int numPoints, std::vector<int> dirtyParams, int xMin, int xMax, int yMin, int yMax, int xDivisions, int yDivisions)
{
    const IRECT core = mB.GetFromTLHC(mVisualizationCoreHeight, mVisualizationCoreHeight).GetHShifted(h + mMargin).GetVShifted(v + getTopBottomMargin());
    
    //label
    mG.AttachControl(new ITextControl(core.GetReducedFromBottom(-2 * mMargin + getTopBottomMargin()), label, TEXT_LABEL, COLOR_TRANSPARENT));
    
    //core
    mPlotControl = mG.AttachControl(new IVPlotControlGrid(core, {{COLOR_CONTROL, plotFunc}}, numPoints, "", STYLE_THEZHE, -1, 1, false, xDivisions, yDivisions));

    //grid labels
    const auto xRange = xMax - xMin;
    const auto xStep = xRange / static_cast<float>(xDivisions);
    const auto hStep = core.H() / static_cast<float>(xDivisions);
    const auto yRange = yMax - yMin;
    const auto yStep = yRange / static_cast<float>(yDivisions);
    const auto vStep = core.H() / static_cast<float>(yDivisions);

    for (int i = static_cast<int>(yMax - yStep), j = 0; i > static_cast<int>(yMin); i -= static_cast<int>(yStep), ++j)
        mG.AttachControl(new ITextControl(core.GetFromLeft(hStep).SubRectVertical(yDivisions, j).GetVShifted(vStep/2.f), std::to_string(i).c_str(), TEXT_GRID, COLOR_PANEL_BACKGROUND, true));

    for (int i = static_cast<int>(xMax - xStep), j = xDivisions - 2; i > static_cast<int>(xMin); i -= static_cast<int>(xStep), --j)
        mG.AttachControl(new ITextControl(core.GetFromTop(vStep).SubRectHorizontal(xDivisions, j).GetHShifted(hStep/2.f), std::to_string(i).c_str(), TEXT_GRID, COLOR_PANEL_BACKGROUND, true));

    //dirtyParams
    for (auto i = 0; i < dirtyParams.size(); ++i)
    {
        mG.ForControlWithParam(
            dirtyParams[i],
            [this](IControl* pControl)
            {
                if (mPlotControl != nullptr)
                {
                    IControl* plotControl = mPlotControl;
                    pControl->SetAnimation(
                        [plotControl](IControl*)
                        {
                            plotControl->SetDirty(true);
                        }
                    );
                }
            }
        );
    }
}

//Plugin Class
TheChorus::TheChorus(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
    const auto& parameterProperties = DSP::getParameterProperties();
    for (int i = 0; i < kNumParams; ++i) {
        const auto& p = parameterProperties[i];

        int flags = 0;
        flags |= !p.isAutomatable ? IParam::EFlags::kFlagCannotAutomate : 0;
        flags |= CStringHasContents(p.textValues) ? IParam::EFlags::kFlagStepped : 0;

        if (std::string(p.unit).compare("Hz") == 0 || std::string(p.unit).compare("ms") == 0 || std::string(p.group).find("Ratios") != std::string::npos)
            GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group, IParam::ShapeExp());
        else if (std::string(p.name).compare("Mix") == 0 || std::string(p.name).compare("Pan") == 0)
            GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group);
        else if (p.isBoolean)
        {
            if (CStringHasContents(p.textValues))
            {
                std::string textOffOn { p.textValues };
                auto delimPos = textOffOn.find("|");
                GetParam(i)->InitBool(p.name, (p.initialValue > 0.5f ? true : false), "", flags, p.group, textOffOn.substr(0, delimPos).c_str(), textOffOn.substr(delimPos+1).c_str());
            }
            else
                GetParam(i)->InitBool(p.name, (p.initialValue > 0.5f ? true : false), "", flags, p.group, "Off", "On");
        }
        else
            GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, p.unit, flags, p.group);

        if (CStringHasContents(p.textValues) && !p.isBoolean)
        {
            WDL_String vals{ p.textValues };
            char* pChar = strtok(vals.Get(), "|");
            int tokIdx = 0;
            while (pChar != nullptr) {
                GetParam(i)->SetDisplayText(static_cast<double>(tokIdx++), pChar);
                pChar = strtok(nullptr, "|");
            }
        }
        else
        {
            GetParam(i)->SetDisplayPrecision(static_cast<int>(-log10(std::max(p.step, 0.001f))));

            if (std::string(p.unit).compare("Hz") == 0)
            {
                GetParam(i)->SetDisplayFunc(
                    [](double v, WDL_String& str)
                    {
                        if (v <= 999.0)
                            str.SetFormatted(7, "%.0f Hz", v);
                        else if (v <= 9999.0)
                            str.SetFormatted(8, "%.2f kHz", v * (1.0 / 1000.0));
                        else 
                            str.SetFormatted(8, "%.1f kHz", v * (1.0 / 1000.0));
                    }
                );
            }
            else if (std::string(p.unit).compare("ms") == 0)
            {
                GetParam(i)->SetDisplayFunc(
                    [](double v, WDL_String& str)
                    {
                        if (v <= 0.1)
                            str.Set("0 ms", 4);
                        else if (v <= 9.9)
                            str.SetFormatted(7, "%.1f ms", v);
                        else if (v <= 999.9)
                            str.SetFormatted(7, "%.0f ms", v);
                        else
                            str.SetFormatted(7, "%.2f s", v * (1.0 / 1000.0));
                    }
                );
            }
            else if (std::string(p.name).compare("Mix") == 0)
            {
                GetParam(i)->SetDisplayFunc(
                    [](double v, WDL_String& str)
                    {
                        if (v <= 1)
                            str.Set("Dry", 3);
                        else if (v >= 99)
                            str.Set("Wet", 3);
                        else
                            str.SetFormatted(6, "%.0f %%", v);
                    }
                );
            }
            else if (std::string(p.name).compare("Pan") == 0)
            {
                GetParam(i)->SetDisplayFunc(
                    [](double v, WDL_String& str)
                    {
                        if (v <= -0.99)
                            str.Set("L", 1);
                        else if (v >= 0.99)
                            str.Set("R", 1);
                        else if (abs(v) <= 0.01)
                            str.Set("C", 1);
                        else
                            str.SetFormatted(5, "%.2f", v);
                    }
                );
            }
            else if (std::string(p.unit).compare("dB") == 0)
            {
                GetParam(i)->SetDisplayFunc(
                    [](double v, WDL_String& str)
                    {  
                        if (abs(v) <= 0.1)
                            str.Set("0", 1);
                        else if (abs(v) <= 9.9)
                            str.SetFormatted(4, "%.1f", v);
                        else
                            str.SetFormatted(3, "%.0f", v);
                    }
                );
            }
        }
    }

    mSOULParams = mDSP.createParameterList();

    mMakeGraphicsFunc = [&]() {
      return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen(PLUG_WIDTH, PLUG_HEIGHT));
    };

    mLayoutFunc = [&](IGraphics* pGraphics) {
      const IRECT b = pGraphics->GetBounds();
      pGraphics->EnableMultiTouch(true);
      pGraphics->EnableMouseOver(true);
      pGraphics->AttachPanelBackground(IPattern(COLOR_PANEL_BACKGROUND));
      pGraphics->AttachCornerResizer(new ICornerResizerControlNoDblClick (b, 20));
      pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);

      //Layout
      Layout layout{ 125, *this, *pGraphics, DSP::getParameterProperties() };

      const float w = layout.getUnitWidth(), h = layout.getUnitHeight(), t = layout.getHorizontalGroupMargin(), tbMar = layout.getTopBottomMargin();

      layout.attachKnob(t, tbMar, 0);
      layout.attachKnob(2 * t + w, tbMar, 1);
      layout.attachKnob(3 * t + 2 * w, tbMar, 2, true, true);

      layout.attachKnob(t, tbMar + h, 3, true);
      layout.attachToggle(2 * t + w, tbMar + h, 4);
      layout.attachKnob(3 * t + 2 * w, tbMar + h, 5, false, true);

      layout.attachKnob(t, tbMar + 2 * h, 6);
      layout.attachKnob(2 * t + w, tbMar + 2 * h, 7);
      layout.attachKnob(3 * t + 2 * w, tbMar + 2 * h, 8);
    };
}

void TheChorus::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{ 
  DISABLE_DENORMALS

  int paramIdx;
  while (mParamsToUpdate.Pop(paramIdx))
      mSOULParams[paramIdx].setValue(GetParam(paramIdx)->Value());

  //renderCtx
  DSP::RenderContext<sample> renderCtx;

  for (auto i = 0; i < DSP::numAudioInputChannels; ++i)
      renderCtx.inputChannels[i] = inputs[i];

  for (auto i = 0; i < 2; ++i)
      renderCtx.outputChannels[i] = outputs[i];

#ifdef VA_OUT_MULTI
  std::unique_ptr<sample[]> nul(new sample[GetBlockSize()]);

#ifdef VA_OUT_GUI
  const uint32_t numGuiOutputChannels = 2;
#else
  const uint32_t numGuiOutputChannels = 0;
#endif

  for (auto i = 2; i < DSP::numAudioOutputChannels - numGuiOutputChannels; ++i)
  {
      if (IsChannelConnected(ERoute::kOutput, i))
          renderCtx.outputChannels[i] = outputs[i];
      else
          renderCtx.outputChannels[i] = nul.get();
  }
#endif

#ifdef VA_OUT_GUI
  std::unique_ptr<sample[]> guiData(new sample[2 * GetBlockSize()]);
  std::array<sample*, 2> gui{ guiData.get(), guiData.get() + GetBlockSize() };
  std::array<sample*, 1> guiL{ gui[0] };
  std::array<sample*, 1> guiR{ gui[1] };

  for (auto i = 0; i < 2; ++i)
      renderCtx.outputChannels[DSP::numAudioOutputChannels - 2 + i] = gui[i];
#endif

  renderCtx.numFrames = nFrames;

  //render
  mDSP.render(renderCtx);

#ifdef VA_OUT_GUI
  mGuiPeakSenderL.ProcessBlock(guiL.data(), nFrames, kGuiCtrlTagL);
  mGuiPeakSenderR.ProcessBlock(guiR.data(), nFrames, kGuiCtrlTagR);
#endif

  RESTORE_DENORMALS
}

#ifdef VA_OUT_GUI
void TheChorus::OnIdle()
{
    mGuiPeakSenderL.TransmitData(*this);
    mGuiPeakSenderR.TransmitData(*this);
}
#endif

void TheChorus::OnReset()
{
    SetTailSize(kTailSeconds * GetSampleRate());
    mDSP.init(GetSampleRate(), ++mSessionID);
    
    for (int i = 0; i < kNumParams; ++i)
        OnParamChange(i);
}

void TheChorus::OnParamChange(int paramIdx)
{
  mParamsToUpdate.Push(paramIdx);
}
