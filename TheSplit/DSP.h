//      _____ _____ _____ __
//     |   __|     |  |  |  |        Auto-generated C++
//     |__   |  |  |  |  |  |__      SOUL Version 0.9.0
//     |_____|_____|_____|_____|     https://soul.dev
//

#include <array>
#include <functional>
#include <cmath>
#include <cstddef>
#include <limits>
#include <cstring>

#ifndef SOUL_CPP_ASSERT
 #define SOUL_CPP_ASSERT(x)
#endif

// If you need to provide custom implementations of the instrinsics that soul uses,
// you can set this macro to provide your own namespace containing them.
#ifndef SOUL_INTRINSICS
 #define SOUL_INTRINSICS std
#endif

//==============================================================================
// Generated from graph 'main::Processor', source file: DSP.soulpatch
//
class main__Processor
{
public:
    main__Processor() = default;
    ~main__Processor() = default;

    //==============================================================================
    template <typename Type, int32_t size> struct Vector;
    template <typename Type, int32_t size> struct FixedArray;
    template <typename Type> struct DynamicArray;

    static constexpr uint32_t maxBlockSize  = 1024;
    static constexpr uint32_t latency       = 0;

    template <typename Item>
    struct span
    {
        Item* start = nullptr;
        size_t numItems = 0;

        constexpr size_t size() const               { return numItems; }
        constexpr bool empty() const                { return numItems == 0; }
        constexpr Item* begin() const               { return start; }
        constexpr Item* end() const                 { return start + numItems; }
        const Item& operator[] (size_t index) const { SOUL_CPP_ASSERT (index < numItems); return start[index]; }
    };

    static constexpr const char*  UID           = "com.TheZhe.TheSplitDSP";
    static constexpr const char*  name          = "TheSplitDSP";
    static constexpr const char*  description   = "TheSplit DSP";
    static constexpr const char*  category      = "effect";
    static constexpr const char*  manufacturer  = "TheZhe";
    static constexpr const char*  version       = "1.0";
    static constexpr const char*  URL           = "";
    static constexpr bool         isInstrument  = false;
    static constexpr const char*  manifest      = "{\r\n"
    "    \"soulPatchV1\": {\r\n"
    "        \"ID\": \"com.TheZhe.TheSplitDSP\",\r\n"
    "        \"version\": \"1.0\",\r\n"
    "        \"name\": \"TheSplitDSP\",\r\n"
    "        \"description\": \"TheSplit DSP\",\r\n"
    "        \"category\": \"effect\",\r\n"
    "        \"manufacturer\": \"TheZhe\",\r\n"
    "        \"website\": \"https://github.com/thezhe/SOUL-VA\",\r\n"
    "        \"isInstrument\": false,\r\n"
    "        \"source\": [\r\n"
    "            \"DSP.soul\",\r\n"
    "            \"../SOUL-VA/include/VA.soul\"\r\n"
    "        ]\r\n"
    "    }\r\n"
    "}";

    //==============================================================================
    struct _RenderStats;
    struct _SparseStreamStatus;
    struct _Stream_in_vec_2_f64_1024;
    struct _Event_in_f32_1;
    struct _Stream_out_vec_2_f64_1024;
    struct VA__Mux4To1__Coeffs;
    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State;
    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State;
    struct VA__Mux2To1__Coeffs;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State;
    struct soul___filters__dc_blocker__Coeffs;
    struct soul___filters__dc_blocker__State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State;
    struct VA__DC_Blocker__Processor___State;
    struct VA__StereoLink__Coeffs;
    struct VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___State;
    struct VA__Difference__Processor_4___State;
    struct VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___State;
    struct soul___filters__tpt__svf__Coeffs;
    struct soul___filters__tpt__crossover__Coeffs;
    struct soul___filters__tpt__svf__State;
    struct soul___filters__tpt__crossover__State;
    struct soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State;
    struct VA__ApplyGain__Processor_2___State;
    struct VA__AbsADAA__Coeffs;
    struct VA__AbsADAA__State;
    struct VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2;
    struct VA__AbsADAA__Processor_2___State;
    struct VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___DelayState_1;
    struct VA__BallisticsFilter__Internal__Coeffs;
    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State;

    struct VA__OnepoleC__Coeffs;
    struct VA__OnepoleC__State;
    struct VA__OnepoleC__Processor___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State;
    struct VA__SmoothedParameter___M__Coeffs;
    struct VA__SmoothedParameter___M__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State;

    struct VA__CTF__Internal__Coeffs;
    struct VA__CTF__Internal__Processor___State;
    struct VA__SmoothedParameter___M_2__Coeffs;
    struct VA__SmoothedParameter___M_2__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State;

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State;

    struct VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State;
    struct VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State;
    struct VA__Difference__Processor_2___State;
    struct VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State;
    struct VA__ApplyGain__Processor___State;
    struct VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2;
    struct VA__AbsADAA__Processor___State;
    struct VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___DelayState_1;

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State;

    struct VA__OnepoleC__Processor_2___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State;

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___DelayState_1;

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State;

    struct VA__OnepoleC__Processor_3___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State;

    struct VA__Difference__Processor_3___State;
    struct VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State;
    struct VA__ApplyGain__Processor_3___State;
    struct VA__SmoothedParameter___M_3__Coeffs;
    struct VA__SmoothedParameter___M_3__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State;

    struct VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State;
    struct VA__SigmoidC2__Processor___State;
    struct VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State;
    struct VA__Difference__Processor___State;
    struct VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State;
    struct VA__DC_Blocker__Processor_2___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State;
    struct VA__DC_Blocker__Processor_3___State;
    struct VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State;
    struct _State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO;
    struct soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___IO;
    struct VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___IO;
    struct VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___IO;
    struct VA__DC_Blocker__Processor___IO;
    struct VA__DC_Blocker__Processor_2___IO;
    struct VA__DC_Blocker__Processor_3___IO;
    struct VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___IO;
    struct VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___IO;
    struct VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___IO;
    struct VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___IO;
    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___IO;

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___IO;

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___IO;

    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___IO;
    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___IO;

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___IO;

    struct VA__OnepoleC__Processor___IO;
    struct VA__OnepoleC__Processor_2___IO;
    struct VA__OnepoleC__Processor_3___IO;
    struct VA__CTF__Internal__Processor___IO;
    struct VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___IO;
    struct VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___IO;
    struct VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___IO;
    struct VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___IO;
    struct VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___IO;
    struct VA__SigmoidC2__Processor___IO;
    struct VA__AbsADAA__Processor___IO;
    struct VA__AbsADAA__Processor_2___IO;
    struct VA__ApplyGain__Processor___IO;
    struct VA__ApplyGain__Processor_2___IO;
    struct VA__ApplyGain__Processor_3___IO;
    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___IO;
    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___IO;
    struct VA__Difference__Processor___IO;
    struct VA__Difference__Processor_2___IO;
    struct VA__Difference__Processor_3___IO;
    struct VA__Difference__Processor_4___IO;
    struct VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___IO;

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___IO;

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___IO;

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___IO;

    struct StringLiteral;

    //==============================================================================
    // The following methods provide basic initialisation and control for the processor

    void init (double newSampleRate, int sessionID)
    {
        memset (reinterpret_cast<void*> (std::addressof (state)), 0, sizeof (state));
        sampleRate = newSampleRate;
        _initialise (state, sessionID);
        initialisedState = state;
    }

    void reset() noexcept
    {
        state = initialisedState;
    }

    uint32_t getNumXRuns() noexcept
    {
        return static_cast<uint32_t> (_get_num_xruns (state));
    }

    //==============================================================================
    // These classes and functions provide a high-level rendering method that
    // presents the processor as a set of standard audio and MIDI channels.

    static constexpr uint32_t numAudioInputChannels  = 2;
    static constexpr uint32_t numAudioOutputChannels = 4;

    struct MIDIMessage
    {
        uint32_t frameIndex = 0;
        uint8_t byte0 = 0, byte1 = 0, byte2 = 0;
    };

    struct MIDIMessageArray
    {
        const MIDIMessage* messages = nullptr;
        uint32_t numMessages = 0;
    };

    template <typename FloatType = float>
    struct RenderContext
    {
        std::array<const FloatType*, 2> inputChannels;
        std::array<FloatType*, 4> outputChannels;
        MIDIMessageArray  incomingMIDI;
        uint32_t          numFrames = 0;
    };

    //==============================================================================
    template <typename FloatType>
    void render (RenderContext<FloatType> context)
    {
        uint32_t startFrame = 0;

        while (startFrame < context.numFrames)
        {
            auto framesRemaining = context.numFrames - startFrame;
            auto numFramesToDo = framesRemaining < maxBlockSize ? framesRemaining : maxBlockSize;
            prepare (numFramesToDo);

            copyToInterleaved (_getInputFrameArrayRef_in (state).elements, &context.inputChannels[0], startFrame, numFramesToDo);

            advance();

            copyFromInterleaved (&context.outputChannels[0], startFrame, _getOutputFrameArrayRef_out (state).elements, numFramesToDo);
            copyFromInterleaved (&context.outputChannels[2], startFrame, _getOutputFrameArrayRef_out1 (state).elements, numFramesToDo);
            startFrame += numFramesToDo;
        }
    }

    //==============================================================================
    // The following methods provide low-level access for read/write to all the
    // endpoints directly, and to run the prepare/advance loop.

    void prepare (uint32_t numFramesToBeRendered)
    {
        SOUL_CPP_ASSERT (numFramesToBeRendered != 0);
        framesToAdvance = numFramesToBeRendered;
        _prepare (state, static_cast<int32_t> (numFramesToBeRendered));
    }

    void advance()
    {
        SOUL_CPP_ASSERT (framesToAdvance != 0); // you must call prepare() before advance()!
        auto framesRemaining = framesToAdvance;

        while (framesRemaining > 0)
        {
            auto framesThisCall = framesRemaining < maxBlockSize ? framesRemaining : maxBlockSize;

            run (state, static_cast<int32_t> (framesThisCall));

            totalFramesElapsed += framesThisCall;
            framesRemaining -= framesThisCall;
        }
    }

    void setNextInputStreamFrames_in (const Vector<double, 2>* frames, uint32_t numFramesToUse)
    {
        auto& buffer = _getInputFrameArrayRef_in (state);

        for (uint32_t i = 0; i < numFramesToUse; ++i)
            buffer[static_cast<int> (i)] = frames[i];
    }

    void setNextInputStreamSparseFrames_in (Vector<double, 2> targetFrameValue, uint32_t numFramesToReachValue)
    {
        _setSparseInputTarget_in (state, targetFrameValue, (int32_t) numFramesToReachValue);
    }

    void addInputEvent_modeIn (float eventValue)
    {
        _addInputEvent_modeIn_f32 (state, eventValue);
    }

    void addInputEvent_flipIn (float eventValue)
    {
        _addInputEvent_flipIn_f32 (state, eventValue);
    }

    void addInputEvent_frequencyIn (float eventValue)
    {
        _addInputEvent_frequencyIn_f32 (state, eventValue);
    }

    void addInputEvent_attackIn (float eventValue)
    {
        _addInputEvent_attackIn_f32 (state, eventValue);
    }

    void addInputEvent_sustainIn (float eventValue)
    {
        _addInputEvent_sustainIn_f32 (state, eventValue);
    }

    void addInputEvent_sensitivityIn (float eventValue)
    {
        _addInputEvent_sensitivityIn_f32 (state, eventValue);
    }

    void addInputEvent_thresholdIn (float eventValue)
    {
        _addInputEvent_thresholdIn_f32 (state, eventValue);
    }

    void addInputEvent_releaseIn (float eventValue)
    {
        _addInputEvent_releaseIn_f32 (state, eventValue);
    }

    void addInputEvent_stereoLinkLsIn (float eventValue)
    {
        _addInputEvent_stereoLinkLsIn_f32 (state, eventValue);
    }

    DynamicArray<const Vector<double, 2>> getOutputStreamFrames_out()
    {
        return { &(_getOutputFrameArrayRef_out (state).elements[0]), static_cast<int32_t> (framesToAdvance) };
    }

    DynamicArray<const Vector<double, 2>> getOutputStreamFrames_out1()
    {
        return { &(_getOutputFrameArrayRef_out1 (state).elements[0]), static_cast<int32_t> (framesToAdvance) };
    }

    //==============================================================================
    // The following methods provide a fixed interface for finding out about
    // the input/output endpoints that this processor provides.

    using EndpointID = const char*;
    enum class EndpointType     { value, stream, event };

    struct EndpointDetails
    {
        const char* name;
        EndpointID endpointID;
        EndpointType endpointType;
        const char* frameType;
        uint32_t numAudioChannels;
        const char* annotation;
    };

    std::array<EndpointDetails, 10> getInputEndpoints() const
    {
        return
        {
            EndpointDetails { "in",             "in:in",             EndpointType::stream, "float64<2>", 2, ""                                                                                                                             },
            EndpointDetails { "modeIn",         "in:modeIn",         EndpointType::event,  "float32",    0, "{ \"name\": \"Mode\", \"min\": 0, \"max\": 3, \"init\": 0, \"text\": \"C&S|L&H|A&S|L&S\", \"group\": \"GroupSelect\" }"       },
            EndpointDetails { "flipIn",         "in:flipIn",         EndpointType::event,  "float32",    0, "{ \"name\": \"Flip\", \"min\": 0, \"max\": 1, \"init\": 0, \"text\": \"Off|On\" }"                                            },
            EndpointDetails { "frequencyIn",    "in:frequencyIn",    EndpointType::event,  "float32",    0, "{ \"name\": \"Freq\", \"min\": 20, \"max\": 20000, \"init\": 1000.0, \"step\": 1, \"unit\": \"Hz\", \"group\": \"L&H\" }"     },
            EndpointDetails { "attackIn",       "in:attackIn",       EndpointType::event,  "float32",    0, "{ \"name\": \"Attack\", \"min\": 4, \"max\": 26, \"init\": 4.0, \"step\": 1, \"unit\": \"ms\", \"group\": \"A&S\" }"          },
            EndpointDetails { "sustainIn",      "in:sustainIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Sustain\", \"min\": 30, \"max\": 200, \"init\": 30.0, \"step\": 1, \"unit\": \"ms\", \"group\": \"A&S\" }"      },
            EndpointDetails { "sensitivityIn",  "in:sensitivityIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Sens\", \"min\": 0, \"max\": 36, \"init\": 36.0, \"step\": 1, \"unit\": \"dB\", \"group\": \"A&S\" }"           },
            EndpointDetails { "thresholdIn",    "in:thresholdIn",    EndpointType::event,  "float32",    0, "{ \"name\": \"Thresh\", \"min\": -50.0, \"max\": -12.0, \"init\": -30.0, \"unit\": \"dB\", \"step\": 1, \"group\": \"L&S\" }" },
            EndpointDetails { "releaseIn",      "in:releaseIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Release\", \"min\": 30, \"max\": 999, \"init\": 30.0, \"unit\": \"ms\", \"step\": 1, \"group\": \"L&S\" }"      },
            EndpointDetails { "stereoLinkLsIn", "in:stereoLinkLsIn", EndpointType::event,  "float32",    0, "{ \"name\": \"Link\", \"min\": 0, \"max\": 100, \"init\": 0.0, \"unit\": \"%\", \"step\": 1, \"group\": \"L&S\" }"            }
        };
    }

    std::array<EndpointDetails, 2> getOutputEndpoints() const
    {
        return
        {
            EndpointDetails { "out",  "out:out",  EndpointType::stream, "float64<2>", 2, "" },
            EndpointDetails { "out1", "out:out1", EndpointType::stream, "float64<2>", 2, "" }
        };
    }

    //==============================================================================
    // The following methods provide help in dealing with the processor's endpoints
    // in a format suitable for traditional audio plugin channels and parameters.

    struct ParameterProperties
    {
        const char* UID;
        const char* name;
        const char* unit;
        float minValue, maxValue, step, initialValue;
        bool isAutomatable, isBoolean, isHidden;
        const char* group;
        const char* textValues;
    };

    struct Parameter
    {
        ParameterProperties properties;
        float currentValue;
        std::function<void(float)> applyValue;

        void setValue (float f)
        {
            currentValue = snapToLegalValue (f);
            applyValue (f);
        }

        float getValue() const
        {
            return currentValue;
        }

    private:
        float snapToLegalValue (float v) const
        {
            if (properties.step > 0)
                v = properties.minValue + properties.step * SOUL_INTRINSICS::floor ((v - properties.minValue) / properties.step + 0.5f);

            return v < properties.minValue ? properties.minValue : (v > properties.maxValue ? properties.maxValue : v);
        }
    };

    struct AudioBus
    {
        const char* name;
        uint32_t numChannels;
    };

    static constexpr bool      hasMIDIInput = false;
    static constexpr uint32_t  numParameters = 9;

    static constexpr const std::array<const ParameterProperties, numParameters> parameters =
    {
        ParameterProperties {  "modeIn",          "Mode",     "",    0.0f,    3.0f,      1.0f,  0.0f,     true,  false,  false,  "GroupSelect",  "C&S|L&H|A&S|L&S"  },
        ParameterProperties {  "flipIn",          "Flip",     "",    0.0f,    1.0f,      1.0f,  0.0f,     true,  false,  false,  "",             "Off|On"           },
        ParameterProperties {  "frequencyIn",     "Freq",     "Hz",  20.0f,   20000.0f,  1.0f,  1000.0f,  true,  false,  false,  "L&H",          ""                 },
        ParameterProperties {  "attackIn",        "Attack",   "ms",  4.0f,    26.0f,     1.0f,  4.0f,     true,  false,  false,  "A&S",          ""                 },
        ParameterProperties {  "sustainIn",       "Sustain",  "ms",  30.0f,   200.0f,    1.0f,  30.0f,    true,  false,  false,  "A&S",          ""                 },
        ParameterProperties {  "sensitivityIn",   "Sens",     "dB",  0.0f,    36.0f,     1.0f,  36.0f,    true,  false,  false,  "A&S",          ""                 },
        ParameterProperties {  "thresholdIn",     "Thresh",   "dB",  -50.0f,  -12.0f,    1.0f,  -30.0f,   true,  false,  false,  "L&S",          ""                 },
        ParameterProperties {  "releaseIn",       "Release",  "ms",  30.0f,   999.0f,    1.0f,  30.0f,    true,  false,  false,  "L&S",          ""                 },
        ParameterProperties {  "stereoLinkLsIn",  "Link",     "%",   0.0f,    100.0f,    1.0f,  0.0f,     true,  false,  false,  "L&S",          ""                 }
    };

    static span<const ParameterProperties> getParameterProperties() { return { parameters.data(), numParameters }; }

    static constexpr uint32_t numInputBuses  = 1;
    static constexpr uint32_t numOutputBuses = 2;

    static constexpr std::array<const AudioBus, numInputBuses>  inputBuses = { AudioBus { "in", 2 } };

    static constexpr std::array<const AudioBus, numOutputBuses> outputBuses =
    {
        AudioBus { "out",  2 },
        AudioBus { "out1", 2 }
    };

    static span<const AudioBus> getInputBuses()  { return { inputBuses.data(), numInputBuses }; }
    static span<const AudioBus> getOutputBuses() { return { outputBuses.data(), numOutputBuses }; }

    struct ParameterList
    {
        Parameter* begin()                      { return params; }
        Parameter* end()                        { return params + numParameters; }
        size_t size() const                     { return numParameters; }
        Parameter& operator[] (size_t index)    { SOUL_CPP_ASSERT (index < numParameters); return params[index]; }

        Parameter params[numParameters == 0 ? 1 : numParameters];
    };

    ParameterList createParameterList()
    {
        return
        {
            {
                Parameter {  parameters[0],  0.0f,     [this] (float v) { addInputEvent_modeIn (v); }          },
                Parameter {  parameters[1],  0.0f,     [this] (float v) { addInputEvent_flipIn (v); }          },
                Parameter {  parameters[2],  1000.0f,  [this] (float v) { addInputEvent_frequencyIn (v); }     },
                Parameter {  parameters[3],  4.0f,     [this] (float v) { addInputEvent_attackIn (v); }        },
                Parameter {  parameters[4],  30.0f,    [this] (float v) { addInputEvent_sustainIn (v); }       },
                Parameter {  parameters[5],  36.0f,    [this] (float v) { addInputEvent_sensitivityIn (v); }   },
                Parameter {  parameters[6],  -30.0f,   [this] (float v) { addInputEvent_thresholdIn (v); }     },
                Parameter {  parameters[7],  30.0f,    [this] (float v) { addInputEvent_releaseIn (v); }       },
                Parameter {  parameters[8],  0.0f,     [this] (float v) { addInputEvent_stereoLinkLsIn (v); }  }
            }
        };
    }

    static constexpr bool hasTimelineEndpoints = false;

    void setTimeSignature (int32_t newNumerator, int32_t newDenominator)
    {
        (void) newNumerator; (void) newDenominator;
    }

    void setTempo (float newBPM)
    {
        (void) newBPM;
    }

    void setTransportState (int32_t newState)
    {
        (void) newState;
    }

    void setPosition (int64_t currentFrame, double currentQuarterNote, double lastBarStartQuarterNote)
    {
        (void) currentFrame; (void) currentQuarterNote; (void) lastBarStartQuarterNote;
    }

    //==============================================================================
    struct ZeroInitialiser
    {
        template <typename Type>   operator Type() const   { return {}; }
        template <typename Index>  ZeroInitialiser operator[] (Index) const { return {}; }
    };

    //==============================================================================
    template <typename Type>
    struct DynamicArray
    {
        using ElementType = Type;
        ElementType* elements = nullptr;
        int32_t numElements = 0;

        constexpr ElementType& operator[] (int i) noexcept                   { return elements[i]; }
        constexpr const ElementType& operator[] (int i) const noexcept       { return elements[i]; }
        constexpr int getElementSizeBytes() const noexcept                   { return sizeof (ElementType); }
    };

    //==============================================================================
    template <typename Type, int32_t size>
    struct FixedArray
    {
        using ElementType = Type;
        ElementType elements[size];
        static constexpr int32_t numElements = size;

        static constexpr FixedArray fromRepeatedValue (ElementType value)
        {
            FixedArray a;

            for (auto& element : a.elements)
                element = value;

            return a;
        }

        static size_t elementOffset (int i) noexcept               { return sizeof (ElementType) * i; }
        ElementType& operator[] (int i) noexcept                   { return elements[i]; }
        const ElementType& operator[] (int i) const noexcept       { return elements[i]; }
        int getElementSizeBytes() const noexcept                   { return sizeof (ElementType); }
        DynamicArray<ElementType> toDynamicArray() const noexcept  { return { const_cast<ElementType*> (&elements[0]), size }; }
        operator ElementType*() const noexcept                     { return const_cast<ElementType*> (&elements[0]); }

        FixedArray& operator= (ZeroInitialiser)
        {
            for (auto& e : elements)
                e = ElementType {};

            return *this;
        }

        template <int start, int end>
        constexpr FixedArray<Type, end - start> slice() const noexcept
        {
            FixedArray<Type, end - start> newSlice;

            for (int i = 0; i < end - start; ++i)
                newSlice.elements[i] = elements[start + i];

            return newSlice;
        }
    };

    //==============================================================================
    template <typename Type, int32_t size>
    struct Vector
    {
        using ElementType = Type;
        ElementType elements[size] = {};
        static constexpr int32_t numElements = size;

        constexpr Vector() = default;
        constexpr Vector (const Vector&) = default;
        constexpr Vector& operator= (const Vector&) = default;

        explicit constexpr Vector (Type value)
        {
            for (auto& element : elements)
                element = value;
        }

        template <typename OtherType>
        constexpr Vector (const Vector<OtherType, size>& other)
        {
            for (int32_t i = 0; i < size; ++i)
                elements[i] = static_cast<Type> (other.elements[i]);
        }

        constexpr Vector (std::initializer_list<Type> i)
        {
            int n = 0;

            for (auto e : i)
                elements[n++] = e;
        }

        static constexpr Vector fromRepeatedValue (Type value)
        {
            return Vector (value);
        }

        constexpr Vector operator+ (const Vector& rhs) const                { return apply<Vector> (rhs, [] (Type a, Type b) { return a + b; }); }
        constexpr Vector operator- (const Vector& rhs) const                { return apply<Vector> (rhs, [] (Type a, Type b) { return a - b; }); }
        constexpr Vector operator* (const Vector& rhs) const                { return apply<Vector> (rhs, [] (Type a, Type b) { return a * b; }); }
        constexpr Vector operator/ (const Vector& rhs) const                { return apply<Vector> (rhs, [] (Type a, Type b) { return a / b; }); }
        constexpr Vector operator% (const Vector& rhs) const                { return apply<Vector> (rhs, [] (Type a, Type b) { return a % b; }); }
        constexpr Vector operator-() const                                  { return apply<Vector> ([] (Type n) { return -n; }); }
        constexpr Vector operator~() const                                  { return apply<Vector> ([] (Type n) { return ~n; }); }
        constexpr Vector operator!() const                                  { return apply<Vector> ([] (Type n) { return ! n; }); }

        Vector& operator= (ZeroInitialiser)
        {
            for (auto& e : elements)
                e = {};

            return *this;
        }

        constexpr Vector<bool, size> operator== (const Vector& rhs) const   { return apply<Vector<bool, size>> (rhs, [] (Type a, Type b) { return a == b; }); }
        constexpr Vector<bool, size> operator!= (const Vector& rhs) const   { return apply<Vector<bool, size>> (rhs, [] (Type a, Type b) { return a != b; }); }

        template <typename ReturnType, typename Op>
        constexpr ReturnType apply (const Vector& rhs, Op&& op) const noexcept
        {
            ReturnType v;

            for (int i = 0; i < size; ++i)
                v.elements[i] = op (elements[i], rhs.elements[i]);

            return v;
        }

        template <typename ReturnType, typename Op>
        constexpr ReturnType apply (Op&& op) const noexcept
        {
            ReturnType v;

            for (int i = 0; i < size; ++i)
                v.elements[i] = op (elements[i]);

            return v;
        }

        template <int start, int end>
        constexpr Vector<Type, end - start> slice() const noexcept
        {
            Vector<Type, end - start> newSlice;

            for (int i = 0; i < end - start; ++i)
                newSlice.elements[i] = elements[start + i];

            return newSlice;
        }

        constexpr const Type& operator[] (int i) const noexcept  { return elements[i]; }
        constexpr Type& operator[] (int i) noexcept              { return elements[i]; }
    };

    //==============================================================================
    struct StringLiteral
    {
        constexpr StringLiteral (int32_t h) noexcept : handle (h) {}
        StringLiteral() = default;
        StringLiteral (const StringLiteral&) = default;
        StringLiteral& operator= (const StringLiteral&) = default;

        const char* toString() const       { return lookupStringLiteral (handle); }
        operator const char*() const       { return lookupStringLiteral (handle); }

        bool operator== (StringLiteral other) const noexcept    { return handle == other.handle; }
        bool operator!= (StringLiteral other) const noexcept    { return handle != other.handle; }

        int32_t handle = 0;
    };


    //==============================================================================
    //==============================================================================
    //
    //    All the code that follows this point should be considered internal.
    //    User code should rarely need to refer to anything beyond this point..
    //
    //==============================================================================
    //==============================================================================

    template <typename Vec>  static Vec _vec_sqrt  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::sqrt (x); }); }
    template <typename Vec>  static Vec _vec_pow   (Vec a, Vec b)  { return a.template apply<Vec> ([&] (typename Vec::ElementType x) { return SOUL_INTRINSICS::pow (x, b); }); }
    template <typename Vec>  static Vec _vec_exp   (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::exp (x); }); }
    template <typename Vec>  static Vec _vec_log   (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::log (x); }); }
    template <typename Vec>  static Vec _vec_log10 (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::log10 (x); }); }
    template <typename Vec>  static Vec _vec_sin   (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::sin (x); }); }
    template <typename Vec>  static Vec _vec_cos   (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::cos (x); }); }
    template <typename Vec>  static Vec _vec_tan   (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::tan (x); }); }
    template <typename Vec>  static Vec _vec_sinh  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::sinh (x); }); }
    template <typename Vec>  static Vec _vec_cosh  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::cosh (x); }); }
    template <typename Vec>  static Vec _vec_tanh  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::tanh (x); }); }
    template <typename Vec>  static Vec _vec_asinh (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::asinh (x); }); }
    template <typename Vec>  static Vec _vec_acosh (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::acosh (x); }); }
    template <typename Vec>  static Vec _vec_atanh (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::atanh (x); }); }
    template <typename Vec>  static Vec _vec_asin  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::asin (x); }); }
    template <typename Vec>  static Vec _vec_acos  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::acos (x); }); }
    template <typename Vec>  static Vec _vec_atan  (Vec a)         { return a.template apply<Vec> ([]  (typename Vec::ElementType x) { return SOUL_INTRINSICS::atan (x); }); }
    template <typename Vec>  static Vec _vec_atan2 (Vec a, Vec b)  { return a.template apply<Vec> ([&] (typename Vec::ElementType x) { return SOUL_INTRINSICS::atan2 (x, b); }); }

    static constexpr int32_t _intrin_clamp (int32_t n, int32_t low, int32_t high)  { return n < low ? low : (n > high ? high : n); }
    static constexpr int32_t _intrin_wrap (int32_t n, int32_t range)   { if (range == 0) return 0; auto x = n % range; return x < 0 ? x + range : x; }

    static constexpr float  _nan32 = std::numeric_limits<float>::quiet_NaN();
    static constexpr double _nan64 = std::numeric_limits<double>::quiet_NaN();

    static constexpr float  _inf32 = std::numeric_limits<float>::infinity();
    static constexpr double _inf64 = std::numeric_limits<double>::infinity();

    static constexpr float  _ninf32 = -_inf32;
    static constexpr double _ninf64 = -_inf64;

    template <typename SourceFloatType, typename DestFloatType>
    static inline void copyToInterleaved (DestFloatType* monoDest, const SourceFloatType* const* sourceChannels, uint32_t sourceStartFrame, uint32_t numFrames)
    {
        auto source = *sourceChannels + sourceStartFrame;

        for (uint32_t i = 0; i < numFrames; ++i)
            monoDest[i] = static_cast<DestFloatType> (source[i]);
    }

    template <typename SourceFloatType, typename DestFloatType, int32_t numChannels>
    static inline void copyToInterleaved (Vector<DestFloatType, numChannels>* vectorDest, const SourceFloatType* const* sourceChannels, uint32_t sourceStartFrame, uint32_t numFrames)
    {
        for (uint32_t i = 0; i < numFrames; ++i)
            for (uint32_t chan = 0; chan < static_cast<uint32_t> (numChannels); ++chan)
                vectorDest[i].elements[chan] = static_cast<DestFloatType> (sourceChannels[chan][sourceStartFrame + i]);
    }

    template <typename SourceFloatType, typename DestFloatType>
    static inline void copyFromInterleaved (DestFloatType* const* destChannels, uint32_t destStartFrame, const SourceFloatType* monoSource, uint32_t numFrames)
    {
        auto dest = *destChannels + destStartFrame;

        for (uint32_t i = 0; i < numFrames; ++i)
            dest[i] = static_cast<DestFloatType> (monoSource[i]);
    }

    template <typename SourceFloatType, typename DestFloatType, int32_t numChannels>
    static inline void copyFromInterleaved (DestFloatType* const* destChannels, uint32_t destStartFrame, const Vector<SourceFloatType, numChannels>* vectorSource, uint32_t numFrames)
    {
        for (uint32_t i = 0; i < numFrames; ++i)
            for (uint32_t chan = 0; chan < static_cast<uint32_t> (numChannels); ++chan)
                destChannels[chan][destStartFrame + i] = static_cast<DestFloatType> (vectorSource[i].elements[chan]);
    }

    //==============================================================================
    struct _RenderStats
    {
        int32_t m_underrunCount, m_underrunFrames, m_overrunCount, m_overrunFrames;
    };

    struct _SparseStreamStatus
    {
        int32_t m_activeRamps;
        FixedArray<int32_t, 10> m_rampArray;
    };

    struct _Stream_in_vec_2_f64_1024
    {
        FixedArray<Vector<double, 2>, 1024> m_buffer;
        Vector<double, 2> m_currentSparseValue, m_targetSparseValue, m_perFrameIncrement;
        int32_t m_numSparseFramesToRender, m_constantFilledFrames;
        bool m_sparseStreamActive;
    };

    struct _Event_in_f32_1
    {
        int32_t m_numFrames;
    };

    struct _Stream_out_vec_2_f64_1024
    {
        FixedArray<Vector<double, 2>, 1024> m_buffer;
    };

    struct VA__Mux4To1__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux4To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux4To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Mux2To1__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct soul___filters__dc_blocker__Coeffs
    {
        double m_b1, m_a0;
    };

    struct soul___filters__dc_blocker__State
    {
        FixedArray<Vector<double, 2>, 1> m_x, m_y;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State m_dcBlocker_state;
    };

    struct VA__StereoLink__Coeffs
    {
        float m_stereoLink;
    };

    struct VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Difference__Processor_4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___State m_stereoLink_state;
        VA__Difference__Processor_4___State m_difference_state;
    };

    struct soul___filters__tpt__svf__Coeffs
    {
        double m_a0, m_a, m_p;
    };

    struct soul___filters__tpt__crossover__Coeffs
    {
        soul___filters__tpt__svf__Coeffs m_svf1, m_svf2;
    };

    struct soul___filters__tpt__svf__State
    {
        FixedArray<Vector<double, 2>, 2> m_z;
    };

    struct soul___filters__tpt__crossover__State
    {
        soul___filters__tpt__svf__State m_svf1, m_svf2;
    };

    struct soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__crossover__Coeffs m_c;
        soul___filters__tpt__crossover__State m_s;
    };

    struct VA__ApplyGain__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__AbsADAA__Coeffs
    {
    };

    struct VA__AbsADAA__State
    {
        Vector<double, 2> m_x_3, m_x_2, m_x_1, m_F3_1, m_F2_1, m_F1_1;
    };

    struct VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__AbsADAA__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__AbsADAA__Coeffs m_c;
        VA__AbsADAA__State m_s;
        VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
    };

    struct VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__BallisticsFilter__Internal__Coeffs
    {
        Vector<double, 2> m_OmegaA, m_OmegaR;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_attack, m_release;
        bool m_recalc;
        int32_t m_counter_1;
        VA__BallisticsFilter__Internal__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__OnepoleC__Coeffs
    {
        Vector<double, 2> m_G;
    };

    struct VA__OnepoleC__State
    {
        Vector<double, 2> m_s;
    };

    struct VA__OnepoleC__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__OnepoleC__Coeffs m_c;
        VA__OnepoleC__State m_s;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___DelayState_1 m__delayState_1;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State
        m_internal_state;
        VA__OnepoleC__Processor___State m_onepoleC_state;
    };

    struct VA__SmoothedParameter___M__Coeffs
    {
        FixedArray<Vector<double, 2>, 1> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M__State
    {
        FixedArray<Vector<double, 2>, 1> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF__Internal__Coeffs
    {
        Vector<double, 2> m_threshold, m_ratio0, m_ratio1;
    };

    struct VA__CTF__Internal__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__CTF__Internal__Coeffs m_c;
    };

    struct VA__SmoothedParameter___M_2__Coeffs
    {
        FixedArray<Vector<double, 2>, 1> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M_2__State
    {
        FixedArray<Vector<double, 2>, 1> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_2__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_2__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_2__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_2__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State m_smoothedParameter0_state;

        VA__CTF__Internal__Processor___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State m_smoothedParameter1_state;

        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State m_smoothedParameter2_state;

    };

    struct VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor_2___State m_applyGain_state;
        VA__AbsADAA__Processor_2___State m_absADAA_state;
        VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State m_stereoLink_state;
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State m_ballisticsFilter_state;
        VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State m_ctf_state;
    };

    struct VA__Difference__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State m_expressorClassical_state;
        VA__Difference__Processor_2___State m_difference_state;
    };

    struct VA__ApplyGain__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__AbsADAA__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__AbsADAA__Coeffs m_c;
        VA__AbsADAA__State m_s;
        VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
    };

    struct VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_attack, m_release;
        bool m_recalc;
        int32_t m_counter_1;
        VA__BallisticsFilter__Internal__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__OnepoleC__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__OnepoleC__Coeffs m_c;
        VA__OnepoleC__State m_s;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___DelayState_1
        m__delayState_1;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State
        m_internal_state;
        VA__OnepoleC__Processor_2___State m_onepoleC_state;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_attack, m_release;
        bool m_recalc;
        int32_t m_counter_1;
        VA__BallisticsFilter__Internal__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__OnepoleC__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__OnepoleC__Coeffs m_c;
        VA__OnepoleC__State m_s;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___DelayState_1
        m__delayState_1;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State
        m_internal_state;
        VA__OnepoleC__Processor_3___State m_onepoleC_state;
    };

    struct VA__Difference__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State m_ballisticsFilter0_state;

        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State m_ballisticsFilter1_state;

        VA__Difference__Processor_3___State m_difference_state;
    };

    struct VA__ApplyGain__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedParameter___M_3__Coeffs
    {
        FixedArray<Vector<double, 2>, 1> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M_3__State
    {
        FixedArray<Vector<double, 2>, 1> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_3__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_3__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor_3___State m_applyGain_state;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State
        m_smoothedGain_state;
    };

    struct VA__SigmoidC2__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor___State m_applyGain_state;
        VA__AbsADAA__Processor___State m_absADAA_state;
        VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___State m_stereoLink_state;
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State m_det_state;
        VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State m_smoothedVolume_state;
        VA__SigmoidC2__Processor___State m_sigmoidC2_state;
    };

    struct VA__Difference__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State m_sustainIsolator_state;
        VA__Difference__Processor___State m_difference_state;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State m_dcBlocker_state;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State m_dcBlocker_state;
    };

    struct VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State m_mux4To1_0_state;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State m_mux4To1_1_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State m_mux2To1_0_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State m_mux2To1_1_state;
        VA__DC_Blocker__Processor___State m_dcBlockerIn_state;
        VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___State m_splitCenterSides_state;
        soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State m_pCrossover_state;
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State m_splitLoudSoft_state;
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State m_splitAttackSustain_state;
        VA__DC_Blocker__Processor_2___State m_dcBlockerOut0_state;
        VA__DC_Blocker__Processor_3___State m_dcBlockerOut1_state;
    };

    struct _State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId, m__framesToAdvance;
        _RenderStats m__renderStats;
        _SparseStreamStatus m__sparseStreamStatus;
        _Stream_in_vec_2_f64_1024 m__in_in;
        _Event_in_f32_1 m__in_modeIn, m__in_flipIn, m__in_frequencyIn, m__in_attackIn, m__in_sustainIn, m__in_sensitivityIn, m__in_thresholdIn, m__in_releaseIn, m__in_stereoLinkLsIn;
        _Stream_out_vec_2_f64_1024 m__out_out, m__out_out1;
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State m_e_state;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___IO
    {
        Vector<double, 2> m__in_in, m__out_lowOut, m__out_highOut;
    };

    struct VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___IO
    {
        Vector<double, 2> m__in_in, m__out_out, m__out_out1;
    };

    struct VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___IO
    {
        Vector<double, 2> m__in_in, m__out_attackOut, m__out_sustainOut;
    };

    struct VA__DC_Blocker__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DC_Blocker__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DC_Blocker__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___IO
    {
        Vector<double, 2> m__in_in, m__out_loudOut, m__out_softOut;
    };

    struct VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___IO
    {
        Vector<double, 2> m__in_x, m__in_y, m__out_Omega;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___IO
    {
        Vector<double, 2> m__in_x, m__in_y, m__out_Omega;
    };

    struct VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___IO
    {
        Vector<double, 2> m__in_x, m__in_y, m__out_Omega;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__OnepoleC__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut;
    };

    struct VA__OnepoleC__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut;
    };

    struct VA__OnepoleC__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut;
    };

    struct VA__CTF__Internal__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_thresholdIn, m__in_ratio0In, m__in_ratio1In, m__out_out;
    };

    struct VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___IO
    {
        Vector<double, 2> m__in_in, m__out_centerOut, m__out_sidesOut;
    };

    struct VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SigmoidC2__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__AbsADAA__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__AbsADAA__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_2___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_3___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__in_in3, m__out_out;
    };

    struct VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__in_in3, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor_4___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___IO
    {
        Vector<double, 2> m__out_out;
    };

    //==============================================================================
    #if __clang__
     #pragma clang diagnostic push
     #pragma clang diagnostic ignored "-Wunused-label"
     #pragma clang diagnostic ignored "-Wunused-parameter"
     #pragma clang diagnostic ignored "-Wshadow"
    #elif defined(__GNUC__)
     #pragma GCC diagnostic push
     #pragma GCC diagnostic ignored "-Wunused-label"
     #pragma GCC diagnostic ignored "-Wunused-parameter"
     #pragma GCC diagnostic ignored "-Wshadow"
    #elif defined(_MSC_VER)
     #pragma warning (push)
     #pragma warning (disable: 4100 4102 4458)
    #endif

    //==============================================================================
    int32_t run (_State& _state, int32_t maxFrames) noexcept
    {
        int32_t _2 = {};
        Vector<double, 2> _3 = {};
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___IO _4 = {};

        _2 = _internal___minInt32 (1024, maxFrames);
        _updateRampingStreams (_state, _2);
        _state.m__frameCount = 0;
        _main_loop_check: { if (! (_state.m__frameCount < _2)) goto _exit; }
        _main_loop_body: { _3 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, _state.m__frameCount);
                           _4 = ZeroInitialiser();
                           _4.m__in_in = _3;
                           VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e__run (_state.m_e_state, _4);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_out, _state.m__frameCount, _4.m__out_out);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_out1, _state.m__frameCount, _4.m__out_out1);
                           _state.m__frameCount = _state.m__frameCount + 1;
                           goto _main_loop_check;
        }
        _exit: { _state.m__frameCount = 0;
                 return _2;
        }
    }

    void _initialise (_State& _state, int32_t sessionID) noexcept
    {
        _state.m__sessionID = sessionID;
        _state.m_e_state.m__arrayEntry = 0;
        _state.m_e_state.m__sessionID = _state.m__sessionID;
        _state.m_e_state.m__processorId = 47;
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___initialise (_state.m_e_state);
    }

    void _addInputEvent_modeIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___modeIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_flipIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___flipIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_frequencyIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___frequencyIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_attackIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___attackIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_sustainIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___sustainIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_sensitivityIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___sensitivityIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_thresholdIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___thresholdIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_releaseIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___releaseIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_stereoLinkLsIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___stereoLinkLsIn_f32 (_state.m_e_state, event);
    }

    FixedArray<Vector<double, 2>, 1024>& _getInputFrameArrayRef_in (_State& _state) noexcept
    {
        return _state.m__in_in.m_buffer;
    }

    void _setSparseStream_struct__Stream_in_vec_2_f64_1024 (_Stream_in_vec_2_f64_1024& streamState, const Vector<double, 2>& targetValue, int32_t framesToReachTarget) noexcept
    {
        double _2 = {};
        Vector<double, 2> rampFrames = {}, delta = {};

        if (! (framesToReachTarget == 0)) goto _ramp;
        _no_ramp: { streamState.m_currentSparseValue = targetValue;
                    streamState.m_targetSparseValue = targetValue;
                    streamState.m_perFrameIncrement = ZeroInitialiser();
                    streamState.m_numSparseFramesToRender = 0;
                    streamState.m_constantFilledFrames = 0;
                    streamState.m_sparseStreamActive = true;
                    return;
        }
        _ramp: { _2 = static_cast<double> (framesToReachTarget);
                 rampFrames = Vector<double, 2> (_2);
                 delta = static_cast<Vector<double, 2>> (targetValue - streamState.m_currentSparseValue);
                 streamState.m_targetSparseValue = targetValue;
                 streamState.m_perFrameIncrement = delta / rampFrames;
                 streamState.m_numSparseFramesToRender = framesToReachTarget;
                 streamState.m_constantFilledFrames = 0;
                 streamState.m_sparseStreamActive = true;
        }
    }

    void _setSparseInputTarget_in (_State& _state, const Vector<double, 2>& targetValue, int32_t framesToReachTarget) noexcept
    {
        if (_state.m__in_in.m_sparseStreamActive) goto _block_1;
        _block_0: { _addRampingStream (_state.m__sparseStreamStatus, 0); }
        _block_1: { _setSparseStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, targetValue, framesToReachTarget); }
    }

    FixedArray<Vector<double, 2>, 1024>& _getOutputFrameArrayRef_out (_State& state) noexcept
    {
        return state.m__out_out.m_buffer;
    }

    FixedArray<Vector<double, 2>, 1024>& _getOutputFrameArrayRef_out1 (_State& state) noexcept
    {
        return state.m__out_out1.m_buffer;
    }

    void _prepare (_State& state, int32_t frames) noexcept
    {
        state.m__framesToAdvance = frames;
    }

    int32_t _get_num_xruns (_State& state) noexcept
    {
        return state.m__renderStats.m_underrunCount + state.m__renderStats.m_overrunCount;
    }

    //==============================================================================
    void _renderSparseFrames_struct__Stream_in_vec_2_f64_1024 (_Stream_in_vec_2_f64_1024& stream, int32_t startFrame, int32_t framesToGenerate) noexcept
    {
        int32_t writePos = {};
        Vector<double, 2> currentValue = {};

        writePos = startFrame;
        currentValue = stream.m_currentSparseValue;
        _main_loop_check: { if (! (framesToGenerate > 0)) goto _exit_after_loop; }
        _main_loop_body: { stream.m_buffer[writePos] = currentValue;
                           currentValue = currentValue + stream.m_perFrameIncrement;
                           writePos = writePos + 1;
                           framesToGenerate = framesToGenerate - 1;
                           goto _main_loop_check;
        }
        _exit_after_loop: { stream.m_currentSparseValue = currentValue; }
    }

    bool _applySparseStreamData_struct__Stream_in_vec_2_f64_1024 (_Stream_in_vec_2_f64_1024& stream, int32_t numFrames) noexcept
    {
        int32_t rampFrames = {};

        rampFrames = 0;
        if (! (stream.m_sparseStreamActive == true)) goto _exitTrue;
        _check_stream_state: { if (! (stream.m_numSparseFramesToRender == 0)) goto _render_ramp; }
        _no_frames_to_render: { if (stream.m_constantFilledFrames == 1024) goto _rampComplete; }
        _add_fixed_value: { stream.m_currentSparseValue = stream.m_targetSparseValue;
                            stream.m_perFrameIncrement = ZeroInitialiser();
                            _renderSparseFrames_struct__Stream_in_vec_2_f64_1024 (stream, stream.m_constantFilledFrames, _internal___minInt32 (numFrames, 1024 - stream.m_constantFilledFrames));
                            stream.m_constantFilledFrames = stream.m_constantFilledFrames + _internal___minInt32 (numFrames, 1024 - stream.m_constantFilledFrames);
                            goto _exit;
        }
        _render_ramp: { rampFrames = _internal___minInt32 (numFrames, stream.m_numSparseFramesToRender);
                        _renderSparseFrames_struct__Stream_in_vec_2_f64_1024 (stream, 0, rampFrames);
                        stream.m_numSparseFramesToRender = stream.m_numSparseFramesToRender - rampFrames;
                        if (rampFrames == numFrames) goto _exit;
        }
        _fill_remainder: { stream.m_currentSparseValue = stream.m_targetSparseValue;
                           stream.m_perFrameIncrement = ZeroInitialiser();
                           _renderSparseFrames_struct__Stream_in_vec_2_f64_1024 (stream, rampFrames, numFrames - rampFrames);
        }
        _exit: { return false; }
        _exitTrue: { return true; }
        _rampComplete: { stream.m_sparseStreamActive = false;
                         return true;
        }
    }

    void _addRampingStream (_SparseStreamStatus& status, int32_t streamId) noexcept
    {
        status.m_rampArray[status.m_activeRamps] = streamId;
        status.m_activeRamps = status.m_activeRamps + 1;
    }

    bool _updateRampingStream (_State& _state, int32_t streamId, int32_t framesToRender) noexcept
    {
        bool rampComplete = {};

        rampComplete = false;
        if (! (streamId == 0)) goto _exit;
        _case_0: { rampComplete = _applySparseStreamData_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, framesToRender); }
        _exit: { return rampComplete; }
    }

    void _updateRampingStreams (_State& _state, int32_t framesToRender) noexcept
    {
        bool rampComplete = {};
        int32_t readPos = {}, writePos = {};

        rampComplete = false;
        readPos = 0;
        writePos = 0;
        if (_state.m__sparseStreamStatus.m_activeRamps == 0) goto _exit;
        _loop: { rampComplete = _updateRampingStream (_state, _state.m__sparseStreamStatus.m_rampArray[readPos], framesToRender);
                 if (rampComplete) goto _rampComplete;
        }
        _rampActive: { _state.m__sparseStreamStatus.m_rampArray[writePos] = _state.m__sparseStreamStatus.m_rampArray[readPos];
                       readPos = readPos + 1;
                       writePos = writePos + 1;
                       if (readPos == _state.m__sparseStreamStatus.m_activeRamps) goto _loopExit;
                       goto _loop;
        }
        _rampComplete: { readPos = readPos + 1;
                         if (! (readPos == _state.m__sparseStreamStatus.m_activeRamps)) goto _loop;
        }
        _loopExit: { _state.m__sparseStreamStatus.m_activeRamps = writePos; }
        _exit: {}
    }

    Vector<double, 2> _readFromStream_struct__Stream_in_vec_2_f64_1024 (const _Stream_in_vec_2_f64_1024& stream, int32_t readPos) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = stream.m_buffer[readPos];
        return _2;
    }

    void _writeToStream_struct__Stream_out_vec_2_f64_1024 (_Stream_out_vec_2_f64_1024& stream, int32_t writePos, Vector<double, 2> value) noexcept
    {
        stream.m_buffer[writePos] = value;
    }

    //==============================================================================
    double soul__intrinsics___pow_specialised_2 (double a, double b) noexcept
    {
        return 0;
    }

    double soul__intrinsics___cos_specialised (double n) noexcept
    {
        return 0;
    }

    double soul__intrinsics___sin_specialised_2 (double n) noexcept
    {
        return 0;
    }

    double soul__intrinsics___tan_specialised (double n) noexcept
    {
        double _2 = {}, _3 = {};

        _2 = SOUL_INTRINSICS::sin (n);
        _3 = SOUL_INTRINSICS::cos (n);
        return _2 / _3;
    }

    double soul__intrinsics___max_specialised (double a, double b) noexcept
    {
        double _2 = {}, _3 = {}, _4 = {}, _T0 = {};

        if (! (a > b)) goto _ternary_false_0;
        _ternary_true_0: { _2 = a;
                           _T0 = _2;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _3 = b;
                            _T0 = _3;
        }
        _ternary_end_0: { _4 = _T0;
                          return _4;
        }
    }

    double soul__intrinsics___clamp_specialised (double n, double low, double high) noexcept
    {
        double _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _T1 = {}, _T0 = {};

        if (! (n < low)) goto _ternary_false_0;
        _ternary_true_0: { _2 = low;
                           _T0 = _2;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { if (! (n > high)) goto _ternary_false_1; }
        _ternary_true_1: { _3 = high;
                           _T1 = _3;
                           goto _ternary_end_1;
        }
        _ternary_false_1: { _4 = n;
                            _T1 = _4;
        }
        _ternary_end_1: { _5 = _T1;
                          _T0 = _5;
        }
        _ternary_end_0: { _6 = _T0;
                          return _6;
        }
    }

    float soul__intrinsics___floor_specialised (float n) noexcept
    {
        float r = {}, _2 = {};
        float _3 = {}, _4 = {}, _5 = {}, _T1 = {}, _T0 = {};

        r = static_cast<float> (static_cast<float> (static_cast<int64_t> (n)));
        if (! (r == static_cast<float> (n))) goto _ternary_false_0;
        _ternary_true_0: { _3 = n;
                           _T0 = _3;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { if (! (n >= 0)) goto _ternary_false_1; }
        _ternary_true_1: { _T1 = r;
        goto _ternary_end_1; }
        _ternary_false_1: { _2 = r - 1.0f;
                            _T1 = _2;
        }
        _ternary_end_1: { _4 = _T1;
                          _T0 = _4;
        }
        _ternary_end_0: { _5 = _T0;
                          return _5;
        }
    }

    Vector<double, 2> soul__intrinsics___sin_specialised_3 (Vector<double, 2> n) noexcept
    {
        return ZeroInitialiser();
    }

    Vector<double, 2> soul__intrinsics___sqrt_specialised_3 (Vector<double, 2> n) noexcept
    {
        return ZeroInitialiser();
    }

    Vector<double, 2> soul__intrinsics___tan_specialised_2 (Vector<double, 2> n) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = _vec_sin (n);
        _3 = _vec_cos (n);
        return _2 / _3;
    }

    double soul__intrinsics___abs_specialised (double n) noexcept
    {
        double _2 = {}, _3 = {}, _4 = {}, _T0 = {};

        if (! (n < 0)) goto _ternary_false_0;
        _ternary_true_0: { _2 = -n;
                           _T0 = _2;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _3 = n;
                            _T0 = _3;
        }
        _ternary_end_0: { _4 = _T0;
                          return _4;
        }
    }

    double soul__intrinsics___min_specialised (double a, double b) noexcept
    {
        double _2 = {}, _3 = {}, _4 = {}, _T0 = {};

        if (! (a < b)) goto _ternary_false_0;
        _ternary_true_0: { _2 = a;
                           _T0 = _2;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _3 = b;
                            _T0 = _3;
        }
        _ternary_end_0: { _4 = _T0;
                          return _4;
        }
    }

    Vector<double, 2> soul__intrinsics___cos_specialised_2 (Vector<double, 2> n) noexcept
    {
        return ZeroInitialiser();
    }

    //==============================================================================
    void soul___filters__dc_blocker__update (soul___filters__dc_blocker__Coeffs& c, double sampleRate, double freqHz) noexcept
    {
        double w = {};

        w = static_cast<double> ((3.141592653589793 * freqHz) / sampleRate);
        c.m_a0 = 1.0 / (1.0 + static_cast<double> (w));
        c.m_b1 = (1.0 - static_cast<double> (w)) * c.m_a0;
    }

    Vector<double, 2> soul___filters__dc_blocker__process (soul___filters__dc_blocker__State& s, Vector<double, 2> x, soul___filters__dc_blocker__Coeffs& c) noexcept
    {
        Vector<double, 2> y = {};

        y = static_cast<Vector<double, 2>> ((x - s.m_x[0]) + (Vector<double, 2> (c.m_a0) * s.m_y[0]));
        s.m_x[0] = x;
        s.m_y[0] = static_cast<Vector<double, 2>> (y);
        return static_cast<Vector<double, 2>> (Vector<double, 2> (c.m_b1) * y);
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO& _io)
    noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 1.0), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 1.0), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 1.0), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__tpt__svf__update (soul___filters__tpt__svf__Coeffs& c, double sampleRate, double freqHz, double quality) noexcept
    {
        double _2 = {}, _3 = {};
        double Q = {}, wd = {}, T = {}, wa = {}, g = {}, R = {};

        _2 = soul__intrinsics___max_specialised (quality, 0.001);
        Q = static_cast<double> (_2);
        wd = static_cast<double> (6.283185307179586 * freqHz);
        T = static_cast<double> (1.0 / sampleRate);
        _3 = SOUL_INTRINSICS::tan (static_cast<double> ((wd * T) / 2.0));
        wa = (2.0 / T) * static_cast<double> (_3);
        g = (wa * T) / 2.0;
        R = 1.0 / (2.0 * Q);
        c.m_a0 = static_cast<double> (1.0 / ((1.0 + ((2.0 * R) * g)) + (g * g)));
        c.m_a = static_cast<double> (g);
        c.m_p = static_cast<double> ((2.0 * R) + g);
    }

    FixedArray<Vector<double, 2>, 3> soul___filters__tpt__svf__process (soul___filters__tpt__svf__State& s, Vector<double, 2> x, soul___filters__tpt__svf__Coeffs& c) noexcept
    {
        Vector<double, 2> hpf = {}, bpf = {}, lpf = {};
        FixedArray<Vector<double, 2>, 3> _2 = {};

        hpf = static_cast<Vector<double, 2>> (Vector<double, 2> (c.m_a0) * ((x - (Vector<double, 2> (c.m_p) * s.m_z[0])) - s.m_z[1]));
        bpf = static_cast<Vector<double, 2>> (static_cast<Vector<double, 2>> ((Vector<double, 2> (c.m_a) * hpf) + static_cast<Vector<double, 2>> (s.m_z[0])));
        lpf = static_cast<Vector<double, 2>> (static_cast<Vector<double, 2>> ((Vector<double, 2> (c.m_a) * bpf) + static_cast<Vector<double, 2>> (s.m_z[1])));
        s.m_z[0] = static_cast<Vector<double, 2>> ((Vector<double, 2> (c.m_a) * hpf) + bpf);
        s.m_z[1] = static_cast<Vector<double, 2>> ((Vector<double, 2> (c.m_a) * bpf) + lpf);
        _2 = ZeroInitialiser();
        _2[0] = static_cast<Vector<double, 2>> (lpf);
        _2[1] = static_cast<Vector<double, 2>> (hpf);
        _2[2] = static_cast<Vector<double, 2>> (bpf);
        return _2;
    }

    //==============================================================================
    void soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___frequencyIn_f32 (soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State& _state,
     float v) noexcept
    {
        _state.m_frequency = v;
        _state.m_recalc = true;
    }

    void soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__update (soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State& _state, soul___filters__tpt__crossover__Coeffs&
    c, double sampleRate, double freqHz) noexcept
    {
        soul___filters__tpt__svf__update (c.m_svf1, sampleRate, freqHz, 0.7071070075035095);
        soul___filters__tpt__svf__update (c.m_svf2, sampleRate, freqHz, 0.7071070075035095);
    }

    FixedArray<Vector<double, 2>, 2> soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__process (soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State&
    _state, soul___filters__tpt__crossover__State& s, Vector<double, 2> x, soul___filters__tpt__crossover__Coeffs& c) noexcept
    {
        FixedArray<Vector<double, 2>, 3> _2 = {}, _3 = {};
        FixedArray<Vector<double, 2>, 3> svf1 = {}, svf2 = {};
        Vector<double, 2> lpf1 = {}, hpf1 = {}, bpf1 = {}, apf1 = {}, lpf2 = {};
        FixedArray<Vector<double, 2>, 2> _4 = {};

        _2 = soul___filters__tpt__svf__process (s.m_svf1, x, c.m_svf1);
        svf1 = static_cast<FixedArray<Vector<double, 2>, 3>> (_2);
        lpf1 = static_cast<Vector<double, 2>> (svf1[0]);
        hpf1 = static_cast<Vector<double, 2>> (svf1[1]);
        bpf1 = static_cast<Vector<double, 2>> (svf1[2]);
        apf1 = (lpf1 - static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.4142135623730952, 1.4142135623730952 } } * static_cast<Vector<double, 2>> (bpf1))) + hpf1;
        _3 = soul___filters__tpt__svf__process (s.m_svf2, static_cast<Vector<double, 2>> (lpf1), c.m_svf2);
        svf2 = static_cast<FixedArray<Vector<double, 2>, 3>> (_3);
        lpf2 = static_cast<Vector<double, 2>> (svf2[0]);
        _4 = ZeroInitialiser();
        _4[0] = static_cast<Vector<double, 2>> (lpf2);
        _4[1] = static_cast<Vector<double, 2>> (apf1 - lpf2);
        return _4;
    }

    void soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__run (soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State& _state, soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_lowOut = {}, out_value_highOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 2> _4 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_lowOut = ZeroInitialiser();
        out_value_highOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 1.0) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__update (_state, _state.m_c, (sampleRate * 1.0), static_cast<double> (clippedFrequency));
        }
        _ifnot_0: { _state.m_counter_1 = 256; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__process (_state, _state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_4);
                   out_value_lowOut = out_value_lowOut + y[0];
                   out_value_highOut = out_value_highOut + y[1];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowOut = out_value_lowOut;
                   _io.m__out_highOut = out_value_highOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___initialise (soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___State& _state)
    noexcept
    {
        _state.m_frequency = 1000.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    Vector<double, 2> VA__vCTF (Vector<double, 2> x, Vector<double, 2> threshold, Vector<double, 2> ratio0, Vector<double, 2> ratio1) noexcept
    {
        Vector<double, 2> divRatio0m1 = {}, divRatio1m1 = {}, thrlin = {}, yInternal = {}, y = {};
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        divRatio0m1 = (Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (ratio0)) - Vector<double, 2> { { 1.0, 1.0 } };
        divRatio1m1 = (Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (ratio1)) - Vector<double, 2> { { 1.0, 1.0 } };
        _2 = VA__vdBtoGain (threshold);
        thrlin = static_cast<Vector<double, 2>> (_2);
        _3 = VA___vpow_specialised_2 (x * static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } / thrlin), static_cast<Vector<double, 2>> (divRatio1m1));
        _4 = VA___vpow_specialised_2 (x * static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } / thrlin), static_cast<Vector<double, 2>> (divRatio0m1));
        _5 = VA__viflt (_3, _4, x, static_cast<Vector<double, 2>> (thrlin));
        yInternal = static_cast<Vector<double, 2>> (_5);
        _6 = VA__vmin (static_cast<Vector<double, 2>> (yInternal), Vector<double, 2> { { 1.9, 1.9 } });
        y = static_cast<Vector<double, 2>> (_6);
        _7 = VA__viflt (Vector<double, 2> { { 1.0, 1.0 } }, static_cast<Vector<double, 2>> (y), x, Vector<double, 2> { { 0.00001, 0.00001 } });
        return _7;
    }

    Vector<double, 2> VA__vStereoLink (Vector<double, 2> x, float percent) noexcept
    {
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> b = {};
        Vector<double, 2> x1 = {};

        _2 = VA__vMixToGains (percent * 0.5f);
        b = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
        x1 = ZeroInitialiser();
        x1[0] = x[1];
        x1[1] = x[0];
        return (b[0] * x) + (b[1] * static_cast<Vector<double, 2>> (x1));
    }

    Vector<double, 2> VA__vSigmoidC2 (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = _vec_sqrt ((x * x) + Vector<double, 2> { { 1.0, 1.0 } });
        return x / _2;
    }

    Vector<double, 2> VA__vOmegaToG_Onepole (Vector<double, 2> x, double fs) noexcept
    {
        Vector<double, 2> Tdiv2 = {}, gOnepole = {};
        Vector<double, 2> _2 = {};

        Tdiv2 = static_cast<Vector<double, 2>> (Vector<double, 2> (1.0 / (2.0 * fs)));
        _2 = _vec_tan (x * static_cast<Vector<double, 2>> (Tdiv2));
        gOnepole = static_cast<Vector<double, 2>> (_2);
        return static_cast<Vector<double, 2>> (gOnepole / static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } + static_cast<Vector<double, 2>> (gOnepole)));
    }

    Vector<double, 2> VA__vdBtoGain (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        Vector<double, 2> b = {};

        _2 = VA___vpow_specialised_2 (Vector<double, 2> { { 10.0, 10.0 } }, x * Vector<double, 2> { { 0.05, 0.05 } });
        b = static_cast<Vector<double, 2>> (_2);
        _3 = VA__vmax (Vector<double, 2> { { 0.00001, 0.00001 } }, static_cast<Vector<double, 2>> (b));
        return _3;
    }

    Vector<double, 2> VA__vSgn (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {};
        int32_t _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _T0 = {}, _T1 = {};

        _2 = ZeroInitialiser();
        if (! (x[0] > 0)) goto _ternary_false_0;
        _ternary_true_0: { _3 = 1;
                           _T0 = _3;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _4 = -1;
                            _T0 = _4;
        }
        _ternary_end_0: { _5 = _T0;
                          _2[0] = static_cast<double> (_5);
                          if (! (x[1] > 0)) goto _ternary_false_1;
        }
        _ternary_true_1: { _6 = 1;
                           _T1 = _6;
                           goto _ternary_end_1;
        }
        _ternary_false_1: { _7 = -1;
                            _T1 = _7;
        }
        _ternary_end_1: { _8 = _T1;
                          _2[1] = static_cast<double> (_8);
                          return _2;
        }
    }

    FixedArray<Vector<double, 2>, 2> VA__vMixToGains (float x) noexcept
    {
        Vector<double, 2> b1 = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        b1 = static_cast<Vector<double, 2>> (Vector<double, 2> (x) * Vector<double, 2> { { 0.01, 0.01 } });
        _2 = ZeroInitialiser();
        _2[0] = static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } - b1);
        _2[1] = static_cast<Vector<double, 2>> (b1);
        return _2;
    }

    Vector<double, 2> VA__vabs (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = soul__intrinsics___abs_specialised (x[0]);
        _2[0] = _3;
        _4 = soul__intrinsics___abs_specialised (x[1]);
        _2[1] = _4;
        return _2;
    }

    Vector<double, 2> VA__vmax (Vector<double, 2> x0, Vector<double, 2> x1) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = soul__intrinsics___max_specialised (x0[0], x1[0]);
        _2[0] = _3;
        _4 = soul__intrinsics___max_specialised (x0[1], x1[1]);
        _2[1] = _4;
        return _2;
    }

    Vector<double, 2> VA__vmin (Vector<double, 2> x0, Vector<double, 2> x1) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = soul__intrinsics___min_specialised (x0[0], x1[0]);
        _2[0] = _3;
        _4 = soul__intrinsics___min_specialised (x0[1], x1[1]);
        _2[1] = _4;
        return _2;
    }

    Vector<double, 2> VA__viflt (Vector<double, 2> trueStatement, Vector<double, 2> falseStatement, Vector<double, 2> a, Vector<double, 2> b) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _T0 = {}, _T1 = {};

        _2 = ZeroInitialiser();
        if (! (a[0] < b[0])) goto _ternary_false_0;
        _ternary_true_0: { _3 = trueStatement[0];
                           _T0 = _3;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _4 = falseStatement[0];
                            _T0 = _4;
        }
        _ternary_end_0: { _5 = _T0;
                          _2[0] = _5;
                          if (! (a[1] < b[1])) goto _ternary_false_1;
        }
        _ternary_true_1: { _6 = trueStatement[1];
                           _T1 = _6;
                           goto _ternary_end_1;
        }
        _ternary_false_1: { _7 = falseStatement[1];
                            _T1 = _7;
        }
        _ternary_end_1: { _8 = _T1;
                          _2[1] = _8;
                          return _2;
        }
    }

    Vector<double, 2> VA___vpow_specialised (Vector<double, 2> base, int32_t exponent) noexcept
    {
        Vector<double, 2> y = {};
        int32_t i = {}, _2 = {};

        y = base;
        i = 1;
        _loop_0: { if (! (i < exponent)) goto _break_0; }
        _body_0: { y = y * base;
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: { return y; }
    }

    Vector<double, 2> VA___vpow_specialised_2 (Vector<double, 2> base, Vector<double, 2> exponent) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = SOUL_INTRINSICS::pow (base[0], exponent[0]);
        _2[0] = _3;
        _4 = SOUL_INTRINSICS::pow (base[1], exponent[1]);
        _2[1] = _4;
        return _2;
    }

    //==============================================================================
    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___initialise (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state) noexcept
    {
        _state.m_mux4To1_0_state.m__arrayEntry = 0;
        _state.m_mux4To1_0_state.m__sessionID = _state.m__sessionID;
        _state.m_mux4To1_0_state.m__processorId = 1;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___initialise (_state.m_mux4To1_0_state);
        _state.m_mux4To1_1_state.m__arrayEntry = 0;
        _state.m_mux4To1_1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux4To1_1_state.m__processorId = 2;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___initialise (_state.m_mux4To1_1_state);
        _state.m_mux2To1_0_state.m__arrayEntry = 0;
        _state.m_mux2To1_0_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_0_state.m__processorId = 3;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___initialise (_state.m_mux2To1_0_state);
        _state.m_mux2To1_1_state.m__arrayEntry = 0;
        _state.m_mux2To1_1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_1_state.m__processorId = 4;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___initialise (_state.m_mux2To1_1_state);
        _state.m_dcBlockerIn_state.m__arrayEntry = 0;
        _state.m_dcBlockerIn_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerIn_state.m__processorId = 5;
        VA__DC_Blocker__Processor___initialise (_state.m_dcBlockerIn_state);
        _state.m_splitCenterSides_state.m__arrayEntry = 0;
        _state.m_splitCenterSides_state.m__sessionID = _state.m__sessionID;
        _state.m_splitCenterSides_state.m__processorId = 6;
        VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___initialise (_state.m_splitCenterSides_state);
        _state.m_pCrossover_state.m__arrayEntry = 0;
        _state.m_pCrossover_state.m__sessionID = _state.m__sessionID;
        _state.m_pCrossover_state.m__processorId = 7;
        soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___initialise (_state.m_pCrossover_state);
        _state.m_splitLoudSoft_state.m__arrayEntry = 0;
        _state.m_splitLoudSoft_state.m__sessionID = _state.m__sessionID;
        _state.m_splitLoudSoft_state.m__processorId = 8;
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___initialise (_state.m_splitLoudSoft_state);
        _state.m_splitAttackSustain_state.m__arrayEntry = 0;
        _state.m_splitAttackSustain_state.m__sessionID = _state.m__sessionID;
        _state.m_splitAttackSustain_state.m__processorId = 9;
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___initialise (_state.m_splitAttackSustain_state);
        _state.m_dcBlockerOut0_state.m__arrayEntry = 0;
        _state.m_dcBlockerOut0_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerOut0_state.m__processorId = 10;
        VA__DC_Blocker__Processor_2___initialise (_state.m_dcBlockerOut0_state);
        _state.m_dcBlockerOut1_state.m__arrayEntry = 0;
        _state.m_dcBlockerOut1_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerOut1_state.m__processorId = 11;
        VA__DC_Blocker__Processor_3___initialise (_state.m_dcBlockerOut1_state);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e__run (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__DC_Blocker__Processor___IO _3 = {};
        VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___IO _4 = {};
        soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___IO _5 = {};
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___IO _6 = {};
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___IO _7 = {};
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___IO _8 = {};
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___IO _9 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___IO _10 = {};
        VA__DC_Blocker__Processor_2___IO _11 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___IO _12 = {};
        VA__DC_Blocker__Processor_3___IO _13 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__DC_Blocker__Processor__run (_state.m_dcBlockerIn_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _3.m__out_out;
        VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides__run (_state.m_splitCenterSides_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _3.m__out_out;
        soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover__run (_state.m_pCrossover_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _3.m__out_out;
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain__run (_state.m_splitAttackSustain_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _3.m__out_out;
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft__run (_state.m_splitLoudSoft_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _4.m__out_centerOut;
        _8.m__in_in1 = _5.m__out_lowOut;
        _8.m__in_in2 = _6.m__out_attackOut;
        _8.m__in_in3 = _7.m__out_loudOut;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0__run (_state.m_mux4To1_0_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _4.m__out_sidesOut;
        _9.m__in_in1 = _5.m__out_highOut;
        _9.m__in_in2 = _6.m__out_sustainOut;
        _9.m__in_in3 = _7.m__out_softOut;
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1__run (_state.m_mux4To1_1_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _8.m__out_out;
        _10.m__in_in1 = _9.m__out_out;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0__run (_state.m_mux2To1_0_state, _10);
        _11 = ZeroInitialiser();
        _11.m__in_in = _10.m__out_out;
        VA__DC_Blocker__Processor_2__run (_state.m_dcBlockerOut0_state, _11);
        _io.m__out_out = _11.m__out_out;
        _12 = ZeroInitialiser();
        _12.m__in_in = _9.m__out_out;
        _12.m__in_in1 = _8.m__out_out;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1__run (_state.m_mux2To1_1_state, _12);
        _13 = ZeroInitialiser();
        _13.m__in_in = _12.m__out_out;
        VA__DC_Blocker__Processor_3__run (_state.m_dcBlockerOut1_state, _13);
        _io.m__out_out1 = _13.m__out_out;
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___modeIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___idxIn_f32 (_state.m_mux4To1_0_state, event);
        VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___idxIn_f32 (_state.m_mux4To1_1_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___flipIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___idxIn_f32 (_state.m_mux2To1_0_state, event);
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___idxIn_f32 (_state.m_mux2To1_1_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___frequencyIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        soul___filters__tpt__crossover__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_pCrossover___frequencyIn_f32 (_state.m_pCrossover_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___attackIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___attackIn_f32 (_state.m_splitAttackSustain_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___sustainIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___sustainIn_f32 (_state.m_splitAttackSustain_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___sensitivityIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___sensitivityIn_f32 (_state.m_splitAttackSustain_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___thresholdIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___thresholdIn_f32 (_state.m_splitLoudSoft_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___releaseIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___releaseIn_f32 (_state.m_splitLoudSoft_state, event);
    }

    void VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___stereoLinkLsIn_f32 (VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___stereoLinkIn_f32 (_state.m_splitLoudSoft_state, event);
    }

    //==============================================================================
    void VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___initialise (VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State& _state)
    noexcept
    {
        _state.m_sustainIsolator_state.m__arrayEntry = 0;
        _state.m_sustainIsolator_state.m__sessionID = _state.m__sessionID;
        _state.m_sustainIsolator_state.m__processorId = 12;
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___initialise (_state.m_sustainIsolator_state);
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 13;
    }

    void VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain__run (VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State& _state, VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___IO _3 = {};
        VA__Difference__Processor___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator__run (_state.m_sustainIsolator_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        _4.m__in_in1 = _3.m__out_out;
        VA__Difference__Processor__run (_state.m_difference_state, _4);
        _io.m__out_attackOut = _4.m__out_out;
        _io.m__out_sustainOut = _3.m__out_out;
    }

    void VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___attackIn_f32 (VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State& _state,
     float event) noexcept
    {
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___attackIn_f32 (_state.m_sustainIsolator_state, event);
    }

    void VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___sustainIn_f32 (VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State& _state,
     float event) noexcept
    {
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___sustainIn_f32 (_state.m_sustainIsolator_state, event);
    }

    void VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___sensitivityIn_f32 (VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain___State& _state,
     float event) noexcept
    {
        VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___sensitivityIn_f32 (_state.m_sustainIsolator_state, event);
    }

    //==============================================================================
    void VA__DC_Blocker__Processor___initialise (VA__DC_Blocker__Processor___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 14;
    }

    void VA__DC_Blocker__Processor__run (VA__DC_Blocker__Processor___State& _state, VA__DC_Blocker__Processor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__DC_Blocker__Processor_2___initialise (VA__DC_Blocker__Processor_2___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 15;
    }

    void VA__DC_Blocker__Processor_2__run (VA__DC_Blocker__Processor_2___State& _state, VA__DC_Blocker__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__DC_Blocker__Processor_3___initialise (VA__DC_Blocker__Processor_3___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 16;
    }

    void VA__DC_Blocker__Processor_3__run (VA__DC_Blocker__Processor_3___State& _state, VA__DC_Blocker__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___initialise (VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State& _state) noexcept
    {
        _state.m_expressorClassical_state.m__arrayEntry = 0;
        _state.m_expressorClassical_state.m__sessionID = _state.m__sessionID;
        _state.m_expressorClassical_state.m__processorId = 17;
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___initialise (_state.m_expressorClassical_state);
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 18;
    }

    void VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft__run (VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State& _state, VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___IO _3 = {};
        VA__Difference__Processor_2___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical__run (_state.m_expressorClassical_state, _3);
        _io.m__out_loudOut = _3.m__out_out;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        _4.m__in_in1 = _3.m__out_out;
        VA__Difference__Processor_2__run (_state.m_difference_state, _4);
        _io.m__out_softOut = _4.m__out_out;
    }

    void VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___thresholdIn_f32 (VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State& _state, float event) noexcept
    {
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___thresholdIn_f32 (_state.m_expressorClassical_state, event);
    }

    void VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___releaseIn_f32 (VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State& _state, float event) noexcept
    {
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___releaseIn_f32 (_state.m_expressorClassical_state, event);
    }

    void VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___stereoLinkIn_f32 (VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft___State& _state, float event) noexcept
    {
        VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___stereoLinkIn_f32 (_state.m_expressorClassical_state, event);
    }

    //==============================================================================
    void VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___initialise (VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 19;
        _state.m_absADAA_state.m__arrayEntry = 0;
        _state.m_absADAA_state.m__sessionID = _state.m__sessionID;
        _state.m_absADAA_state.m__processorId = 20;
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 21;
        VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_det_state.m__arrayEntry = 0;
        _state.m_det_state.m__sessionID = _state.m__sessionID;
        _state.m_det_state.m__processorId = 22;
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___initialise (_state.m_det_state);
        _state.m_smoothedVolume_state.m__arrayEntry = 0;
        _state.m_smoothedVolume_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedVolume_state.m__processorId = 23;
        VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___initialise (_state.m_smoothedVolume_state);
        _state.m_sigmoidC2_state.m__arrayEntry = 0;
        _state.m_sigmoidC2_state.m__sessionID = _state.m__sessionID;
        _state.m_sigmoidC2_state.m__processorId = 24;
    }

    void VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator__run (VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State&
    _state, VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__AbsADAA__Processor___IO _3 = {};
        VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___IO _4 = {};
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___IO _5 = {};
        VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___IO _6 = {};
        VA__SigmoidC2__Processor___IO _7 = {};
        VA__ApplyGain__Processor___IO _8 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__AbsADAA__Processor___run_oversampled (_state.m_absADAA_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _3.m__out_out;
        VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink__run (_state.m_stereoLink_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _4.m__out_out;
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det__run (_state.m_det_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume__run (_state.m_smoothedVolume_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_out;
        VA__SigmoidC2__Processor__run (_state.m_sigmoidC2_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_b = _7.m__out_out;
        _8.m__in_in = _2;
        VA__ApplyGain__Processor__run (_state.m_applyGain_state, _8);
        _io.m__out_out = _8.m__out_out;
    }

    void VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___sustainIn_f32 (VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State&
    _state, float event) noexcept
    {
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___release0In_f32 (_state.m_det_state, event);
    }

    void VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___attackIn_f32 (VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State&
    _state, float event) noexcept
    {
        VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___release1In_f32 (_state.m_det_state, event);
    }

    void VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___sensitivityIn_f32 (VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator___State&
    _state, float event) noexcept
    {
        VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___volumeIn_f32 (_state.m_smoothedVolume_state, event);

    }

    //==============================================================================
    void VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___initialise (VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 25;
        _state.m_absADAA_state.m__arrayEntry = 0;
        _state.m_absADAA_state.m__sessionID = _state.m__sessionID;
        _state.m_absADAA_state.m__processorId = 26;
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 27;
        VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_ballisticsFilter_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter_state.m__processorId = 28;
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___initialise (_state.m_ballisticsFilter_state);
        _state.m_ctf_state.m__arrayEntry = 0;
        _state.m_ctf_state.m__sessionID = _state.m__sessionID;
        _state.m_ctf_state.m__processorId = 29;
        VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___initialise (_state.m_ctf_state);
    }

    void VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical__run (VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State&
    _state, VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__AbsADAA__Processor_2___IO _3 = {};
        VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___IO _4 = {};
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___IO _5 = {};
        VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___IO _6 = {};
        VA__ApplyGain__Processor_2___IO _7 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__AbsADAA__Processor_2___run_oversampled (_state.m_absADAA_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _3.m__out_out;
        VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink__run (_state.m_stereoLink_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _4.m__out_out;
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter__run (_state.m_ballisticsFilter_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf__run (_state.m_ctf_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_b = _6.m__out_out;
        _7.m__in_in = _2;
        VA__ApplyGain__Processor_2__run (_state.m_applyGain_state, _7);
        _io.m__out_out = _7.m__out_out;
    }

    void VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___stereoLinkIn_f32 (VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State&
    _state, float event) noexcept
    {
        VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___stereoLinkIn_f32 (_state.m_stereoLink_state, event);
    }

    void VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___releaseIn_f32 (VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___releaseIn_f32 (_state.m_ballisticsFilter_state,
        event);
    }

    void VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___thresholdIn_f32 (VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical___State&
    _state, float event) noexcept
    {
        VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___thresholdIn_f32 (_state.m_ctf_state, event);
    }

    //==============================================================================
    void VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___initialise (VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State&
    _state) noexcept
    {
        _state.m_ballisticsFilter0_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter0_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter0_state.m__processorId = 30;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___initialise
        (_state.m_ballisticsFilter0_state);
        _state.m_ballisticsFilter1_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter1_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter1_state.m__processorId = 31;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___initialise
        (_state.m_ballisticsFilter1_state);
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 32;
    }

    void VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det__run (VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State&
    _state, VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___IO _3 =
        {};
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___IO _4 =
        {};
        VA__Difference__Processor_3___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0__run (_state.m_ballisticsFilter0_state,
         _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1__run (_state.m_ballisticsFilter1_state,
         _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _3.m__out_out;
        _5.m__in_in1 = _4.m__out_out;
        VA__Difference__Processor_3__run (_state.m_difference_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___release0In_f32 (VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___releaseIn_f32
        (_state.m_ballisticsFilter0_state, event);
    }

    void VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___release1In_f32 (VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___releaseIn_f32
        (_state.m_ballisticsFilter1_state, event);
    }

    //==============================================================================
    void VA__BallisticsFilter__Internal__update (VA__BallisticsFilter__Internal__Coeffs& c, float attack, float release) noexcept
    {
        c.m_OmegaA = Vector<double, 2> (1000.0f / attack);
        c.m_OmegaR = Vector<double, 2> (1000.0f / release);
    }

    Vector<double, 2> VA__BallisticsFilter__Internal__process (Vector<double, 2> x, Vector<double, 2> y, const VA__BallisticsFilter__Internal__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__viflt (c.m_OmegaR, c.m_OmegaA, x, y);
        return _2;
    }

    //==============================================================================
    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___releaseIn_f32
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State&
    _state, float v) noexcept
    {
        _state.m_release = v;
        _state.m_recalc = true;
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal__run
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State&
    _state, VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_Omega = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_Omega = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__BallisticsFilter__Internal__update (_state.m_c, _state.m_attack, _state.m_release);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_x;
                   _3 = _io.m__in_y;
                   _4 = VA__BallisticsFilter__Internal__process (_2, _3, _state.m_c);
                   out_value_Omega = out_value_Omega + _4;
                   _state.m__resumePoint = 1;
                   _io.m__out_Omega = out_value_Omega;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___initialise
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___State&
    _state) noexcept
    {
        _state.m_attack = 4.0f;
        _state.m_release = 30.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___releaseIn_f32
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State&
    _state, float v) noexcept
    {
        _state.m_release = v;
        _state.m_recalc = true;
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal__run
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State&
    _state, VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_Omega = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_Omega = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__BallisticsFilter__Internal__update (_state.m_c, _state.m_attack, _state.m_release);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_x;
                   _3 = _io.m__in_y;
                   _4 = VA__BallisticsFilter__Internal__process (_2, _3, _state.m_c);
                   out_value_Omega = out_value_Omega + _4;
                   _state.m__resumePoint = 1;
                   _io.m__out_Omega = out_value_Omega;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___initialise
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___State&
    _state) noexcept
    {
        _state.m_attack = 4.0f;
        _state.m_release = 30.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___releaseIn_f32
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State&
    _state, float v) noexcept
    {
        _state.m_release = v;
        _state.m_recalc = true;
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal__run
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State&
    _state, VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_Omega = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_Omega = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__BallisticsFilter__Internal__update (_state.m_c, _state.m_attack, _state.m_release);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_x;
                   _3 = _io.m__in_y;
                   _4 = VA__BallisticsFilter__Internal__process (_2, _3, _state.m_c);
                   out_value_Omega = out_value_Omega + _4;
                   _state.m__resumePoint = 1;
                   _io.m__out_Omega = out_value_Omega;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___initialise
    (VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___State&
    _state) noexcept
    {
        _state.m_attack = 4.0f;
        _state.m_release = 4.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___initialise (VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State&
    _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 33;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___initialise
        (_state.m_internal_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 34;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter__run (VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        int32_t _4 = {}, _5 = {};
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___IO
        _6 = {};
        VA__OnepoleC__Processor___IO _7 = {};

        _2 = _io.m__in_in;
        _4 = _state.m__delayState_1.m_index;
        _3 = _state.m__delayState_1.m_buffer[_4];
        _6 = ZeroInitialiser();
        _6.m__in_x = _2;
        _6.m__in_y = _3;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal__run
        (_state.m_internal_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_Omega = _6.m__out_Omega;
        VA__OnepoleC__Processor__run (_state.m_onepoleC_state, _7);
        _io.m__out_out = _7.m__out_lowpassOut;
        _5 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_5] = _7.m__out_lowpassOut;
        _state.m__delayState_1.m_index = (_5 + 1) & 0;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___releaseIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ballisticsFilter_internal___releaseIn_f32
        (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___initialise
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State&
    _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 35;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___initialise
        (_state.m_internal_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 36;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0__run
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        int32_t _4 = {}, _5 = {};
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___IO
        _6 = {};
        VA__OnepoleC__Processor_2___IO _7 = {};

        _2 = _io.m__in_in;
        _4 = _state.m__delayState_1.m_index;
        _3 = _state.m__delayState_1.m_buffer[_4];
        _6 = ZeroInitialiser();
        _6.m__in_x = _2;
        _6.m__in_y = _3;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal__run
        (_state.m_internal_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_Omega = _6.m__out_Omega;
        VA__OnepoleC__Processor_2__run (_state.m_onepoleC_state, _7);
        _io.m__out_out = _7.m__out_lowpassOut;
        _5 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_5] = _7.m__out_lowpassOut;
        _state.m__delayState_1.m_index = (_5 + 1) & 0;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___releaseIn_f32
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter0_internal___releaseIn_f32
        (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___initialise
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State&
    _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 37;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___initialise
        (_state.m_internal_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 38;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1__run
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        int32_t _4 = {}, _5 = {};
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___IO
        _6 = {};
        VA__OnepoleC__Processor_3___IO _7 = {};

        _2 = _io.m__in_in;
        _4 = _state.m__delayState_1.m_index;
        _3 = _state.m__delayState_1.m_buffer[_4];
        _6 = ZeroInitialiser();
        _6.m__in_x = _2;
        _6.m__in_y = _3;
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal__run
        (_state.m_internal_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_Omega = _6.m__out_Omega;
        VA__OnepoleC__Processor_3__run (_state.m_onepoleC_state, _7);
        _io.m__out_out = _7.m__out_lowpassOut;
        _5 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_5] = _7.m__out_lowpassOut;
        _state.m__delayState_1.m_index = (_5 + 1) & 0;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___releaseIn_f32
    (VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Internal__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__DET__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_det_ballisticsFilter1_internal___releaseIn_f32
        (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__OnepoleC__updatePerSample (VA__OnepoleC__Coeffs& c, Vector<double, 2> Omega, double fs) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vOmegaToG_Onepole (Omega, fs);
        c.m_G = _2;
    }

    FixedArray<Vector<double, 2>, 2> VA__OnepoleC__process (VA__OnepoleC__State& s, Vector<double, 2> x, const VA__OnepoleC__Coeffs& c) noexcept
    {
        Vector<double, 2> v = {}, lpf = {}, hpf = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        v = static_cast<Vector<double, 2>> ((x - s.m_s) * c.m_G);
        lpf = v + static_cast<Vector<double, 2>> (s.m_s);
        hpf = static_cast<Vector<double, 2>> (x - static_cast<Vector<double, 2>> (lpf));
        s.m_s = static_cast<Vector<double, 2>> (v + lpf);
        _2 = ZeroInitialiser();
        _2[0] = static_cast<Vector<double, 2>> (lpf);
        _2[1] = static_cast<Vector<double, 2>> (hpf);
        return _2;
    }

    //==============================================================================
    void VA__OnepoleC__Processor__run (VA__OnepoleC__Processor___State& _state, VA__OnepoleC__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _4 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 1.0));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
        }
    }

    //==============================================================================
    void VA__OnepoleC__Processor_2__run (VA__OnepoleC__Processor_2___State& _state, VA__OnepoleC__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _4 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 1.0));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
        }
    }

    //==============================================================================
    void VA__OnepoleC__Processor_3__run (VA__OnepoleC__Processor_3___State& _state, VA__OnepoleC__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _4 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 1.0));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
        }
    }

    //==============================================================================
    void VA__CTF__Internal__updatePerSample (VA__CTF__Internal__Coeffs& c, Vector<double, 2> threshold, Vector<double, 2> ratio0, Vector<double, 2> ratio1) noexcept
    {
        c.m_threshold = threshold;
        c.m_ratio0 = ratio0;
        c.m_ratio1 = ratio1;
    }

    Vector<double, 2> VA__CTF__Internal__process (Vector<double, 2> x, const VA__CTF__Internal__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vCTF (x, c.m_threshold, c.m_ratio0, c.m_ratio1);
        return _2;
    }

    //==============================================================================
    void VA__CTF__Internal__Processor__run (VA__CTF__Internal__Processor___State& _state, VA__CTF__Internal__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_thresholdIn;
                   _3 = _io.m__in_ratio0In;
                   _4 = _io.m__in_ratio1In;
                   VA__CTF__Internal__updatePerSample (_state.m_c, _2, _3, _4);
                   _5 = _io.m__in_in;
                   _6 = VA__CTF__Internal__process (_5, _state.m_c);
                   out_value_out = out_value_out + _6;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___initialise (VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 39;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___initialise
        (_state.m_smoothedParameter0_state);
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 40;
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 41;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___initialise
        (_state.m_smoothedParameter1_state);
        _state.m_smoothedParameter2_state.m__arrayEntry = 0;
        _state.m_smoothedParameter2_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter2_state.m__processorId = 42;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___initialise
        (_state.m_smoothedParameter2_state);
    }

    void VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf__run (VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State&
    _state, VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___IO _3 = {};

        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___IO _4 = {};

        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___IO _5 = {};

        VA__CTF__Internal__Processor___IO _6 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0__run (_state.m_smoothedParameter0_state,
         _3);
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1__run (_state.m_smoothedParameter1_state,
         _4);
        _5 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2__run (_state.m_smoothedParameter2_state,
         _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _2;
        _6.m__in_thresholdIn = _3.m__out_out;
        _6.m__in_ratio0In = _4.m__out_out;
        _6.m__in_ratio1In = _5.m__out_out;
        VA__CTF__Internal__Processor__run (_state.m_internal_state, _6);
        _io.m__out_out = _6.m__out_out;
    }

    void VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___thresholdIn_f32 (VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state,
         event);
    }

    //==============================================================================
    void VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___initialise (VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___State& _state) noexcept
    {
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 43;
        VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 44;
    }

    void VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides__run (VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___State& _state, VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___IO _3 = {};
        VA__Difference__Processor_4___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink__run (_state.m_stereoLink_state, _3);
        _io.m__out_centerOut = _3.m__out_out;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        _4.m__in_in1 = _3.m__out_out;
        VA__Difference__Processor_4__run (_state.m_difference_state, _4);
        _io.m__out_sidesOut = _4.m__out_out;
    }

    //==============================================================================
    void VA__StereoLink__update (VA__StereoLink__Coeffs& c, float stereoLink) noexcept
    {
        c.m_stereoLink = stereoLink;
    }

    Vector<double, 2> VA__StereoLink__process (Vector<double, 2> x, const VA__StereoLink__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vStereoLink (x, c.m_stereoLink);
        return _2;
    }

    //==============================================================================
    void VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink__run (VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__StereoLink__update (_state.m_c, _state.m_stereoLink);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = VA__StereoLink__process (_2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___stereoLinkIn_f32 (VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State&
    _state, float v) noexcept
    {
        _state.m_stereoLink = v;
        _state.m_recalc = true;
    }

    void VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink__run (VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__StereoLink__update (_state.m_c, _state.m_stereoLink);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = VA__StereoLink__process (_2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink__run (VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__StereoLink__update (_state.m_c, _state.m_stereoLink);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = VA__StereoLink__process (_2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__SplitCenterSides__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitCenterSides_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 100.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__SigmoidC2__Processor__run (VA__SigmoidC2__Processor___State& _state, VA__SigmoidC2__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = VA__vSigmoidC2 (_2);
        out_value_out = out_value_out + _3;
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    Vector<double, 2> VA__AbsADAA__f (Vector<double, 2> x, const VA__AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vabs (x);
        return _2;
    }

    Vector<double, 2> VA__AbsADAA__F1 (Vector<double, 2> x, const VA__AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 2);
        return (_2 * Vector<double, 2> { { 0.5, 0.5 } }) * _3;
    }

    Vector<double, 2> VA__AbsADAA__F2 (Vector<double, 2> x, const VA__AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 3);
        return (_2 * Vector<double, 2> { { 0.16666666666666667, 0.16666666666666667 } }) * _3;
    }

    Vector<double, 2> VA__AbsADAA__processADAA2 (VA__AbsADAA__State& s, Vector<double, 2> x, const VA__AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> x_0mx_1 = {}, F2_0 = {}, F1_0 = {}, x_0mx_2 = {}, xBar = {}, delta = {}, f_0 = {};
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _9 = {}, _10 = {}, _11 = {}, _12 = {};

        x_0mx_1 = static_cast<Vector<double, 2>> (x - s.m_x_1);
        _2 = VA__AbsADAA__F2 (x, c);
        F2_0 = static_cast<Vector<double, 2>> (_2);
        _3 = VA__AbsADAA__F1 (static_cast<Vector<double, 2>> (Vector<double, 2> { { 0.5, 0.5 } } * static_cast<Vector<double, 2>> (x + s.m_x_1)), c);
        _4 = VA__vabs (static_cast<Vector<double, 2>> (x_0mx_1));
        _5 = VA__viflt (_3, static_cast<Vector<double, 2>> ((F2_0 - static_cast<Vector<double, 2>> (s.m_F2_1)) / x_0mx_1), _4, Vector<double, 2> { { 1e-7, 1e-7 } });
        F1_0 = static_cast<Vector<double, 2>> (_5);
        x_0mx_2 = static_cast<Vector<double, 2>> (x - s.m_x_2);
        xBar = Vector<double, 2> { { 0.5, 0.5 } } * static_cast<Vector<double, 2>> (x + s.m_x_2);
        delta = xBar - static_cast<Vector<double, 2>> (s.m_x_1);
        _6 = VA__AbsADAA__f (static_cast<Vector<double, 2>> (Vector<double, 2> { { 0.5, 0.5 } } * (xBar + static_cast<Vector<double, 2>> (s.m_x_1))), c);
        _7 = VA__AbsADAA__F1 (static_cast<Vector<double, 2>> (xBar), c);
        _8 = VA__AbsADAA__F2 (static_cast<Vector<double, 2>> (xBar), c);
        _9 = VA__vabs (static_cast<Vector<double, 2>> (delta));
        _10 = VA__viflt (_6, static_cast<Vector<double, 2>> ((Vector<double, 2> { { 2.0, 2.0 } } / delta) * static_cast<Vector<double, 2>> (_7 + ((s.m_F2_1 - _8) / static_cast<Vector<double, 2>> (delta)))), _9, Vector<double, 2> { { 1e-7, 1e-7 } });
        _11 = VA__vabs (static_cast<Vector<double, 2>> (x_0mx_2));
        _12 = VA__viflt (_10, static_cast<Vector<double, 2>> ((Vector<double, 2> { { 2.0, 2.0 } } / x_0mx_2) * (F1_0 - static_cast<Vector<double, 2>> (s.m_F1_1))), _11, Vector<double, 2> { { 1e-7, 1e-7 } });
        f_0 = static_cast<Vector<double, 2>> (_12);
        s.m_x_2 = s.m_x_1;
        s.m_x_1 = x;
        s.m_F2_1 = static_cast<Vector<double, 2>> (F2_0);
        s.m_F1_1 = static_cast<Vector<double, 2>> (F1_0);
        return static_cast<Vector<double, 2>> (f_0);
    }

    Vector<double, 2> VA__AbsADAA__process (VA__AbsADAA__State& s, Vector<double, 2> x, const VA__AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__AbsADAA__processADAA2 (s, x, c);
        return _2;
    }

    //==============================================================================
    void VA__AbsADAA__Processor__run (VA__AbsADAA__Processor___State& _state, VA__AbsADAA__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = VA__AbsADAA__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    void VA__AbsADAA__Processor___run_oversampled (VA__AbsADAA__Processor___State& _state, VA__AbsADAA__Processor___IO& _io) noexcept
    {
        VA__AbsADAA__Processor___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor__run (_state, _io);
        VA__AbsADAA__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__AbsADAA__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor__run (_state, _io);
        VA__AbsADAA__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__AbsADAA__Processor___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA__AbsADAA__Processor___upsamplerWrite (VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _2 = src.m_filterA[0].m_in + ((input - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _3 = src.m_filterA[0].m_out[0] + ((_2 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _4 = src.m_filterA[0].m_out[1] + ((_3 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = input;
        src.m_filterA[0].m_out[0] = _2;
        src.m_filterA[0].m_out[1] = _3;
        src.m_filterA[0].m_out[2] = _4;
        src.m_buffer[0] = _4;
        _5 = src.m_filterB[0].m_in + ((input - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _6 = src.m_filterB[0].m_out[0] + ((_5 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _7 = src.m_filterB[0].m_out[1] + ((_6 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = input;
        src.m_filterB[0].m_out[0] = _5;
        src.m_filterB[0].m_out[1] = _6;
        src.m_filterB[0].m_out[2] = _7;
        src.m_buffer[1] = _7;
        src.m_bufferPos = 0;
    }

    void VA__AbsADAA__Processor___upsamplerRead (VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__AbsADAA__Processor___downsamplerWrite (VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__AbsADAA__Processor___downsamplerRead (VA__AbsADAA__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _2 = src.m_filterA[0].m_in + ((src.m_buffer[1] - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _3 = src.m_filterA[0].m_out[0] + ((_2 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _4 = src.m_filterA[0].m_out[1] + ((_3 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = src.m_buffer[1];
        src.m_filterA[0].m_out[0] = _2;
        src.m_filterA[0].m_out[1] = _3;
        src.m_filterA[0].m_out[2] = _4;
        _5 = src.m_filterB[0].m_in + ((src.m_buffer[0] - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _6 = src.m_filterB[0].m_out[0] + ((_5 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _7 = src.m_filterB[0].m_out[1] + ((_6 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = src.m_buffer[0];
        src.m_filterB[0].m_out[0] = _5;
        src.m_filterB[0].m_out[1] = _6;
        src.m_filterB[0].m_out[2] = _7;
        output = (_4 + _7) * Vector<double, 2> { { 0.5, 0.5 } };
        src.m_bufferPos = 0;
    }

    //==============================================================================
    void VA__AbsADAA__Processor_2__run (VA__AbsADAA__Processor_2___State& _state, VA__AbsADAA__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = VA__AbsADAA__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    void VA__AbsADAA__Processor_2___run_oversampled (VA__AbsADAA__Processor_2___State& _state, VA__AbsADAA__Processor_2___IO& _io) noexcept
    {
        VA__AbsADAA__Processor_2___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor_2__run (_state, _io);
        VA__AbsADAA__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__AbsADAA__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__AbsADAA__Processor_2__run (_state, _io);
        VA__AbsADAA__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__AbsADAA__Processor_2___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA__AbsADAA__Processor_2___upsamplerWrite (VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _2 = src.m_filterA[0].m_in + ((input - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _3 = src.m_filterA[0].m_out[0] + ((_2 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _4 = src.m_filterA[0].m_out[1] + ((_3 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = input;
        src.m_filterA[0].m_out[0] = _2;
        src.m_filterA[0].m_out[1] = _3;
        src.m_filterA[0].m_out[2] = _4;
        src.m_buffer[0] = _4;
        _5 = src.m_filterB[0].m_in + ((input - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _6 = src.m_filterB[0].m_out[0] + ((_5 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _7 = src.m_filterB[0].m_out[1] + ((_6 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = input;
        src.m_filterB[0].m_out[0] = _5;
        src.m_filterB[0].m_out[1] = _6;
        src.m_filterB[0].m_out[2] = _7;
        src.m_buffer[1] = _7;
        src.m_bufferPos = 0;
    }

    void VA__AbsADAA__Processor_2___upsamplerRead (VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__AbsADAA__Processor_2___downsamplerWrite (VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__AbsADAA__Processor_2___downsamplerRead (VA__AbsADAA__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _2 = src.m_filterA[0].m_in + ((src.m_buffer[1] - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _3 = src.m_filterA[0].m_out[0] + ((_2 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _4 = src.m_filterA[0].m_out[1] + ((_3 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = src.m_buffer[1];
        src.m_filterA[0].m_out[0] = _2;
        src.m_filterA[0].m_out[1] = _3;
        src.m_filterA[0].m_out[2] = _4;
        _5 = src.m_filterB[0].m_in + ((src.m_buffer[0] - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _6 = src.m_filterB[0].m_out[0] + ((_5 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _7 = src.m_filterB[0].m_out[1] + ((_6 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = src.m_buffer[0];
        src.m_filterB[0].m_out[0] = _5;
        src.m_filterB[0].m_out[1] = _6;
        src.m_filterB[0].m_out[2] = _7;
        output = (_4 + _7) * Vector<double, 2> { { 0.5, 0.5 } };
        src.m_bufferPos = 0;
    }

    //==============================================================================
    void VA__ApplyGain__Processor__run (VA__ApplyGain__Processor___State& _state, VA__ApplyGain__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_b;
        _3 = _io.m__in_in;
        out_value_out = out_value_out + (_2 * _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__ApplyGain__Processor_2__run (VA__ApplyGain__Processor_2___State& _state, VA__ApplyGain__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_b;
        _3 = _io.m__in_in;
        out_value_out = out_value_out + (_2 * _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__ApplyGain__Processor_3__run (VA__ApplyGain__Processor_3___State& _state, VA__ApplyGain__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_b;
        _3 = _io.m__in_in;
        out_value_out = out_value_out + (_2 * _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Mux4To1__update (VA__Mux4To1__Coeffs& c, float idx) noexcept
    {
        float _2 = {};

        _2 = soul__intrinsics___floor_specialised (idx);
        c.m_idx = static_cast<int32_t> (_2);
    }

    Vector<double, 2> VA__Mux4To1__process (FixedArray<Vector<double, 2>, 4> x, const VA__Mux4To1__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (c.m_idx), 4) & 3];
    }

    //==============================================================================
    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___idxIn_f32 (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0__run (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State& _state, VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 4> _7 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Mux4To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _7 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _7[0] = _2;
                   _3 = _io.m__in_in1;
                   _7[1] = _3;
                   _4 = _io.m__in_in2;
                   _7[2] = _4;
                   _5 = _io.m__in_in3;
                   _7[3] = _5;
                   _6 = VA__Mux4To1__process (_7, _state.m_c);
                   out_value_out = out_value_out + _6;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___initialise (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_0___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___idxIn_f32 (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1__run (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State& _state, VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 4> _7 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Mux4To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _7 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _7[0] = _2;
                   _3 = _io.m__in_in1;
                   _7[1] = _3;
                   _4 = _io.m__in_in2;
                   _7[2] = _4;
                   _5 = _io.m__in_in3;
                   _7[3] = _5;
                   _6 = VA__Mux4To1__process (_7, _state.m_c);
                   out_value_out = out_value_out + _6;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___initialise (VA__Mux4To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux4To1_1___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux2To1__update (VA__Mux2To1__Coeffs& c, float idx) noexcept
    {
        float _2 = {};

        _2 = soul__intrinsics___floor_specialised (idx);
        c.m_idx = static_cast<int32_t> (_2);
    }

    Vector<double, 2> VA__Mux2To1__process (FixedArray<Vector<double, 2>, 2> x, const VA__Mux2To1__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (c.m_idx), 2) & 1];
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State& _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Mux2To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _5 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _5[0] = _2;
                   _3 = _io.m__in_in1;
                   _5[1] = _3;
                   _4 = VA__Mux2To1__process (_5, _state.m_c);
                   out_value_out = out_value_out + _4;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_0___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State& _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Mux2To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _5 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _5[0] = _2;
                   _3 = _io.m__in_in1;
                   _5[1] = _3;
                   _4 = VA__Mux2To1__process (_5, _state.m_c);
                   out_value_out = out_value_out + _4;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_mux2To1_1___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Difference__Processor__run (VA__Difference__Processor___State& _state, VA__Difference__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 - _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Difference__Processor_2__run (VA__Difference__Processor_2___State& _state, VA__Difference__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 - _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Difference__Processor_3__run (VA__Difference__Processor_3___State& _state, VA__Difference__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 - _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Difference__Processor_4__run (VA__Difference__Processor_4___State& _state, VA__Difference__Processor_4___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 - _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___initialise (VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 45;
        _state.m_smoothedGain_state.m__arrayEntry = 0;
        _state.m_smoothedGain_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGain_state.m__processorId = 46;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___initialise
        (_state.m_smoothedGain_state);
    }

    void VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume__run (VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State&
    _state, VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___IO
        _3 = {};
        VA__ApplyGain__Processor_3___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain__run
        (_state.m_smoothedGain_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor_3__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___volumeIn_f32 (VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___in_f32
        (_state.m_smoothedGain_state, event);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___in_f32
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State& _state,
     float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0__init
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State& _state)
    noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { -30.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 1> _2 = {};
        FixedArray<Vector<double, 2>, 1> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 1.0) / 5000.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 1.0) * 1.0);
                    VA__SmoothedParameter___M__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M__process (_state.m_s, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 1>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___initialise
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0___State& _state)
    noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { -30.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter0__init (_state);

    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1__init
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State& _state)
    noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 1.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 1> _2 = {};
        FixedArray<Vector<double, 2>, 1> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 1.0) / 2000.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 1.0) * 1.0);
                    VA__SmoothedParameter___M_2__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_2__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_2__process (_state.m_s, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 1>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___initialise
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1___State& _state)
    noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter1__init (_state);

    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2__init
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State& _state)
    noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 0.25f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2__run (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 1> _2 = {};
        FixedArray<Vector<double, 2>, 1> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 1.0) / 2000.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 1.0) * 1.0);
                    VA__SmoothedParameter___M_2__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_2__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_2__process (_state.m_s, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 1>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___initialise
    (VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2___State& _state)
    noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 0.25f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF__Processor___for__root__VA__ExpressorClassical__Processor___for__root__VA__SplitLoudSoft__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitLoudSoft_expressorClassical_ctf_smoothedParameter2__init (_state);

    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___in_f32
    (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain__init
    (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 36.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain__run
    (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 1> _2 = {};
        FixedArray<Vector<double, 2>, 1> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 1.0) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 1.0) * 1.0);
                    VA__SmoothedParameter___M_3__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_3__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_3__process (_state.m_s, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 1>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___initialise
    (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 36.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__SustainIsolator__Processor___for__root__VA__SplitAttackSustain__Processor___for__root__VA__HighLevel__TheSplit__Processor___for__root__main__Processor_e_splitAttackSustain_sustainIsolator_smoothedVolume_smoothedGain__init
        (_state);
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};

        y = ZeroInitialiser();
        y[0] = Vector<double, 2> (VA__SmoothedParameter___M___get_dyn_array_element_slice_f32 (parameter, 0));
        return y;
    }

    void VA__SmoothedParameter___M__update (VA__SmoothedParameter___M__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        int32_t i = {}, _5 = {};

        _2 = VA__SmoothedParameter___M__decodeParameter (parameter, fs);
        c.m_target = _2;
        _3 = VA__vabs (c.m_target[0] - s.m_current[0]);
        _4 = VA__vmax (Vector<double, 2> { { 1.0, 1.0 } }, _3 * divMaxDelta);
        s.m_remainingRampSamples = static_cast<int32_t> (_4[0]);
        i = 0;
        _loop_0: { if (! (i < 1)) goto _break_0; }
        _body_0: { c.m_increment[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = (c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] - s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0]) / Vector<double, 2> (s.m_remainingRampSamples);
                   _5 = i;
                   i = _5 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter___M__updateUnsmoothed (VA__SmoothedParameter___M__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};

        _2 = VA__SmoothedParameter___M__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M__process (VA__SmoothedParameter___M__State& s, const VA__SmoothedParameter___M__Coeffs& c) noexcept
    {
        int32_t _2 = {}, _3 = {}, i = {}, _4 = {}, i_2 = {}, _5 = {};

        if (! (s.m_remainingRampSamples != 0)) goto _ifnot_0;
        _if_0: { _2 = s.m_remainingRampSamples;
                 _3 = _2 - 1;
                 s.m_remainingRampSamples = _3;
                 if (! (_3 == 0)) goto _ifnot_1;
        }
        _if_1: { i = 0; }
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _ifnot_0; }
        _body_0: { s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _4 = i;
                   i = _4 + 1;
                   goto _loop_0;
        }
        _ifnot_1: { i_2 = 0; }
        _loop_1: { if (! (static_cast<int64_t> (i_2) < 1L)) goto _ifnot_0; }
        _body_1: { s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] = s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] + c.m_increment[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0];
                   _5 = i_2;
                   i_2 = _5 + 1;
                   goto _loop_1;
        }
        _ifnot_0: { return s.m_current; }
    }

    float VA__SmoothedParameter___M___get_dyn_array_element_slice_f32 (DynamicArray<float> array, int32_t index) noexcept
    {
        if (! (array.numElements == 0)) goto _notEmpty;
        _empty: { return 0; }
        _notEmpty: { return array[_internal___wrapInt32 (index, array.numElements)]; }
    }

    int32_t VA__SmoothedParameter___M___get_array_size_slice_f32 (DynamicArray<float> array) noexcept;

    //==============================================================================
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_2__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};

        y = ZeroInitialiser();
        y[0] = Vector<double, 2> (VA__SmoothedParameter___M_2___get_dyn_array_element_slice_f32 (parameter, 0));
        return y;
    }

    void VA__SmoothedParameter___M_2__update (VA__SmoothedParameter___M_2__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_2__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        int32_t i = {}, _5 = {};

        _2 = VA__SmoothedParameter___M_2__decodeParameter (parameter, fs);
        c.m_target = _2;
        _3 = VA__vabs (c.m_target[0] - s.m_current[0]);
        _4 = VA__vmax (Vector<double, 2> { { 1.0, 1.0 } }, _3 * divMaxDelta);
        s.m_remainingRampSamples = static_cast<int32_t> (_4[0]);
        i = 0;
        _loop_0: { if (! (i < 1)) goto _break_0; }
        _body_0: { c.m_increment[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = (c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] - s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0]) / Vector<double, 2> (s.m_remainingRampSamples);
                   _5 = i;
                   i = _5 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter___M_2__updateUnsmoothed (VA__SmoothedParameter___M_2__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_2__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};

        _2 = VA__SmoothedParameter___M_2__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_2__process (VA__SmoothedParameter___M_2__State& s, const VA__SmoothedParameter___M_2__Coeffs& c) noexcept
    {
        int32_t _2 = {}, _3 = {}, i = {}, _4 = {}, i_2 = {}, _5 = {};

        if (! (s.m_remainingRampSamples != 0)) goto _ifnot_0;
        _if_0: { _2 = s.m_remainingRampSamples;
                 _3 = _2 - 1;
                 s.m_remainingRampSamples = _3;
                 if (! (_3 == 0)) goto _ifnot_1;
        }
        _if_1: { i = 0; }
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _ifnot_0; }
        _body_0: { s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _4 = i;
                   i = _4 + 1;
                   goto _loop_0;
        }
        _ifnot_1: { i_2 = 0; }
        _loop_1: { if (! (static_cast<int64_t> (i_2) < 1L)) goto _ifnot_0; }
        _body_1: { s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] = s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] + c.m_increment[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0];
                   _5 = i_2;
                   i_2 = _5 + 1;
                   goto _loop_1;
        }
        _ifnot_0: { return s.m_current; }
    }

    float VA__SmoothedParameter___M_2___get_dyn_array_element_slice_f32 (DynamicArray<float> array, int32_t index) noexcept
    {
        if (! (array.numElements == 0)) goto _notEmpty;
        _empty: { return 0; }
        _notEmpty: { return array[_internal___wrapInt32 (index, array.numElements)]; }
    }

    int32_t VA__SmoothedParameter___M_2___get_array_size_slice_f32 (DynamicArray<float> array) noexcept;

    //==============================================================================
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_3__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vdBtoGain (Vector<double, 2> (VA__SmoothedParameter___M_3___get_dyn_array_element_slice_f32 (parameter, 0)));
        y[0] = _2;
        return y;
    }

    void VA__SmoothedParameter___M_3__update (VA__SmoothedParameter___M_3__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_3__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        int32_t i = {}, _5 = {};

        _2 = VA__SmoothedParameter___M_3__decodeParameter (parameter, fs);
        c.m_target = _2;
        _3 = VA__vabs (c.m_target[0] - s.m_current[0]);
        _4 = VA__vmax (Vector<double, 2> { { 1.0, 1.0 } }, _3 * divMaxDelta);
        s.m_remainingRampSamples = static_cast<int32_t> (_4[0]);
        i = 0;
        _loop_0: { if (! (i < 1)) goto _break_0; }
        _body_0: { c.m_increment[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = (c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] - s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0]) / Vector<double, 2> (s.m_remainingRampSamples);
                   _5 = i;
                   i = _5 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter___M_3__updateUnsmoothed (VA__SmoothedParameter___M_3__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_3__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};

        _2 = VA__SmoothedParameter___M_3__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_3__process (VA__SmoothedParameter___M_3__State& s, const VA__SmoothedParameter___M_3__Coeffs& c) noexcept
    {
        int32_t _2 = {}, _3 = {}, i = {}, _4 = {}, i_2 = {}, _5 = {};

        if (! (s.m_remainingRampSamples != 0)) goto _ifnot_0;
        _if_0: { _2 = s.m_remainingRampSamples;
                 _3 = _2 - 1;
                 s.m_remainingRampSamples = _3;
                 if (! (_3 == 0)) goto _ifnot_1;
        }
        _if_1: { i = 0; }
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _ifnot_0; }
        _body_0: { s.m_current[_intrin_wrap (static_cast<int32_t> (i), 1) & 0] = c.m_target[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _4 = i;
                   i = _4 + 1;
                   goto _loop_0;
        }
        _ifnot_1: { i_2 = 0; }
        _loop_1: { if (! (static_cast<int64_t> (i_2) < 1L)) goto _ifnot_0; }
        _body_1: { s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] = s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0] + c.m_increment[_intrin_wrap (static_cast<int32_t> (i_2), 1) & 0];
                   _5 = i_2;
                   i_2 = _5 + 1;
                   goto _loop_1;
        }
        _ifnot_0: { return s.m_current; }
    }

    float VA__SmoothedParameter___M_3___get_dyn_array_element_slice_f32 (DynamicArray<float> array, int32_t index) noexcept
    {
        if (! (array.numElements == 0)) goto _notEmpty;
        _empty: { return 0; }
        _notEmpty: { return array[_internal___wrapInt32 (index, array.numElements)]; }
    }

    int32_t VA__SmoothedParameter___M_3___get_array_size_slice_f32 (DynamicArray<float> array) noexcept;

    //==============================================================================
    int32_t _internal___minInt32 (int32_t a, int32_t b) noexcept
    {
        if (! (a < b)) goto _moreThan;
        _lessThan: { return a; }
        _moreThan: { return b; }
    }

    int32_t _internal___wrapInt32 (int32_t n, int32_t range) noexcept
    {
        int32_t _2 = {};

        if (! (n == 0)) goto _notEquals;
        _equals: { return 0; }
        _notEquals: { _2 = n % range;
                      if (! (_2 < 0)) goto _moduloPositive;
        }
        _moduloNegative: { return _2 + range; }
        _moduloPositive: { return _2; }
    }


    #if __clang__
     #pragma clang diagnostic pop
    #elif defined(__GNUC__)
     #pragma GCC diagnostic pop
    #elif defined(_MSC_VER)
     #pragma warning (pop)
    #endif

    //==============================================================================
    // The program contains no string literals, so this function should never be called
    static constexpr const char* lookupStringLiteral (int32_t)  { return {}; }

    //==============================================================================
    _State state = {}, initialisedState;

    double sampleRate = 1.0;
    uint32_t framesToAdvance = 0;
    uint64_t totalFramesElapsed = 0;
};

