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

    static constexpr const char*  UID           = "com.TheZhe.TheUtilityDSP";
    static constexpr const char*  name          = "TheUtilityDSP";
    static constexpr const char*  description   = "TheUtility DSP";
    static constexpr const char*  category      = "effect";
    static constexpr const char*  manufacturer  = "TheZhe";
    static constexpr const char*  version       = "1.0";
    static constexpr const char*  URL           = "";
    static constexpr bool         isInstrument  = false;
    static constexpr const char*  manifest      = "{\r\n"
    "    \"soulPatchV1\": {\r\n"
    "        \"ID\": \"com.TheZhe.TheUtilityDSP\",\r\n"
    "        \"version\": \"1.0\",\r\n"
    "        \"name\": \"TheUtilityDSP\",\r\n"
    "        \"description\": \"TheUtility DSP\",\r\n"
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
    struct VA__Mux3To1__Coeffs;
    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State;
    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State;
    struct VA__Difference__Processor_3___State;
    struct VA__Mux2To1__Coeffs;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State;
    struct VA__ApplyGain__Processor_6___State;
    struct VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State;
    struct VA__ApplyGain__Processor_2___State;
    struct VA__ApplyGain__Processor_3___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State;
    struct VA__ApplyGain__Processor_4___State;
    struct VA__StreamToEvents__Processor___State;
    struct VA__SmoothedParameter__Coeffs;
    struct VA__SmoothedParameter__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State;
    struct VA__ApplyGain__Processor_5___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State;
    struct VA__StreamToEvents__Processor_2___State;
    struct VA__ApplyGains__Processor___State;
    struct VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State;
    struct _State;
    struct VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___IO;
    struct VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___IO;
    struct VA__ApplyGain__Processor_2___IO;
    struct VA__ApplyGain__Processor_3___IO;
    struct VA__ApplyGain__Processor_4___IO;
    struct VA__ApplyGain__Processor_5___IO;
    struct VA__ApplyGain__Processor_6___IO;
    struct VA__ApplyGains__Processor___IO;
    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___IO;
    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___IO;
    struct VA__Difference__Processor_3___IO;
    struct VA__StreamToEvents__Processor___IO;
    struct VA__StreamToEvents__Processor_2___IO;
    struct VA__SmoothedParameter__Mode;
    struct VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___IO;
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

    static constexpr uint32_t numAudioInputChannels  = 4;
    static constexpr uint32_t numAudioOutputChannels = 2;

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
        std::array<const FloatType*, 4> inputChannels;
        std::array<FloatType*, 2> outputChannels;
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
            copyToInterleaved (_getInputFrameArrayRef_dryIn (state).elements, &context.inputChannels[2], startFrame, numFramesToDo);

            advance();

            copyFromInterleaved (&context.outputChannels[0], startFrame, _getOutputFrameArrayRef_out (state).elements, numFramesToDo);
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

    void setNextInputStreamFrames_dryIn (const Vector<double, 2>* frames, uint32_t numFramesToUse)
    {
        auto& buffer = _getInputFrameArrayRef_dryIn (state);

        for (uint32_t i = 0; i < numFramesToUse; ++i)
            buffer[static_cast<int> (i)] = frames[i];
    }

    void setNextInputStreamSparseFrames_dryIn (Vector<double, 2> targetFrameValue, uint32_t numFramesToReachValue)
    {
        _setSparseInputTarget_dryIn (state, targetFrameValue, (int32_t) numFramesToReachValue);
    }

    void addInputEvent_complementIn (float eventValue)
    {
        _addInputEvent_complementIn_f32 (state, eventValue);
    }

    void addInputEvent_invertL_In (float eventValue)
    {
        _addInputEvent_invertL_In_f32 (state, eventValue);
    }

    void addInputEvent_invertR_In (float eventValue)
    {
        _addInputEvent_invertR_In_f32 (state, eventValue);
    }

    void addInputEvent_volumeWetIn (float eventValue)
    {
        _addInputEvent_volumeWetIn_f32 (state, eventValue);
    }

    void addInputEvent_volumeDryIn (float eventValue)
    {
        _addInputEvent_volumeDryIn_f32 (state, eventValue);
    }

    void addInputEvent_mixIn (float eventValue)
    {
        _addInputEvent_mixIn_f32 (state, eventValue);
    }

    void addInputEvent_AB_In (float eventValue)
    {
        _addInputEvent_AB_In_f32 (state, eventValue);
    }

    void addInputEvent_volumeModeIn (float eventValue)
    {
        _addInputEvent_volumeModeIn_f32 (state, eventValue);
    }

    void addInputEvent_panWetIn (float eventValue)
    {
        _addInputEvent_panWetIn_f32 (state, eventValue);
    }

    void addInputEvent_panDryIn (float eventValue)
    {
        _addInputEvent_panDryIn_f32 (state, eventValue);
    }

    void addInputEvent_panModeMetaIn (float eventValue)
    {
        _addInputEvent_panModeMetaIn_f32 (state, eventValue);
    }

    DynamicArray<const Vector<double, 2>> getOutputStreamFrames_out()
    {
        return { &(_getOutputFrameArrayRef_out (state).elements[0]), static_cast<int32_t> (framesToAdvance) };
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

    std::array<EndpointDetails, 13> getInputEndpoints() const
    {
        return
        {
            EndpointDetails { "in",            "in:in",            EndpointType::stream, "float64<2>", 2, ""                                                                                                                                                        },
            EndpointDetails { "dryIn",         "in:dryIn",         EndpointType::stream, "float64<2>", 2, ""                                                                                                                                                        },
            EndpointDetails { "complementIn",  "in:complementIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Complement\", \"init\": 0.0, \"boolean\": true, \"group\": \"Wet\" }"                                                                      },
            EndpointDetails { "invertL_In",    "in:invertL_In",    EndpointType::event,  "float32",    0, "{ \"name\": \"Invert L\", \"init\": 0.0, \"boolean\": true, \"group\": \"Wet\" }"                                                                        },
            EndpointDetails { "invertR_In",    "in:invertR_In",    EndpointType::event,  "float32",    0, "{ \"name\": \"Invert R\", \"init\": 0.0, \"boolean\": true, \"group\": \"Wet\" }"                                                                        },
            EndpointDetails { "volumeWetIn",   "in:volumeWetIn",   EndpointType::event,  "float32",    0, "{ \"name\": \"Wet\", \"min\": -60.099998474121097, \"max\": 24, \"init\": 0.0, \"step\": 0.10000000149011612, \"unit\": \"dB\", \"group\": \"Volume\" "
            "}" },
            EndpointDetails { "volumeDryIn",   "in:volumeDryIn",   EndpointType::event,  "float32",    0, "{ \"name\": \"Dry\", \"min\": -60.099998474121097, \"max\": 24, \"init\": 0.0, \"step\": 0.10000000149011612, \"unit\": \"dB\", \"group\": \"Volume\" "
            "}" },
            EndpointDetails { "mixIn",         "in:mixIn",         EndpointType::event,  "float32",    0, "{ \"name\": \"Mix\", \"min\": 0, \"max\": 100, \"init\": 100.0, \"unit\": \"%\", \"step\": 1, \"group\": \"Volume\" }"                                   },
            EndpointDetails { "AB_In",         "in:AB_In",         EndpointType::event,  "float32",    0, "{ \"name\": \"A/B\", \"init\": 1.0, \"boolean\": true, \"text\": \"Dry|Wet\", \"group\": \"Volume\" }"                                                   },
            EndpointDetails { "volumeModeIn",  "in:volumeModeIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Mode\", \"min\": 0, \"init\": 0, \"text\": \"Wet-Dry|Wet-Mix|Wet-A/B\", \"group\": \"Volume\" }"                                           },
            EndpointDetails { "panWetIn",      "in:panWetIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Wet\", \"min\": -1, \"max\": 1, \"init\": 0.0, \"step\": 0.009999999776482582, \"group\": \"Pan\" }"                                       },
            EndpointDetails { "panDryIn",      "in:panDryIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Dry\", \"min\": -1, \"max\": 1, \"init\": 0.0, \"step\": 0.009999999776482582, \"group\": \"Pan\" }"                                       },
            EndpointDetails { "panModeMetaIn", "in:panModeMetaIn", EndpointType::event,  "float32",    0, "{ \"name\": \"Mode\", \"min\": 0, \"init\": 0, \"text\": \"Unlinked|Linked|Inverted\", \"group\": \"Pan\" }"                                             }
        };
    }

    std::array<EndpointDetails, 1> getOutputEndpoints() const
    {
        return
        {
            EndpointDetails { "out", "out:out", EndpointType::stream, "float64<2>", 2, "" }
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
    static constexpr uint32_t  numParameters = 11;

    static constexpr const std::array<const ParameterProperties, numParameters> parameters =
    {
        ParameterProperties {  "complementIn",   "Complement",  "",    0.0f,    1.0f,    0.001f,  0.0f,    true,  true,   false,  "Wet",     ""                          },
        ParameterProperties {  "invertL_In",     "Invert L",    "",    0.0f,    1.0f,    0.001f,  0.0f,    true,  true,   false,  "Wet",     ""                          },
        ParameterProperties {  "invertR_In",     "Invert R",    "",    0.0f,    1.0f,    0.001f,  0.0f,    true,  true,   false,  "Wet",     ""                          },
        ParameterProperties {  "volumeWetIn",    "Wet",         "dB",  -60.1f,  24.0f,   0.1f,    0.0f,    true,  false,  false,  "Volume",  ""                          },
        ParameterProperties {  "volumeDryIn",    "Dry",         "dB",  -60.1f,  24.0f,   0.1f,    0.0f,    true,  false,  false,  "Volume",  ""                          },
        ParameterProperties {  "mixIn",          "Mix",         "%",   0.0f,    100.0f,  1.0f,    100.0f,  true,  false,  false,  "Volume",  ""                          },
        ParameterProperties {  "AB_In",          "A/B",         "",    0.0f,    1.0f,    1.0f,    1.0f,    true,  true,   false,  "Volume",  "Dry|Wet"                   },
        ParameterProperties {  "volumeModeIn",   "Mode",        "",    0.0f,    2.0f,    1.0f,    0.0f,    true,  false,  false,  "Volume",  "Wet-Dry|Wet-Mix|Wet-A/B"   },
        ParameterProperties {  "panWetIn",       "Wet",         "",    -1.0f,   1.0f,    0.01f,   0.0f,    true,  false,  false,  "Pan",     ""                          },
        ParameterProperties {  "panDryIn",       "Dry",         "",    -1.0f,   1.0f,    0.01f,   0.0f,    true,  false,  false,  "Pan",     ""                          },
        ParameterProperties {  "panModeMetaIn",  "Mode",        "",    0.0f,    2.0f,    1.0f,    0.0f,    true,  false,  false,  "Pan",     "Unlinked|Linked|Inverted"  }
    };

    static span<const ParameterProperties> getParameterProperties() { return { parameters.data(), numParameters }; }

    static constexpr uint32_t numInputBuses  = 2;
    static constexpr uint32_t numOutputBuses = 1;

    static constexpr std::array<const AudioBus, numInputBuses>  inputBuses =
    {
        AudioBus { "in",    2 },
        AudioBus { "dryIn", 2 }
    };

    static constexpr std::array<const AudioBus, numOutputBuses> outputBuses = { AudioBus { "out", 2 } };

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
                Parameter {  parameters[0],   0.0f,    [this] (float v) { addInputEvent_complementIn (v); }   },
                Parameter {  parameters[1],   0.0f,    [this] (float v) { addInputEvent_invertL_In (v); }     },
                Parameter {  parameters[2],   0.0f,    [this] (float v) { addInputEvent_invertR_In (v); }     },
                Parameter {  parameters[3],   0.0f,    [this] (float v) { addInputEvent_volumeWetIn (v); }    },
                Parameter {  parameters[4],   0.0f,    [this] (float v) { addInputEvent_volumeDryIn (v); }    },
                Parameter {  parameters[5],   100.0f,  [this] (float v) { addInputEvent_mixIn (v); }          },
                Parameter {  parameters[6],   1.0f,    [this] (float v) { addInputEvent_AB_In (v); }          },
                Parameter {  parameters[7],   0.0f,    [this] (float v) { addInputEvent_volumeModeIn (v); }   },
                Parameter {  parameters[8],   0.0f,    [this] (float v) { addInputEvent_panWetIn (v); }       },
                Parameter {  parameters[9],   0.0f,    [this] (float v) { addInputEvent_panDryIn (v); }       },
                Parameter {  parameters[10],  0.0f,    [this] (float v) { addInputEvent_panModeMetaIn (v); }  }
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
        FixedArray<int32_t, 13> m_rampArray;
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

    struct VA__Mux3To1__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux3To1__Coeffs m_c;
    };

    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux3To1__Coeffs m_c;
    };

    struct VA__Difference__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Mux2To1__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__ApplyGain__Processor_6___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State m_unsmoothedParameter_state;
        VA__ApplyGain__Processor_6___State m_applyGain_state;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__ApplyGain__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__ApplyGain__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__ApplyGain__Processor_4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__StreamToEvents__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        Vector<double, 2> m_prevStream;
    };

    struct VA__SmoothedParameter__Coeffs
    {
        FixedArray<Vector<double, 2>, 2> m_target, m_increment;
    };

    struct VA__SmoothedParameter__State
    {
        FixedArray<Vector<double, 2>, 2> m_current;
        int32_t m_remainingSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__ApplyGain__Processor_5___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__StreamToEvents__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        Vector<double, 2> m_prevStream;
    };

    struct VA__ApplyGains__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State m_mux3To1_state;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State m_mux3To1_1_state;
        VA__Difference__Processor_3___State m_difference_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State m_mux2To1_state;
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State m_phaseInverts_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State m_upWet_state;
        VA__ApplyGain__Processor_2___State m_applyGain_state;
        VA__ApplyGain__Processor_3___State m_applyGain1_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State m_upMix_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State m_upAB_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State m_upPanWet_state;
        VA__ApplyGain__Processor_4___State m_applyGain3_state;
        VA__StreamToEvents__Processor___State m_streamToEvents_state;
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State m_sp_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State m_upDry_state;
        VA__ApplyGain__Processor_5___State m_applyGain4_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State m_upPanDry_state;
        VA__StreamToEvents__Processor_2___State m_streamToEvents1_state;
        VA__ApplyGains__Processor___State m_applyGains_state;
    };

    struct _State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId, m__framesToAdvance;
        _RenderStats m__renderStats;
        _SparseStreamStatus m__sparseStreamStatus;
        _Stream_in_vec_2_f64_1024 m__in_in, m__in_dryIn;
        _Event_in_f32_1 m__in_complementIn, m__in_invertL_In, m__in_invertR_In, m__in_volumeWetIn, m__in_volumeDryIn, m__in_mixIn, m__in_AB_In, m__in_volumeModeIn, m__in_panWetIn, m__in_panDryIn, m__in_panModeMetaIn;
        _Stream_out_vec_2_f64_1024 m__out_out;
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State m_e_state;
    };

    struct VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___IO
    {
        Vector<double, 2> m__in_in, m__in_dryIn, m__out_out;
    };

    struct VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_2___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_3___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_4___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_5___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGain__Processor_6___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGains__Processor___IO
    {
        Vector<double, 2> m__in_b, m__in_b1, m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__out_out;
    };

    struct VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__StreamToEvents__Processor___IO
    {
        Vector<double, 2> m__in_in;
    };

    struct VA__StreamToEvents__Processor_2___IO
    {
        Vector<double, 2> m__in_in;
    };

    struct VA__SmoothedParameter__Mode
    {
        int32_t m_idx, m_numIn, m_numOut, m_funcD, m_funcE;
        double m_slewRateSeconds;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___IO
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
        Vector<double, 2> _3 = {}, _4 = {};
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___IO _5 = {};

        _2 = _internal___minInt32 (1024, maxFrames);
        _updateRampingStreams (_state, _2);
        _state.m__frameCount = 0;
        _main_loop_check: { if (! (_state.m__frameCount < _2)) goto _exit; }
        _main_loop_body: { _3 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, _state.m__frameCount);
                           _4 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_dryIn, _state.m__frameCount);
                           _5 = ZeroInitialiser();
                           _5.m__in_in = _3;
                           _5.m__in_dryIn = _4;
                           VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e__run (_state.m_e_state, _5);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_out, _state.m__frameCount, _5.m__out_out);
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
        _state.m_e_state.m__processorId = 22;
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___initialise (_state.m_e_state);
    }

    void _addInputEvent_complementIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___complementIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_invertL_In_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___invertL_In_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_invertR_In_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___invertR_In_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_volumeWetIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeWetIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_volumeDryIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeDryIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_mixIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___mixIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_AB_In_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___AB_In_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_volumeModeIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeModeIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_panWetIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___panWetIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_panDryIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___panDryIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_panModeMetaIn_f32 (_State& _state, const float& event) noexcept
    {
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

    FixedArray<Vector<double, 2>, 1024>& _getInputFrameArrayRef_dryIn (_State& _state) noexcept
    {
        return _state.m__in_dryIn.m_buffer;
    }

    void _setSparseInputTarget_dryIn (_State& _state, const Vector<double, 2>& targetValue, int32_t framesToReachTarget) noexcept
    {
        if (_state.m__in_dryIn.m_sparseStreamActive) goto _block_1;
        _block_0: { _addRampingStream (_state.m__sparseStreamStatus, 1); }
        _block_1: { _setSparseStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_dryIn, targetValue, framesToReachTarget); }
    }

    FixedArray<Vector<double, 2>, 1024>& _getOutputFrameArrayRef_out (_State& state) noexcept
    {
        return state.m__out_out.m_buffer;
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
        if (! (streamId == 0)) goto _next_0;
        _case_0: { rampComplete = _applySparseStreamData_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, framesToRender);
                   goto _exit;
        }
        _next_0: { if (! (streamId == 1)) goto _exit; }
        _case_1: { rampComplete = _applySparseStreamData_struct__Stream_in_vec_2_f64_1024 (_state.m__in_dryIn, framesToRender); }
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

    float soul__intrinsics___log10_specialised (float n) noexcept
    {
        return 0;
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

    int32_t soul__intrinsics___max_specialised_2 (int32_t a, int32_t b) noexcept
    {
        int32_t _2 = {}, _3 = {}, _4 = {}, _T0 = {};

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

    //==============================================================================
    Vector<double, 2> VA__vdBtoGain (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        Vector<double, 2> b = {};

        _2 = VA___vpow_specialised_2 (Vector<double, 2> { { 10.0, 10.0 } }, x * Vector<double, 2> { { 0.05, 0.05 } });
        b = static_cast<Vector<double, 2>> (_2);
        _3 = VA__vmax (Vector<double, 2> { { 0.00001, 0.00001 } }, static_cast<Vector<double, 2>> (b));
        return _3;
    }

    Vector<double, 2> VA__vVolumeToGain (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        Vector<double, 2> y = {};

        _2 = VA__vdBtoGain (x);
        y = static_cast<Vector<double, 2>> (_2);
        _3 = VA__viflt (ZeroInitialiser(), static_cast<Vector<double, 2>> (y), x, Vector<double, 2> { { -60.0, -60.0 } });
        return _3;
    }

    Vector<double, 2> VA__vPhaseInvertsToGain (float invertL, float invertR) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _T0 = {}, _T1 = {};

        _2 = ZeroInitialiser();
        if (! static_cast<bool> (invertL)) goto _ternary_false_0;
        _ternary_true_0: { _3 = -1.0;
                           _T0 = _3;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { _4 = 1.0;
                            _T0 = _4;
        }
        _ternary_end_0: { _5 = _T0;
                          _2[0] = _5;
                          if (! static_cast<bool> (invertR)) goto _ternary_false_1;
        }
        _ternary_true_1: { _6 = -1.0;
                           _T1 = _6;
                           goto _ternary_end_1;
        }
        _ternary_false_1: { _7 = 1.0;
                            _T1 = _7;
        }
        _ternary_end_1: { _8 = _T1;
                          _2[1] = _8;
                          return _2;
        }
    }

    FixedArray<Vector<double, 2>, 2> VA__vMakeupMixPansToGains (float makeup, float mix, float panDry, float panWet) noexcept
    {
        FixedArray<Vector<double, 2>, 2> bMakeup = {}, bMix = {}, bPans = {};
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {};
        FixedArray<Vector<double, 2>, 2> _5 = {}, _6 = {};

        bMakeup = ZeroInitialiser();
        bMakeup[0] = Vector<double, 2> { { 1.0, 1.0 } };
        _2 = VA__vdBtoGain (Vector<double, 2> (makeup));
        bMakeup[1] = _2;
        _5 = VA__vMixToGains (mix);
        bMix = static_cast<FixedArray<Vector<double, 2>, 2>> (_5);
        bPans = ZeroInitialiser();
        _3 = VA__vPanToGain (panDry);
        bPans[0] = _3;
        _4 = VA__vPanToGain (panWet);
        bPans[1] = _4;
        _6 = ZeroInitialiser();
        _6[0] = (bMakeup[0] * bMix[0]) * bPans[0];
        _6[1] = (bMakeup[1] * bMix[1]) * bPans[1];
        return _6;
    }

    FixedArray<Vector<double, 2>, 2> VA__vABtoGains (bool wet) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {};

        y = ZeroInitialiser();
        if (! wet) goto _ifnot_0;
        _if_0: { y[1] = Vector<double, 2> { { 1.0, 1.0 } };
                 goto _ifend_0;
        }
        _ifnot_0: { y[0] = Vector<double, 2> { { 1.0, 1.0 } }; }
        _ifend_0: { return y; }
    }

    FixedArray<Vector<double, 2>, 2> VA__vMixPanToGains (float m, float p) noexcept
    {
        FixedArray<Vector<double, 2>, 2> _2 = {}, _3 = {}, _4 = {};
        FixedArray<Vector<double, 2>, 2> bPan = {}, bMix = {};

        _2 = VA__vPanToGains (p);
        bPan = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
        _3 = VA__vMixToGains (m);
        bMix = static_cast<FixedArray<Vector<double, 2>, 2>> (_3);
        _4 = ZeroInitialiser();
        _4[0] = bMix[0] * bPan[0];
        _4[1] = bMix[1] * bPan[1];
        return _4;
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

    FixedArray<Vector<double, 2>, 2> VA__vPanToGains (float x) noexcept
    {
        Vector<double, 2> _2 = {};
        Vector<double, 2> b1 = {};
        FixedArray<Vector<double, 2>, 2> _3 = {};

        _2 = VA__vPanToGain (x);
        b1 = static_cast<Vector<double, 2>> (_2);
        _3 = ZeroInitialiser();
        _3[0] = static_cast<Vector<double, 2>> (Vector<double, 2> { { 2.0, 2.0 } } - b1);
        _3[1] = static_cast<Vector<double, 2>> (b1);
        return _3;
    }

    Vector<double, 2> VA__vPanToGain (float x) noexcept
    {
        double bR = {};
        Vector<double, 2> _2 = {};

        bR = static_cast<double> (static_cast<double> (x) + 1.0);
        _2 = ZeroInitialiser();
        _2[0] = 2.0 - static_cast<double> (bR);
        _2[1] = static_cast<double> (bR);
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

    Vector<double, 2> VA__vmax (Vector<double, 2> x, Vector<double, 2> x1) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = soul__intrinsics___max_specialised (x[0], x1[0]);
        _2[0] = _3;
        _4 = soul__intrinsics___max_specialised (x[1], x1[1]);
        _2[1] = _4;
        return _2;
    }

    double VA__vmaxr (Vector<double, 2> x) noexcept
    {
        double _2 = {};

        _2 = soul__intrinsics___max_specialised (x[0], x[1]);
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
    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___initialise (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state) noexcept
    {
        _state.m_mux3To1_state.m__arrayEntry = 0;
        _state.m_mux3To1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux3To1_state.m__processorId = 1;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___initialise (_state.m_mux3To1_state);
        _state.m_mux3To1_1_state.m__arrayEntry = 0;
        _state.m_mux3To1_1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux3To1_1_state.m__processorId = 2;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___initialise (_state.m_mux3To1_1_state);
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 3;
        _state.m_mux2To1_state.m__arrayEntry = 0;
        _state.m_mux2To1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_state.m__processorId = 4;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___initialise (_state.m_mux2To1_state);
        _state.m_phaseInverts_state.m__arrayEntry = 0;
        _state.m_phaseInverts_state.m__sessionID = _state.m__sessionID;
        _state.m_phaseInverts_state.m__processorId = 5;
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___initialise (_state.m_phaseInverts_state);
        _state.m_upWet_state.m__arrayEntry = 0;
        _state.m_upWet_state.m__sessionID = _state.m__sessionID;
        _state.m_upWet_state.m__processorId = 6;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___initialise (_state.m_upWet_state);
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 7;
        _state.m_applyGain1_state.m__arrayEntry = 0;
        _state.m_applyGain1_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain1_state.m__processorId = 8;
        _state.m_upMix_state.m__arrayEntry = 0;
        _state.m_upMix_state.m__sessionID = _state.m__sessionID;
        _state.m_upMix_state.m__processorId = 9;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___initialise (_state.m_upMix_state);
        _state.m_upAB_state.m__arrayEntry = 0;
        _state.m_upAB_state.m__sessionID = _state.m__sessionID;
        _state.m_upAB_state.m__processorId = 10;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___initialise (_state.m_upAB_state);
        _state.m_upPanWet_state.m__arrayEntry = 0;
        _state.m_upPanWet_state.m__sessionID = _state.m__sessionID;
        _state.m_upPanWet_state.m__processorId = 11;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___initialise (_state.m_upPanWet_state);
        _state.m_applyGain3_state.m__arrayEntry = 0;
        _state.m_applyGain3_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain3_state.m__processorId = 12;
        _state.m_streamToEvents_state.m__arrayEntry = 0;
        _state.m_streamToEvents_state.m__sessionID = _state.m__sessionID;
        _state.m_streamToEvents_state.m__processorId = 13;
        _state.m_sp_state.m__arrayEntry = 0;
        _state.m_sp_state.m__sessionID = _state.m__sessionID;
        _state.m_sp_state.m__processorId = 14;
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___initialise (_state.m_sp_state);
        _state.m_upDry_state.m__arrayEntry = 0;
        _state.m_upDry_state.m__sessionID = _state.m__sessionID;
        _state.m_upDry_state.m__processorId = 15;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___initialise (_state.m_upDry_state);
        _state.m_applyGain4_state.m__arrayEntry = 0;
        _state.m_applyGain4_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain4_state.m__processorId = 16;
        _state.m_upPanDry_state.m__arrayEntry = 0;
        _state.m_upPanDry_state.m__sessionID = _state.m__sessionID;
        _state.m_upPanDry_state.m__processorId = 17;
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___initialise (_state.m_upPanDry_state);
        _state.m_streamToEvents1_state.m__arrayEntry = 0;
        _state.m_streamToEvents1_state.m__sessionID = _state.m__sessionID;
        _state.m_streamToEvents1_state.m__processorId = 18;
        _state.m_applyGains_state.m__arrayEntry = 0;
        _state.m_applyGains_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGains_state.m__processorId = 19;
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e__run (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___IO _4 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___IO _5 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___IO _6 = {};
        VA__ApplyGain__Processor_2___IO _7 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___IO _8 = {};
        VA__ApplyGain__Processor_3___IO _9 = {};
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___IO _10 = {};
        VA__ApplyGain__Processor_4___IO _11 = {};
        VA__StreamToEvents__Processor___IO _12 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___IO _13 = {};
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___IO _14 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___IO _15 = {};
        VA__ApplyGain__Processor_5___IO _16 = {};
        VA__StreamToEvents__Processor_2___IO _17 = {};
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___IO _18 = {};
        VA__Difference__Processor_3___IO _19 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___IO _20 = {};
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___IO _21 = {};
        VA__ApplyGains__Processor___IO _22 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_dryIn;
        _4 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet__run (_state.m_upPanWet_state, _4);
        _5 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet__run (_state.m_upWet_state, _5);
        _6 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix__run (_state.m_upMix_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_b = _6.m__out_out1;
        _7.m__in_in = _5.m__out_out;
        VA__ApplyGain__Processor_2__run (_state.m_applyGain_state, _7);
        _8 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB__run (_state.m_upAB_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_b = _8.m__out_out1;
        _9.m__in_in = _5.m__out_out;
        VA__ApplyGain__Processor_3__run (_state.m_applyGain1_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _5.m__out_out;
        _10.m__in_in1 = _7.m__out_out;
        _10.m__in_in2 = _9.m__out_out;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1__run (_state.m_mux3To1_state, _10);
        _11 = ZeroInitialiser();
        _11.m__in_b = _10.m__out_out;
        _11.m__in_in = _4.m__out_out;
        VA__ApplyGain__Processor_4__run (_state.m_applyGain3_state, _11);
        _12 = ZeroInitialiser();
        _12.m__in_in = _11.m__out_out;
        VA__StreamToEvents__Processor__run (_state.m_streamToEvents_state, _12);
        _13 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry__run (_state.m_upDry_state, _13);
        _14 = ZeroInitialiser();
        _14.m__in_in = _13.m__out_out;
        _14.m__in_in1 = _6.m__out_out;
        _14.m__in_in2 = _8.m__out_out;
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1__run (_state.m_mux3To1_1_state, _14);
        _15 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry__run (_state.m_upPanDry_state, _15);
        _16 = ZeroInitialiser();
        _16.m__in_b = _15.m__out_out;
        _16.m__in_in = _14.m__out_out;
        VA__ApplyGain__Processor_5__run (_state.m_applyGain4_state, _16);
        _17 = ZeroInitialiser();
        _17.m__in_in = _16.m__out_out;
        VA__StreamToEvents__Processor_2__run (_state.m_streamToEvents1_state, _17);
        _18 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp__run (_state.m_sp_state, _18);
        _19 = ZeroInitialiser();
        _19.m__in_in = _3;
        _19.m__in_in1 = _2;
        VA__Difference__Processor_3__run (_state.m_difference_state, _19);
        _20 = ZeroInitialiser();
        _20.m__in_in = _2;
        _20.m__in_in1 = _19.m__out_out;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1__run (_state.m_mux2To1_state, _20);
        _21 = ZeroInitialiser();
        _21.m__in_in = _20.m__out_out;
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts__run (_state.m_phaseInverts_state, _21);
        _22 = ZeroInitialiser();
        _22.m__in_b = _18.m__out_out;
        _22.m__in_b1 = _18.m__out_out1;
        _22.m__in_in = _3;
        _22.m__in_in1 = _21.m__out_out;
        VA__ApplyGains__Processor__run (_state.m_applyGains_state, _22);
        _io.m__out_out = _22.m__out_out;
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___complementIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___idxIn_f32 (_state.m_mux2To1_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___invertL_In_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___invertL_In_f32 (_state.m_phaseInverts_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___invertR_In_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___invertR_In_f32 (_state.m_phaseInverts_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeWetIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___in_f32 (_state.m_upWet_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeDryIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___in_f32 (_state.m_upDry_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___mixIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___in_f32 (_state.m_upMix_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___AB_In_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___in_f32 (_state.m_upAB_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___volumeModeIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___idxIn_f32 (_state.m_mux3To1_state, event);
        VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___idxIn_f32 (_state.m_mux3To1_1_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___panWetIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___in_f32 (_state.m_upPanWet_state, event);
    }

    void VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___panDryIn_f32 (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___in_f32 (_state.m_upPanDry_state, event);
    }

    //==============================================================================
    void VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___initialise (VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State& _state) noexcept
    {
        _state.m_unsmoothedParameter_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter_state.m__processorId = 20;
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___initialise (_state.m_unsmoothedParameter_state);
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 21;
    }

    void VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts__run (VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State& _state, VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___IO _3 = {};
        VA__ApplyGain__Processor_6___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter__run (_state.m_unsmoothedParameter_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor_6__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___invertL_In_f32 (VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___in_f32 (_state.m_unsmoothedParameter_state, event);
    }

    void VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___invertR_In_f32 (VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts___State& _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___in1_f32 (_state.m_unsmoothedParameter_state, event);
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
    void VA__ApplyGain__Processor_4__run (VA__ApplyGain__Processor_4___State& _state, VA__ApplyGain__Processor_4___IO& _io) noexcept
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
    void VA__ApplyGain__Processor_5__run (VA__ApplyGain__Processor_5___State& _state, VA__ApplyGain__Processor_5___IO& _io) noexcept
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
    void VA__ApplyGain__Processor_6__run (VA__ApplyGain__Processor_6___State& _state, VA__ApplyGain__Processor_6___IO& _io) noexcept
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
    void VA__ApplyGains__Processor__run (VA__ApplyGains__Processor___State& _state, VA__ApplyGains__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_b;
        _3 = _io.m__in_in;
        _4 = _io.m__in_b1;
        _5 = _io.m__in_in1;
        out_value_out = out_value_out + ((_2 * _3) + (_4 * _5));
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Mux3To1__update (VA__Mux3To1__Coeffs& c, float idx) noexcept
    {
        c.m_idx = static_cast<int32_t> (idx);
    }

    Vector<double, 2> VA__Mux3To1__process (FixedArray<Vector<double, 2>, 3> x, const VA__Mux3To1__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (c.m_idx), 3)), 3)), 3)];
    }

    //==============================================================================
    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___idxIn_f32 (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1__run (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State& _state, VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};
        int32_t updateIntervalSamples = {};
        FixedArray<Vector<double, 2>, 3> _6 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                   if (! _state.m_recalc) goto _ifnot_0;
        }
        _if_0: { _state.m_recalc = false;
                 VA__Mux3To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _6 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _6[0] = _2;
                   _3 = _io.m__in_in1;
                   _6[1] = _3;
                   _4 = _io.m__in_in2;
                   _6[2] = _4;
                   _5 = VA__Mux3To1__process (_6, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___initialise (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___idxIn_f32 (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1__run (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State& _state, VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};
        int32_t updateIntervalSamples = {};
        FixedArray<Vector<double, 2>, 3> _6 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                   if (! _state.m_recalc) goto _ifnot_0;
        }
        _if_0: { _state.m_recalc = false;
                 VA__Mux3To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _6 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _6[0] = _2;
                   _3 = _io.m__in_in1;
                   _6[1] = _3;
                   _4 = _io.m__in_in2;
                   _6[2] = _4;
                   _5 = VA__Mux3To1__process (_6, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___initialise (VA__Mux3To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux3To1_1___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux2To1__update (VA__Mux2To1__Coeffs& c, float idx) noexcept
    {
        c.m_idx = static_cast<int32_t> (idx);
    }

    Vector<double, 2> VA__Mux2To1__process (FixedArray<Vector<double, 2>, 2> x, const VA__Mux2To1__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (c.m_idx), 2) & 1];
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State& _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State& _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        int32_t updateIntervalSamples = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                   if (! _state.m_recalc) goto _ifnot_0;
        }
        _if_0: { _state.m_recalc = false;
                 VA__Mux2To1__update (_state.m_c, _state.m_idx);
        }
        _ifnot_0: { _state.m_counter_1 = updateIntervalSamples; }
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

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_mux2To1___State& _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
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
    static VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _stateUpCast (VA__StreamToEvents__Processor___State& s)
    {
        auto offset = static_cast<int32_t> (offsetof (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State, m_streamToEvents_state));
        return *reinterpret_cast<VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State*> (reinterpret_cast<char*> (&s) - offset);
    }

    //==============================================================================
    void VA__StreamToEvents__Processor__run (VA__StreamToEvents__Processor___State& _state, VA__StreamToEvents__Processor___IO& _io) noexcept
    {
        int32_t _resumePoint = {};
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_prevStream = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_in;
                   if (! (_state.m_prevStream[0] != _2[0])) goto _ifnot_0;
        }
        _if_0: { _3 = _io.m__in_in;
                 _state.m_prevStream[0] = _3[0];
                 _4 = _io.m__in_in;
                 VA__StreamToEvents__Processor___out_f32 (_state, static_cast<float> (_4[0]));
        }
        _ifnot_0: { _5 = _io.m__in_in;
                    if (! (_state.m_prevStream[1] != _5[1])) goto _advance_start_0;
        }
        _if_1: { _6 = _io.m__in_in;
                 _state.m_prevStream[1] = _6[1];
                 _7 = _io.m__in_in;
                 VA__StreamToEvents__Processor___out1_f32 (_state, static_cast<float> (_7[1]));
        }
        _advance_start_0: { _state.m__resumePoint = 1; }
    }

    void VA__StreamToEvents__Processor___out_f32 (VA__StreamToEvents__Processor___State& _state, float value) noexcept
    {
        auto& _2 = _stateUpCast (_state);
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in2_f32 (_2.m_sp_state, value);
    }

    void VA__StreamToEvents__Processor___out1_f32 (VA__StreamToEvents__Processor___State& _state, float value) noexcept
    {
        auto& _2 = _stateUpCast (_state);
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in3_f32 (_2.m_sp_state, value);
    }

    //==============================================================================
    static VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State& _stateUpCast (VA__StreamToEvents__Processor_2___State& s)
    {
        auto offset = static_cast<int32_t> (offsetof (VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State, m_streamToEvents1_state));
        return *reinterpret_cast<VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e___State*> (reinterpret_cast<char*> (&s) - offset);
    }

    //==============================================================================
    void VA__StreamToEvents__Processor_2__run (VA__StreamToEvents__Processor_2___State& _state, VA__StreamToEvents__Processor_2___IO& _io) noexcept
    {
        int32_t _resumePoint = {};
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {};

        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_prevStream = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_in;
                   if (! (_state.m_prevStream[0] != _2[0])) goto _ifnot_0;
        }
        _if_0: { _3 = _io.m__in_in;
                 _state.m_prevStream[0] = _3[0];
                 _4 = _io.m__in_in;
                 VA__StreamToEvents__Processor_2___out_f32 (_state, static_cast<float> (_4[0]));
        }
        _ifnot_0: { _5 = _io.m__in_in;
                    if (! (_state.m_prevStream[1] != _5[1])) goto _advance_start_0;
        }
        _if_1: { _6 = _io.m__in_in;
                 _state.m_prevStream[1] = _6[1];
                 _7 = _io.m__in_in;
                 VA__StreamToEvents__Processor_2___out1_f32 (_state, static_cast<float> (_7[1]));
        }
        _advance_start_0: { _state.m__resumePoint = 1; }
    }

    void VA__StreamToEvents__Processor_2___out_f32 (VA__StreamToEvents__Processor_2___State& _state, float value) noexcept
    {
        auto& _2 = _stateUpCast (_state);
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in_f32 (_2.m_sp_state, value);
    }

    void VA__StreamToEvents__Processor_2___out1_f32 (VA__StreamToEvents__Processor_2___State& _state, float value) noexcept
    {
        auto& _2 = _stateUpCast (_state);
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in1_f32 (_2.m_sp_state, value);
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__SmoothedParameter__decodeParameter (FixedArray<float, 4> parameter, int32_t modeIdx) noexcept
    {
        VA__SmoothedParameter__Mode mode = {};
        FixedArray<Vector<double, 2>, 2> y = {}, _2 = {}, _3 = {}, y2 = {}, y2_2 = {}, _4 = {};
        Vector<double, 2> _5 = {}, _6 = {}, _7 = {}, _8 = {};
        FixedArray<Vector<double, 2>, 2> y2_3 = {}, y2_4 = {};
        int32_t i = {}, _9 = {}, i_2 = {}, _10 = {}, i_3 = {}, _11 = {}, i_4 = {}, _12 = {};
        float _13 = {};

        mode = static_cast<VA__SmoothedParameter__Mode> (FixedArray<VA__SmoothedParameter__Mode, 9> { { VA__SmoothedParameter__Mode { 0, 1, 1, 0, 0, 100.0 }, VA__SmoothedParameter__Mode { 1, 1, 1, 1, 0, 100.0 }, VA__SmoothedParameter__Mode { 2, 2, 2, 2, 0, 100.0 }, VA__SmoothedParameter__Mode { 3, 1, 1, 3,
        0, 100.0 }, VA__SmoothedParameter__Mode { 4, 1, 1, 0, 0, 5000.0 }, VA__SmoothedParameter__Mode { 5, 1, 1, 5, 6, 10.0 }, VA__SmoothedParameter__Mode { 6, 4, 2, 4, 0, 100.0 }, VA__SmoothedParameter__Mode { 7, 1, 2, 8, 0, 100.0 }, VA__SmoothedParameter__Mode { 8, 4, 2, 7, 0, 100.0 } } }[_intrin_wrap (static_cast<int32_t>
        (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (modeIdx), 9)), 9)), 9)]);
        y = ZeroInitialiser();
        if (! (mode.m_funcD == 0)) goto _ifnot_0;
        _if_0: { y[0] = Vector<double, 2> (parameter[0]);
                 goto _ifend_0;
        }
        _ifnot_0: { if (! (mode.m_funcD == 1)) goto _ifnot_1; }
        _if_1: { _5 = VA__vVolumeToGain (Vector<double, 2> (parameter[0]));
                 y[0] = _5;
                 goto _ifend_0;
        }
        _ifnot_1: { if (! (mode.m_funcD == 2)) goto _ifnot_2; }
        _if_2: { _2 = VA__vMixPanToGains (parameter[0], parameter[1]);
                 y2_3 = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                 i = 0;
        }
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _ifend_0; }
        _body_0: { y[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = y2_3[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _9 = i;
                   i = _9 + 1;
                   goto _loop_0;
        }
        _ifnot_2: { if (! (mode.m_funcD == 3)) goto _ifnot_3; }
        _if_3: { y[0] = Vector<double, 2> (static_cast<double> (parameter[0]) * 0.01);
                 goto _ifend_0;
        }
        _ifnot_3: { if (! (mode.m_funcD == 5)) goto _ifnot_4; }
        _if_4: { _13 = SOUL_INTRINSICS::log10 (parameter[0]);
                 y[0] = Vector<double, 2> (_13);
                 goto _ifend_0;
        }
        _ifnot_4: { if (! (mode.m_funcD == 4)) goto _ifnot_5; }
        _if_5: { _3 = VA__vMakeupMixPansToGains (parameter[0], parameter[1], parameter[2], parameter[3]);
                 y2_4 = static_cast<FixedArray<Vector<double, 2>, 2>> (_3);
                 i_2 = 0;
        }
        _loop_1: { if (! (static_cast<int64_t> (i_2) < 2L)) goto _ifend_0; }
        _body_1: { y[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] = y2_4[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1];
                   _10 = i_2;
                   i_2 = _10 + 1;
                   goto _loop_1;
        }
        _ifnot_5: { if (! (mode.m_funcD == 8)) goto _ifnot_6; }
        _if_6: { y2 = ZeroInitialiser();
                 _6 = VA__vdBtoGain (Vector<double, 2> (parameter[0]));
                 y2[0] = _6;
                 y2[1] = static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (y2[0]));
                 i_3 = 0;
        }
        _loop_2: { if (! (static_cast<int64_t> (i_3) < 2L)) goto _ifend_0; }
        _body_2: { y[_intrin_wrap (static_cast<int32_t> (i_3), 2) & 1] = y2[_intrin_wrap (static_cast<int32_t> (i_3), 2) & 1];
                   _11 = i_3;
                   i_3 = _11 + 1;
                   goto _loop_2;
        }
        _ifnot_6: { y2_2 = ZeroInitialiser();
                    _4 = ZeroInitialiser();
                    _7 = ZeroInitialiser();
                    _7[0] = static_cast<double> (parameter[0]);
                    _7[1] = static_cast<double> (parameter[1]);
                    _4[0] = _7;
                    _8 = ZeroInitialiser();
                    _8[0] = static_cast<double> (parameter[2]);
                    _8[1] = static_cast<double> (parameter[3]);
                    _4[1] = _8;
                    y2_2 = _4;
                    i_4 = 0;
        }
        _loop_3: { if (! (static_cast<int64_t> (i_4) < 2L)) goto _ifend_0; }
        _body_3: { y[_intrin_wrap (static_cast<int32_t> (i_4), 2) & 1] = y2_2[_intrin_wrap (static_cast<int32_t> (i_4), 2) & 1];
                   _12 = i_4;
                   i_4 = _12 + 1;
                   goto _loop_3;
        }
        _ifend_0: { return y; }
    }

    FixedArray<Vector<double, 2>, 2> VA__SmoothedParameter__encodeParameter (FixedArray<Vector<double, 2>, 2> parameter, int32_t modeIdx) noexcept
    {
        VA__SmoothedParameter__Mode mode = {};
        FixedArray<Vector<double, 2>, 2> y = {};
        Vector<double, 2> _2 = {};

        mode = static_cast<VA__SmoothedParameter__Mode> (FixedArray<VA__SmoothedParameter__Mode, 9> { { VA__SmoothedParameter__Mode { 0, 1, 1, 0, 0, 100.0 }, VA__SmoothedParameter__Mode { 1, 1, 1, 1, 0, 100.0 }, VA__SmoothedParameter__Mode { 2, 2, 2, 2, 0, 100.0 }, VA__SmoothedParameter__Mode { 3, 1, 1, 3,
        0, 100.0 }, VA__SmoothedParameter__Mode { 4, 1, 1, 0, 0, 5000.0 }, VA__SmoothedParameter__Mode { 5, 1, 1, 5, 6, 10.0 }, VA__SmoothedParameter__Mode { 6, 4, 2, 4, 0, 100.0 }, VA__SmoothedParameter__Mode { 7, 1, 2, 8, 0, 100.0 }, VA__SmoothedParameter__Mode { 8, 4, 2, 7, 0, 100.0 } } }[_intrin_wrap (static_cast<int32_t>
        (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (modeIdx), 9)), 9)), 9)]);
        y = ZeroInitialiser();
        if (! (mode.m_funcE == 6)) goto _ifnot_0;
        _if_0: { _2 = VA___vpow_specialised_2 (Vector<double, 2> { { 10.0, 10.0 } }, parameter[0]);
                 y[0] = _2;
                 return y;
        }
        _ifnot_0: { return parameter; }
    }

    void VA__SmoothedParameter__update (VA__SmoothedParameter__Coeffs& c, FixedArray<float, 4> parameter, VA__SmoothedParameter__State& s, int32_t modeIdx, double fs) noexcept
    {
        VA__SmoothedParameter__Mode mode = {};
        double divMaxDelta = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        int32_t i = {}, _3 = {}, _4 = {}, _5 = {}, i_2 = {}, _6 = {};
        Vector<double, 2> _7 = {};
        double _8 = {};

        mode = static_cast<VA__SmoothedParameter__Mode> (FixedArray<VA__SmoothedParameter__Mode, 9> { { VA__SmoothedParameter__Mode { 0, 1, 1, 0, 0, 100.0 }, VA__SmoothedParameter__Mode { 1, 1, 1, 1, 0, 100.0 }, VA__SmoothedParameter__Mode { 2, 2, 2, 2, 0, 100.0 }, VA__SmoothedParameter__Mode { 3, 1, 1, 3,
        0, 100.0 }, VA__SmoothedParameter__Mode { 4, 1, 1, 0, 0, 5000.0 }, VA__SmoothedParameter__Mode { 5, 1, 1, 5, 6, 10.0 }, VA__SmoothedParameter__Mode { 6, 4, 2, 4, 0, 100.0 }, VA__SmoothedParameter__Mode { 7, 1, 2, 8, 0, 100.0 }, VA__SmoothedParameter__Mode { 8, 4, 2, 7, 0, 100.0 } } }[_intrin_wrap (static_cast<int32_t>
        (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (modeIdx), 9)), 9)), 9)]);
        divMaxDelta = static_cast<double> (fs / mode.m_slewRateSeconds);
        _2 = VA__SmoothedParameter__decodeParameter (parameter, modeIdx);
        c.m_target = _2;
        i = 0;
        _loop_0: { if (! (i < mode.m_numOut)) goto _break_0; }
        _body_0: { _7 = VA__vabs (c.m_target[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] - s.m_current[_intrin_wrap (static_cast<int32_t> (i), 2) & 1]);
                   _8 = VA__vmaxr (_7 * Vector<double, 2> (divMaxDelta));
                   _3 = soul__intrinsics___max_specialised_2 (s.m_remainingSamples, static_cast<int32_t> (_8));
                   s.m_remainingSamples = _3;
                   _4 = i;
                   i = _4 + 1;
                   goto _loop_0;
        }
        _break_0: { _5 = soul__intrinsics___max_specialised_2 (1, s.m_remainingSamples);
                    s.m_remainingSamples = _5;
                    i_2 = 0;
        }
        _loop_1: { if (! (i_2 < mode.m_numOut)) goto _break_1; }
        _body_1: { c.m_increment[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] = (c.m_target[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] - s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1]) / Vector<double, 2> (s.m_remainingSamples);
                   _6 = i_2;
                   i_2 = _6 + 1;
                   goto _loop_1;
        }
        _break_1: {}
    }

    void VA__SmoothedParameter__updateUnsmoothed (VA__SmoothedParameter__Coeffs& c, FixedArray<float, 4> parameter, VA__SmoothedParameter__State& s, int32_t modeIdx) noexcept
    {
        FixedArray<Vector<double, 2>, 2> _2 = {};

        _2 = VA__SmoothedParameter__decodeParameter (parameter, modeIdx);
        c.m_target = _2;
        s.m_remainingSamples = 1;
    }

    FixedArray<Vector<double, 2>, 2> VA__SmoothedParameter__process (VA__SmoothedParameter__State& s, const VA__SmoothedParameter__Coeffs& c, int32_t modeIdx) noexcept
    {
        int32_t _2 = {}, _3 = {}, i = {}, _4 = {}, i_2 = {}, _5 = {};
        FixedArray<Vector<double, 2>, 2> _6 = {};

        if (! (s.m_remainingSamples != 0)) goto _ifnot_0;
        _if_0: { _2 = s.m_remainingSamples;
                 _3 = _2 - 1;
                 s.m_remainingSamples = _3;
                 if (! (_3 == 0)) goto _ifnot_1;
        }
        _if_1: { i = 0; }
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _ifnot_0; }
        _body_0: { s.m_current[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = c.m_target[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _4 = i;
                   i = _4 + 1;
                   goto _loop_0;
        }
        _ifnot_1: { i_2 = 0; }
        _loop_1: { if (! (static_cast<int64_t> (i_2) < 2L)) goto _ifnot_0; }
        _body_1: { s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] = s.m_current[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] + c.m_increment[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1];
                   _5 = i_2;
                   i_2 = _5 + 1;
                   goto _loop_1;
        }
        _ifnot_0: { _6 = VA__SmoothedParameter__encodeParameter (s.m_current, modeIdx);
                    return _6;
        }
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in1_f32 (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state, float v) noexcept
    {
        _state.m_parameter[1] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in2_f32 (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state, float v) noexcept
    {
        _state.m_parameter[2] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___in3_f32 (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state, float v) noexcept
    {
        _state.m_parameter[3] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp__init (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { 1.0f, 1.0f, 1.0f, 1.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp__run (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state, VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        int32_t _resumePoint = {};
        int32_t updateIntervalSamples = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 8);
        }
        _body_0: { updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                   if (! _state.m_recalc) goto _ifnot_0;
        }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 8, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 8);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   out_value_out1 = out_value_out1 + y[1];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   _io.m__out_out1 = out_value_out1;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___initialise (VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp___State& _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 1.0f, 1.0f, 1.0f, 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_sp__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet___State& _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upWet__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry___State& _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upDry__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 100.0f, 100.0f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M_2__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    out_value_out1 = out_value_out1 + _state.m_y[1];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
                    _io.m__out_out1 = out_value_out1;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix___State& _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 100.0f, 100.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upMix__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 1.0f, 1.0f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M_3__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    out_value_out1 = out_value_out1 + _state.m_y[1];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
                    _io.m__out_out1 = out_value_out1;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB___State& _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 1.0f, 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upAB__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M_4__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet___State& _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanWet__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State& _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry__init (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State& _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry__run (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State& _state, VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M_4__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry___State& _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_upPanDry__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___in1_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State&
    _state, float v) noexcept
    {
        _state.m_parameter[1] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter__init (VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter__run (VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};

        out_value_out = ZeroInitialiser();
        if (! _state.m_recalc) goto _ifnot_0;
        _if_0: { _state.m_recalc = false;
                 _2 = VA__UnsmoothedParameter___M_5__decodeParameter (_state.m_parameter);
                 _state.m_y = _2;
        }
        _ifnot_0: { out_value_out = out_value_out + _state.m_y[0];
                    _state.m__resumePoint = 1;
                    _io.m__out_out = out_value_out;
        }
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__PhaseInverts__Processor___for__root__VA__HighLevel__TheUtility__Processor___for__root__main__Processor_e_phaseInverts_unsmoothedParameter__init (_state);
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vVolumeToGain (Vector<double, 2> (parameter[0]));
        y[0] = _2;
        return y;
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M_2__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {}, _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vMixToGains (parameter[0]);
        y = _2;
        return y;
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M_3__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {}, _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vABtoGains (static_cast<bool> (parameter[0]));
        y = _2;
        return y;
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M_4__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vPanToGain (parameter[0]);
        y[0] = _2;
        return y;
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M_5__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vPhaseInvertsToGain (parameter[0], parameter[1]);
        y[0] = _2;
        return y;
    }

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

