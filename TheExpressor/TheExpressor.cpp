#include "TheExpressor.h"
#include "IPlug_include_in_plug_src.h"

TheExpressor::TheExpressor(const InstanceInfo& info)
	: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
	const auto& parameterProperties = DSP::getParameterProperties();
	for (int i = 0; i < kNumParams; ++i) {
		const auto& p = parameterProperties[i];

		int flags = 0;
		flags |= CStringHasContents(p.textValues) ? IParam::EFlags::kFlagStepped : 0;
		flags |= (std::string(p.name).find("Meta") != std::string::npos) ? IParam::EFlags::kFlagMeta : 0;

		if (std::string(p.unit).compare("Hz") == 0 || std::string(p.unit).compare("ms") == 0 || std::string(p.group).find("Ratios") != std::string::npos)
			GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group, IParam::ShapeExp());
		else if (std::string(p.name).compare("Mix") == 0 || std::string(p.name).compare("Pan") == 0)
			GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, "", flags, p.group);
		else if (p.isBoolean)
		{
			if (CStringHasContents(p.textValues))
			{
				std::string textOffOn{ p.textValues };
				auto delimPos = textOffOn.find("|");
				GetParam(i)->InitBool(p.name, (p.initialValue > 0.5f ? true : false), "", flags, p.group, textOffOn.substr(0, delimPos).c_str(), textOffOn.substr(delimPos + 1).c_str());
			}
			else
				GetParam(i)->InitBool(p.name, (p.initialValue > 0.5f ? true : false), "", flags, p.group, "Off", "On");
		}
		else if (CStringHasContents(p.textValues))
		{
			//Add cases here
		}
		else
			GetParam(i)->InitDouble(p.name, p.initialValue, p.minValue, p.maxValue, p.step, p.unit, flags, p.group);

		if (!CStringHasContents(p.textValues) && !p.isBoolean)
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
			else if (std::string(p.unit).compare("dB") == 0 || std::string(p.group).compare("Ratios") == 0)
			{
				GetParam(i)->SetDisplayFunc(
					[](double v, WDL_String& str)
					{
						if (v < -60.0)
							str.Set("-inf");
						else if (abs(v) <= 0.1)
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
		mLayout.init(125, this, pGraphics, DSP::getParameterProperties(), IColor(255, 255, 164, 0) /*orange web*/);

		const float w = mLayout.getUnitWidth(), h = mLayout.getUnitHeight(), t = mLayout.getHorizontalGroupMargin(), tbMar = mLayout.getTopBottomMargin();

		mLayout.attachKnob(3 * w + 3 * t, tbMar, 0);
		mLayout.attachKnob(4 * w + 3 * t, tbMar, 1);
		mLayout.attachKnob(5 * w + 3 * t, tbMar, 2);

		mLayout.attachKnob(6 * w + 4 * t, tbMar, 3);
		mLayout.attachKnob(7 * w + 4 * t, tbMar, 4);

		mLayout.attachKnob(8 * w + 5 * t, tbMar, 5);

		mLayout.attachToggle(3 * w + 3 * t, h + tbMar, 6);
		mLayout.attachKnob(4 * w + 3 * t, h + tbMar, 7);
		mLayout.attachKnob(5 * w + 3 * t, h + tbMar, 8);

		mLayout.attachKnob(6 * w + 4 * t, h + tbMar, 9);
		mLayout.attachKnob(7 * w + 4 * t, h + tbMar, 10);

		mLayout.attachKnob(8 * w + 5 * t, h + tbMar, 11);

		mLayout.attachMeter(2 * w + 2 * t, tbMar, "Gain", -27, 6, 11);

		mLayout.attachPlot(
			t,
			tbMar,
			"Transfer Function",
			[&](double x)
			{
				DSP::Vector<double, 2> vX{ Utility::dBtoGain(Utility::lerp(-70.0, 0.0, x)) };

				auto fs = mDSP.state.m_e_state.m_mux3To1Fs_state.m_c.m_idx;
				auto& state = mDSP.state.m_e_state;

				DSP::Vector<double, 2> vY{ };
				if (fs == static_cast<int32_t> (Fs::fs_441_48))
					vY = mDSP.VA__CTF_Color__Internal__process(vX, state.m_internalDS0_state.m_ctfColor_state.m_internal_state.m_c);
				else if (fs == static_cast<int32_t> (Fs::fs_882_96))
					vY = mDSP.VA__CTF_Color__Internal__process(vX, state.m_internalDS2_state.m_ctfColor_state.m_internal_state.m_c);
				else
					vY = mDSP.VA__CTF_Color__Internal__process(vX, state.m_internalDS4_state.m_ctfColor_state.m_internal_state.m_c);

				return Utility::lerp(1.0, -1.0, (Utility::gainTodB(vY[0] * vX[0]) - 10.0) / -70.0);
			},
			70,
			{ 2, 3, 4, 9, 10 }
			);

		mLayout.attachExtras();
	};
}

/*==============================================================
Methods below rarely need changed
==============================================================*/

void TheExpressor::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
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
		renderCtx.outputChannels[static_cast<std::array<iplug::sample*, DSP::numAudioOutputChannels>::size_type>(DSP::numAudioOutputChannels - 2) + i] = gui[i];
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
void TheExpressor::OnIdle()
{
	mGuiPeakSenderL.TransmitData(*this);
	mGuiPeakSenderR.TransmitData(*this);
}
#endif

void TheExpressor::OnReset()
{
	if (mNeedInit)
	{
		mNeedInit = false;

		mDSP.init(GetSampleRate(), 0);
	}

	mDSP.sampleRate = GetSampleRate();
	SetTailSize(PLUG_TAIL_SECONDS * mDSP.sampleRate);
}

void TheExpressor::OnParamChange(int paramIdx)
{
	mParamsToUpdate.Push(paramIdx);
}

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
void Layout::init(float width, IEditorDelegate* dlg, IGraphics* pGraphics, DSP::span<const DSP::ParameterProperties> parameterProperties, IColor panelBackground)
{
	mD = dlg;

	mG = pGraphics;

	mB = mG->GetBounds();

	mKnob = mG->LoadSVG(KNOB_FN);
	mKnobD = mG->LoadSVG(KNOB_D_FN);

	for (auto i = 0; i < parameterProperties.size(); ++i)
	{
		const auto& p = parameterProperties[i];
		if (std::find(mGroupVector.begin(), mGroupVector.end(), std::string(p.group)) == mGroupVector.end())
			mGroupVector.push_back(std::string(p.group));
	}

	mWidth = width;

	mMargin = 0.15f * mWidth;
	mHeight = mWidth + mMargin;
	mCore = mWidth - 2.f * mMargin;
	mVisualizationCoreHeight = 2 * mHeight - 3 * mMargin;
	mValue = mCore * 63.f / 250.f;

	mValueText = IText(mValue, COLOR_CONTROL);
	mToggleText = IText(mCore * 0.65, COLOR_CONTROL);

	mPanelBackgroundColor = panelBackground;

	mG->EnableMultiTouch(true);
	mG->EnableMouseOver(true);
	mG->AttachPanelBackground(IPattern(mPanelBackgroundColor));
	mG->AttachCornerResizer(new ICornerResizerControlNoDblClick(mB, 20));
	mG->LoadFont("Roboto-Regular", ROBOTO_FN);

	mParameters.clear();
	mParameters.resize(parameterProperties.size());
}

void Layout::attachKnob(float h, float v, int paramIdx, bool unsmoothed)
{
	const IRECT core = mB.GetFromTLHC(mCore, mCore).GetHShifted(h + mMargin).GetVShifted(v + mMargin).GetScaledAboutCentre(0.9f);
	const IRECT bounds = mB.GetFromTLHC(mWidth, mHeight).GetHShifted(h).GetVShifted(v);

	ISVG svg = (unsmoothed ? mKnobD : mKnob);
	auto& p = mParameters[paramIdx];

	p.push_back(mG->AttachControl(new IPanelControl(bounds, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group

	p.push_back(mG->AttachControl(new ITextControl(bounds.GetReducedFromBottom(mMargin), mD->GetParam(paramIdx)->GetName(), TEXT_LABEL, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group
	p.push_back(mG->AttachControl(new ICaptionControl(core, paramIdx, TEXT_LABEL.WithVAlign(EVAlign::Middle).WithSize(TEXT_LABEL.mSize + 2), COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group, paramIdx
	p.push_back(mG->AttachControl(new ISVGKnobControl(core, svg, paramIdx), paramIdx, mD->GetParam(paramIdx)->GetGroup())); //group, paramIdx, ctrlTag
}

void Layout::attachToggle(float h, float v, int paramIdx, bool longValue)
{
	const IRECT core = mB.GetFromTLHC(mCore, mCore).GetHShifted(h + mMargin).GetVShifted(v + mMargin);
	const IRECT bounds = mB.GetFromTLHC(mWidth, mHeight).GetHShifted(h).GetVShifted(v);

	auto& p = mParameters[paramIdx];

	p.push_back(mG->AttachControl(new IPanelControl(bounds, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group

	p.push_back(mG->AttachControl(new ITextControl(bounds.GetReducedFromBottom(mMargin), mD->GetParam(paramIdx)->GetName(), TEXT_LABEL, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group
	p.push_back(mG->AttachControl(new ITextToggleControlMouseOver(core, paramIdx, mD->GetParam(paramIdx)->GetDisplayText(0.0), mD->GetParam(paramIdx)->GetDisplayText(1.0), longValue ? mToggleText.WithSize(mToggleText.mSize * 0.5f) : mToggleText), paramIdx, mD->GetParam(paramIdx)->GetGroup())); //group, paramIdx, ctrlTag
}

void Layout::attachDropDown(float h, float v, int paramIdx, IAnimationFunction animationFunc)
{
	const IRECT core = mB.GetFromTLHC(mWidth, mCore).GetHShifted(h).GetVShifted(v + mMargin);
	const IRECT bounds = mB.GetFromTLHC(mWidth, mHeight).GetHShifted(h).GetVShifted(v);

	auto& p = mParameters[paramIdx];

	p.push_back(mG->AttachControl(new IPanelControl(bounds, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group
	p.push_back(mG->AttachControl(new ITextControl(bounds.GetReducedFromBottom(mMargin), mD->GetParam(paramIdx)->GetName(), TEXT_LABEL, COLOR_TRANSPARENT), -1, mD->GetParam(paramIdx)->GetGroup())); //group

	auto* caption = mG->AttachControl(new ICaptionControl(core.GetFromTop(mToggleText.mSize / 2).GetVShifted(core.H() / 2.f - mToggleText.mSize / 4), paramIdx, mToggleText.WithSize(mToggleText.mSize * 0.5f)), paramIdx, mD->GetParam(paramIdx)->GetGroup()); //group, paramIdx, ctrlTag

	auto defaultAnimation = caption->GetAnimationFunction();

	if (animationFunc)
		caption->SetAnimation(
			[animationFunc, defaultAnimation](IControl* c)
			{
				if (defaultAnimation)
					defaultAnimation(c);

				animationFunc(c);
			}
	);
}

void Layout::attachExtras()
{
	for (auto i = 0; i < mGroupVector.size(); ++i)
		mG->AttachControl(new IVGroupControl(mGroupVector[i].c_str(), mGroupVector[i].c_str(), 0, 0, 0, -getTopBottomMargin(), STYLE_THEZHE.WithLabelText(TEXT_GROUP)), -1, mGroupVector[i].c_str());

	auto versionStr = std::string("v").append(PLUG_VERSION_STR);

	mG->AttachControl(new IURLControl(mB.GetFromBottom(getTopBottomMargin() * 1.8f).GetFromLeft(versionStr.size() * TEXT_SPEC.mSize * 0.4f), versionStr.c_str(), PLUG_URL_STR, TEXT_SPEC, COLOR_TRANSPARENT, COLOR_CONTROL_MO, COLOR_CONTROL));
}

void Layout::hideParameter(int paramIdx, bool hide)
{
	auto& p = mParameters[paramIdx];

	for (auto i = 0; i < p.size(); ++i)
		if (p[i] != nullptr)
			p[i]->Hide(hide);
}

void Layout::attachMeter(float h, float v, const char* label, float min, float max, int divisions)
{
	const IRECT core = mB.GetFromTLHC(mCore, mVisualizationCoreHeight).GetHShifted(h + mMargin).GetVShifted(v + getTopBottomMargin());

	//grid
	const auto rangeValue = max - min;
	const auto stepValue = rangeValue / static_cast<float>(divisions);
	for (int i = static_cast<int>(stepValue); i < static_cast<int>(rangeValue); i += static_cast<int>(stepValue))
		mG->AttachControl(new IVLabelControl(core.GetFromTop(core.H() * static_cast<float>(i) / rangeValue), "", STYLE_THEZHE.WithColor(EVColor::kFR, DEFAULT_SHCOLOR)));

	//grid labels
	const auto step = core.H() / static_cast<float>(divisions);
	for (int i = static_cast<int>(max - stepValue), j = 0; i > static_cast<int>(min); i -= static_cast<int>(stepValue), ++j)
		mG->AttachControl(new ITextControl(core.SubRectVertical(divisions, j).GetVShifted(step / 2.f), std::to_string(i).c_str(), DEFAULT_TEXT.WithVAlign(EVAlign::Middle), mPanelBackgroundColor, true));

	//core frame and label
	mG->AttachControl(new IVLabelControl(core, "", STYLE_THEZHE));
	mG->AttachControl(new ITextControl(core.GetReducedFromBottom(-2.f * mMargin + getTopBottomMargin()), label, TEXT_LABEL, COLOR_TRANSPARENT));

	//core
	mG->AttachControl(new IVMeterControl<1>(mB.GetFromTLHC(mCore / 7.f, mVisualizationCoreHeight).GetHShifted(h + mMargin + mCore / 7.f).GetVShifted(v + getTopBottomMargin()), "", STYLE_THEZHE.WithDrawFrame(false), EDirection::Vertical, {}, 0, IVMeterControl<1>::EResponse::Log, min, max, {}), kGuiCtrlTagL);
	mG->AttachControl(new IVMeterControl<1>(mB.GetFromTLHC(mCore / 7.f, mVisualizationCoreHeight).GetHShifted(h + mMargin + mCore * 5.f / 7.f).GetVShifted(v + getTopBottomMargin()), "", STYLE_THEZHE.WithDrawFrame(false), EDirection::Vertical, {}, 0, IVMeterControl<1>::EResponse::Log, min, max, {}), kGuiCtrlTagR);
}

void Layout::attachPlot(float h, float v, const char* label, IVPlotControl::IPlotFunc plotFunc, int numPoints, std::vector<int> dirtyParams, int xMin, int xMax, int yMin, int yMax, int xDivisions, int yDivisions)
{
	const IRECT core = mB.GetFromTLHC(mVisualizationCoreHeight, mVisualizationCoreHeight).GetHShifted(h + mMargin).GetVShifted(v + getTopBottomMargin());

	//label
	mG->AttachControl(new ITextControl(core.GetReducedFromBottom(-2 * mMargin + getTopBottomMargin()), label, TEXT_LABEL, COLOR_TRANSPARENT));

	//core
	mPlotControl = mG->AttachControl(new IVPlotControlGrid(core, { {COLOR_CONTROL, plotFunc} }, numPoints, "", STYLE_THEZHE, -1, 1, false, xDivisions, yDivisions));

	//grid labels
	const auto xRange = xMax - xMin;
	const auto xStep = xRange / static_cast<float>(xDivisions);
	const auto hStep = core.H() / static_cast<float>(xDivisions);
	const auto yRange = yMax - yMin;
	const auto yStep = yRange / static_cast<float>(yDivisions);
	const auto vStep = core.H() / static_cast<float>(yDivisions);

	for (int i = static_cast<int>(yMax - yStep), j = 0; i > static_cast<int>(yMin); i -= static_cast<int>(yStep), ++j)
		mG->AttachControl(new ITextControl(core.GetFromLeft(hStep).SubRectVertical(yDivisions, j).GetVShifted(vStep / 2.f), std::to_string(i).c_str(), TEXT_GRID, mPanelBackgroundColor, true));

	for (int i = static_cast<int>(xMax - xStep), j = xDivisions - 2; i > static_cast<int>(xMin); i -= static_cast<int>(xStep), --j)
		mG->AttachControl(new ITextControl(core.GetFromTop(vStep).SubRectHorizontal(xDivisions, j).GetHShifted(hStep / 2.f), std::to_string(i).c_str(), TEXT_GRID, mPanelBackgroundColor, true));

	//dirtyParams
	for (auto i = 0; i < dirtyParams.size(); ++i)
	{
		mG->ForControlWithParam(
			dirtyParams[i],
			[this](IControl* pControl)
			{
				if (mPlotControl != nullptr)
				{
					IControl* plotControl = mPlotControl;

					auto defaultAnimation = pControl->GetAnimationFunction();

					pControl->SetAnimation(
						[plotControl, defaultAnimation](IControl* c)
						{
							if (defaultAnimation)
								defaultAnimation(c);

							plotControl->SetDirty(true);
						}
					);
				}
			}
		);
	}
}