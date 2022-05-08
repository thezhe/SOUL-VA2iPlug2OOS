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

    static constexpr const char*  UID           = "com.TheZhe.TheChorusDSP";
    static constexpr const char*  name          = "TheChorusDSP";
    static constexpr const char*  description   = "TheChorus DSP";
    static constexpr const char*  category      = "effect";
    static constexpr const char*  manufacturer  = "TheZhe";
    static constexpr const char*  version       = "1.0";
    static constexpr const char*  URL           = "";
    static constexpr bool         isInstrument  = false;
    static constexpr const char*  manifest      = "{\r\n"
    "    \"soulPatchV1\": {\r\n"
    "        \"ID\": \"com.TheZhe.TheChorusDSP\",\r\n"
    "        \"version\": \"1.0\",\r\n"
    "        \"name\": \"TheChorusDSP\",\r\n"
    "        \"description\": \"TheChorus DSP\",\r\n"
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
    struct VA__SmoothedParameter___M_5__Coeffs;
    struct VA__SmoothedParameter___M_5__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State;
    struct VA__Lfo__Internal__Coeffs;
    struct VA__Lfo__Internal__State;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State;
    struct VA__DelayLine___M__State;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State;
    struct soul___filters__dc_blocker__Coeffs;
    struct soul___filters__dc_blocker__State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State;
    struct VA__DC_Blocker__Processor___State;
    struct VA__SmoothedParameter___M_3__Coeffs;
    struct VA__SmoothedParameter___M_3__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State;
    struct VA__ApplyGains__Processor___State;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State;
    struct VA__SmoothedParameter___M__Coeffs;
    struct VA__SmoothedParameter___M__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State;
    struct VA__LadderLpfS__Internal__Coeffs;
    struct VA__LadderLpfS__Internal___M__State;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State;
    struct VA__SmoothedParameter___M_2__Coeffs;
    struct VA__SmoothedParameter___M_2__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State;
    struct VA__ApplyGain__Processor___State;
    struct VA__SmoothedParameter___M_4__Coeffs;
    struct VA__SmoothedParameter___M_4__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State;
    struct VA__DC_Blocker__Processor_2___State;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State;
    struct VA__DC_Blocker__Processor_3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State;
    struct VA__ApplyGains__Processor_2___State;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State;
    struct VA__ApplyGain__Processor_2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___State;
    struct VA__DC_Blocker__Processor_4___State;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___State;
    struct VA__DC_Blocker__Processor_5___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State;
    struct VA__ApplyGains__Processor_3___State;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State;
    struct VA__ApplyGain__Processor_3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___State;
    struct VA__DC_Blocker__Processor_6___State;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State;
    struct VA__Mux3To1Fs__Coeffs;
    struct VA__Mux3To1Fs__Processor___State;
    struct VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State;
    struct _State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___IO;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___IO;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___IO;
    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___IO;
    struct VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___IO;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___IO;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___IO;
    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___IO;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___IO;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___IO;
    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___IO;
    struct VA__DC_Blocker__Processor___IO;
    struct VA__DC_Blocker__Processor_2___IO;
    struct VA__DC_Blocker__Processor_3___IO;
    struct VA__DC_Blocker__Processor_4___IO;
    struct VA__DC_Blocker__Processor_5___IO;
    struct VA__DC_Blocker__Processor_6___IO;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___IO;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___IO;
    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___IO;
    struct VA__ApplyGain__Processor___IO;
    struct VA__ApplyGain__Processor_2___IO;
    struct VA__ApplyGain__Processor_3___IO;
    struct VA__ApplyGains__Processor___IO;
    struct VA__ApplyGains__Processor_2___IO;
    struct VA__ApplyGains__Processor_3___IO;
    struct VA__Mux3To1Fs__Processor___IO;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___IO;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___IO;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___IO;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___IO;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___IO;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___IO;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___IO;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___IO;
    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___IO;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___IO;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___IO;
    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___IO;
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
        std::array<const FloatType*, 2> inputChannels;
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

    void addInputEvent_depthIn (float eventValue)
    {
        _addInputEvent_depthIn_f32 (state, eventValue);
    }

    void addInputEvent_rateIn (float eventValue)
    {
        _addInputEvent_rateIn_f32 (state, eventValue);
    }

    void addInputEvent_widthIn (float eventValue)
    {
        _addInputEvent_widthIn_f32 (state, eventValue);
    }

    void addInputEvent_delayIn (float eventValue)
    {
        _addInputEvent_delayIn_f32 (state, eventValue);
    }

    void addInputEvent_modeIn (float eventValue)
    {
        _addInputEvent_modeIn_f32 (state, eventValue);
    }

    void addInputEvent_cutoffIn (float eventValue)
    {
        _addInputEvent_cutoffIn_f32 (state, eventValue);
    }

    void addInputEvent_mixIn (float eventValue)
    {
        _addInputEvent_mixIn_f32 (state, eventValue);
    }

    void addInputEvent_panIn (float eventValue)
    {
        _addInputEvent_panIn_f32 (state, eventValue);
    }

    void addInputEvent_makeupIn (float eventValue)
    {
        _addInputEvent_makeupIn_f32 (state, eventValue);
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

    std::array<EndpointDetails, 10> getInputEndpoints() const
    {
        return
        {
            EndpointDetails { "in",       "in:in",       EndpointType::stream, "float64<2>", 2, ""                                                                                                                                            },
            EndpointDetails { "depthIn",  "in:depthIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Depth\", \"min\": 0, \"max\": 100, \"init\": 50.0, \"unit\": \"%\", \"step\": 1, \"group\": \"Main\" }"                        },
            EndpointDetails { "rateIn",   "in:rateIn",   EndpointType::event,  "float32",    0, "{ \"name\": \"Rate\", \"min\": 0.1, \"max\": 4.0, \"init\": 2.0, \"unit\": \"Hz\", \"step\": 0.1, \"group\": \"Main\" }"                     },
            EndpointDetails { "widthIn",  "in:widthIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Width\", \"min\": -180, \"max\": 180, \"init\": 180.0, \"unit\": \"deg\", \"step\": 1, \"group\": \"Main\" }"                  },
            EndpointDetails { "delayIn",  "in:delayIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Min Delay\", \"min\": 0, \"max\": 35, \"init\": 3.0, \"unit\": \"ms\", \"step\": 1, \"group\": \"LFO\" }"                      },
            EndpointDetails { "modeIn",   "in:modeIn",   EndpointType::event,  "float32",    0, "{ \"name\": \"Waveform\", \"init\": 0, \"boolean\": true, \"text\": \"Tri|Sine\", \"group\": \"LFO\" }"                                      },
            EndpointDetails { "cutoffIn", "in:cutoffIn", EndpointType::event,  "float32",    0, "{ \"name\": \"Cutoff\", \"min\": 3000, \"max\": 18000, \"init\": 3000.0, \"unit\": \"Hz\", \"step\": 1, \"group\": \"BBD Ladder\" }"         },
            EndpointDetails { "mixIn",    "in:mixIn",    EndpointType::event,  "float32",    0, "{ \"name\": \"Mix\", \"min\": 0, \"max\": 100, \"init\": 50.0, \"unit\": \"%\", \"step\": 1, \"group\": \"Utility\" }"                       },
            EndpointDetails { "panIn",    "in:panIn",    EndpointType::event,  "float32",    0, "{ \"name\": \"Pan\", \"min\": -1, \"max\": 1, \"init\": 0.0, \"step\": 0.009999999776482582, \"group\": \"Utility\" }"                       },
            EndpointDetails { "makeupIn", "in:makeupIn", EndpointType::event,  "float32",    0, "{ \"name\": \"Makeup\", \"min\": -12, \"max\": 12, \"init\": 0.0, \"step\": 0.10000000149011612, \"unit\": \"dB\", \"group\": \"Utility\" }" }
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
    static constexpr uint32_t  numParameters = 9;

    static constexpr const std::array<const ParameterProperties, numParameters> parameters =
    {
        ParameterProperties {  "depthIn",   "Depth",      "%",    0.0f,     100.0f,    1.0f,   50.0f,    true,  false,  false,  "Main",        ""          },
        ParameterProperties {  "rateIn",    "Rate",       "Hz",   0.1f,     4.0f,      0.1f,   2.0f,     true,  false,  false,  "Main",        ""          },
        ParameterProperties {  "widthIn",   "Width",      "deg",  -180.0f,  180.0f,    1.0f,   180.0f,   true,  false,  false,  "Main",        ""          },
        ParameterProperties {  "delayIn",   "Min Delay",  "ms",   0.0f,     35.0f,     1.0f,   3.0f,     true,  false,  false,  "LFO",         ""          },
        ParameterProperties {  "modeIn",    "Waveform",   "",     0.0f,     1.0f,      1.0f,   0.0f,     true,  true,   false,  "LFO",         "Tri|Sine"  },
        ParameterProperties {  "cutoffIn",  "Cutoff",     "Hz",   3000.0f,  18000.0f,  1.0f,   3000.0f,  true,  false,  false,  "BBD Ladder",  ""          },
        ParameterProperties {  "mixIn",     "Mix",        "%",    0.0f,     100.0f,    1.0f,   50.0f,    true,  false,  false,  "Utility",     ""          },
        ParameterProperties {  "panIn",     "Pan",        "",     -1.0f,    1.0f,      0.01f,  0.0f,     true,  false,  false,  "Utility",     ""          },
        ParameterProperties {  "makeupIn",  "Makeup",     "dB",   -12.0f,   12.0f,     0.1f,   0.0f,     true,  false,  false,  "Utility",     ""          }
    };

    static span<const ParameterProperties> getParameterProperties() { return { parameters.data(), numParameters }; }

    static constexpr uint32_t numInputBuses  = 1;
    static constexpr uint32_t numOutputBuses = 1;

    static constexpr std::array<const AudioBus, numInputBuses>  inputBuses = { AudioBus { "in", 2 } };

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
                Parameter {  parameters[0],  50.0f,    [this] (float v) { addInputEvent_depthIn (v); }   },
                Parameter {  parameters[1],  2.0f,     [this] (float v) { addInputEvent_rateIn (v); }    },
                Parameter {  parameters[2],  180.0f,   [this] (float v) { addInputEvent_widthIn (v); }   },
                Parameter {  parameters[3],  3.0f,     [this] (float v) { addInputEvent_delayIn (v); }   },
                Parameter {  parameters[4],  0.0f,     [this] (float v) { addInputEvent_modeIn (v); }    },
                Parameter {  parameters[5],  3000.0f,  [this] (float v) { addInputEvent_cutoffIn (v); }  },
                Parameter {  parameters[6],  50.0f,    [this] (float v) { addInputEvent_mixIn (v); }     },
                Parameter {  parameters[7],  0.0f,     [this] (float v) { addInputEvent_panIn (v); }     },
                Parameter {  parameters[8],  0.0f,     [this] (float v) { addInputEvent_makeupIn (v); }  }
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

    struct VA__SmoothedParameter___M_5__Coeffs
    {
        FixedArray<Vector<double, 2>, 1> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M_5__State
    {
        FixedArray<Vector<double, 2>, 1> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_5__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_5__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Internal__Coeffs
    {
        Vector<double, 2> m_depth, m_phaseIncrement;
        int32_t m_mode;
    };

    struct VA__Lfo__Internal__State
    {
        Vector<double, 2> m_phase;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_rate, m_width, m_mode;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Lfo__Internal__Coeffs m_c;
        VA__Lfo__Internal__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State m_smoothedParameter0_state;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State m_internal_state;
    };

    struct VA__DelayLine___M__State
    {
        int32_t m_readPos, m_writePos;
        FixedArray<Vector<double, 2>, 1874> m_buf;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_delayMs;
        bool m_recalc;
        int32_t m_counter_1;
        VA__DelayLine___M__State m_s;
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

    struct VA__SmoothedParameter___M_3__Coeffs
    {
        FixedArray<Vector<double, 2>, 2> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M_3__State
    {
        FixedArray<Vector<double, 2>, 2> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_3__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_3__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__ApplyGains__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State m_smoothedGains_state;
        VA__ApplyGains__Processor___State m_applyGains_state;
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

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State
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

    struct VA__LadderLpfS__Internal__Coeffs
    {
        Vector<double, 2> m_g, m_k, m_N;
    };

    struct VA__LadderLpfS__Internal___M__State
    {
        FixedArray<Vector<double, 2>, 4> m_s;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter, 1>
        m_filterA, m_filterB;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_nonlinearity;
        bool m_recalc;
        int32_t m_counter_1;
        VA__LadderLpfS__Internal__Coeffs m_c;
        VA__LadderLpfS__Internal___M__State m_s;
        int32_t m_updateIntervalSamples;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2 m__in_src, m__G_OnepoleIn_src,
         m__kIn_src, m__out_src;
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

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State
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

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State m_smoothedParameter0_state;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State m_smoothedParameter1_state;
    };

    struct VA__ApplyGain__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedParameter___M_4__Coeffs
    {
        FixedArray<Vector<double, 2>, 1> m_target, m_increment;
    };

    struct VA__SmoothedParameter___M_4__State
    {
        FixedArray<Vector<double, 2>, 1> m_current;
        int32_t m_remainingRampSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_4__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_4__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor___State m_applyGain_state;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State m_smoothedGain_state;
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

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State m_lfo_state;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State m_delayLine_state;
        VA__DC_Blocker__Processor___State m_dcBlockerIn_state;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State m_smoothedMixPan_state;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State m_ladderLpfS_state;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State m_smoothedVolume_state;
        VA__DC_Blocker__Processor_2___State m_dcBlockerOut_state;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_5__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_5__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_rate, m_width, m_mode;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Lfo__Internal__Coeffs m_c;
        VA__Lfo__Internal__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State m_smoothedParameter0_state;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State m_internal_state;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_delayMs;
        bool m_recalc;
        int32_t m_counter_1;
        VA__DelayLine___M__State m_s;
        int32_t m_updateIntervalSamples;
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

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_3__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_3__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__ApplyGains__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State m_smoothedGains_state;
        VA__ApplyGains__Processor_2___State m_applyGains_state;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State
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

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter, 1>
        m_filterA, m_filterB;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_nonlinearity;
        bool m_recalc;
        int32_t m_counter_1;
        VA__LadderLpfS__Internal__Coeffs m_c;
        VA__LadderLpfS__Internal___M__State m_s;
        int32_t m_updateIntervalSamples;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2 m__in_src, m__G_OnepoleIn_src,
         m__kIn_src, m__out_src;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State
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

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State m_smoothedParameter0_state;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State m_smoothedParameter1_state;
    };

    struct VA__ApplyGain__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_4__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_4__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor_2___State m_applyGain_state;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State m_smoothedGain_state;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor_4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___State m_dcBlocker_state;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State m_lfo_state;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State m_delayLine_state;
        VA__DC_Blocker__Processor_3___State m_dcBlockerIn_state;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State m_smoothedMixPan_state;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State m_ladderLpfS_state;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State m_smoothedVolume_state;
        VA__DC_Blocker__Processor_4___State m_dcBlockerOut_state;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
        int32_t m__undersamplingCount;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_5__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_5__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_rate, m_width, m_mode;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Lfo__Internal__Coeffs m_c;
        VA__Lfo__Internal__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State m_smoothedParameter0_state;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State m_internal_state;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_delayMs;
        bool m_recalc;
        int32_t m_counter_1;
        VA__DelayLine___M__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor_5___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___State m_dcBlocker_state;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_3__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_3__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__ApplyGains__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State m_smoothedGains_state;
        VA__ApplyGains__Processor_3___State m_applyGains_state;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State
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

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2_filter, 1>
        m_filterA, m_filterB;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_nonlinearity;
        bool m_recalc;
        int32_t m_counter_1;
        VA__LadderLpfS__Internal__Coeffs m_c;
        VA__LadderLpfS__Internal___M__State m_s;
        int32_t m_updateIntervalSamples;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2 m__in_src, m__G_OnepoleIn_src,
         m__kIn_src, m__out_src;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State
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

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State m_smoothedParameter0_state;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State m_smoothedParameter1_state;
    };

    struct VA__ApplyGain__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 1> m_iParameter;
        FixedArray<float, 2> m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter___M_4__Coeffs m_c;
        Vector<double, 2> m_divMaxDelta;
        double m_fs;
        VA__SmoothedParameter___M_4__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor_3___State m_applyGain_state;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State m_smoothedGain_state;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Coeffs m_c;
        soul___filters__dc_blocker__State m_s;
    };

    struct VA__DC_Blocker__Processor_6___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___State m_dcBlocker_state;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4
    {
        FixedArray<Vector<double, 2>, 4> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter, 2> m_filterA, m_filterB;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State m_lfo_state;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State m_delayLine_state;
        VA__DC_Blocker__Processor_5___State m_dcBlockerIn_state;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State m_smoothedMixPan_state;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State m_ladderLpfS_state;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State m_smoothedVolume_state;
        VA__DC_Blocker__Processor_6___State m_dcBlockerOut_state;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4 m__in_src, m__out_src;
        int32_t m__undersamplingCount;
    };

    struct VA__Mux3To1Fs__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux3To1Fs__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Mux3To1Fs__Coeffs m_c;
    };

    struct VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State m_internalDS0_state;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State m_internalDS2_state;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State m_internalDS4_state;
        VA__Mux3To1Fs__Processor___State m_mux3To1Fs_state;
    };

    struct _State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId, m__framesToAdvance;
        _RenderStats m__renderStats;
        _SparseStreamStatus m__sparseStreamStatus;
        _Stream_in_vec_2_f64_1024 m__in_in;
        _Event_in_f32_1 m__in_depthIn, m__in_rateIn, m__in_widthIn, m__in_delayIn, m__in_modeIn, m__in_cutoffIn, m__in_mixIn, m__in_panIn, m__in_makeupIn;
        _Stream_out_vec_2_f64_1024 m__out_out;
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State m_e_state;
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

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___IO
    {
        Vector<double, 2> m__in_in, m__in_G_OnepoleIn, m__in_kIn, m__out_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___IO
    {
        Vector<double, 2> m__in_in, m__in_G_OnepoleIn, m__in_kIn, m__out_out;
    };

    struct VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___IO
    {
        Vector<double, 2> m__in_in, m__in_G_OnepoleIn, m__in_kIn, m__out_out;
    };

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
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

    struct VA__DC_Blocker__Processor_4___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DC_Blocker__Processor_5___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DC_Blocker__Processor_6___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___IO
    {
        Vector<double, 2> m__in_in, m__in_lfoIn, m__out_out;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___IO
    {
        Vector<double, 2> m__in_in, m__in_lfoIn, m__out_out;
    };

    struct VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___IO
    {
        Vector<double, 2> m__in_in, m__in_lfoIn, m__out_out;
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

    struct VA__ApplyGains__Processor___IO
    {
        Vector<double, 2> m__in_b, m__in_b1, m__in_in, m__in_in1, m__out_out;
    };

    struct VA__ApplyGains__Processor_2___IO
    {
        Vector<double, 2> m__in_b, m__in_b1, m__in_in, m__in_in1, m__out_out;
    };

    struct VA__ApplyGains__Processor_3___IO
    {
        Vector<double, 2> m__in_b, m__in_b1, m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux3To1Fs__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__out_out;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___IO
    {
        Vector<double, 2> m__in_depthIn, m__out_out;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___IO
    {
        Vector<double, 2> m__in_depthIn, m__out_out;
    };

    struct VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___IO
    {
        Vector<double, 2> m__in_depthIn, m__out_out;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___IO
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
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___IO _4 = {};

        _2 = _internal___minInt32 (1024, maxFrames);
        _updateRampingStreams (_state, _2);
        _state.m__frameCount = 0;
        _main_loop_check: { if (! (_state.m__frameCount < _2)) goto _exit; }
        _main_loop_body: { _3 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, _state.m__frameCount);
                           _4 = ZeroInitialiser();
                           _4.m__in_in = _3;
                           VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e__run (_state.m_e_state, _4);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_out, _state.m__frameCount, _4.m__out_out);
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
        _state.m_e_state.m__processorId = 59;
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___initialise (_state.m_e_state);
    }

    void _addInputEvent_depthIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___depthIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_rateIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___rateIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_widthIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___widthIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_delayIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___delayIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_modeIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___modeIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_cutoffIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___cutoffIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_mixIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___mixIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_panIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___panIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_makeupIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___makeupIn_f32 (_state.m_e_state, event);
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

    Vector<double, 2> soul__intrinsics___readLinearInterpolated_specialised (const FixedArray<Vector<double, 2>, 1874>& array, double index) noexcept
    {
        double _2 = {};
        double indexFloor = {};
        int32_t intIndex = {};
        Vector<double, 2> sample1 = {}, sample2 = {};

        _2 = soul__intrinsics___floor_specialised_2 (index);
        indexFloor = static_cast<double> (_2);
        intIndex = static_cast<int32_t> (static_cast<int32_t> (indexFloor));
        sample1 = static_cast<Vector<double, 2>> (array[_intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (intIndex), 1874)), 1874)), 1874)]);
        sample2 = static_cast<Vector<double, 2>> (array[_intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (intIndex + 1), 1874)), 1874)), 1874)]);
        return static_cast<Vector<double, 2>> (sample1 + ((sample2 - sample1) * static_cast<Vector<double, 2>> (Vector<double, 2> (index - static_cast<double> (indexFloor)))));
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

    Vector<double, 2> soul__intrinsics___tanh_specialised (Vector<double, 2> n) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = _vec_sinh (n);
        _3 = _vec_cosh (n);
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

    double soul__intrinsics___floor_specialised_2 (double n) noexcept
    {
        double r = {}, _2 = {};
        double _3 = {}, _4 = {}, _5 = {}, _T1 = {}, _T0 = {};

        r = static_cast<double> (static_cast<double> (static_cast<int64_t> (n)));
        if (! (r == static_cast<double> (n))) goto _ternary_false_0;
        _ternary_true_0: { _3 = n;
                           _T0 = _3;
                           goto _ternary_end_0;
        }
        _ternary_false_0: { if (! (n >= 0)) goto _ternary_false_1; }
        _ternary_true_1: { _T1 = r;
        goto _ternary_end_1; }
        _ternary_false_1: { _2 = r - 1.0;
                            _T1 = _2;
        }
        _ternary_end_1: { _4 = _T1;
                          _T0 = _4;
        }
        _ternary_end_0: { _5 = _T0;
                          return _5;
        }
    }

    Vector<double, 2> soul__intrinsics___sinh_specialised (Vector<double, 2> n) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = _vec_exp (n);
        _3 = _vec_exp (-n);
        return (_2 - _3) / Vector<double, 2> { { 2.0, 2.0 } };
    }

    Vector<double, 2> soul__intrinsics___cosh_specialised (Vector<double, 2> n) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = _vec_exp (n);
        _3 = _vec_exp (-n);
        return (_2 + _3) / Vector<double, 2> { { 2.0, 2.0 } };
    }

    Vector<double, 2> soul__intrinsics___exp_specialised_2 (Vector<double, 2> n) noexcept
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
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 0.5), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 0.5), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 0.25), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker__run (soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___State& _state, soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___IO&
    _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    soul___filters__dc_blocker__update (_state.m_c, (sampleRate * 0.25), 1.0);
        }
        _body_0: { _2 = _io.m__in_in;
                   _3 = soul___filters__dc_blocker__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    Vector<double, 2> VA__vBBD (Vector<double, 2> x, Vector<double, 2> b) noexcept
    {
        Vector<double, 2> c1 = {}, c2 = {};
        Vector<double, 2> _2 = {}, _3 = {};

        c1 = static_cast<Vector<double, 2>> (b * Vector<double, 2> { { 0.125, 0.125 } });
        c2 = static_cast<Vector<double, 2>> (b * Vector<double, 2> { { 0.0625, 0.0625 } });
        _2 = VA___vpow_specialised (x, 2);
        _3 = VA___vpow_specialised (x, 3);
        return (x - static_cast<Vector<double, 2>> (c1 * static_cast<Vector<double, 2>> (_2))) - static_cast<Vector<double, 2>> (c2 * static_cast<Vector<double, 2>> (_3));
    }

    Vector<double, 2> VA__vCutoffToG_Onepole (float x, double fs) noexcept
    {
        Vector<double, 2> Tpi = {}, gOnepole = {};
        Vector<double, 2> _2 = {};

        Tpi = static_cast<Vector<double, 2>> (Vector<double, 2> (3.141592653589793 / fs));
        _2 = _vec_tanh (Vector<double, 2> (x) * static_cast<Vector<double, 2>> (Tpi));
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

    double VA__vmaxr (Vector<double, 2> x) noexcept
    {
        double _2 = {};

        _2 = soul__intrinsics___max_specialised (x[0], x[1]);
        return _2;
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
    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___initialise (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state) noexcept
    {
        _state.m_lfo_state.m__arrayEntry = 0;
        _state.m_lfo_state.m__sessionID = _state.m__sessionID;
        _state.m_lfo_state.m__processorId = 1;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___initialise (_state.m_lfo_state);
        _state.m_delayLine_state.m__arrayEntry = 0;
        _state.m_delayLine_state.m__sessionID = _state.m__sessionID;
        _state.m_delayLine_state.m__processorId = 2;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___initialise (_state.m_delayLine_state);
        _state.m_dcBlockerIn_state.m__arrayEntry = 0;
        _state.m_dcBlockerIn_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerIn_state.m__processorId = 3;
        VA__DC_Blocker__Processor___initialise (_state.m_dcBlockerIn_state);
        _state.m_smoothedMixPan_state.m__arrayEntry = 0;
        _state.m_smoothedMixPan_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedMixPan_state.m__processorId = 4;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___initialise (_state.m_smoothedMixPan_state);
        _state.m_ladderLpfS_state.m__arrayEntry = 0;
        _state.m_ladderLpfS_state.m__sessionID = _state.m__sessionID;
        _state.m_ladderLpfS_state.m__processorId = 5;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___initialise (_state.m_ladderLpfS_state);
        _state.m_smoothedVolume_state.m__arrayEntry = 0;
        _state.m_smoothedVolume_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedVolume_state.m__processorId = 6;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___initialise (_state.m_smoothedVolume_state);
        _state.m_dcBlockerOut_state.m__arrayEntry = 0;
        _state.m_dcBlockerOut_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerOut_state.m__processorId = 7;
        VA__DC_Blocker__Processor_2___initialise (_state.m_dcBlockerOut_state);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0__run (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State& _state,
     VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__DC_Blocker__Processor___IO _3 = {};
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___IO _4 = {};
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___IO _5 = {};
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___IO _6 = {};
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___IO _7 = {};
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___IO _8 = {};
        VA__DC_Blocker__Processor_2___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__DC_Blocker__Processor__run (_state.m_dcBlockerIn_state, _3);
        _4 = ZeroInitialiser();
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo__run (_state.m_lfo_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _3.m__out_out;
        _5.m__in_lfoIn = _4.m__out_out;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine__run (_state.m_delayLine_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS__run (_state.m_ladderLpfS_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_out;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume__run (_state.m_smoothedVolume_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _3.m__out_out;
        _8.m__in_in1 = _7.m__out_out;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan__run (_state.m_smoothedMixPan_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_out;
        VA__DC_Blocker__Processor_2__run (_state.m_dcBlockerOut_state, _9);
        _io.m__out_out = _9.m__out_out;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___depthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___depthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___rateIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___rateIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___widthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___widthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___modeIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___modeIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___delayIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___delayIn_f32 (_state.m_delayLine_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___cutoffIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___cutoffIn_f32 (_state.m_ladderLpfS_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___makeupIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___volumeIn_f32 (_state.m_smoothedVolume_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___mixIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___mixIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___panIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___panIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    //==============================================================================
    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___initialise (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state) noexcept
    {
        _state.m_lfo_state.m__arrayEntry = 0;
        _state.m_lfo_state.m__sessionID = _state.m__sessionID;
        _state.m_lfo_state.m__processorId = 8;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___initialise (_state.m_lfo_state);
        _state.m_delayLine_state.m__arrayEntry = 0;
        _state.m_delayLine_state.m__sessionID = _state.m__sessionID;
        _state.m_delayLine_state.m__processorId = 9;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___initialise (_state.m_delayLine_state);
        _state.m_dcBlockerIn_state.m__arrayEntry = 0;
        _state.m_dcBlockerIn_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerIn_state.m__processorId = 10;
        VA__DC_Blocker__Processor_3___initialise (_state.m_dcBlockerIn_state);
        _state.m_smoothedMixPan_state.m__arrayEntry = 0;
        _state.m_smoothedMixPan_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedMixPan_state.m__processorId = 11;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___initialise (_state.m_smoothedMixPan_state);
        _state.m_ladderLpfS_state.m__arrayEntry = 0;
        _state.m_ladderLpfS_state.m__sessionID = _state.m__sessionID;
        _state.m_ladderLpfS_state.m__processorId = 12;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___initialise (_state.m_ladderLpfS_state);
        _state.m_smoothedVolume_state.m__arrayEntry = 0;
        _state.m_smoothedVolume_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedVolume_state.m__processorId = 13;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___initialise (_state.m_smoothedVolume_state);
        _state.m_dcBlockerOut_state.m__arrayEntry = 0;
        _state.m_dcBlockerOut_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerOut_state.m__processorId = 14;
        VA__DC_Blocker__Processor_4___initialise (_state.m_dcBlockerOut_state);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2__run (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State& _state,
     VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__DC_Blocker__Processor_3___IO _3 = {};
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___IO _4 = {};
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___IO _5 = {};
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___IO _6 = {};
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___IO _7 = {};
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___IO _8 = {};
        VA__DC_Blocker__Processor_4___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__DC_Blocker__Processor_3__run (_state.m_dcBlockerIn_state, _3);
        _4 = ZeroInitialiser();
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo__run (_state.m_lfo_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _3.m__out_out;
        _5.m__in_lfoIn = _4.m__out_out;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine__run (_state.m_delayLine_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS__run (_state.m_ladderLpfS_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_out;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume__run (_state.m_smoothedVolume_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _3.m__out_out;
        _8.m__in_in1 = _7.m__out_out;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan__run (_state.m_smoothedMixPan_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_out;
        VA__DC_Blocker__Processor_4__run (_state.m_dcBlockerOut_state, _9);
        _io.m__out_out = _9.m__out_out;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___depthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___depthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___rateIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___rateIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___widthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___widthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___modeIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___modeIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___delayIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___delayIn_f32 (_state.m_delayLine_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___cutoffIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___cutoffIn_f32 (_state.m_ladderLpfS_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___makeupIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___volumeIn_f32 (_state.m_smoothedVolume_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___mixIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___mixIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___panIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___panIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___run_undersampled (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___IO& _io) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___downsamplerWrite (_state.m__in_src, _io.m__in_in);
        if (! (_state.m__undersamplingCount == 0)) goto _continue;
        _process_block: { VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___downsamplerRead (_state.m__in_src, _io.m__in_in);
                          VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2__run (_state, _io);
                          VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___upsamplerWrite (_state.m__out_src, _io.m__out_out);
        }
        _continue: { _state.m__undersamplingCount = _internal___wrapInt32 (_state.m__undersamplingCount + 1, 2);
                     VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___upsamplerRead (_state.m__out_src, _io.m__out_out);
        }
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___downsamplerWrite (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___downsamplerRead (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2>& output) noexcept
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

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___upsamplerWrite (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2> input) noexcept
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

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___upsamplerRead (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    //==============================================================================
    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___initialise (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state) noexcept
    {
        _state.m_lfo_state.m__arrayEntry = 0;
        _state.m_lfo_state.m__sessionID = _state.m__sessionID;
        _state.m_lfo_state.m__processorId = 15;
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___initialise (_state.m_lfo_state);
        _state.m_delayLine_state.m__arrayEntry = 0;
        _state.m_delayLine_state.m__sessionID = _state.m__sessionID;
        _state.m_delayLine_state.m__processorId = 16;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___initialise (_state.m_delayLine_state);
        _state.m_dcBlockerIn_state.m__arrayEntry = 0;
        _state.m_dcBlockerIn_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerIn_state.m__processorId = 17;
        VA__DC_Blocker__Processor_5___initialise (_state.m_dcBlockerIn_state);
        _state.m_smoothedMixPan_state.m__arrayEntry = 0;
        _state.m_smoothedMixPan_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedMixPan_state.m__processorId = 18;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___initialise (_state.m_smoothedMixPan_state);
        _state.m_ladderLpfS_state.m__arrayEntry = 0;
        _state.m_ladderLpfS_state.m__sessionID = _state.m__sessionID;
        _state.m_ladderLpfS_state.m__processorId = 19;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___initialise (_state.m_ladderLpfS_state);
        _state.m_smoothedVolume_state.m__arrayEntry = 0;
        _state.m_smoothedVolume_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedVolume_state.m__processorId = 20;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___initialise (_state.m_smoothedVolume_state);
        _state.m_dcBlockerOut_state.m__arrayEntry = 0;
        _state.m_dcBlockerOut_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlockerOut_state.m__processorId = 21;
        VA__DC_Blocker__Processor_6___initialise (_state.m_dcBlockerOut_state);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4__run (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State& _state,
     VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__DC_Blocker__Processor_5___IO _3 = {};
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___IO _4 = {};
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___IO _5 = {};
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___IO _6 = {};
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___IO _7 = {};
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___IO _8 = {};
        VA__DC_Blocker__Processor_6___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__DC_Blocker__Processor_5__run (_state.m_dcBlockerIn_state, _3);
        _4 = ZeroInitialiser();
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo__run (_state.m_lfo_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _3.m__out_out;
        _5.m__in_lfoIn = _4.m__out_out;
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine__run (_state.m_delayLine_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS__run (_state.m_ladderLpfS_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_out;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume__run (_state.m_smoothedVolume_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _3.m__out_out;
        _8.m__in_in1 = _7.m__out_out;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan__run (_state.m_smoothedMixPan_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_out;
        VA__DC_Blocker__Processor_6__run (_state.m_dcBlockerOut_state, _9);
        _io.m__out_out = _9.m__out_out;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___depthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___depthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___rateIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___rateIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___widthIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___widthIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___modeIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___modeIn_f32 (_state.m_lfo_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___delayIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___delayIn_f32 (_state.m_delayLine_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___cutoffIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___cutoffIn_f32 (_state.m_ladderLpfS_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___makeupIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___volumeIn_f32 (_state.m_smoothedVolume_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___mixIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___mixIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___panIn_f32 (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___panIn_f32 (_state.m_smoothedMixPan_state, event);
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___run_undersampled (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___IO& _io) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___downsamplerWrite (_state.m__in_src, _io.m__in_in);
        if (! (_state.m__undersamplingCount == 0)) goto _continue;
        _process_block: { VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___downsamplerRead (_state.m__in_src, _io.m__in_in);
                          VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4__run (_state, _io);
                          VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___upsamplerWrite (_state.m__out_src, _io.m__out_out);
        }
        _continue: { _state.m__undersamplingCount = _internal___wrapInt32 (_state.m__undersamplingCount + 1, 4);
                     VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___upsamplerRead (_state.m__out_src, _io.m__out_out);
        }
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___downsamplerWrite (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___downsamplerRead (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    src, Vector<double, 2>& output) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _9 = {}, _10 = {}, _11 = {}, _12 = {}, _13 = {}, _14 = {}, _15 = {}, _16 = {}, _17 = {}, _18 = {}, _19 = {}, _20 = {}, _21 = {};

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
        _8 = (_4 + _7) * Vector<double, 2> { { 0.5, 0.5 } };
        _9 = src.m_filterA[0].m_in + ((src.m_buffer[3] - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _10 = src.m_filterA[0].m_out[0] + ((_9 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _11 = src.m_filterA[0].m_out[1] + ((_10 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = src.m_buffer[3];
        src.m_filterA[0].m_out[0] = _9;
        src.m_filterA[0].m_out[1] = _10;
        src.m_filterA[0].m_out[2] = _11;
        _12 = src.m_filterB[0].m_in + ((src.m_buffer[2] - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _13 = src.m_filterB[0].m_out[0] + ((_12 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _14 = src.m_filterB[0].m_out[1] + ((_13 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = src.m_buffer[2];
        src.m_filterB[0].m_out[0] = _12;
        src.m_filterB[0].m_out[1] = _13;
        src.m_filterB[0].m_out[2] = _14;
        _15 = (_11 + _14) * Vector<double, 2> { { 0.5, 0.5 } };
        _16 = src.m_filterA[1].m_in + ((_15 - src.m_filterA[1].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _17 = src.m_filterA[1].m_out[0] + ((_16 - src.m_filterA[1].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _18 = src.m_filterA[1].m_out[1] + ((_17 - src.m_filterA[1].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[1].m_in = _15;
        src.m_filterA[1].m_out[0] = _16;
        src.m_filterA[1].m_out[1] = _17;
        src.m_filterA[1].m_out[2] = _18;
        _19 = src.m_filterB[1].m_in + ((_8 - src.m_filterB[1].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _20 = src.m_filterB[1].m_out[0] + ((_19 - src.m_filterB[1].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _21 = src.m_filterB[1].m_out[1] + ((_20 - src.m_filterB[1].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[1].m_in = _8;
        src.m_filterB[1].m_out[0] = _19;
        src.m_filterB[1].m_out[1] = _20;
        src.m_filterB[1].m_out[2] = _21;
        output = (_18 + _21) * Vector<double, 2> { { 0.5, 0.5 } };
        src.m_bufferPos = 0;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___upsamplerWrite (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    src, Vector<double, 2> input) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _9 = {}, _10 = {}, _11 = {}, _12 = {}, _13 = {}, _14 = {}, _15 = {}, _16 = {}, _17 = {}, _18 = {}, _19 = {};

        _2 = src.m_filterA[0].m_in + ((input - src.m_filterA[0].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _3 = src.m_filterA[0].m_out[0] + ((_2 - src.m_filterA[0].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _4 = src.m_filterA[0].m_out[1] + ((_3 - src.m_filterA[0].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[0].m_in = input;
        src.m_filterA[0].m_out[0] = _2;
        src.m_filterA[0].m_out[1] = _3;
        src.m_filterA[0].m_out[2] = _4;
        _5 = src.m_filterB[0].m_in + ((input - src.m_filterB[0].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _6 = src.m_filterB[0].m_out[0] + ((_5 - src.m_filterB[0].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _7 = src.m_filterB[0].m_out[1] + ((_6 - src.m_filterB[0].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[0].m_in = input;
        src.m_filterB[0].m_out[0] = _5;
        src.m_filterB[0].m_out[1] = _6;
        src.m_filterB[0].m_out[2] = _7;
        _8 = src.m_filterA[1].m_in + ((_4 - src.m_filterA[1].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _9 = src.m_filterA[1].m_out[0] + ((_8 - src.m_filterA[1].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _10 = src.m_filterA[1].m_out[1] + ((_9 - src.m_filterA[1].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[1].m_in = _4;
        src.m_filterA[1].m_out[0] = _8;
        src.m_filterA[1].m_out[1] = _9;
        src.m_filterA[1].m_out[2] = _10;
        src.m_buffer[0] = _10;
        _11 = src.m_filterB[1].m_in + ((_4 - src.m_filterB[1].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _12 = src.m_filterB[1].m_out[0] + ((_11 - src.m_filterB[1].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _13 = src.m_filterB[1].m_out[1] + ((_12 - src.m_filterB[1].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[1].m_in = _4;
        src.m_filterB[1].m_out[0] = _11;
        src.m_filterB[1].m_out[1] = _12;
        src.m_filterB[1].m_out[2] = _13;
        src.m_buffer[1] = _13;
        _14 = src.m_filterA[1].m_in + ((_7 - src.m_filterA[1].m_out[0]) * Vector<double, 2> { { 0.039151597768068317, 0.039151597768068317 } });
        _15 = src.m_filterA[1].m_out[0] + ((_14 - src.m_filterA[1].m_out[1]) * Vector<double, 2> { { 0.30264684557914736, 0.30264684557914736 } });
        _16 = src.m_filterA[1].m_out[1] + ((_15 - src.m_filterA[1].m_out[2]) * Vector<double, 2> { { 0.6746159195899963, 0.6746159195899963 } });
        src.m_filterA[1].m_in = _7;
        src.m_filterA[1].m_out[0] = _14;
        src.m_filterA[1].m_out[1] = _15;
        src.m_filterA[1].m_out[2] = _16;
        src.m_buffer[2] = _16;
        _17 = src.m_filterB[1].m_in + ((_7 - src.m_filterB[1].m_out[0]) * Vector<double, 2> { { 0.1473771184682846, 0.1473771184682846 } });
        _18 = src.m_filterB[1].m_out[0] + ((_17 - src.m_filterB[1].m_out[1]) * Vector<double, 2> { { 0.48246854543685915, 0.48246854543685915 } });
        _19 = src.m_filterB[1].m_out[1] + ((_18 - src.m_filterB[1].m_out[2]) * Vector<double, 2> { { 0.8830050230026245, 0.8830050230026245 } });
        src.m_filterB[1].m_in = _7;
        src.m_filterB[1].m_out[0] = _17;
        src.m_filterB[1].m_out[1] = _18;
        src.m_filterB[1].m_out[2] = _19;
        src.m_buffer[3] = _19;
        src.m_bufferPos = 0;
    }

    void VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___upsamplerRead (VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    //==============================================================================
    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___initialise (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state) noexcept
    {
        _state.m_internalDS0_state.m__arrayEntry = 0;
        _state.m_internalDS0_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS0_state.m__processorId = 22;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___initialise (_state.m_internalDS0_state);
        _state.m_internalDS2_state.m__arrayEntry = 0;
        _state.m_internalDS2_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS2_state.m__processorId = 23;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___initialise (_state.m_internalDS2_state);
        _state.m_internalDS4_state.m__arrayEntry = 0;
        _state.m_internalDS4_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS4_state.m__processorId = 24;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___initialise (_state.m_internalDS4_state);
        _state.m_mux3To1Fs_state.m__arrayEntry = 0;
        _state.m_mux3To1Fs_state.m__sessionID = _state.m__sessionID;
        _state.m_mux3To1Fs_state.m__processorId = 25;
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e__run (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___IO _3 = {};
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___IO _4 = {};
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___IO _5 = {};
        VA__Mux3To1Fs__Processor___IO _6 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0__run (_state.m_internalDS0_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___run_undersampled (_state.m_internalDS2_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___run_undersampled (_state.m_internalDS4_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _3.m__out_out;
        _6.m__in_in1 = _4.m__out_out;
        _6.m__in_in2 = _5.m__out_out;
        VA__Mux3To1Fs__Processor__run (_state.m_mux3To1Fs_state, _6);
        _io.m__out_out = _6.m__out_out;
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___depthIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___depthIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___depthIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___depthIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___rateIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___rateIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___rateIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___rateIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___widthIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___widthIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___widthIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___widthIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___modeIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___modeIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___modeIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___modeIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___delayIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___delayIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___delayIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___delayIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___cutoffIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___cutoffIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___cutoffIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___cutoffIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___makeupIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___makeupIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___makeupIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___makeupIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___mixIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___mixIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___mixIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___mixIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___panIn_f32 (VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0___panIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2___panIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4___panIn_f32 (_state.m_internalDS4_state, event);
    }

    //==============================================================================
    void VA__LadderLpfS__Internal__updatePerSample (VA__LadderLpfS__Internal__Coeffs& c, Vector<double, 2> G_Onepole, Vector<double, 2> k) noexcept
    {
        c.m_g = G_Onepole;
        c.m_k = k;
    }

    //==============================================================================
    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal__run (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 2.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__LadderLpfS__Internal___M__update (_state.m_c, _state.m_nonlinearity, _state.m_s, (sampleRate * 2.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_G_OnepoleIn;
                   _3 = _io.m__in_kIn;
                   VA__LadderLpfS__Internal__updatePerSample (_state.m_c, _2, _3);
                   _4 = _io.m__in_in;
                   _5 = VA__LadderLpfS__Internal___M__process (_state.m_s, _4, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___initialise (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State&
    _state) noexcept
    {
        _state.m_nonlinearity = 0.5f;
        _state.m_recalc = true;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___run_oversampled (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___IO& _io) noexcept
    {
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerWrite (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerWrite (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___downsamplerRead (_state.m__out_src, _io.m__out_out);

    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2> input) noexcept
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

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___upsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___downsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___downsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2>& output) noexcept
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
    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal__run (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__LadderLpfS__Internal___M__update (_state.m_c, _state.m_nonlinearity, _state.m_s, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_G_OnepoleIn;
                   _3 = _io.m__in_kIn;
                   VA__LadderLpfS__Internal__updatePerSample (_state.m_c, _2, _3);
                   _4 = _io.m__in_in;
                   _5 = VA__LadderLpfS__Internal___M__process (_state.m_s, _4, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___initialise (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State&
    _state) noexcept
    {
        _state.m_nonlinearity = 0.5f;
        _state.m_recalc = true;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___run_oversampled (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___IO& _io) noexcept
    {
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerWrite (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerWrite (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___downsamplerRead (_state.m__out_src, _io.m__out_out);

    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2> input) noexcept
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

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___upsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___downsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___downsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2>& output) noexcept
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
    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal__run (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__LadderLpfS__Internal___M__update (_state.m_c, _state.m_nonlinearity, _state.m_s, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_G_OnepoleIn;
                   _3 = _io.m__in_kIn;
                   VA__LadderLpfS__Internal__updatePerSample (_state.m_c, _2, _3);
                   _4 = _io.m__in_in;
                   _5 = VA__LadderLpfS__Internal___M__process (_state.m_s, _4, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___initialise (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State&
    _state) noexcept
    {
        _state.m_nonlinearity = 0.5f;
        _state.m_recalc = true;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___run_oversampled (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___State&
    _state, VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___IO& _io) noexcept
    {
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerWrite (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerWrite (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__G_OnepoleIn_src, _io.m__in_G_OnepoleIn);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (_state.m__kIn_src, _io.m__in_kIn);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal__run (_state, _io);
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___downsamplerWrite (_state.m__out_src, _io.m__out_out);

        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___downsamplerRead (_state.m__out_src, _io.m__out_out);

    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2> input) noexcept
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

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___upsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___downsamplerWrite (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___downsamplerRead (VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___SampleRateConverter_vec_2_f64_2&
    src, Vector<double, 2>& output) noexcept
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
    void VA__LadderLpfS__Internal___M__update (VA__LadderLpfS__Internal__Coeffs& c, float nonlinearity, VA__LadderLpfS__Internal___M__State& s, double fs) noexcept
    {
        c.m_N = Vector<double, 2> ((static_cast<float> (88200.0 / fs) * nonlinearity) * (1.0f + static_cast<float> (c.m_k[0])));
    }

    Vector<double, 2> VA__LadderLpfS__Internal___M__process (VA__LadderLpfS__Internal___M__State& s, Vector<double, 2> x, const VA__LadderLpfS__Internal__Coeffs& c) noexcept
    {
        Vector<double, 2> S = {}, G = {}, y = {}, _2 = {};
        int32_t i = {}, _3 = {}, i_2 = {}, _4 = {};
        Vector<double, 2> v = {};

        S = ZeroInitialiser();
        G = Vector<double, 2> { { 1.0, 1.0 } };
        i = 3;
        _loop_0: { if (! (i > -1)) goto _break_0; }
        _body_0: { S = S + (G * s.m_s[_intrin_wrap (static_cast<int32_t> (i), 4) & 3]);
                   G = G * c.m_g;
                   _3 = i;
                   i = _3 - 1;
                   goto _loop_0;
        }
        _break_0: { y = (x - (c.m_k * S)) / static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } + static_cast<Vector<double, 2>> (c.m_k * G));
                    i_2 = 0;
        }
        _loop_1: { if (! (i_2 < 4)) goto _break_1; }
        _body_1: { v = static_cast<Vector<double, 2>> ((y - s.m_s[_intrin_wrap (static_cast<int32_t> (i_2), 4) & 3]) * c.m_g);
                   _2 = VA__vBBD (static_cast<Vector<double, 2>> (v + static_cast<Vector<double, 2>> (s.m_s[_intrin_wrap (static_cast<int32_t> (i_2), 4) & 3])), c.m_N);
                   y = _2;
                   s.m_s[_intrin_wrap (static_cast<int32_t> (i_2), 4) & 3] = static_cast<Vector<double, 2>> (v + static_cast<Vector<double, 2>> (y));
                   _4 = i_2;
                   i_2 = _4 + 1;
                   goto _loop_1;
        }
        _break_1: { return y * static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } + static_cast<Vector<double, 2>> (c.m_k)); }
    }

    //==============================================================================
    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___initialise (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 26;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 27;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___initialise (_state.m_internal_state);
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 28;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS__run (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State&
    _state, VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___IO _4 = {};
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_G_OnepoleIn = _3.m__out_out;
        _5.m__in_kIn = _4.m__out_out;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_internal___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___cutoffIn_f32 (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);

    }

    //==============================================================================
    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___initialise (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 29;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 30;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___initialise (_state.m_internal_state);
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 31;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS__run (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State&
    _state, VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___IO _4 = {};
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_G_OnepoleIn = _3.m__out_out;
        _5.m__in_kIn = _4.m__out_out;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_internal___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___cutoffIn_f32 (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);

    }

    //==============================================================================
    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___initialise (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 32;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 33;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___initialise (_state.m_internal_state);
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 34;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS__run (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State&
    _state, VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___IO _4 = {};
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_G_OnepoleIn = _3.m__out_out;
        _5.m__in_kIn = _4.m__out_out;
        VA__LadderLpfS__Internal__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_internal___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___cutoffIn_f32 (VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);

    }

    //==============================================================================
    void VA__DC_Blocker__Processor___initialise (VA__DC_Blocker__Processor___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 35;
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
        _state.m_dcBlocker_state.m__processorId = 36;
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
        _state.m_dcBlocker_state.m__processorId = 37;
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
    void VA__DC_Blocker__Processor_4___initialise (VA__DC_Blocker__Processor_4___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 38;
    }

    void VA__DC_Blocker__Processor_4__run (VA__DC_Blocker__Processor_4___State& _state, VA__DC_Blocker__Processor_4___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_4_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__DC_Blocker__Processor_5___initialise (VA__DC_Blocker__Processor_5___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 39;
    }

    void VA__DC_Blocker__Processor_5__run (VA__DC_Blocker__Processor_5___State& _state, VA__DC_Blocker__Processor_5___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_5_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__DC_Blocker__Processor_6___initialise (VA__DC_Blocker__Processor_6___State& _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 40;
    }

    void VA__DC_Blocker__Processor_6__run (VA__DC_Blocker__Processor_6___State& _state, VA__DC_Blocker__Processor_6___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_6_dcBlocker__run (_state.m_dcBlocker_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___delayIn_f32 (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State&
    _state, float v) noexcept
    {
        _state.m_delayMs = v;
        _state.m_recalc = true;
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine__run (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State&
    _state, VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _check_terminate: { if (_resumePoint == -1) goto _exit; }
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
                    if (! ((sampleRate * 1.0) < 48001.0)) goto _ifnot_0;
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_1; }
        _if_1: { _state.m_recalc = false;
                 VA__DelayLine___M__update (_state.m_s, _state.m_delayMs, (sampleRate * 1.0));
        }
        _ifnot_1: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = _io.m__in_lfoIn;
                   _4 = VA__DelayLine___M__process (_state.m_s, _2, _3, (sampleRate * 1.0));
                   out_value_out = out_value_out + _4;
                   _state.m__resumePoint = 1;
                   goto _exit;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
        _ifnot_0: { _state.m__resumePoint = -1; }
        _exit: { _io.m__out_out = out_value_out; }
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___initialise (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_delayLine___State&
    _state) noexcept
    {
        _state.m_delayMs = 3.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___delayIn_f32 (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State&
    _state, float v) noexcept
    {
        _state.m_delayMs = v;
        _state.m_recalc = true;
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine__run (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State&
    _state, VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _check_terminate: { if (_resumePoint == -1) goto _exit; }
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    if (! ((sampleRate * 0.5) < 48001.0)) goto _ifnot_0;
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_1; }
        _if_1: { _state.m_recalc = false;
                 VA__DelayLine___M__update (_state.m_s, _state.m_delayMs, (sampleRate * 0.5));
        }
        _ifnot_1: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = _io.m__in_lfoIn;
                   _4 = VA__DelayLine___M__process (_state.m_s, _2, _3, (sampleRate * 0.5));
                   out_value_out = out_value_out + _4;
                   _state.m__resumePoint = 1;
                   goto _exit;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
        _ifnot_0: { _state.m__resumePoint = -1; }
        _exit: { _io.m__out_out = out_value_out; }
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___initialise (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_delayLine___State&
    _state) noexcept
    {
        _state.m_delayMs = 3.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___delayIn_f32 (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State&
    _state, float v) noexcept
    {
        _state.m_delayMs = v;
        _state.m_recalc = true;
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine__run (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State&
    _state, VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _check_terminate: { if (_resumePoint == -1) goto _exit; }
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    if (! ((sampleRate * 0.25) < 48001.0)) goto _ifnot_0;
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_1; }
        _if_1: { _state.m_recalc = false;
                 VA__DelayLine___M__update (_state.m_s, _state.m_delayMs, (sampleRate * 0.25));
        }
        _ifnot_1: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _3 = _io.m__in_lfoIn;
                   _4 = VA__DelayLine___M__process (_state.m_s, _2, _3, (sampleRate * 0.25));
                   out_value_out = out_value_out + _4;
                   _state.m__resumePoint = 1;
                   goto _exit;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
        _ifnot_0: { _state.m__resumePoint = -1; }
        _exit: { _io.m__out_out = out_value_out; }
    }

    void VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___initialise (VA__DelayLine__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_delayLine___State&
    _state) noexcept
    {
        _state.m_delayMs = 3.0f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__DelayLine___M__update (VA__DelayLine___M__State& s, float delayMs, double fs) noexcept
    {
        double fsDiv1k = {};

        fsDiv1k = static_cast<double> (fs / 1000.0);
        s.m_readPos = _intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (static_cast<int32_t> (s.m_writePos) - static_cast<int32_t> (fsDiv1k * static_cast<double> (delayMs))), 1874)), 1874)), 1874);
    }

    Vector<double, 2> VA__DelayLine___M__process (VA__DelayLine___M__State& s, Vector<double, 2> x, Vector<double, 2> lfo, double fs) noexcept
    {
        double maxDepthSamples = {};
        Vector<double, 2> _2 = {}, _3 = {};
        Vector<double, 2> l = {}, r = {}, y = {};
        int32_t _4 = {}, _5 = {};

        maxDepthSamples = static_cast<double> ((4.0 * fs) / 1000.0);
        s.m_buf[s.m_writePos] = x;
        _2 = soul__intrinsics___readLinearInterpolated_specialised (s.m_buf, static_cast<double> (s.m_readPos) - static_cast<double> (maxDepthSamples * static_cast<double> (lfo[0])));
        l = static_cast<Vector<double, 2>> (_2);
        _3 = soul__intrinsics___readLinearInterpolated_specialised (s.m_buf, static_cast<double> (s.m_readPos) - static_cast<double> (maxDepthSamples * static_cast<double> (lfo[1])));
        r = static_cast<Vector<double, 2>> (_3);
        y = (l * Vector<double, 2> { { 1.0, 0 } }) + (r * Vector<double, 2> { { 0, 1.0 } });
        _4 = s.m_readPos;
        s.m_readPos = _intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_4 + 1), 1874)), 1874);
        _5 = s.m_writePos;
        s.m_writePos = _intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_5 + 1), 1874)), 1874);
        return static_cast<Vector<double, 2>> (y);
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
    void VA__ApplyGains__Processor_2__run (VA__ApplyGains__Processor_2___State& _state, VA__ApplyGains__Processor_2___IO& _io) noexcept
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
    void VA__ApplyGains__Processor_3__run (VA__ApplyGains__Processor_3___State& _state, VA__ApplyGains__Processor_3___IO& _io) noexcept
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
    void VA__Mux3To1Fs__update (VA__Mux3To1Fs__Coeffs& c, double fs) noexcept
    {
        if (! (fs > 96001.0)) goto _ifnot_0;
        _if_0: { c.m_idx = 2;
                 return;
        }
        _ifnot_0: { if (! (fs > 48001.0)) goto _ifnot_1; }
        _if_1: { c.m_idx = 1;
                 return;
        }
        _ifnot_1: { c.m_idx = 0; }
    }

    Vector<double, 2> VA__Mux3To1Fs__process (FixedArray<Vector<double, 2>, 3> x, const VA__Mux3To1Fs__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (_internal___wrapInt32 (static_cast<int32_t> (_intrin_wrap (static_cast<int32_t> (c.m_idx), 3)), 3)), 3)];
    }

    //==============================================================================
    void VA__Mux3To1Fs__Processor__run (VA__Mux3To1Fs__Processor___State& _state, VA__Mux3To1Fs__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 3> _6 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_c = ZeroInitialiser();
                    VA__Mux3To1Fs__update (_state.m_c, (sampleRate * 1.0));
        }
        _body_0: { _6 = ZeroInitialiser();
                   _2 = _io.m__in_in;
                   _6[0] = _2;
                   _3 = _io.m__in_in1;
                   _6[1] = _3;
                   _4 = _io.m__in_in2;
                   _6[2] = _4;
                   _5 = VA__Mux3To1Fs__process (_6, _state.m_c);
                   out_value_out = out_value_out + _5;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___initialise (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State&
    _state) noexcept
    {
        _state.m_smoothedGains_state.m__arrayEntry = 0;
        _state.m_smoothedGains_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGains_state.m__processorId = 41;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___initialise (_state.m_smoothedGains_state);

        _state.m_applyGains_state.m__arrayEntry = 0;
        _state.m_applyGains_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGains_state.m__processorId = 42;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan__run (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State&
    _state, VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___IO _4 = {};
        VA__ApplyGains__Processor___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains__run (_state.m_smoothedGains_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_b = _4.m__out_out;
        _5.m__in_b1 = _4.m__out_out1;
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__ApplyGains__Processor__run (_state.m_applyGains_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___mixIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___in_f32 (_state.m_smoothedGains_state, event);

    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___panIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___in1_f32 (_state.m_smoothedGains_state, event);

    }

    //==============================================================================
    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___initialise (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State&
    _state) noexcept
    {
        _state.m_smoothedGains_state.m__arrayEntry = 0;
        _state.m_smoothedGains_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGains_state.m__processorId = 43;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___initialise (_state.m_smoothedGains_state);

        _state.m_applyGains_state.m__arrayEntry = 0;
        _state.m_applyGains_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGains_state.m__processorId = 44;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan__run (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State&
    _state, VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___IO _4 = {};
        VA__ApplyGains__Processor_2___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains__run (_state.m_smoothedGains_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_b = _4.m__out_out;
        _5.m__in_b1 = _4.m__out_out1;
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__ApplyGains__Processor_2__run (_state.m_applyGains_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___mixIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___in_f32 (_state.m_smoothedGains_state, event);

    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___panIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___in1_f32 (_state.m_smoothedGains_state, event);

    }

    //==============================================================================
    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___initialise (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State&
    _state) noexcept
    {
        _state.m_smoothedGains_state.m__arrayEntry = 0;
        _state.m_smoothedGains_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGains_state.m__processorId = 45;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___initialise (_state.m_smoothedGains_state);

        _state.m_applyGains_state.m__arrayEntry = 0;
        _state.m_applyGains_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGains_state.m__processorId = 46;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan__run (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State&
    _state, VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___IO _4 = {};
        VA__ApplyGains__Processor_3___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains__run (_state.m_smoothedGains_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_b = _4.m__out_out;
        _5.m__in_b1 = _4.m__out_out1;
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__ApplyGains__Processor_3__run (_state.m_applyGains_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___mixIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___in_f32 (_state.m_smoothedGains_state, event);

    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___panIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___in1_f32 (_state.m_smoothedGains_state, event);

    }

    //==============================================================================
    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___initialise (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 47;
        _state.m_smoothedGain_state.m__arrayEntry = 0;
        _state.m_smoothedGain_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGain_state.m__processorId = 48;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___initialise (_state.m_smoothedGain_state);
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume__run (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State&
    _state, VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___IO _3 = {};
        VA__ApplyGain__Processor___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain__run (_state.m_smoothedGain_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___volumeIn_f32 (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___in_f32 (_state.m_smoothedGain_state, event);

    }

    //==============================================================================
    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___initialise (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 49;
        _state.m_smoothedGain_state.m__arrayEntry = 0;
        _state.m_smoothedGain_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGain_state.m__processorId = 50;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___initialise (_state.m_smoothedGain_state);
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume__run (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State&
    _state, VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___IO _3 = {};
        VA__ApplyGain__Processor_2___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain__run (_state.m_smoothedGain_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor_2__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___volumeIn_f32 (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___in_f32 (_state.m_smoothedGain_state, event);

    }

    //==============================================================================
    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___initialise (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State&
    _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 51;
        _state.m_smoothedGain_state.m__arrayEntry = 0;
        _state.m_smoothedGain_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGain_state.m__processorId = 52;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___initialise (_state.m_smoothedGain_state);
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume__run (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State&
    _state, VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___IO _3 = {};
        VA__ApplyGain__Processor_3___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain__run (_state.m_smoothedGain_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor_3__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___volumeIn_f32 (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___in_f32 (_state.m_smoothedGain_state, event);

    }

    //==============================================================================
    void VA__Lfo__Internal__updatePerSample (VA__Lfo__Internal__Coeffs& c, Vector<double, 2> depth) noexcept
    {
        c.m_depth = depth;
    }

    void VA__Lfo__Internal__update (VA__Lfo__Internal__Coeffs& c, float rate, float width, float mode, VA__Lfo__Internal__State& s, double fs) noexcept
    {
        double T = {};
        float _2 = {};

        T = static_cast<double> (1.0 / fs);
        c.m_phaseIncrement = Vector<double, 2> (static_cast<double> (rate) * T);
        s.m_phase[0] = s.m_phase[1] + static_cast<double> (width * 0.0027777778f);
        _loop_0: { if (! (s.m_phase[0] < 0)) goto _loop_1; }
        _body_0: { s.m_phase[0] = s.m_phase[0] + 1.0;
                   goto _loop_0;
        }
        _loop_1: { if (! (s.m_phase[0] >= 1.0)) goto _break_1; }
        _body_1: { s.m_phase[0] = s.m_phase[0] - 1.0;
                   goto _loop_1;
        }
        _break_1: { _2 = soul__intrinsics___floor_specialised (mode);
                    c.m_mode = static_cast<int32_t> (_2);
        }
    }

    Vector<double, 2> VA__Lfo__Internal__process (VA__Lfo__Internal__State& s, const VA__Lfo__Internal__Coeffs& c) noexcept
    {
        Vector<double, 2> y = {}, _2 = {}, _3 = {};

        y = ZeroInitialiser();
        if (! (c.m_mode == 0)) goto _ifnot_0;
        _if_0: { _2 = VA__vabs ((s.m_phase * Vector<double, 2> { { 2.0, 2.0 } }) - Vector<double, 2> { { 1.0, 1.0 } });
                 y = static_cast<Vector<double, 2>> (Vector<double, 2> { { 1.0, 1.0 } } - static_cast<Vector<double, 2>> (_2));
                 goto _ifend_0;
        }
        _ifnot_0: { if (! (c.m_mode == 1)) goto _ifend_0; }
        _if_1: { _3 = _vec_sin (s.m_phase * Vector<double, 2> { { 6.283185307179586, 6.283185307179586 } });
                 y = (_3 + Vector<double, 2> { { 1.0, 1.0 } }) * Vector<double, 2> { { 0.5, 0.5 } };
        }
        _ifend_0: { s.m_phase = s.m_phase + c.m_phaseIncrement; }
        _loop_0: { if (! (s.m_phase[0] >= 1.0)) goto _loop_1; }
        _body_0: { s.m_phase[0] = s.m_phase[0] - 1.0;
                   goto _loop_0;
        }
        _loop_1: { if (! (s.m_phase[1] >= 1.0)) goto _break_1; }
        _body_1: { s.m_phase[1] = s.m_phase[1] - 1.0;
                   goto _loop_1;
        }
        _break_1: { return y * c.m_depth; }
    }

    //==============================================================================
    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___rateIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_rate = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___widthIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_width = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___modeIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_mode = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal__run (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State&
    _state, VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Lfo__Internal__update (_state.m_c, _state.m_rate, _state.m_width, _state.m_mode, _state.m_s, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_depthIn;
                   VA__Lfo__Internal__updatePerSample (_state.m_c, _2);
                   _3 = VA__Lfo__Internal__process (_state.m_s, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___initialise (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___State&
    _state) noexcept
    {
        _state.m_rate = 2.0f;
        _state.m_width = 180.0f;
        _state.m_mode = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___rateIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_rate = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___widthIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_width = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___modeIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_mode = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal__run (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State&
    _state, VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Lfo__Internal__update (_state.m_c, _state.m_rate, _state.m_width, _state.m_mode, _state.m_s, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_depthIn;
                   VA__Lfo__Internal__updatePerSample (_state.m_c, _2);
                   _3 = VA__Lfo__Internal__process (_state.m_s, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___initialise (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___State&
    _state) noexcept
    {
        _state.m_rate = 2.0f;
        _state.m_width = 180.0f;
        _state.m_mode = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___rateIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_rate = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___widthIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_width = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___modeIn_f32 (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State&
    _state, float v) noexcept
    {
        _state.m_mode = v;
        _state.m_recalc = true;
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal__run (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State&
    _state, VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__Lfo__Internal__update (_state.m_c, _state.m_rate, _state.m_width, _state.m_mode, _state.m_s, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_depthIn;
                   VA__Lfo__Internal__updatePerSample (_state.m_c, _2);
                   _3 = VA__Lfo__Internal__process (_state.m_s, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___initialise (VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___State&
    _state) noexcept
    {
        _state.m_rate = 2.0f;
        _state.m_width = 180.0f;
        _state.m_mode = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___initialise (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 53;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 54;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___initialise (_state.m_internal_state);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo__run (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state, VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___IO& _io) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___IO _2 = {};
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___IO _3 = {};

        _2 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0__run (_state.m_smoothedParameter0_state, _2);
        _3 = ZeroInitialiser();
        _3.m__in_depthIn = _2.m__out_out;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal__run (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___depthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___rateIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___rateIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___widthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___widthIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___modeIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_internal___modeIn_f32 (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___initialise (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 55;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 56;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___initialise (_state.m_internal_state);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo__run (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state, VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___IO& _io) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___IO _2 = {};
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___IO _3 = {};

        _2 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0__run (_state.m_smoothedParameter0_state, _2);
        _3 = ZeroInitialiser();
        _3.m__in_depthIn = _2.m__out_out;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal__run (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___depthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___rateIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___rateIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___widthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___widthIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___modeIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_internal___modeIn_f32 (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___initialise (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 57;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 58;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___initialise (_state.m_internal_state);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo__run (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state, VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___IO& _io) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___IO _2 = {};
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___IO _3 = {};

        _2 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0__run (_state.m_smoothedParameter0_state, _2);
        _3 = ZeroInitialiser();
        _3.m__in_depthIn = _2.m__out_out;
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal__run (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___depthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___rateIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___rateIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___widthIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___widthIn_f32 (_state.m_internal_state, event);
    }

    void VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___modeIn_f32 (VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo___State&
    _state, float event) noexcept
    {
        VA__Lfo__Internal__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_internal___modeIn_f32 (_state.m_internal_state, event);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 3000.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___IO& _io) noexcept
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
                    _state.m_fs = static_cast<double> ((sampleRate * 1.0) * 2.0);
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 3000.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___IO& _io) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_ladderLpfS_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 3000.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.5) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.5) * 2.0);
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 3000.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.5) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.5) * 1.0);
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_ladderLpfS_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 3000.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.25) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.25) * 2.0);
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 3000.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.25) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.25) * 1.0);
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

    void VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__LadderLpfS__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_ladderLpfS_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___in1_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[1] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 50.0f, 0 } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 50.0f, 0 } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedMixPan_smoothedGains__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___in1_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[1] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 50.0f, 0 } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.5) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.5) * 1.0);
                    VA__SmoothedParameter___M_3__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_3__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_3__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 50.0f, 0 } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedMixPan_smoothedGains__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___in1_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[1] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 50.0f, 0 } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, out_value_out1 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        out_value_out1 = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.25) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.25) * 1.0);
                    VA__SmoothedParameter___M_3__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_3__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_3__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 50.0f, 0 } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedMixPan_smoothedGains__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___IO& _io) noexcept
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
                    VA__SmoothedParameter___M_4__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_4__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_4__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_smoothedVolume_smoothedGain__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.5) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.5) * 1.0);
                    VA__SmoothedParameter___M_4__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_4__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_4__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_smoothedVolume_smoothedGain__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.25) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.25) * 1.0);
                    VA__SmoothedParameter___M_4__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_4__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_4__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_smoothedVolume_smoothedGain__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___IO& _io) noexcept
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
                    VA__SmoothedParameter___M_5__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_5__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_5__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS0_lfo_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.5) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.5) * 1.0);
                    VA__SmoothedParameter___M_5__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_5__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_5__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS2_lfo_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 1L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 1> { { 50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 1) & 0];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 256.0));
                    _state.m_divMaxDelta = static_cast<Vector<double, 2>> (Vector<double, 2> ((sampleRate * 0.25) / 100.0));
                    _state.m_fs = static_cast<double> ((sampleRate * 0.25) * 1.0);
                    VA__SmoothedParameter___M_5__updateUnsmoothed (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<double> (_state.m_fs));
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter___M_5__update (_state.m_c, _state.m_parameter.toDynamicArray(), _state.m_s, static_cast<Vector<double, 2>> (_state.m_divMaxDelta), static_cast<double> (_state.m_fs));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter___M_5__process (_state.m_s, _state.m_c);
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

    void VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 1> { { 50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__Lfo__Processor___for__root__VA__HighLevel__TheChorus__Internal__Processor___for__root__VA__HighLevel__TheChorus__Processor___for__root__main__Processor_e_internalDS4_lfo_smoothedParameter0__init (_state);
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vCutoffToG_Onepole (VA__SmoothedParameter___M___get_dyn_array_element_slice_f32 (parameter, 0), fs);
        y[0] = _2;
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
    FixedArray<Vector<double, 2>, 2> VA__SmoothedParameter___M_3__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {}, _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vMixPanToGains (VA__SmoothedParameter___M_3___get_dyn_array_element_slice_f32 (parameter, 0), VA__SmoothedParameter___M_3___get_dyn_array_element_slice_f32 (parameter, 1));
        y = _2;
        return y;
    }

    void VA__SmoothedParameter___M_3__update (VA__SmoothedParameter___M_3__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_3__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 2> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        double _5 = {}, _6 = {};
        int32_t r0 = {}, r1 = {};
        int32_t _7 = {}, _8 = {}, i = {}, _9 = {};

        _2 = VA__SmoothedParameter___M_3__decodeParameter (parameter, fs);
        c.m_target = _2;
        _3 = VA__vabs (c.m_target[0] - s.m_current[0]);
        _5 = VA__vmaxr (_3 * divMaxDelta);
        r0 = static_cast<int32_t> (static_cast<int32_t> (_5));
        _4 = VA__vabs (c.m_target[1] - s.m_current[1]);
        _6 = VA__vmaxr (_4 * divMaxDelta);
        r1 = static_cast<int32_t> (static_cast<int32_t> (_6));
        _7 = soul__intrinsics___max_specialised_2 (static_cast<int32_t> (r0), static_cast<int32_t> (r1));
        _8 = soul__intrinsics___max_specialised_2 (1, _7);
        s.m_remainingRampSamples = _8;
        i = 0;
        _loop_0: { if (! (i < 2)) goto _break_0; }
        _body_0: { c.m_increment[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = (c.m_target[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] - s.m_current[_intrin_wrap (static_cast<int32_t> (i), 2) & 1]) / Vector<double, 2> (s.m_remainingRampSamples);
                   _9 = i;
                   i = _9 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter___M_3__updateUnsmoothed (VA__SmoothedParameter___M_3__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_3__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 2> _2 = {};

        _2 = VA__SmoothedParameter___M_3__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 2> VA__SmoothedParameter___M_3__process (VA__SmoothedParameter___M_3__State& s, const VA__SmoothedParameter___M_3__Coeffs& c) noexcept
    {
        int32_t _2 = {}, _3 = {}, i = {}, _4 = {}, i_2 = {}, _5 = {};

        if (! (s.m_remainingRampSamples != 0)) goto _ifnot_0;
        _if_0: { _2 = s.m_remainingRampSamples;
                 _3 = _2 - 1;
                 s.m_remainingRampSamples = _3;
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
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_4__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vdBtoGain (Vector<double, 2> (VA__SmoothedParameter___M_4___get_dyn_array_element_slice_f32 (parameter, 0)));
        y[0] = _2;
        return y;
    }

    void VA__SmoothedParameter___M_4__update (VA__SmoothedParameter___M_4__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_4__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        int32_t i = {}, _5 = {};

        _2 = VA__SmoothedParameter___M_4__decodeParameter (parameter, fs);
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

    void VA__SmoothedParameter___M_4__updateUnsmoothed (VA__SmoothedParameter___M_4__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_4__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};

        _2 = VA__SmoothedParameter___M_4__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_4__process (VA__SmoothedParameter___M_4__State& s, const VA__SmoothedParameter___M_4__Coeffs& c) noexcept
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

    float VA__SmoothedParameter___M_4___get_dyn_array_element_slice_f32 (DynamicArray<float> array, int32_t index) noexcept
    {
        if (! (array.numElements == 0)) goto _notEmpty;
        _empty: { return 0; }
        _notEmpty: { return array[_internal___wrapInt32 (index, array.numElements)]; }
    }

    int32_t VA__SmoothedParameter___M_4___get_array_size_slice_f32 (DynamicArray<float> array) noexcept;

    //==============================================================================
    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_5__decodeParameter (DynamicArray<float> parameter, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> y = {};

        y = ZeroInitialiser();
        y[0] = Vector<double, 2> (static_cast<double> (VA__SmoothedParameter___M_5___get_dyn_array_element_slice_f32 (parameter, 0)) * 0.01);
        return y;
    }

    void VA__SmoothedParameter___M_5__update (VA__SmoothedParameter___M_5__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_5__State& s, Vector<double, 2> divMaxDelta, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};
        Vector<double, 2> _3 = {}, _4 = {};
        int32_t i = {}, _5 = {};

        _2 = VA__SmoothedParameter___M_5__decodeParameter (parameter, fs);
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

    void VA__SmoothedParameter___M_5__updateUnsmoothed (VA__SmoothedParameter___M_5__Coeffs& c, DynamicArray<float> parameter, VA__SmoothedParameter___M_5__State& s, double fs) noexcept
    {
        FixedArray<Vector<double, 2>, 1> _2 = {};

        _2 = VA__SmoothedParameter___M_5__decodeParameter (parameter, fs);
        c.m_target = _2;
        s.m_remainingRampSamples = 1;
    }

    FixedArray<Vector<double, 2>, 1> VA__SmoothedParameter___M_5__process (VA__SmoothedParameter___M_5__State& s, const VA__SmoothedParameter___M_5__Coeffs& c) noexcept
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

    float VA__SmoothedParameter___M_5___get_dyn_array_element_slice_f32 (DynamicArray<float> array, int32_t index) noexcept
    {
        if (! (array.numElements == 0)) goto _notEmpty;
        _empty: { return 0; }
        _notEmpty: { return array[_internal___wrapInt32 (index, array.numElements)]; }
    }

    int32_t VA__SmoothedParameter___M_5___get_array_size_slice_f32 (DynamicArray<float> array) noexcept;

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

