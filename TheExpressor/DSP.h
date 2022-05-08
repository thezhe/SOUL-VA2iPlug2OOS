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

    static constexpr const char*  UID           = "com.TheZhe.TheExpressorDSP";
    static constexpr const char*  name          = "TheExpressorDSP";
    static constexpr const char*  description   = "TheExpressor DSP";
    static constexpr const char*  category      = "effect";
    static constexpr const char*  manufacturer  = "TheZhe";
    static constexpr const char*  version       = "1.0";
    static constexpr const char*  URL           = "";
    static constexpr bool         isInstrument  = false;
    static constexpr const char*  manifest      = "{\r\n"
    "    \"soulPatchV1\": {\r\n"
    "        \"ID\": \"com.TheZhe.TheExpressorDSP\",\r\n"
    "        \"version\": \"1.0\",\r\n"
    "        \"name\": \"TheExpressorDSP\",\r\n"
    "        \"description\": \"TheExpressor DSP\",\r\n"
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
    struct soul___filters__dc_blocker__Coeffs;
    struct soul___filters__dc_blocker__State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___State;
    struct VA__DC_Blocker__Processor___State;
    struct VA__ApplyGain__Processor_2___State;
    struct VA__Mux2To1__Coeffs;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State;
    struct soul___filters__tpt__svf__Coeffs;
    struct soul___filters__tpt__svf__State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State;
    struct VA___AbsADAA__Coeffs;
    struct VA___AbsADAA__Internal__State;
    struct VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter;
    struct VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2;
    struct VA___AbsADAA__Internal__Processor___State;
    struct VA___AbsADAA__Processor___State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___State;
    struct VA__StereoLink__Coeffs;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State;
    struct VA__BallisticsFilter__Internal__Processor___DelayState_1;
    struct VA__Difference__Processor___State;
    struct VA__Step__Processor___State;
    struct VA__Difference__Processor_2___State;
    struct VA__Sum__Processor___State;
    struct VA__ApplyGain__Processor___State;
    struct VA__BranchingCutoff__Processor___State;
    struct VA__OnepoleC__Coeffs;
    struct VA__OnepoleC__State;
    struct VA__OnepoleC__Processor___State;
    struct VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2;
    struct VA__BallisticsFilter__Internal__Processor___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State;
    struct VA__SmoothedParameter__Coeffs;
    struct VA__SmoothedParameter__State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State;
    struct VA__CTF_Color__Internal__Coeffs;
    struct VA__CTF_Color__Internal__Processor___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___State;
    struct VA__DC_Blocker__Processor_2___State;
    struct VA__ApplyGain__Processor_3___State;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State;
    struct VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter;
    struct VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2;
    struct VA___AbsADAA__Internal__Processor_2___State;
    struct VA___AbsADAA__Processor_2___State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___State;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State;
    struct VA__BallisticsFilter__Internal__Processor_2___DelayState_1;
    struct VA__Difference__Processor_3___State;
    struct VA__Step__Processor_2___State;
    struct VA__Difference__Processor_4___State;
    struct VA__Sum__Processor_2___State;
    struct VA__ApplyGain__Processor_5___State;
    struct VA__BranchingCutoff__Processor_2___State;
    struct VA__OnepoleC__Processor_2___State;
    struct VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2;
    struct VA__BallisticsFilter__Internal__Processor_2___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State;
    struct VA__CTF_Color__Internal__Processor_2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___State;
    struct VA__DC_Blocker__Processor_3___State;
    struct VA__ApplyGain__Processor_4___State;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State;
    struct VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter;
    struct VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2;
    struct VA___AbsADAA__Internal__Processor_3___State;
    struct VA___AbsADAA__Processor_3___State;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___State;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State;
    struct VA__BallisticsFilter__Internal__Processor_3___DelayState_1;
    struct VA__Difference__Processor_5___State;
    struct VA__Step__Processor_3___State;
    struct VA__Difference__Processor_6___State;
    struct VA__Sum__Processor_3___State;
    struct VA__ApplyGain__Processor_6___State;
    struct VA__BranchingCutoff__Processor_3___State;
    struct VA__OnepoleC__Processor_3___State;
    struct VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter;
    struct VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2;
    struct VA__BallisticsFilter__Internal__Processor_3___State;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State;
    struct VA__CTF_Color__Internal__Processor_3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State;
    struct VA__Mux3To1Fs__Coeffs;
    struct VA__Mux3To1Fs__Processor___State;
    struct VA__Mux3To1Fs__Processor_2___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State;
    struct VA__ApplyGains__Processor___State;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State;
    struct VA__ApplyGain__Processor_7___State;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State;
    struct VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State;
    struct _State;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_2_dcBlocker___IO;
    struct soul___filters__dc_blocker__Processor___for__root__VA__DC_Blocker__Processor_3_dcBlocker___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___IO;
    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___IO;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___IO;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___IO;
    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___IO;
    struct VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___IO;
    struct VA__DC_Blocker__Processor___IO;
    struct VA__DC_Blocker__Processor_2___IO;
    struct VA__DC_Blocker__Processor_3___IO;
    struct VA__BallisticsFilter__Internal__Processor___IO;
    struct VA__BallisticsFilter__Internal__Processor_2___IO;
    struct VA__BallisticsFilter__Internal__Processor_3___IO;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___IO;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___IO;
    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___IO;
    struct VA__OnepoleC__Processor___IO;
    struct VA__OnepoleC__Processor_2___IO;
    struct VA__OnepoleC__Processor_3___IO;
    struct VA__BranchingCutoff__Processor___IO;
    struct VA__BranchingCutoff__Processor_2___IO;
    struct VA__BranchingCutoff__Processor_3___IO;
    struct VA__Step__Processor___IO;
    struct VA__Step__Processor_2___IO;
    struct VA__Step__Processor_3___IO;
    struct VA__CTF_Color__Internal__Processor___IO;
    struct VA__CTF_Color__Internal__Processor_2___IO;
    struct VA__CTF_Color__Internal__Processor_3___IO;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___IO;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___IO;
    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___IO;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___IO;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___IO;
    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___IO;
    struct VA__ApplyGain__Processor___IO;
    struct VA__ApplyGain__Processor_2___IO;
    struct VA__ApplyGain__Processor_3___IO;
    struct VA__ApplyGain__Processor_4___IO;
    struct VA__ApplyGain__Processor_5___IO;
    struct VA__ApplyGain__Processor_6___IO;
    struct VA__ApplyGain__Processor_7___IO;
    struct VA__ApplyGains__Processor___IO;
    struct VA__Mux3To1Fs__Processor___IO;
    struct VA__Mux3To1Fs__Processor_2___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___IO;
    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___IO;
    struct VA__Sum__Processor___IO;
    struct VA__Sum__Processor_2___IO;
    struct VA__Sum__Processor_3___IO;
    struct VA__Difference__Processor___IO;
    struct VA__Difference__Processor_2___IO;
    struct VA__Difference__Processor_3___IO;
    struct VA__Difference__Processor_4___IO;
    struct VA__Difference__Processor_5___IO;
    struct VA__Difference__Processor_6___IO;
    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___IO;
    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___IO;
    struct VA__SmoothedParameter__Mode;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___IO;
    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___IO;
    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___IO;
    struct VA___AbsADAA__Processor___IO;
    struct VA___AbsADAA__Internal__Processor___IO;
    struct VA___AbsADAA__Internal__Processor_2___IO;
    struct VA___AbsADAA__Internal__Processor_3___IO;
    struct VA___AbsADAA__Processor_2___IO;
    struct VA___AbsADAA__Processor_3___IO;
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
        std::array<const FloatType*, 4> inputChannels;
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
            copyToInterleaved (_getInputFrameArrayRef_scIn (state).elements, &context.inputChannels[2], startFrame, numFramesToDo);

            advance();

            copyFromInterleaved (&context.outputChannels[0], startFrame, _getOutputFrameArrayRef_out (state).elements, numFramesToDo);
            copyFromInterleaved (&context.outputChannels[2], startFrame, _getOutputFrameArrayRef_guiOut (state).elements, numFramesToDo);
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

    void setNextInputStreamFrames_scIn (const Vector<double, 2>* frames, uint32_t numFramesToUse)
    {
        auto& buffer = _getInputFrameArrayRef_scIn (state);

        for (uint32_t i = 0; i < numFramesToUse; ++i)
            buffer[static_cast<int> (i)] = frames[i];
    }

    void setNextInputStreamSparseFrames_scIn (Vector<double, 2> targetFrameValue, uint32_t numFramesToReachValue)
    {
        _setSparseInputTarget_scIn (state, targetFrameValue, (int32_t) numFramesToReachValue);
    }

    void addInputEvent_attackIn (float eventValue)
    {
        _addInputEvent_attackIn_f32 (state, eventValue);
    }

    void addInputEvent_releaseIn (float eventValue)
    {
        _addInputEvent_releaseIn_f32 (state, eventValue);
    }

    void addInputEvent_thresholdIn (float eventValue)
    {
        _addInputEvent_thresholdIn_f32 (state, eventValue);
    }

    void addInputEvent_ratioIn (float eventValue)
    {
        _addInputEvent_ratioIn_f32 (state, eventValue);
    }

    void addInputEvent_ratio1In (float eventValue)
    {
        _addInputEvent_ratio1In_f32 (state, eventValue);
    }

    void addInputEvent_makeupIn (float eventValue)
    {
        _addInputEvent_makeupIn_f32 (state, eventValue);
    }

    void addInputEvent_sidechainIn (float eventValue)
    {
        _addInputEvent_sidechainIn_f32 (state, eventValue);
    }

    void addInputEvent_cutoffHP_In (float eventValue)
    {
        _addInputEvent_cutoffHP_In_f32 (state, eventValue);
    }

    void addInputEvent_stereoLinkIn (float eventValue)
    {
        _addInputEvent_stereoLinkIn_f32 (state, eventValue);
    }

    void addInputEvent_softnessIn (float eventValue)
    {
        _addInputEvent_softnessIn_f32 (state, eventValue);
    }

    void addInputEvent_colorIn (float eventValue)
    {
        _addInputEvent_colorIn_f32 (state, eventValue);
    }

    void addInputEvent_mixIn (float eventValue)
    {
        _addInputEvent_mixIn_f32 (state, eventValue);
    }

    DynamicArray<const Vector<double, 2>> getOutputStreamFrames_out()
    {
        return { &(_getOutputFrameArrayRef_out (state).elements[0]), static_cast<int32_t> (framesToAdvance) };
    }

    DynamicArray<const Vector<double, 2>> getOutputStreamFrames_guiOut()
    {
        return { &(_getOutputFrameArrayRef_guiOut (state).elements[0]), static_cast<int32_t> (framesToAdvance) };
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

    std::array<EndpointDetails, 14> getInputEndpoints() const
    {
        return
        {
            EndpointDetails { "in",           "in:in",           EndpointType::stream, "float64<2>", 2, ""                                                                                                                                                        },
            EndpointDetails { "scIn",         "in:scIn",         EndpointType::stream, "float64<2>", 2, ""                                                                                                                                                        },
            EndpointDetails { "attackIn",     "in:attackIn",     EndpointType::event,  "float32",    0, "{ \"name\": \"Attack\", \"min\": 0.10000000149011612, \"max\": 50, \"init\": 0.10000000149011612, \"unit\": \"ms\", \"step\": 0.1, \"group\": \"Main\""
            " }" },
            EndpointDetails { "releaseIn",    "in:releaseIn",    EndpointType::event,  "float32",    0, "{ \"name\": \"Release\", \"min\": 30, \"max\": 3000, \"init\": 30.0, \"unit\": \"ms\", \"step\": 1, \"group\": \"Main\" }"                               },
            EndpointDetails { "thresholdIn",  "in:thresholdIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Threshold\", \"min\": -50.0, \"max\": 0.0, \"init\": -50.0, \"unit\": \"dB\", \"step\": 0.10000000149011612, \"group\": \"Main\" }"        },
            EndpointDetails { "ratioIn",      "in:ratioIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Post-Threshold\", \"min\": 0.5, \"max\": 20.0, \"init\": 20.0, \"step\": 0.10000000149011612, \"group\": \"Ratios\" }"                     },
            EndpointDetails { "ratio1In",     "in:ratio1In",     EndpointType::event,  "float32",    0, "{ \"name\": \"Pre-Threshold\", \"min\": 0.5, \"max\": 1.5, \"init\": 1.0, \"step\": 0.10000000149011612, \"group\": \"Ratios\" }"                        },
            EndpointDetails { "makeupIn",     "in:makeupIn",     EndpointType::event,  "float32",    0, "{ \"name\": \"Makeup\", \"min\": -6, \"max\": 50, \"init\": 0.0, \"step\": 0.10000000149011612, \"unit\": \"dB\", \"group\": \"Utility\" }"              },
            EndpointDetails { "sidechainIn",  "in:sidechainIn",  EndpointType::event,  "float32",    0, "{ \"name\": \"Sidechain\", \"init\": 0.0, \"boolean\": true, \"group\": \"Detector\" }"                                                                  },
            EndpointDetails { "cutoffHP_In",  "in:cutoffHP_In",  EndpointType::event,  "float32",    0, "{ \"name\": \"High Pass\", \"min\": 1, \"max\": 500, \"init\": 1.0, \"unit\": \"Hz\", \"step\": 1, \"group\": \"Detector\" }"                            },
            EndpointDetails { "stereoLinkIn", "in:stereoLinkIn", EndpointType::event,  "float32",    0, "{ \"name\": \"Stereo Link\", \"min\": 0, \"max\": 100, \"init\": 0.0, \"unit\": \"%\", \"step\": 1, \"group\": \"Detector\" }"                           },
            EndpointDetails { "softnessIn",   "in:softnessIn",   EndpointType::event,  "float32",    0, "{ \"name\": \"Softness\", \"min\": 0, \"max\": 24, \"init\": 0.0, \"unit\": \"dB\", \"step\": 0.10000000149011612, \"group\": \"Knee\" }"                },
            EndpointDetails { "colorIn",      "in:colorIn",      EndpointType::event,  "float32",    0, "{ \"name\": \"Color\", \"min\": -24, \"max\": 24, \"init\": 0.0, \"unit\": \"dB\", \"step\": 0.10000000149011612, \"group\": \"Knee\" }"                 },
            EndpointDetails { "mixIn",        "in:mixIn",        EndpointType::event,  "float32",    0, "{ \"name\": \"Mix\", \"min\": 0, \"max\": 100, \"init\": 100.0, \"unit\": \"%\", \"step\": 1, \"group\": \"Utility\" }"                                  }
        };
    }

    std::array<EndpointDetails, 2> getOutputEndpoints() const
    {
        return
        {
            EndpointDetails { "out",    "out:out",    EndpointType::stream, "float64<2>", 2, "" },
            EndpointDetails { "guiOut", "out:guiOut", EndpointType::stream, "float64<2>", 2, "" }
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
    static constexpr uint32_t  numParameters = 12;

    static constexpr const std::array<const ParameterProperties, numParameters> parameters =
    {
        ParameterProperties {  "attackIn",      "Attack",          "ms",  0.1f,    50.0f,    0.1f,    0.1f,    true,  false,  false,  "Main",      ""  },
        ParameterProperties {  "releaseIn",     "Release",         "ms",  30.0f,   3000.0f,  1.0f,    30.0f,   true,  false,  false,  "Main",      ""  },
        ParameterProperties {  "thresholdIn",   "Threshold",       "dB",  -50.0f,  0.0f,     0.1f,    -50.0f,  true,  false,  false,  "Main",      ""  },
        ParameterProperties {  "ratioIn",       "Post-Threshold",  "",    0.5f,    20.0f,    0.1f,    20.0f,   true,  false,  false,  "Ratios",    ""  },
        ParameterProperties {  "ratio1In",      "Pre-Threshold",   "",    0.5f,    1.5f,     0.1f,    1.0f,    true,  false,  false,  "Ratios",    ""  },
        ParameterProperties {  "makeupIn",      "Makeup",          "dB",  -6.0f,   50.0f,    0.1f,    0.0f,    true,  false,  false,  "Utility",   ""  },
        ParameterProperties {  "sidechainIn",   "Sidechain",       "",    0.0f,    1.0f,     0.001f,  0.0f,    true,  true,   false,  "Detector",  ""  },
        ParameterProperties {  "cutoffHP_In",   "High Pass",       "Hz",  1.0f,    500.0f,   1.0f,    1.0f,    true,  false,  false,  "Detector",  ""  },
        ParameterProperties {  "stereoLinkIn",  "Stereo Link",     "%",   0.0f,    100.0f,   1.0f,    0.0f,    true,  false,  false,  "Detector",  ""  },
        ParameterProperties {  "softnessIn",    "Softness",        "dB",  0.0f,    24.0f,    0.1f,    0.0f,    true,  false,  false,  "Knee",      ""  },
        ParameterProperties {  "colorIn",       "Color",           "dB",  -24.0f,  24.0f,    0.1f,    0.0f,    true,  false,  false,  "Knee",      ""  },
        ParameterProperties {  "mixIn",         "Mix",             "%",   0.0f,    100.0f,   1.0f,    100.0f,  true,  false,  false,  "Utility",   ""  }
    };

    static span<const ParameterProperties> getParameterProperties() { return { parameters.data(), numParameters }; }

    static constexpr uint32_t numInputBuses  = 2;
    static constexpr uint32_t numOutputBuses = 2;

    static constexpr std::array<const AudioBus, numInputBuses>  inputBuses =
    {
        AudioBus { "in",   2 },
        AudioBus { "scIn", 2 }
    };

    static constexpr std::array<const AudioBus, numOutputBuses> outputBuses =
    {
        AudioBus { "out",    2 },
        AudioBus { "guiOut", 2 }
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
                Parameter {  parameters[0],   0.1f,    [this] (float v) { addInputEvent_attackIn (v); }      },
                Parameter {  parameters[1],   30.0f,   [this] (float v) { addInputEvent_releaseIn (v); }     },
                Parameter {  parameters[2],   -50.0f,  [this] (float v) { addInputEvent_thresholdIn (v); }   },
                Parameter {  parameters[3],   20.0f,   [this] (float v) { addInputEvent_ratioIn (v); }       },
                Parameter {  parameters[4],   1.0f,    [this] (float v) { addInputEvent_ratio1In (v); }      },
                Parameter {  parameters[5],   0.0f,    [this] (float v) { addInputEvent_makeupIn (v); }      },
                Parameter {  parameters[6],   0.0f,    [this] (float v) { addInputEvent_sidechainIn (v); }   },
                Parameter {  parameters[7],   1.0f,    [this] (float v) { addInputEvent_cutoffHP_In (v); }   },
                Parameter {  parameters[8],   0.0f,    [this] (float v) { addInputEvent_stereoLinkIn (v); }  },
                Parameter {  parameters[9],   0.0f,    [this] (float v) { addInputEvent_softnessIn (v); }    },
                Parameter {  parameters[10],  0.0f,    [this] (float v) { addInputEvent_colorIn (v); }       },
                Parameter {  parameters[11],  100.0f,  [this] (float v) { addInputEvent_mixIn (v); }         }
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
        FixedArray<int32_t, 14> m_rampArray;
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

    struct VA__ApplyGain__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Mux2To1__Coeffs
    {
        int32_t m_idx;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct soul___filters__tpt__svf__Coeffs
    {
        double m_a0, m_a, m_p;
    };

    struct soul___filters__tpt__svf__State
    {
        FixedArray<Vector<double, 2>, 2> m_z;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA___AbsADAA__Coeffs
    {
    };

    struct VA___AbsADAA__Internal__State
    {
        FixedArray<Vector<double, 2>, 2> m_x, m_F_0, m_F_1;
    };

    struct VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA___AbsADAA__Internal__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Coeffs m_c;
        VA___AbsADAA__Internal__State m_s;
        VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
    };

    struct VA___AbsADAA__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Internal__Processor___State m_internal_state;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA__StereoLink__Coeffs
    {
        float m_stereoLink;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Internal__Processor___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__Difference__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Step__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Difference__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Sum__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__ApplyGain__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__BranchingCutoff__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Difference__Processor___State m_difference_state;
        VA__Step__Processor___State m_step_state;
        VA__Difference__Processor_2___State m_difference1_state;
        VA__Sum__Processor___State m_sum_state;
        VA__ApplyGain__Processor___State m_applyGain_state;
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

    struct VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__BallisticsFilter__Internal__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Internal__Processor___DelayState_1 m__delayState_1;
        VA__BranchingCutoff__Processor___State m_branchingCutoff_state;
        VA__OnepoleC__Processor___State m_onepoleC_state;
        VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2 m__in_src, m__attackIn_src, m__releaseIn_src, m__out_src;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State m_unsmoothedParameter_state;

        VA__BallisticsFilter__Internal__Processor___State m_internal_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State m_unsmoothedParameter1_state;

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

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Internal__Coeffs
    {
        Vector<double, 2> m_threshold, m_ratio, m_ratio1, m_softness, m_color;
    };

    struct VA__CTF_Color__Internal__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__CTF_Color__Internal__Coeffs m_c;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State m_smoothedParameter0_state;
        VA__CTF_Color__Internal__Processor___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State m_smoothedParameter1_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State m_smoothedParameter2_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State m_smoothedParameter3_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State m_smoothedParameter4_state;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__DC_Blocker__Processor___State m_dcBlocker_state;
        VA__ApplyGain__Processor_2___State m_applyGain_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State m_mux2To1_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State m_pSvf_state;
        VA___AbsADAA__Processor___State m_absADAA_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___State m_pSvf1_state;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State m_stereoLink_state;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State m_ballisticsFilter_state;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State m_ctfColor_state;
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

    struct VA__ApplyGain__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA___AbsADAA__Internal__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Coeffs m_c;
        VA___AbsADAA__Internal__State m_s;
        VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
    };

    struct VA___AbsADAA__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Internal__Processor_2___State m_internal_state;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Internal__Processor_2___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__Difference__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Step__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Difference__Processor_4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Sum__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__ApplyGain__Processor_5___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__BranchingCutoff__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Difference__Processor_3___State m_difference_state;
        VA__Step__Processor_2___State m_step_state;
        VA__Difference__Processor_4___State m_difference1_state;
        VA__Sum__Processor_2___State m_sum_state;
        VA__ApplyGain__Processor_5___State m_applyGain_state;
    };

    struct VA__OnepoleC__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__OnepoleC__Coeffs m_c;
        VA__OnepoleC__State m_s;
    };

    struct VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__BallisticsFilter__Internal__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Internal__Processor_2___DelayState_1 m__delayState_1;
        VA__BranchingCutoff__Processor_2___State m_branchingCutoff_state;
        VA__OnepoleC__Processor_2___State m_onepoleC_state;
        VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2 m__in_src, m__attackIn_src, m__releaseIn_src, m__out_src;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State m_unsmoothedParameter_state;

        VA__BallisticsFilter__Internal__Processor_2___State m_internal_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State m_unsmoothedParameter1_state;

    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Internal__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__CTF_Color__Internal__Coeffs m_c;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State m_smoothedParameter0_state;
        VA__CTF_Color__Internal__Processor_2___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State m_smoothedParameter1_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State m_smoothedParameter2_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State m_smoothedParameter3_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State m_smoothedParameter4_state;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__DC_Blocker__Processor_2___State m_dcBlocker_state;
        VA__ApplyGain__Processor_3___State m_applyGain_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State m_mux2To1_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State m_pSvf_state;
        VA___AbsADAA__Processor_2___State m_absADAA_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___State m_pSvf1_state;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State m_stereoLink_state;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State m_ballisticsFilter_state;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State m_ctfColor_state;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2 m__in_src, m__scIn_src, m__out_src, m__guiOut_src;
        int32_t m__undersamplingCount;
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

    struct VA__ApplyGain__Processor_4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_idx;
        bool m_recalc;
        int32_t m_counter_1;
        VA__Mux2To1__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA___AbsADAA__Internal__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Coeffs m_c;
        VA___AbsADAA__Internal__State m_s;
        VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2 m__in_src, m__out_src;
    };

    struct VA___AbsADAA__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA___AbsADAA__Internal__Processor_3___State m_internal_state;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_frequency, m_quality;
        bool m_recalc;
        int32_t m_counter_1;
        soul___filters__tpt__svf__Coeffs m_c;
        soul___filters__tpt__svf__State m_s;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        float m_stereoLink;
        bool m_recalc;
        int32_t m_counter_1;
        VA__StereoLink__Coeffs m_c;
        int32_t m_updateIntervalSamples;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Internal__Processor_3___DelayState_1
    {
        int32_t m_index;
        FixedArray<Vector<double, 2>, 1> m_buffer;
    };

    struct VA__Difference__Processor_5___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Step__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Difference__Processor_6___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__Sum__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__ApplyGain__Processor_6___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__BranchingCutoff__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Difference__Processor_5___State m_difference_state;
        VA__Step__Processor_3___State m_step_state;
        VA__Difference__Processor_6___State m_difference1_state;
        VA__Sum__Processor_3___State m_sum_state;
        VA__ApplyGain__Processor_6___State m_applyGain_state;
    };

    struct VA__OnepoleC__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__OnepoleC__Coeffs m_c;
        VA__OnepoleC__State m_s;
    };

    struct VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2
    {
        FixedArray<Vector<double, 2>, 2> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2_filter, 1> m_filterA, m_filterB;
    };

    struct VA__BallisticsFilter__Internal__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__BallisticsFilter__Internal__Processor_3___DelayState_1 m__delayState_1;
        VA__BranchingCutoff__Processor_3___State m_branchingCutoff_state;
        VA__OnepoleC__Processor_3___State m_onepoleC_state;
        VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2 m__in_src, m__attackIn_src, m__releaseIn_src, m__out_src;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 2> m_iParameter, m_parameter;
        bool m_recalc;
        FixedArray<Vector<double, 2>, 2> m_y;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State m_unsmoothedParameter_state;

        VA__BallisticsFilter__Internal__Processor_3___State m_internal_state;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State m_unsmoothedParameter1_state;

    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Internal__Processor_3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__CTF_Color__Internal__Coeffs m_c;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State m_smoothedParameter0_state;
        VA__CTF_Color__Internal__Processor_3___State m_internal_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State m_smoothedParameter1_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State m_smoothedParameter2_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State m_smoothedParameter3_state;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State m_smoothedParameter4_state;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter
    {
        Vector<double, 2> m_in;
        FixedArray<Vector<double, 2>, 3> m_out;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4
    {
        FixedArray<Vector<double, 2>, 4> m_buffer;
        int32_t m_bufferPos;
        FixedArray<VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4_filter, 2> m_filterA, m_filterB;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__DC_Blocker__Processor_3___State m_dcBlocker_state;
        VA__ApplyGain__Processor_4___State m_applyGain_state;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State m_mux2To1_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State m_pSvf_state;
        VA___AbsADAA__Processor_3___State m_absADAA_state;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___State m_pSvf1_state;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State m_stereoLink_state;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State m_ballisticsFilter_state;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State m_ctfColor_state;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4 m__in_src, m__scIn_src, m__out_src, m__guiOut_src;
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

    struct VA__Mux3To1Fs__Processor_2___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__Mux3To1Fs__Coeffs m_c;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__ApplyGains__Processor___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State m_smoothedGains_state;
        VA__ApplyGains__Processor___State m_applyGains_state;
    };

    struct VA__ApplyGain__Processor_7___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        FixedArray<float, 4> m_iParameter, m_parameter;
        bool m_recalc;
        int32_t m_counter_1;
        VA__SmoothedParameter__Coeffs m_c;
        VA__SmoothedParameter__State m_s;
        int32_t m_updateIntervalSamples;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__ApplyGain__Processor_7___State m_applyGain_state;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State m_smoothedGain_state;
    };

    struct VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State m_internalDS0_state;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State m_internalDS2_state;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State m_internalDS4_state;
        VA__Mux3To1Fs__Processor___State m_mux3To1Fs_state;
        VA__Mux3To1Fs__Processor_2___State m_mux3To1Fs1_state;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State m_smoothedMixPan_state;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State m_smoothedVolume_state;
    };

    struct _State
    {
        int32_t m__resumePoint, m__frameCount, m__arrayEntry, m__sessionID, m__processorId, m__framesToAdvance;
        _RenderStats m__renderStats;
        _SparseStreamStatus m__sparseStreamStatus;
        _Stream_in_vec_2_f64_1024 m__in_in, m__in_scIn;
        _Event_in_f32_1 m__in_attackIn, m__in_releaseIn, m__in_thresholdIn, m__in_ratioIn, m__in_ratio1In, m__in_makeupIn, m__in_sidechainIn, m__in_cutoffHP_In, m__in_stereoLinkIn, m__in_softnessIn, m__in_colorIn, m__in_mixIn;
        _Stream_out_vec_2_f64_1024 m__out_out, m__out_guiOut;
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State m_e_state;
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

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___IO
    {
        Vector<double, 2> m__in_in, m__out_highpassOut;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___IO
    {
        Vector<double, 2> m__in_in, m__out_lowpassOut;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___IO
    {
        Vector<double, 2> m__in_in, m__out_highpassOut;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___IO
    {
        Vector<double, 2> m__in_in, m__out_lowpassOut;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___IO
    {
        Vector<double, 2> m__in_in, m__out_highpassOut;
    };

    struct soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___IO
    {
        Vector<double, 2> m__in_in, m__out_lowpassOut;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___IO
    {
        Vector<double, 2> m__in_in, m__in_scIn, m__out_out, m__out_guiOut;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___IO
    {
        Vector<double, 2> m__in_in, m__in_scIn, m__out_out, m__out_guiOut;
    };

    struct VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___IO
    {
        Vector<double, 2> m__in_in, m__in_scIn, m__out_out, m__out_guiOut;
    };

    struct VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___IO
    {
        Vector<double, 2> m__in_in, m__in_scIn, m__out_out, m__out_guiOut;
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

    struct VA__BallisticsFilter__Internal__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_attackIn, m__in_releaseIn, m__out_out;
    };

    struct VA__BallisticsFilter__Internal__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_attackIn, m__in_releaseIn, m__out_out;
    };

    struct VA__BallisticsFilter__Internal__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_attackIn, m__in_releaseIn, m__out_out;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__OnepoleC__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut, m__out_stateOut;
    };

    struct VA__OnepoleC__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut, m__out_stateOut;
    };

    struct VA__OnepoleC__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_Omega, m__out_lowpassOut, m__out_stateOut;
    };

    struct VA__BranchingCutoff__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_stateIn, m__in_attackIn, m__in_releaseIn, m__out_OmegaOut;
    };

    struct VA__BranchingCutoff__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_stateIn, m__in_attackIn, m__in_releaseIn, m__out_OmegaOut;
    };

    struct VA__BranchingCutoff__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_stateIn, m__in_attackIn, m__in_releaseIn, m__out_OmegaOut;
    };

    struct VA__Step__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__Step__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__Step__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__CTF_Color__Internal__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_thresholdIn, m__in_ratioIn, m__in_ratio1In, m__in_softnessIn, m__in_colorIn, m__out_out;
    };

    struct VA__CTF_Color__Internal__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_thresholdIn, m__in_ratioIn, m__in_ratio1In, m__in_softnessIn, m__in_colorIn, m__out_out;
    };

    struct VA__CTF_Color__Internal__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__in_thresholdIn, m__in_ratioIn, m__in_ratio1In, m__in_softnessIn, m__in_colorIn, m__out_out;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___IO
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

    struct VA__ApplyGain__Processor_7___IO
    {
        Vector<double, 2> m__in_b, m__in_in, m__out_out;
    };

    struct VA__ApplyGains__Processor___IO
    {
        Vector<double, 2> m__in_b, m__in_b1, m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux3To1Fs__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__out_out;
    };

    struct VA__Mux3To1Fs__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__in_in2, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Sum__Processor___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Sum__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Sum__Processor_3___IO
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

    struct VA__Difference__Processor_5___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__Difference__Processor_6___IO
    {
        Vector<double, 2> m__in_in, m__in_in1, m__out_out;
    };

    struct VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___IO
    {
        Vector<double, 2> m__in_dryIn, m__in_wetIn, m__out_out;
    };

    struct VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA__SmoothedParameter__Mode
    {
        int32_t m_idx, m_numIn, m_numOut, m_funcD, m_funcE;
        double m_slewRateSeconds;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___IO
    {
        Vector<double, 2> m__out_out, m__out_out1;
    };

    struct VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___IO
    {
        Vector<double, 2> m__out_out;
    };

    struct VA___AbsADAA__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA___AbsADAA__Internal__Processor___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA___AbsADAA__Internal__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA___AbsADAA__Internal__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA___AbsADAA__Processor_2___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
    };

    struct VA___AbsADAA__Processor_3___IO
    {
        Vector<double, 2> m__in_in, m__out_out;
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
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___IO _5 = {};

        _2 = _internal___minInt32 (1024, maxFrames);
        _updateRampingStreams (_state, _2);
        _state.m__frameCount = 0;
        _main_loop_check: { if (! (_state.m__frameCount < _2)) goto _exit; }
        _main_loop_body: { _3 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_in, _state.m__frameCount);
                           _4 = _readFromStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_scIn, _state.m__frameCount);
                           _5 = ZeroInitialiser();
                           _5.m__in_in = _3;
                           _5.m__in_scIn = _4;
                           VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e__run (_state.m_e_state, _5);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_out, _state.m__frameCount, _5.m__out_out);
                           _writeToStream_struct__Stream_out_vec_2_f64_1024 (_state.m__out_guiOut, _state.m__frameCount, _5.m__out_guiOut);
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
        _state.m_e_state.m__processorId = 93;
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___initialise (_state.m_e_state);
    }

    void _addInputEvent_attackIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___attackIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_releaseIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___releaseIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_thresholdIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___thresholdIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_ratioIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___ratioIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_ratio1In_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___ratio1In_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_makeupIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___makeupIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_sidechainIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___sidechainIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_cutoffHP_In_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___cutoffHP_In_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_stereoLinkIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___stereoLinkIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_softnessIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___softnessIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_colorIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___colorIn_f32 (_state.m_e_state, event);
    }

    void _addInputEvent_mixIn_f32 (_State& _state, const float& event) noexcept
    {
        VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___mixIn_f32 (_state.m_e_state, event);
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

    FixedArray<Vector<double, 2>, 1024>& _getInputFrameArrayRef_scIn (_State& _state) noexcept
    {
        return _state.m__in_scIn.m_buffer;
    }

    void _setSparseInputTarget_scIn (_State& _state, const Vector<double, 2>& targetValue, int32_t framesToReachTarget) noexcept
    {
        if (_state.m__in_scIn.m_sparseStreamActive) goto _block_1;
        _block_0: { _addRampingStream (_state.m__sparseStreamStatus, 1); }
        _block_1: { _setSparseStream_struct__Stream_in_vec_2_f64_1024 (_state.m__in_scIn, targetValue, framesToReachTarget); }
    }

    FixedArray<Vector<double, 2>, 1024>& _getOutputFrameArrayRef_out (_State& state) noexcept
    {
        return state.m__out_out.m_buffer;
    }

    FixedArray<Vector<double, 2>, 1024>& _getOutputFrameArrayRef_guiOut (_State& state) noexcept
    {
        return state.m__out_guiOut.m_buffer;
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
        _case_1: { rampComplete = _applySparseStreamData_struct__Stream_in_vec_2_f64_1024 (_state.m__in_scIn, framesToRender); }
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

    Vector<double, 2> soul__intrinsics___tan_specialised_2 (Vector<double, 2> n) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = _vec_sin (n);
        _3 = _vec_cos (n);
        return _2 / _3;
    }

    Vector<double, 2> soul__intrinsics___log10_specialised_3 (Vector<double, 2> n) noexcept
    {
        return ZeroInitialiser();
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
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___frequencyIn_f32 (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State&
    _state, float v) noexcept
    {
        _state.m_frequency = v;
        _state.m_recalc = true;
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___IO& _io) noexcept
    {
        Vector<double, 2> out_value_highpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_highpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 1.0) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 1.0), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_highpassOut = out_value_highpassOut + y[1];
                   _state.m__resumePoint = 1;
                   _io.m__out_highpassOut = out_value_highpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___State&
    _state) noexcept
    {
        _state.m_frequency = 1.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 1.0) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 1.0), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___State&
    _state) noexcept
    {
        _state.m_frequency = 10000.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___frequencyIn_f32 (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State&
    _state, float v) noexcept
    {
        _state.m_frequency = v;
        _state.m_recalc = true;
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___IO& _io) noexcept
    {
        Vector<double, 2> out_value_highpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_highpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 0.5) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 0.5), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_highpassOut = out_value_highpassOut + y[1];
                   _state.m__resumePoint = 1;
                   _io.m__out_highpassOut = out_value_highpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___State&
    _state) noexcept
    {
        _state.m_frequency = 1.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 0.5) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 0.5), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___State&
    _state) noexcept
    {
        _state.m_frequency = 10000.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___frequencyIn_f32 (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State&
    _state, float v) noexcept
    {
        _state.m_frequency = v;
        _state.m_recalc = true;
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___IO& _io) noexcept
    {
        Vector<double, 2> out_value_highpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_highpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 0.25) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 0.25), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_highpassOut = out_value_highpassOut + y[1];
                   _state.m__resumePoint = 1;
                   _io.m__out_highpassOut = out_value_highpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___State&
    _state) noexcept
    {
        _state.m_frequency = 1.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1__run (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___State&
    _state, soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, _2 = {};
        int32_t _resumePoint = {};
        double _3 = {};
        double clippedFrequency = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 _3 = soul__intrinsics___clamp_specialised (static_cast<double> (_state.m_frequency), 5.0, (sampleRate * 0.25) * 0.49);
                 clippedFrequency = static_cast<double> (_3);
                 soul___filters__tpt__svf__update (_state.m_c, (sampleRate * 0.25), static_cast<double> (clippedFrequency), static_cast<double> (_state.m_quality));
        }
        _ifnot_0: { _state.m_counter_1 = 1024; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = _io.m__in_in;
                   _4 = soul___filters__tpt__svf__process (_state.m_s, _2, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___initialise (soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___State&
    _state) noexcept
    {
        _state.m_frequency = 10000.0f;
        _state.m_quality = 0.70710677f;
        _state.m_recalc = true;
    }

    //==============================================================================
    Vector<double, 2> VA__vStep (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__viflt (ZeroInitialiser(), Vector<double, 2> { { 1.0, 1.0 } }, x, ZeroInitialiser());
        return _2;
    }

    Vector<double, 2> VA__vCTF_Color (Vector<double, 2> x, Vector<double, 2> threshold, Vector<double, 2> ratio, Vector<double, 2> ratio1, Vector<double, 2> softness, Vector<double, 2> color) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _9 = {}, _10 = {}, _11 = {}, _12 = {}, _13 = {};
        Vector<double, 2> xdB = {}, xdBmthr = {}, divRatio = {}, divRatio1 = {}, softnessDiv2 = {}, thresholdPlus = {}, c = {}, b = {}, a = {}, softKnee = {}, divColorWidth = {}, colorInternal = {}, ydB = {}, y = {};

        _2 = VA__vGainTodB (x);
        xdB = static_cast<Vector<double, 2>> (_2);
        xdBmthr = xdB - static_cast<Vector<double, 2>> (threshold);
        divRatio = Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (ratio);
        divRatio1 = Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (ratio1);
        softnessDiv2 = static_cast<Vector<double, 2>> (softness * Vector<double, 2> { { 0.5, 0.5 } });
        thresholdPlus = static_cast<Vector<double, 2>> (threshold + static_cast<Vector<double, 2>> (softnessDiv2));
        _3 = VA__vmax (softness * Vector<double, 2> { { 2.0, 2.0 } }, Vector<double, 2> { { 0.000006055454452393343, 0.000006055454452393343 } });
        c = (divRatio - divRatio1) / static_cast<Vector<double, 2>> (_3);
        b = divRatio - static_cast<Vector<double, 2>> ((Vector<double, 2> { { 2.0, 2.0 } } * static_cast<Vector<double, 2>> (c)) * static_cast<Vector<double, 2>> (thresholdPlus));
        _4 = VA___vpow_specialised (static_cast<Vector<double, 2>> (thresholdPlus), 2);
        a = static_cast<Vector<double, 2>> ((threshold - (threshold * static_cast<Vector<double, 2>> (divRatio))) + static_cast<Vector<double, 2>> (c * static_cast<Vector<double, 2>> (_4)));
        _5 = VA___vpow_specialised (static_cast<Vector<double, 2>> (xdB), 2);
        softKnee = (a + (b * xdB)) + (c * static_cast<Vector<double, 2>> (_5));
        _6 = VA__vabs (color);
        _7 = VA__vmax (_6, Vector<double, 2> { { 1.0, 1.0 } });
        divColorWidth = Vector<double, 2> { { 1.0, 1.0 } } / static_cast<Vector<double, 2>> (_7);
        _8 = VA___vpow_specialised (static_cast<Vector<double, 2>> (xdBmthr * divColorWidth), 2);
        colorInternal = static_cast<Vector<double, 2>> (color / (Vector<double, 2> { { 1.0, 1.0 } } + _8));
        _9 = VA__viflt (static_cast<Vector<double, 2>> (softKnee), threshold + static_cast<Vector<double, 2>> (xdBmthr * divRatio), static_cast<Vector<double, 2>> (xdBmthr), static_cast<Vector<double, 2>> (softnessDiv2));
        _10 = VA__viflt (threshold + static_cast<Vector<double, 2>> (xdBmthr * divRatio1), _9, static_cast<Vector<double, 2>> (xdBmthr), static_cast<Vector<double, 2>> (-softnessDiv2));
        ydB = static_cast<Vector<double, 2>> (_10 + static_cast<Vector<double, 2>> (colorInternal));
        _11 = VA__vdBtoGain (static_cast<Vector<double, 2>> (ydB));
        _12 = VA__vmin (_11 / x, Vector<double, 2> { { 1.5, 1.5 } });
        y = static_cast<Vector<double, 2>> (_12);
        _13 = VA__viflt (Vector<double, 2> { { 1.0, 1.0 } }, static_cast<Vector<double, 2>> (y), x, Vector<double, 2> { { 0.00001, 0.00001 } });
        return _13;
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

    Vector<double, 2> VA__vTauToOmega (float x) noexcept
    {
        return Vector<double, 2> (1000.0f / x);
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

    Vector<double, 2> VA__vGainTodB (Vector<double, 2> x) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        Vector<double, 2> b = {};

        _2 = VA__vmax (Vector<double, 2> { { 0.00001, 0.00001 } }, x);
        b = static_cast<Vector<double, 2>> (_2);
        _3 = _vec_log10 (static_cast<Vector<double, 2>> (b));
        return Vector<double, 2> { { 20.0, 20.0 } } * _3;
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

    Vector<double, 2> VA__vmin (Vector<double, 2> x, Vector<double, 2> x1) noexcept
    {
        Vector<double, 2> _2 = {};
        double _3 = {}, _4 = {};

        _2 = ZeroInitialiser();
        _3 = soul__intrinsics___min_specialised (x[0], x1[0]);
        _2[0] = _3;
        _4 = soul__intrinsics___min_specialised (x[1], x1[1]);
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
    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___initialise (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 1;
        VA__DC_Blocker__Processor___initialise (_state.m_dcBlocker_state);
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 2;
        _state.m_mux2To1_state.m__arrayEntry = 0;
        _state.m_mux2To1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_state.m__processorId = 3;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___initialise (_state.m_mux2To1_state);
        _state.m_pSvf_state.m__arrayEntry = 0;
        _state.m_pSvf_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf_state.m__processorId = 4;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___initialise (_state.m_pSvf_state);
        _state.m_absADAA_state.m__arrayEntry = 0;
        _state.m_absADAA_state.m__sessionID = _state.m__sessionID;
        _state.m_absADAA_state.m__processorId = 5;
        VA___AbsADAA__Processor___initialise (_state.m_absADAA_state);
        _state.m_pSvf1_state.m__arrayEntry = 0;
        _state.m_pSvf1_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf1_state.m__processorId = 6;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___initialise (_state.m_pSvf1_state);
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 7;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_ballisticsFilter_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter_state.m__processorId = 8;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___initialise (_state.m_ballisticsFilter_state);
        _state.m_ctfColor_state.m__arrayEntry = 0;
        _state.m_ctfColor_state.m__sessionID = _state.m__sessionID;
        _state.m_ctfColor_state.m__processorId = 9;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___initialise (_state.m_ctfColor_state);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0__run (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__DC_Blocker__Processor___IO _4 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___IO _5 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___IO _6 = {};
        VA___AbsADAA__Processor___IO _7 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1___IO _8 = {};
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___IO _9 = {};
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___IO _10 = {};
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___IO _11 = {};
        VA__ApplyGain__Processor_2___IO _12 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_scIn;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        VA__DC_Blocker__Processor__run (_state.m_dcBlocker_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1__run (_state.m_mux2To1_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf__run (_state.m_pSvf_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_highpassOut;
        VA___AbsADAA__Processor__run (_state.m_absADAA_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf1__run (_state.m_pSvf1_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_lowpassOut;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink__run (_state.m_stereoLink_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _9.m__out_out;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter__run (_state.m_ballisticsFilter_state, _10);
        _11 = ZeroInitialiser();
        _11.m__in_in = _10.m__out_out;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor__run (_state.m_ctfColor_state, _11);
        _12 = ZeroInitialiser();
        _12.m__in_b = _11.m__out_out;
        _12.m__in_in = _4.m__out_out;
        VA__ApplyGain__Processor_2__run (_state.m_applyGain_state, _12);
        _io.m__out_out = _12.m__out_out;
        _io.m__out_guiOut = _11.m__out_out;
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___sidechainIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___idxIn_f32 (_state.m_mux2To1_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___attackIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___attackIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___releaseIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___releaseIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___stereoLinkIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___stereoLinkIn_f32 (_state.m_stereoLink_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___thresholdIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___thresholdIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___ratioIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___ratioIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___ratio1In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___ratio1In_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___softnessIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___softnessIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___colorIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___colorIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___cutoffHP_In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___State&
    _state, float event) noexcept
    {
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_pSvf___frequencyIn_f32 (_state.m_pSvf_state, event);
    }

    //==============================================================================
    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___initialise (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 10;
        VA__DC_Blocker__Processor_2___initialise (_state.m_dcBlocker_state);
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 11;
        _state.m_mux2To1_state.m__arrayEntry = 0;
        _state.m_mux2To1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_state.m__processorId = 12;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___initialise (_state.m_mux2To1_state);
        _state.m_pSvf_state.m__arrayEntry = 0;
        _state.m_pSvf_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf_state.m__processorId = 13;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___initialise (_state.m_pSvf_state);
        _state.m_absADAA_state.m__arrayEntry = 0;
        _state.m_absADAA_state.m__sessionID = _state.m__sessionID;
        _state.m_absADAA_state.m__processorId = 14;
        VA___AbsADAA__Processor_2___initialise (_state.m_absADAA_state);
        _state.m_pSvf1_state.m__arrayEntry = 0;
        _state.m_pSvf1_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf1_state.m__processorId = 15;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___initialise (_state.m_pSvf1_state);
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 16;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_ballisticsFilter_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter_state.m__processorId = 17;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___initialise (_state.m_ballisticsFilter_state);
        _state.m_ctfColor_state.m__arrayEntry = 0;
        _state.m_ctfColor_state.m__sessionID = _state.m__sessionID;
        _state.m_ctfColor_state.m__processorId = 18;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___initialise (_state.m_ctfColor_state);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2__run (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__DC_Blocker__Processor_2___IO _4 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___IO _5 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___IO _6 = {};
        VA___AbsADAA__Processor_2___IO _7 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1___IO _8 = {};
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___IO _9 = {};
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___IO _10 = {};
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___IO _11 = {};
        VA__ApplyGain__Processor_3___IO _12 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_scIn;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        VA__DC_Blocker__Processor_2__run (_state.m_dcBlocker_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1__run (_state.m_mux2To1_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf__run (_state.m_pSvf_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_highpassOut;
        VA___AbsADAA__Processor_2__run (_state.m_absADAA_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf1__run (_state.m_pSvf1_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_lowpassOut;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink__run (_state.m_stereoLink_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _9.m__out_out;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter__run (_state.m_ballisticsFilter_state, _10);
        _11 = ZeroInitialiser();
        _11.m__in_in = _10.m__out_out;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor__run (_state.m_ctfColor_state, _11);
        _12 = ZeroInitialiser();
        _12.m__in_b = _11.m__out_out;
        _12.m__in_in = _4.m__out_out;
        VA__ApplyGain__Processor_3__run (_state.m_applyGain_state, _12);
        _io.m__out_out = _12.m__out_out;
        _io.m__out_guiOut = _11.m__out_out;
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___sidechainIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___idxIn_f32 (_state.m_mux2To1_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___attackIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___attackIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___releaseIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___releaseIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___stereoLinkIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___stereoLinkIn_f32 (_state.m_stereoLink_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___thresholdIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___thresholdIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___ratioIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___ratioIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___ratio1In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___ratio1In_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___softnessIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___softnessIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___colorIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___colorIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___cutoffHP_In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, float event) noexcept
    {
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_pSvf___frequencyIn_f32 (_state.m_pSvf_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___run_undersampled (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___State&
    _state, VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___IO& _io) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerWrite (_state.m__scIn_src, _io.m__in_scIn);
        if (! (_state.m__undersamplingCount == 0)) goto _continue;
        _process_block: { VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerRead (_state.m__in_src, _io.m__in_in);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerRead (_state.m__scIn_src, _io.m__in_scIn);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2__run (_state, _io);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerWrite (_state.m__out_src, _io.m__out_out);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerWrite (_state.m__guiOut_src, _io.m__out_guiOut);
        }
        _continue: { _state.m__undersamplingCount = _internal___wrapInt32 (_state.m__undersamplingCount + 1, 2);
                     VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerRead (_state.m__out_src, _io.m__out_out);
                     VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerRead (_state.m__guiOut_src, _io.m__out_guiOut);
        }
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerWrite (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___downsamplerRead (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
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

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerWrite (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
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

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___upsamplerRead (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___SampleRateConverter_vec_2_f64_2&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    //==============================================================================
    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___initialise (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state) noexcept
    {
        _state.m_dcBlocker_state.m__arrayEntry = 0;
        _state.m_dcBlocker_state.m__sessionID = _state.m__sessionID;
        _state.m_dcBlocker_state.m__processorId = 19;
        VA__DC_Blocker__Processor_3___initialise (_state.m_dcBlocker_state);
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 20;
        _state.m_mux2To1_state.m__arrayEntry = 0;
        _state.m_mux2To1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux2To1_state.m__processorId = 21;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___initialise (_state.m_mux2To1_state);
        _state.m_pSvf_state.m__arrayEntry = 0;
        _state.m_pSvf_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf_state.m__processorId = 22;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___initialise (_state.m_pSvf_state);
        _state.m_absADAA_state.m__arrayEntry = 0;
        _state.m_absADAA_state.m__sessionID = _state.m__sessionID;
        _state.m_absADAA_state.m__processorId = 23;
        VA___AbsADAA__Processor_3___initialise (_state.m_absADAA_state);
        _state.m_pSvf1_state.m__arrayEntry = 0;
        _state.m_pSvf1_state.m__sessionID = _state.m__sessionID;
        _state.m_pSvf1_state.m__processorId = 24;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___initialise (_state.m_pSvf1_state);
        _state.m_stereoLink_state.m__arrayEntry = 0;
        _state.m_stereoLink_state.m__sessionID = _state.m__sessionID;
        _state.m_stereoLink_state.m__processorId = 25;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___initialise (_state.m_stereoLink_state);
        _state.m_ballisticsFilter_state.m__arrayEntry = 0;
        _state.m_ballisticsFilter_state.m__sessionID = _state.m__sessionID;
        _state.m_ballisticsFilter_state.m__processorId = 26;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___initialise (_state.m_ballisticsFilter_state);
        _state.m_ctfColor_state.m__arrayEntry = 0;
        _state.m_ctfColor_state.m__sessionID = _state.m__sessionID;
        _state.m_ctfColor_state.m__processorId = 27;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___initialise (_state.m_ctfColor_state);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4__run (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__DC_Blocker__Processor_3___IO _4 = {};
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___IO _5 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___IO _6 = {};
        VA___AbsADAA__Processor_3___IO _7 = {};
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1___IO _8 = {};
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___IO _9 = {};
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___IO _10 = {};
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___IO _11 = {};
        VA__ApplyGain__Processor_4___IO _12 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_scIn;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        VA__DC_Blocker__Processor_3__run (_state.m_dcBlocker_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1__run (_state.m_mux2To1_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _5.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf__run (_state.m_pSvf_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _6.m__out_highpassOut;
        VA___AbsADAA__Processor_3__run (_state.m_absADAA_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf1__run (_state.m_pSvf1_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _8.m__out_lowpassOut;
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink__run (_state.m_stereoLink_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _9.m__out_out;
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter__run (_state.m_ballisticsFilter_state, _10);
        _11 = ZeroInitialiser();
        _11.m__in_in = _10.m__out_out;
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor__run (_state.m_ctfColor_state, _11);
        _12 = ZeroInitialiser();
        _12.m__in_b = _11.m__out_out;
        _12.m__in_in = _4.m__out_out;
        VA__ApplyGain__Processor_4__run (_state.m_applyGain_state, _12);
        _io.m__out_out = _12.m__out_out;
        _io.m__out_guiOut = _11.m__out_out;
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___sidechainIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___idxIn_f32 (_state.m_mux2To1_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___attackIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___attackIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___releaseIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___releaseIn_f32 (_state.m_ballisticsFilter_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___stereoLinkIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___stereoLinkIn_f32 (_state.m_stereoLink_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___thresholdIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___thresholdIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___ratioIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___ratioIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___ratio1In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___ratio1In_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___softnessIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___softnessIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___colorIn_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___colorIn_f32 (_state.m_ctfColor_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___cutoffHP_In_f32 (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, float event) noexcept
    {
        soul___filters__tpt__svf__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_pSvf___frequencyIn_f32 (_state.m_pSvf_state, event);
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___run_undersampled (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___State&
    _state, VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___IO& _io) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerWrite (_state.m__scIn_src, _io.m__in_scIn);
        if (! (_state.m__undersamplingCount == 0)) goto _continue;
        _process_block: { VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerRead (_state.m__in_src, _io.m__in_in);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerRead (_state.m__scIn_src, _io.m__in_scIn);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4__run (_state, _io);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerWrite (_state.m__out_src, _io.m__out_out);
                          VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerWrite (_state.m__guiOut_src, _io.m__out_guiOut);
        }
        _continue: { _state.m__undersamplingCount = _internal___wrapInt32 (_state.m__undersamplingCount + 1, 4);
                     VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerRead (_state.m__out_src, _io.m__out_out);
                     VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerRead (_state.m__guiOut_src, _io.m__out_guiOut);
        }
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerWrite (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___downsamplerRead (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
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

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerWrite (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
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

    void VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___upsamplerRead (VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___SampleRateConverter_vec_2_f64_4&
    state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    //==============================================================================
    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___initialise (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state) noexcept
    {
        _state.m_internalDS0_state.m__arrayEntry = 0;
        _state.m_internalDS0_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS0_state.m__processorId = 28;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___initialise (_state.m_internalDS0_state);
        _state.m_internalDS2_state.m__arrayEntry = 0;
        _state.m_internalDS2_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS2_state.m__processorId = 29;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___initialise (_state.m_internalDS2_state);
        _state.m_internalDS4_state.m__arrayEntry = 0;
        _state.m_internalDS4_state.m__sessionID = _state.m__sessionID;
        _state.m_internalDS4_state.m__processorId = 30;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___initialise (_state.m_internalDS4_state);
        _state.m_mux3To1Fs_state.m__arrayEntry = 0;
        _state.m_mux3To1Fs_state.m__sessionID = _state.m__sessionID;
        _state.m_mux3To1Fs_state.m__processorId = 31;
        _state.m_mux3To1Fs1_state.m__arrayEntry = 0;
        _state.m_mux3To1Fs1_state.m__sessionID = _state.m__sessionID;
        _state.m_mux3To1Fs1_state.m__processorId = 32;
        _state.m_smoothedMixPan_state.m__arrayEntry = 0;
        _state.m_smoothedMixPan_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedMixPan_state.m__processorId = 33;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___initialise (_state.m_smoothedMixPan_state);
        _state.m_smoothedVolume_state.m__arrayEntry = 0;
        _state.m_smoothedVolume_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedVolume_state.m__processorId = 34;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___initialise (_state.m_smoothedVolume_state);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e__run (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___IO _4 = {};
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___IO _5 = {};
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___IO _6 = {};
        VA__Mux3To1Fs__Processor___IO _7 = {};
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___IO _8 = {};
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___IO _9 = {};
        VA__Mux3To1Fs__Processor_2___IO _10 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_scIn;
        _4 = ZeroInitialiser();
        _4.m__in_in = _2;
        _4.m__in_scIn = _3;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0__run (_state.m_internalDS0_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_scIn = _3;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___run_undersampled (_state.m_internalDS2_state, _5);
        _6 = ZeroInitialiser();
        _6.m__in_in = _2;
        _6.m__in_scIn = _3;
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___run_undersampled (_state.m_internalDS4_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _4.m__out_out;
        _7.m__in_in1 = _5.m__out_out;
        _7.m__in_in2 = _6.m__out_out;
        VA__Mux3To1Fs__Processor__run (_state.m_mux3To1Fs_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume__run (_state.m_smoothedVolume_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_dryIn = _2;
        _9.m__in_wetIn = _8.m__out_out;
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan__run (_state.m_smoothedMixPan_state, _9);
        _io.m__out_out = _9.m__out_out;
        _10 = ZeroInitialiser();
        _10.m__in_in = _4.m__out_guiOut;
        _10.m__in_in1 = _5.m__out_guiOut;
        _10.m__in_in2 = _6.m__out_guiOut;
        VA__Mux3To1Fs__Processor_2__run (_state.m_mux3To1Fs1_state, _10);
        _io.m__out_guiOut = _10.m__out_out;
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___attackIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___attackIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___attackIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___attackIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___releaseIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___releaseIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___releaseIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___releaseIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___thresholdIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___thresholdIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___thresholdIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___thresholdIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___ratioIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___ratioIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___ratioIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___ratioIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___ratio1In_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___ratio1In_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___ratio1In_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___ratio1In_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___sidechainIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___sidechainIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___sidechainIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___sidechainIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___cutoffHP_In_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___cutoffHP_In_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___cutoffHP_In_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___cutoffHP_In_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___stereoLinkIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___stereoLinkIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___stereoLinkIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___stereoLinkIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___softnessIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___softnessIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___softnessIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___softnessIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___colorIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0___colorIn_f32 (_state.m_internalDS0_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2___colorIn_f32 (_state.m_internalDS2_state, event);
        VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4___colorIn_f32 (_state.m_internalDS4_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___makeupIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___volumeIn_f32 (_state.m_smoothedVolume_state, event);
    }

    void VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___mixIn_f32 (VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e___State& _state, float event) noexcept
    {
        VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___mixIn_f32 (_state.m_smoothedMixPan_state, event);
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
    void VA__BallisticsFilter__Internal__Processor___initialise (VA__BallisticsFilter__Internal__Processor___State& _state) noexcept
    {
        _state.m_branchingCutoff_state.m__arrayEntry = 0;
        _state.m_branchingCutoff_state.m__sessionID = _state.m__sessionID;
        _state.m_branchingCutoff_state.m__processorId = 38;
        VA__BranchingCutoff__Processor___initialise (_state.m_branchingCutoff_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 39;
    }

    void VA__BallisticsFilter__Internal__Processor__run (VA__BallisticsFilter__Internal__Processor___State& _state, VA__BallisticsFilter__Internal__Processor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _6 = {}, _7 = {};
        VA__BranchingCutoff__Processor___IO _8 = {};
        VA__OnepoleC__Processor___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_attackIn;
        _4 = _io.m__in_releaseIn;
        _6 = _state.m__delayState_1.m_index;
        _5 = _state.m__delayState_1.m_buffer[_6];
        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_stateIn = _5;
        _8.m__in_attackIn = _3;
        _8.m__in_releaseIn = _4;
        VA__BranchingCutoff__Processor__run (_state.m_branchingCutoff_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _2;
        _9.m__in_Omega = _8.m__out_OmegaOut;
        VA__OnepoleC__Processor__run (_state.m_onepoleC_state, _9);
        _io.m__out_out = _9.m__out_lowpassOut;
        _7 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_7] = _9.m__out_stateOut;
        _state.m__delayState_1.m_index = (_7 + 1) & 0;
    }

    void VA__BallisticsFilter__Internal__Processor___run_oversampled (VA__BallisticsFilter__Internal__Processor___State& _state, VA__BallisticsFilter__Internal__Processor___IO& _io) noexcept
    {
        VA__BallisticsFilter__Internal__Processor___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor___upsamplerWrite (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor___upsamplerWrite (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA__BallisticsFilter__Internal__Processor___upsamplerWrite (VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA__BallisticsFilter__Internal__Processor___upsamplerRead (VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor___downsamplerWrite (VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor___downsamplerRead (VA__BallisticsFilter__Internal__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA__BallisticsFilter__Internal__Processor_2___initialise (VA__BallisticsFilter__Internal__Processor_2___State& _state) noexcept
    {
        _state.m_branchingCutoff_state.m__arrayEntry = 0;
        _state.m_branchingCutoff_state.m__sessionID = _state.m__sessionID;
        _state.m_branchingCutoff_state.m__processorId = 40;
        VA__BranchingCutoff__Processor_2___initialise (_state.m_branchingCutoff_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 41;
    }

    void VA__BallisticsFilter__Internal__Processor_2__run (VA__BallisticsFilter__Internal__Processor_2___State& _state, VA__BallisticsFilter__Internal__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _6 = {}, _7 = {};
        VA__BranchingCutoff__Processor_2___IO _8 = {};
        VA__OnepoleC__Processor_2___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_attackIn;
        _4 = _io.m__in_releaseIn;
        _6 = _state.m__delayState_1.m_index;
        _5 = _state.m__delayState_1.m_buffer[_6];
        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_stateIn = _5;
        _8.m__in_attackIn = _3;
        _8.m__in_releaseIn = _4;
        VA__BranchingCutoff__Processor_2__run (_state.m_branchingCutoff_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _2;
        _9.m__in_Omega = _8.m__out_OmegaOut;
        VA__OnepoleC__Processor_2__run (_state.m_onepoleC_state, _9);
        _io.m__out_out = _9.m__out_lowpassOut;
        _7 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_7] = _9.m__out_stateOut;
        _state.m__delayState_1.m_index = (_7 + 1) & 0;
    }

    void VA__BallisticsFilter__Internal__Processor_2___run_oversampled (VA__BallisticsFilter__Internal__Processor_2___State& _state, VA__BallisticsFilter__Internal__Processor_2___IO& _io) noexcept
    {
        VA__BallisticsFilter__Internal__Processor_2___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerWrite (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerWrite (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_2__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_2__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor_2___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA__BallisticsFilter__Internal__Processor_2___upsamplerWrite (VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA__BallisticsFilter__Internal__Processor_2___upsamplerRead (VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor_2___downsamplerWrite (VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor_2___downsamplerRead (VA__BallisticsFilter__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA__BallisticsFilter__Internal__Processor_3___initialise (VA__BallisticsFilter__Internal__Processor_3___State& _state) noexcept
    {
        _state.m_branchingCutoff_state.m__arrayEntry = 0;
        _state.m_branchingCutoff_state.m__sessionID = _state.m__sessionID;
        _state.m_branchingCutoff_state.m__processorId = 42;
        VA__BranchingCutoff__Processor_3___initialise (_state.m_branchingCutoff_state);
        _state.m_onepoleC_state.m__arrayEntry = 0;
        _state.m_onepoleC_state.m__sessionID = _state.m__sessionID;
        _state.m_onepoleC_state.m__processorId = 43;
    }

    void VA__BallisticsFilter__Internal__Processor_3__run (VA__BallisticsFilter__Internal__Processor_3___State& _state, VA__BallisticsFilter__Internal__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        int32_t _6 = {}, _7 = {};
        VA__BranchingCutoff__Processor_3___IO _8 = {};
        VA__OnepoleC__Processor_3___IO _9 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_attackIn;
        _4 = _io.m__in_releaseIn;
        _6 = _state.m__delayState_1.m_index;
        _5 = _state.m__delayState_1.m_buffer[_6];
        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_stateIn = _5;
        _8.m__in_attackIn = _3;
        _8.m__in_releaseIn = _4;
        VA__BranchingCutoff__Processor_3__run (_state.m_branchingCutoff_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_in = _2;
        _9.m__in_Omega = _8.m__out_OmegaOut;
        VA__OnepoleC__Processor_3__run (_state.m_onepoleC_state, _9);
        _io.m__out_out = _9.m__out_lowpassOut;
        _7 = _state.m__delayState_1.m_index;
        _state.m__delayState_1.m_buffer[_7] = _9.m__out_stateOut;
        _state.m__delayState_1.m_index = (_7 + 1) & 0;
    }

    void VA__BallisticsFilter__Internal__Processor_3___run_oversampled (VA__BallisticsFilter__Internal__Processor_3___State& _state, VA__BallisticsFilter__Internal__Processor_3___IO& _io) noexcept
    {
        VA__BallisticsFilter__Internal__Processor_3___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerWrite (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerWrite (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_3__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor_3___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__attackIn_src, _io.m__in_attackIn);
        VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (_state.m__releaseIn_src, _io.m__in_releaseIn);
        VA__BallisticsFilter__Internal__Processor_3__run (_state, _io);
        VA__BallisticsFilter__Internal__Processor_3___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA__BallisticsFilter__Internal__Processor_3___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA__BallisticsFilter__Internal__Processor_3___upsamplerWrite (VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA__BallisticsFilter__Internal__Processor_3___upsamplerRead (VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor_3___downsamplerWrite (VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA__BallisticsFilter__Internal__Processor_3___downsamplerRead (VA__BallisticsFilter__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___initialise (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State&
    _state) noexcept
    {
        _state.m_unsmoothedParameter_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter_state.m__processorId = 44;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___initialise (_state.m_unsmoothedParameter_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 45;
        VA__BallisticsFilter__Internal__Processor___initialise (_state.m_internal_state);
        _state.m_unsmoothedParameter1_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter1_state.m__processorId = 46;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___initialise (_state.m_unsmoothedParameter1_state);

    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter__run (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___IO _3 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___IO _4 = {};
        VA__BallisticsFilter__Internal__Processor___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter__run (_state.m_unsmoothedParameter_state,
         _3);
        _4 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1__run (_state.m_unsmoothedParameter1_state,
         _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_attackIn = _3.m__out_out;
        _5.m__in_releaseIn = _4.m__out_out;
        VA__BallisticsFilter__Internal__Processor___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___attackIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___in_f32 (_state.m_unsmoothedParameter_state,
         event);
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___releaseIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___in_f32 (_state.m_unsmoothedParameter1_state,
         event);
    }

    //==============================================================================
    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___initialise (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State&
    _state) noexcept
    {
        _state.m_unsmoothedParameter_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter_state.m__processorId = 47;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___initialise (_state.m_unsmoothedParameter_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 48;
        VA__BallisticsFilter__Internal__Processor_2___initialise (_state.m_internal_state);
        _state.m_unsmoothedParameter1_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter1_state.m__processorId = 49;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___initialise (_state.m_unsmoothedParameter1_state);

    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter__run (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___IO _3 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___IO _4 = {};
        VA__BallisticsFilter__Internal__Processor_2___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter__run (_state.m_unsmoothedParameter_state,
         _3);
        _4 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1__run (_state.m_unsmoothedParameter1_state,
         _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_attackIn = _3.m__out_out;
        _5.m__in_releaseIn = _4.m__out_out;
        VA__BallisticsFilter__Internal__Processor_2___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___attackIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___in_f32 (_state.m_unsmoothedParameter_state,
         event);
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___releaseIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___in_f32 (_state.m_unsmoothedParameter1_state,
         event);
    }

    //==============================================================================
    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___initialise (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State&
    _state) noexcept
    {
        _state.m_unsmoothedParameter_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter_state.m__processorId = 50;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___initialise (_state.m_unsmoothedParameter_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 51;
        VA__BallisticsFilter__Internal__Processor_3___initialise (_state.m_internal_state);
        _state.m_unsmoothedParameter1_state.m__arrayEntry = 0;
        _state.m_unsmoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_unsmoothedParameter1_state.m__processorId = 52;
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___initialise (_state.m_unsmoothedParameter1_state);

    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter__run (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State&
    _state, VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___IO _3 = {};
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___IO _4 = {};
        VA__BallisticsFilter__Internal__Processor_3___IO _5 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter__run (_state.m_unsmoothedParameter_state,
         _3);
        _4 = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1__run (_state.m_unsmoothedParameter1_state,
         _4);
        _5 = ZeroInitialiser();
        _5.m__in_in = _2;
        _5.m__in_attackIn = _3.m__out_out;
        _5.m__in_releaseIn = _4.m__out_out;
        VA__BallisticsFilter__Internal__Processor_3___run_oversampled (_state.m_internal_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___attackIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___in_f32 (_state.m_unsmoothedParameter_state,
         event);
    }

    void VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___releaseIn_f32 (VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter___State&
    _state, float event) noexcept
    {
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___in_f32 (_state.m_unsmoothedParameter1_state,
         event);
    }

    //==============================================================================
    void VA__OnepoleC__updatePerSample (VA__OnepoleC__Coeffs& c, Vector<double, 2> Omega, double fs) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vOmegaToG_Onepole (Omega, fs);
        c.m_G = _2;
    }

    FixedArray<Vector<double, 2>, 3> VA__OnepoleC__process (VA__OnepoleC__State& s, Vector<double, 2> x, const VA__OnepoleC__Coeffs& c) noexcept
    {
        Vector<double, 2> v = {}, lpf = {}, hpf = {};
        FixedArray<Vector<double, 2>, 3> _2 = {};

        v = static_cast<Vector<double, 2>> ((x - s.m_s) * c.m_G);
        lpf = v + static_cast<Vector<double, 2>> (s.m_s);
        hpf = static_cast<Vector<double, 2>> (x - static_cast<Vector<double, 2>> (lpf));
        s.m_s = static_cast<Vector<double, 2>> (v + lpf);
        _2 = ZeroInitialiser();
        _2[0] = static_cast<Vector<double, 2>> (lpf);
        _2[1] = static_cast<Vector<double, 2>> (hpf);
        _2[2] = s.m_s;
        return _2;
    }

    //==============================================================================
    void VA__OnepoleC__Processor__run (VA__OnepoleC__Processor___State& _state, VA__OnepoleC__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, out_value_stateOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        out_value_stateOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 2.0));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   out_value_stateOut = out_value_stateOut + y[2];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   _io.m__out_stateOut = out_value_stateOut;
        }
    }

    //==============================================================================
    void VA__OnepoleC__Processor_2__run (VA__OnepoleC__Processor_2___State& _state, VA__OnepoleC__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, out_value_stateOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        out_value_stateOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 1.0));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   out_value_stateOut = out_value_stateOut + y[2];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   _io.m__out_stateOut = out_value_stateOut;
        }
    }

    //==============================================================================
    void VA__OnepoleC__Processor_3__run (VA__OnepoleC__Processor_3___State& _state, VA__OnepoleC__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_lowpassOut = {}, out_value_stateOut = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 3> _4 = {};
        FixedArray<Vector<double, 2>, 3> y = {};

        out_value_lowpassOut = ZeroInitialiser();
        out_value_stateOut = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
        }
        _body_0: { _2 = _io.m__in_Omega;
                   VA__OnepoleC__updatePerSample (_state.m_c, _2, (sampleRate * 0.5));
                   _3 = _io.m__in_in;
                   _4 = VA__OnepoleC__process (_state.m_s, _3, _state.m_c);
                   y = static_cast<FixedArray<Vector<double, 2>, 3>> (_4);
                   out_value_lowpassOut = out_value_lowpassOut + y[0];
                   out_value_stateOut = out_value_stateOut + y[2];
                   _state.m__resumePoint = 1;
                   _io.m__out_lowpassOut = out_value_lowpassOut;
                   _io.m__out_stateOut = out_value_stateOut;
        }
    }

    //==============================================================================
    void VA__BranchingCutoff__Processor___initialise (VA__BranchingCutoff__Processor___State& _state) noexcept
    {
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 53;
        _state.m_step_state.m__arrayEntry = 0;
        _state.m_step_state.m__sessionID = _state.m__sessionID;
        _state.m_step_state.m__processorId = 54;
        _state.m_difference1_state.m__arrayEntry = 0;
        _state.m_difference1_state.m__sessionID = _state.m__sessionID;
        _state.m_difference1_state.m__processorId = 55;
        _state.m_sum_state.m__arrayEntry = 0;
        _state.m_sum_state.m__sessionID = _state.m__sessionID;
        _state.m_sum_state.m__processorId = 56;
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 57;
    }

    void VA__BranchingCutoff__Processor__run (VA__BranchingCutoff__Processor___State& _state, VA__BranchingCutoff__Processor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        VA__Difference__Processor_2___IO _6 = {};
        VA__Difference__Processor___IO _7 = {};
        VA__Step__Processor___IO _8 = {};
        VA__ApplyGain__Processor___IO _9 = {};
        VA__Sum__Processor___IO _10 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_stateIn;
        _4 = _io.m__in_attackIn;
        _5 = _io.m__in_releaseIn;
        _6 = ZeroInitialiser();
        _6.m__in_in = _4;
        _6.m__in_in1 = _5;
        VA__Difference__Processor_2__run (_state.m_difference1_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_in1 = _3;
        VA__Difference__Processor__run (_state.m_difference_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        VA__Step__Processor__run (_state.m_step_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_b = _6.m__out_out;
        _9.m__in_in = _8.m__out_out;
        VA__ApplyGain__Processor__run (_state.m_applyGain_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _5;
        _10.m__in_in1 = _9.m__out_out;
        VA__Sum__Processor__run (_state.m_sum_state, _10);
        _io.m__out_OmegaOut = _10.m__out_out;
    }

    //==============================================================================
    void VA__BranchingCutoff__Processor_2___initialise (VA__BranchingCutoff__Processor_2___State& _state) noexcept
    {
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 58;
        _state.m_step_state.m__arrayEntry = 0;
        _state.m_step_state.m__sessionID = _state.m__sessionID;
        _state.m_step_state.m__processorId = 59;
        _state.m_difference1_state.m__arrayEntry = 0;
        _state.m_difference1_state.m__sessionID = _state.m__sessionID;
        _state.m_difference1_state.m__processorId = 60;
        _state.m_sum_state.m__arrayEntry = 0;
        _state.m_sum_state.m__sessionID = _state.m__sessionID;
        _state.m_sum_state.m__processorId = 61;
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 62;
    }

    void VA__BranchingCutoff__Processor_2__run (VA__BranchingCutoff__Processor_2___State& _state, VA__BranchingCutoff__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        VA__Difference__Processor_4___IO _6 = {};
        VA__Difference__Processor_3___IO _7 = {};
        VA__Step__Processor_2___IO _8 = {};
        VA__ApplyGain__Processor_5___IO _9 = {};
        VA__Sum__Processor_2___IO _10 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_stateIn;
        _4 = _io.m__in_attackIn;
        _5 = _io.m__in_releaseIn;
        _6 = ZeroInitialiser();
        _6.m__in_in = _4;
        _6.m__in_in1 = _5;
        VA__Difference__Processor_4__run (_state.m_difference1_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_in1 = _3;
        VA__Difference__Processor_3__run (_state.m_difference_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        VA__Step__Processor_2__run (_state.m_step_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_b = _6.m__out_out;
        _9.m__in_in = _8.m__out_out;
        VA__ApplyGain__Processor_5__run (_state.m_applyGain_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _5;
        _10.m__in_in1 = _9.m__out_out;
        VA__Sum__Processor_2__run (_state.m_sum_state, _10);
        _io.m__out_OmegaOut = _10.m__out_out;
    }

    //==============================================================================
    void VA__BranchingCutoff__Processor_3___initialise (VA__BranchingCutoff__Processor_3___State& _state) noexcept
    {
        _state.m_difference_state.m__arrayEntry = 0;
        _state.m_difference_state.m__sessionID = _state.m__sessionID;
        _state.m_difference_state.m__processorId = 63;
        _state.m_step_state.m__arrayEntry = 0;
        _state.m_step_state.m__sessionID = _state.m__sessionID;
        _state.m_step_state.m__processorId = 64;
        _state.m_difference1_state.m__arrayEntry = 0;
        _state.m_difference1_state.m__sessionID = _state.m__sessionID;
        _state.m_difference1_state.m__processorId = 65;
        _state.m_sum_state.m__arrayEntry = 0;
        _state.m_sum_state.m__sessionID = _state.m__sessionID;
        _state.m_sum_state.m__processorId = 66;
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 67;
    }

    void VA__BranchingCutoff__Processor_3__run (VA__BranchingCutoff__Processor_3___State& _state, VA__BranchingCutoff__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {};
        VA__Difference__Processor_6___IO _6 = {};
        VA__Difference__Processor_5___IO _7 = {};
        VA__Step__Processor_3___IO _8 = {};
        VA__ApplyGain__Processor_6___IO _9 = {};
        VA__Sum__Processor_3___IO _10 = {};

        _2 = _io.m__in_in;
        _3 = _io.m__in_stateIn;
        _4 = _io.m__in_attackIn;
        _5 = _io.m__in_releaseIn;
        _6 = ZeroInitialiser();
        _6.m__in_in = _4;
        _6.m__in_in1 = _5;
        VA__Difference__Processor_6__run (_state.m_difference1_state, _6);
        _7 = ZeroInitialiser();
        _7.m__in_in = _2;
        _7.m__in_in1 = _3;
        VA__Difference__Processor_5__run (_state.m_difference_state, _7);
        _8 = ZeroInitialiser();
        _8.m__in_in = _7.m__out_out;
        VA__Step__Processor_3__run (_state.m_step_state, _8);
        _9 = ZeroInitialiser();
        _9.m__in_b = _6.m__out_out;
        _9.m__in_in = _8.m__out_out;
        VA__ApplyGain__Processor_6__run (_state.m_applyGain_state, _9);
        _10 = ZeroInitialiser();
        _10.m__in_in = _5;
        _10.m__in_in1 = _9.m__out_out;
        VA__Sum__Processor_3__run (_state.m_sum_state, _10);
        _io.m__out_OmegaOut = _10.m__out_out;
    }

    //==============================================================================
    void VA__Step__Processor__run (VA__Step__Processor___State& _state, VA__Step__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = VA__vStep (_2);
        out_value_out = out_value_out + _3;
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Step__Processor_2__run (VA__Step__Processor_2___State& _state, VA__Step__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = VA__vStep (_2);
        out_value_out = out_value_out + _3;
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Step__Processor_3__run (VA__Step__Processor_3___State& _state, VA__Step__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = VA__vStep (_2);
        out_value_out = out_value_out + _3;
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__CTF_Color__Internal__updatePerSample (VA__CTF_Color__Internal__Coeffs& c, Vector<double, 2> threshold, Vector<double, 2> ratio, Vector<double, 2> ratio1, Vector<double, 2> softness, Vector<double, 2> color) noexcept
    {
        c.m_threshold = threshold;
        c.m_ratio = ratio;
        c.m_ratio1 = ratio1;
        c.m_softness = softness;
        c.m_color = color;
    }

    Vector<double, 2> VA__CTF_Color__Internal__process (Vector<double, 2> x, const VA__CTF_Color__Internal__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vCTF_Color (x, c.m_threshold, c.m_ratio, c.m_ratio1, c.m_softness, c.m_color);
        return _2;
    }

    //==============================================================================
    void VA__CTF_Color__Internal__Processor__run (VA__CTF_Color__Internal__Processor___State& _state, VA__CTF_Color__Internal__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_thresholdIn;
                   _3 = _io.m__in_ratioIn;
                   _4 = _io.m__in_ratio1In;
                   _5 = _io.m__in_softnessIn;
                   _6 = _io.m__in_colorIn;
                   VA__CTF_Color__Internal__updatePerSample (_state.m_c, _2, _3, _4, _5, _6);
                   _7 = _io.m__in_in;
                   _8 = VA__CTF_Color__Internal__process (_7, _state.m_c);
                   out_value_out = out_value_out + _8;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void VA__CTF_Color__Internal__Processor_2__run (VA__CTF_Color__Internal__Processor_2___State& _state, VA__CTF_Color__Internal__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_thresholdIn;
                   _3 = _io.m__in_ratioIn;
                   _4 = _io.m__in_ratio1In;
                   _5 = _io.m__in_softnessIn;
                   _6 = _io.m__in_colorIn;
                   VA__CTF_Color__Internal__updatePerSample (_state.m_c, _2, _3, _4, _5, _6);
                   _7 = _io.m__in_in;
                   _8 = VA__CTF_Color__Internal__process (_7, _state.m_c);
                   out_value_out = out_value_out + _8;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void VA__CTF_Color__Internal__Processor_3__run (VA__CTF_Color__Internal__Processor_3___State& _state, VA__CTF_Color__Internal__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _body_0;
        _block_0: { _state.m_c = ZeroInitialiser(); }
        _body_0: { _2 = _io.m__in_thresholdIn;
                   _3 = _io.m__in_ratioIn;
                   _4 = _io.m__in_ratio1In;
                   _5 = _io.m__in_softnessIn;
                   _6 = _io.m__in_colorIn;
                   VA__CTF_Color__Internal__updatePerSample (_state.m_c, _2, _3, _4, _5, _6);
                   _7 = _io.m__in_in;
                   _8 = VA__CTF_Color__Internal__process (_7, _state.m_c);
                   out_value_out = out_value_out + _8;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    //==============================================================================
    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___initialise (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 68;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 69;
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 70;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

        _state.m_smoothedParameter2_state.m__arrayEntry = 0;
        _state.m_smoothedParameter2_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter2_state.m__processorId = 71;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___initialise (_state.m_smoothedParameter2_state);

        _state.m_smoothedParameter3_state.m__arrayEntry = 0;
        _state.m_smoothedParameter3_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter3_state.m__processorId = 72;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___initialise (_state.m_smoothedParameter3_state);

        _state.m_smoothedParameter4_state.m__arrayEntry = 0;
        _state.m_smoothedParameter4_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter4_state.m__processorId = 73;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___initialise (_state.m_smoothedParameter4_state);

    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor__run (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___IO _4 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___IO _5 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___IO _6 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___IO _7 = {};
        VA__CTF_Color__Internal__Processor___IO _8 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);

        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);

        _5 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2__run (_state.m_smoothedParameter2_state, _5);

        _6 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3__run (_state.m_smoothedParameter3_state, _6);

        _7 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4__run (_state.m_smoothedParameter4_state, _7);

        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_thresholdIn = _3.m__out_out;
        _8.m__in_ratioIn = _4.m__out_out;
        _8.m__in_ratio1In = _5.m__out_out;
        _8.m__in_softnessIn = _6.m__out_out;
        _8.m__in_colorIn = _7.m__out_out;
        VA__CTF_Color__Internal__Processor__run (_state.m_internal_state, _8);
        _io.m__out_out = _8.m__out_out;
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___thresholdIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___ratioIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___in_f32 (_state.m_smoothedParameter1_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___ratio1In_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___in_f32 (_state.m_smoothedParameter2_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___softnessIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___in_f32 (_state.m_smoothedParameter3_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___colorIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___in_f32 (_state.m_smoothedParameter4_state,
         event);
    }

    //==============================================================================
    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___initialise (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 74;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 75;
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 76;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

        _state.m_smoothedParameter2_state.m__arrayEntry = 0;
        _state.m_smoothedParameter2_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter2_state.m__processorId = 77;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___initialise (_state.m_smoothedParameter2_state);

        _state.m_smoothedParameter3_state.m__arrayEntry = 0;
        _state.m_smoothedParameter3_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter3_state.m__processorId = 78;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___initialise (_state.m_smoothedParameter3_state);

        _state.m_smoothedParameter4_state.m__arrayEntry = 0;
        _state.m_smoothedParameter4_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter4_state.m__processorId = 79;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___initialise (_state.m_smoothedParameter4_state);

    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor__run (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___IO _4 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___IO _5 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___IO _6 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___IO _7 = {};
        VA__CTF_Color__Internal__Processor_2___IO _8 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);

        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);

        _5 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2__run (_state.m_smoothedParameter2_state, _5);

        _6 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3__run (_state.m_smoothedParameter3_state, _6);

        _7 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4__run (_state.m_smoothedParameter4_state, _7);

        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_thresholdIn = _3.m__out_out;
        _8.m__in_ratioIn = _4.m__out_out;
        _8.m__in_ratio1In = _5.m__out_out;
        _8.m__in_softnessIn = _6.m__out_out;
        _8.m__in_colorIn = _7.m__out_out;
        VA__CTF_Color__Internal__Processor_2__run (_state.m_internal_state, _8);
        _io.m__out_out = _8.m__out_out;
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___thresholdIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___ratioIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___in_f32 (_state.m_smoothedParameter1_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___ratio1In_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___in_f32 (_state.m_smoothedParameter2_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___softnessIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___in_f32 (_state.m_smoothedParameter3_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___colorIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___in_f32 (_state.m_smoothedParameter4_state,
         event);
    }

    //==============================================================================
    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___initialise (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state) noexcept
    {
        _state.m_smoothedParameter0_state.m__arrayEntry = 0;
        _state.m_smoothedParameter0_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter0_state.m__processorId = 80;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___initialise (_state.m_smoothedParameter0_state);

        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 81;
        _state.m_smoothedParameter1_state.m__arrayEntry = 0;
        _state.m_smoothedParameter1_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter1_state.m__processorId = 82;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___initialise (_state.m_smoothedParameter1_state);

        _state.m_smoothedParameter2_state.m__arrayEntry = 0;
        _state.m_smoothedParameter2_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter2_state.m__processorId = 83;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___initialise (_state.m_smoothedParameter2_state);

        _state.m_smoothedParameter3_state.m__arrayEntry = 0;
        _state.m_smoothedParameter3_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter3_state.m__processorId = 84;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___initialise (_state.m_smoothedParameter3_state);

        _state.m_smoothedParameter4_state.m__arrayEntry = 0;
        _state.m_smoothedParameter4_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedParameter4_state.m__processorId = 85;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___initialise (_state.m_smoothedParameter4_state);

    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor__run (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___IO _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___IO _4 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___IO _5 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___IO _6 = {};
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___IO _7 = {};
        VA__CTF_Color__Internal__Processor_3___IO _8 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0__run (_state.m_smoothedParameter0_state, _3);

        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1__run (_state.m_smoothedParameter1_state, _4);

        _5 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2__run (_state.m_smoothedParameter2_state, _5);

        _6 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3__run (_state.m_smoothedParameter3_state, _6);

        _7 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4__run (_state.m_smoothedParameter4_state, _7);

        _8 = ZeroInitialiser();
        _8.m__in_in = _2;
        _8.m__in_thresholdIn = _3.m__out_out;
        _8.m__in_ratioIn = _4.m__out_out;
        _8.m__in_ratio1In = _5.m__out_out;
        _8.m__in_softnessIn = _6.m__out_out;
        _8.m__in_colorIn = _7.m__out_out;
        VA__CTF_Color__Internal__Processor_3__run (_state.m_internal_state, _8);
        _io.m__out_out = _8.m__out_out;
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___thresholdIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___in_f32 (_state.m_smoothedParameter0_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___ratioIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___in_f32 (_state.m_smoothedParameter1_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___ratio1In_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___in_f32 (_state.m_smoothedParameter2_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___softnessIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___in_f32 (_state.m_smoothedParameter3_state,
         event);
    }

    void VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___colorIn_f32 (VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor___State&
    _state, float event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___in_f32 (_state.m_smoothedParameter4_state,
         event);
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
    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___stereoLinkIn_f32 (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State&
    _state, float v) noexcept
    {
        _state.m_stereoLink = v;
        _state.m_recalc = true;
    }

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink__run (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
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

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___stereoLinkIn_f32 (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State&
    _state, float v) noexcept
    {
        _state.m_stereoLink = v;
        _state.m_recalc = true;
    }

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink__run (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
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

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___stereoLinkIn_f32 (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State&
    _state, float v) noexcept
    {
        _state.m_stereoLink = v;
        _state.m_recalc = true;
    }

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink__run (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State&
    _state, VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};
        int32_t _resumePoint = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
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

    void VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___initialise (VA__StereoLink__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_stereoLink___State&
    _state) noexcept
    {
        _state.m_stereoLink = 0;
        _state.m_recalc = true;
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
    void VA__ApplyGain__Processor_7__run (VA__ApplyGain__Processor_7___State& _state, VA__ApplyGain__Processor_7___IO& _io) noexcept
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
    void VA__Mux3To1Fs__Processor_2__run (VA__Mux3To1Fs__Processor_2___State& _state, VA__Mux3To1Fs__Processor_2___IO& _io) noexcept
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
    void VA__Mux2To1__update (VA__Mux2To1__Coeffs& c, float idx) noexcept
    {
        c.m_idx = static_cast<int32_t> (idx);
    }

    Vector<double, 2> VA__Mux2To1__process (FixedArray<Vector<double, 2>, 2> x, const VA__Mux2To1__Coeffs& c) noexcept
    {
        return x[_intrin_wrap (static_cast<int32_t> (c.m_idx), 2) & 1];
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State&
    _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State&
    _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
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

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_mux2To1___State&
    _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State&
    _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State&
    _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
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

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_mux2To1___State&
    _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___idxIn_f32 (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State&
    _state, float v) noexcept
    {
        _state.m_idx = v;
        _state.m_recalc = true;
    }

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1__run (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State&
    _state, VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {}, _4 = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _5 = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
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

    void VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___initialise (VA__Mux2To1__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_mux2To1___State&
    _state) noexcept
    {
        _state.m_idx = 0;
        _state.m_recalc = true;
    }

    //==============================================================================
    void VA__Sum__Processor__run (VA__Sum__Processor___State& _state, VA__Sum__Processor___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 + _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Sum__Processor_2__run (VA__Sum__Processor_2___State& _state, VA__Sum__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 + _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
    }

    //==============================================================================
    void VA__Sum__Processor_3__run (VA__Sum__Processor_3___State& _state, VA__Sum__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {}, _2 = {}, _3 = {};

        out_value_out = ZeroInitialiser();
        _2 = _io.m__in_in;
        _3 = _io.m__in_in1;
        out_value_out = out_value_out + (_2 + _3);
        _state.m__resumePoint = 1;
        _io.m__out_out = out_value_out;
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
    void VA__Difference__Processor_5__run (VA__Difference__Processor_5___State& _state, VA__Difference__Processor_5___IO& _io) noexcept
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
    void VA__Difference__Processor_6__run (VA__Difference__Processor_6___State& _state, VA__Difference__Processor_6___IO& _io) noexcept
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
    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___initialise (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State& _state) noexcept
    {
        _state.m_smoothedGains_state.m__arrayEntry = 0;
        _state.m_smoothedGains_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGains_state.m__processorId = 86;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___initialise (_state.m_smoothedGains_state);
        _state.m_applyGains_state.m__arrayEntry = 0;
        _state.m_applyGains_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGains_state.m__processorId = 87;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan__run (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State& _state, VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___IO _4 = {};
        VA__ApplyGains__Processor___IO _5 = {};

        _2 = _io.m__in_dryIn;
        _3 = _io.m__in_wetIn;
        _4 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains__run (_state.m_smoothedGains_state, _4);
        _5 = ZeroInitialiser();
        _5.m__in_b = _4.m__out_out;
        _5.m__in_b1 = _4.m__out_out1;
        _5.m__in_in = _2;
        _5.m__in_in1 = _3;
        VA__ApplyGains__Processor__run (_state.m_applyGains_state, _5);
        _io.m__out_out = _5.m__out_out;
    }

    void VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___mixIn_f32 (VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan___State& _state, float event)
    noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___in_f32 (_state.m_smoothedGains_state, event);
    }

    //==============================================================================
    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___initialise (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State& _state) noexcept
    {
        _state.m_applyGain_state.m__arrayEntry = 0;
        _state.m_applyGain_state.m__sessionID = _state.m__sessionID;
        _state.m_applyGain_state.m__processorId = 88;
        _state.m_smoothedGain_state.m__arrayEntry = 0;
        _state.m_smoothedGain_state.m__sessionID = _state.m__sessionID;
        _state.m_smoothedGain_state.m__processorId = 89;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___initialise (_state.m_smoothedGain_state);
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume__run (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State& _state, VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___IO&
    _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___IO _3 = {};
        VA__ApplyGain__Processor_7___IO _4 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain__run (_state.m_smoothedGain_state, _3);
        _4 = ZeroInitialiser();
        _4.m__in_b = _3.m__out_out;
        _4.m__in_in = _2;
        VA__ApplyGain__Processor_7__run (_state.m_applyGain_state, _4);
        _io.m__out_out = _4.m__out_out;
    }

    void VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___volumeIn_f32 (VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume___State& _state, float
    event) noexcept
    {
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___in_f32 (_state.m_smoothedGain_state, event);
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
        _if_1: { _5 = VA__vdBtoGain (Vector<double, 2> (parameter[0]));
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
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 1.0f, 1.0f, 1.0f, 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter2__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter3__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ctfColor_smoothedParameter4__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 1.0f, 1.0f, 1.0f, 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter2__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter3__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.5) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.5));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ctfColor_smoothedParameter4__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { -50.0f, -50.0f, -50.0f, -50.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter0__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 20.0f, 20.0f, 20.0f, 20.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State&
    _state) noexcept
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

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 5);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 5, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 5);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 1.0f, 1.0f, 1.0f, 1.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter2__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter3__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4__init (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4__run (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 0.25) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 4);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 4, (sampleRate * 0.25));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 4);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___initialise (VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__CTF_Color__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ctfColor_smoothedParameter4__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = FixedArray<float, 4> { { 100.0f, 0, 0, 0 } }[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___IO& _io) noexcept
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
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 2);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 2, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 2);
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

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 4> { { 100.0f, 0, 0, 0 } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedMixPan__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedMixPan_smoothedGains__init (_state);
    }

    //==============================================================================
    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___in_f32 (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain__init (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 4L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 4) & 3] = ZeroInitialiser()[_intrin_wrap (static_cast<int32_t> (i), 4) & 3];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain__run (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State&
    _state, VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___IO& _io) noexcept
    {
        Vector<double, 2> out_value_out = {};
        int32_t _resumePoint = {};
        FixedArray<Vector<double, 2>, 2> _2 = {};
        FixedArray<Vector<double, 2>, 2> y = {};

        out_value_out = ZeroInitialiser();
        _resumePoint = _state.m__resumePoint;
        if (_resumePoint == 1) goto _resume_point_1;
        _block_0: { _state.m_s = ZeroInitialiser();
                    _state.m_c = ZeroInitialiser();
                    _state.m_updateIntervalSamples = static_cast<int32_t> (static_cast<int32_t> (((sampleRate * 1.0) / 44100.0) * 1024.0));
                    VA__SmoothedParameter__updateUnsmoothed (_state.m_c, _state.m_parameter, _state.m_s, 1);
        }
        _body_0: { if (! _state.m_recalc) goto _ifnot_0; }
        _if_0: { _state.m_recalc = false;
                 VA__SmoothedParameter__update (_state.m_c, _state.m_parameter, _state.m_s, 1, (sampleRate * 1.0));
        }
        _ifnot_0: { _state.m_counter_1 = _state.m_updateIntervalSamples; }
        _loop_1: { if (! (_state.m_counter_1 > 0)) goto _body_0; }
        _body_1: { _2 = VA__SmoothedParameter__process (_state.m_s, _state.m_c, 1);
                   y = static_cast<FixedArray<Vector<double, 2>, 2>> (_2);
                   out_value_out = out_value_out + y[0];
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
                   return;
        }
        _resume_point_1: { _state.m_counter_1 = _state.m_counter_1 - 1;
                           goto _loop_1;
        }
    }

    void VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___initialise (VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain___State&
    _state) noexcept
    {
        _state.m_iParameter = ZeroInitialiser();
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = false;
        VA__SmoothedParameter__Processor___for__root__VA__SmoothedVolume__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_smoothedVolume_smoothedGain__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 0.1f, 0.1f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 0.1f, 0.1f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 30.0f, 30.0f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 30.0f, 30.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS0_ballisticsFilter_unsmoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 0.1f, 0.1f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 0.1f, 0.1f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 30.0f, 30.0f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 30.0f, 30.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS2_ballisticsFilter_unsmoothedParameter1__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 0.1f, 0.1f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 0.1f, 0.1f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter__init (_state);
    }

    //==============================================================================
    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___in_f32 (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State&
    _state, float v) noexcept
    {
        _state.m_parameter[0] = v;
        _state.m_recalc = true;
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1__init (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        int32_t i = {}, _2 = {};

        i = 0;
        _loop_0: { if (! (static_cast<int64_t> (i) < 2L)) goto _break_0; }
        _body_0: { _state.m_parameter[_intrin_wrap (static_cast<int32_t> (i), 2) & 1] = FixedArray<float, 2> { { 30.0f, 30.0f } }[_intrin_wrap (static_cast<int32_t> (i), 2) & 1];
                   _2 = i;
                   i = _2 + 1;
                   goto _loop_0;
        }
        _break_0: {}
    }

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1__run (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State&
    _state, VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___IO& _io) noexcept
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

    void VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___initialise (VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1___State&
    _state) noexcept
    {
        _state.m_iParameter = FixedArray<float, 2> { { 30.0f, 30.0f } };
        _state.m_parameter = ZeroInitialiser();
        _state.m_recalc = true;
        _state.m_y = ZeroInitialiser();
        VA__UnsmoothedParameter__Processor___for__root__VA__BallisticsFilter__Processor___for__root__VA__HighLevel__TheExpressor__Internal__Processor___for__root__VA__HighLevel__TheExpressor__Processor___for__root__main__Processor_e_internalDS4_ballisticsFilter_unsmoothedParameter1__init (_state);
    }

    //==============================================================================
    FixedArray<Vector<double, 2>, 2> VA__UnsmoothedParameter___M__decodeParameter (FixedArray<float, 2> parameter) noexcept
    {
        FixedArray<Vector<double, 2>, 2> y = {};
        Vector<double, 2> _2 = {};

        y = ZeroInitialiser();
        _2 = VA__vTauToOmega (parameter[0]);
        y[0] = _2;
        return y;
    }

    //==============================================================================
    Vector<double, 2> VA___AbsADAA__f (Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {};

        _2 = VA__vabs (x);
        return _2;
    }

    Vector<double, 2> VA___AbsADAA__F1 (Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 2);
        return (_2 * Vector<double, 2> { { 0.5, 0.5 } }) * _3;
    }

    Vector<double, 2> VA___AbsADAA__F2 (Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 3);
        return (_2 * Vector<double, 2> { { 0.16666666666666667, 0.16666666666666667 } }) * _3;
    }

    Vector<double, 2> VA___AbsADAA__F3 (Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 4);
        return (_2 * Vector<double, 2> { { 0.041666666666666667, 0.041666666666666667 } }) * _3;
    }

    Vector<double, 2> VA___AbsADAA__F4 (Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {};

        _2 = VA__vSgn (x);
        _3 = VA___vpow_specialised (x, 5);
        return (_2 * Vector<double, 2> { { 0.008333333333333334, 0.008333333333333334 } }) * _3;
    }

    //==============================================================================
    void VA___AbsADAA__Processor___initialise (VA___AbsADAA__Processor___State& _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 90;
    }

    void VA___AbsADAA__Processor__run (VA___AbsADAA__Processor___State& _state, VA___AbsADAA__Processor___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA___AbsADAA__Internal__Processor___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA___AbsADAA__Internal__Processor___run_oversampled (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    Vector<double, 2> VA___AbsADAA__Internal__F (int32_t o, Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {};

        if (! (o == 0)) goto _ifnot_0;
        _if_0: { _2 = VA___AbsADAA__f (x, c);
                 return _2;
        }
        _ifnot_0: { if (! (o == 1)) goto _ifnot_1; }
        _if_1: { _3 = VA___AbsADAA__F1 (x, c);
                 return _3;
        }
        _ifnot_1: { if (! (o == 2)) goto _ifnot_2; }
        _if_2: { _4 = VA___AbsADAA__F2 (x, c);
                 return _4;
        }
        _ifnot_2: { if (! (o == 3)) goto _ifnot_3; }
        _if_3: { _5 = VA___AbsADAA__F3 (x, c);
                 return _5;
        }
        _ifnot_3: { _6 = VA___AbsADAA__F4 (x, c);
                    return _6;
        }
    }

    Vector<double, 2> VA___AbsADAA__Internal__process (VA___AbsADAA__Internal__State& s, Vector<double, 2> x, const VA___AbsADAA__Coeffs& c) noexcept
    {
        Vector<double, 2> _2 = {}, _3 = {}, _4 = {}, _5 = {}, _6 = {}, _7 = {}, _8 = {}, _9 = {}, _10 = {}, _11 = {}, _12 = {};
        int32_t i = {}, _13 = {}, i_2 = {}, _14 = {};
        int32_t n = {}, co = {};
        Vector<double, 2> div = {}, div2 = {}, xBar = {}, delta = {};

        s.m_x[0] = x;
        _2 = VA___AbsADAA__Internal__F (1, s.m_x[0], c);
        s.m_F_0[1] = _2;
        i = 1;
        _loop_0: { if (! (i < 2)) goto _break_0; }
        _body_0: { n = static_cast<int32_t> ((i - 1) / 2);
                   co = (1 - static_cast<int32_t> (i)) + 1;
                   if (! ((i & 1) == 1)) goto _ifnot_0;
        }
        _if_0: { div = static_cast<Vector<double, 2>> (s.m_x[_intrin_wrap (static_cast<int32_t> (n), 2) & 1] - s.m_x[_intrin_wrap (static_cast<int32_t> (n + 1), 2) & 1]);
                 _3 = VA___AbsADAA__Internal__F (static_cast<int32_t> (co + -1), Vector<double, 2> { { 0.5, 0.5 } } * (s.m_x[_intrin_wrap (static_cast<int32_t> (n), 2) & 1] + s.m_x[_intrin_wrap (static_cast<int32_t> (n + 1), 2) & 1]), c);
                 _4 = VA__vabs (static_cast<Vector<double, 2>> (div));
                 _5 = VA__viflt (_3, (s.m_F_0[_intrin_wrap (static_cast<int32_t> (co), 2) & 1] - s.m_F_1[_intrin_wrap (static_cast<int32_t> (co), 2) & 1]) / static_cast<Vector<double, 2>> (div), _4, Vector<double, 2> { { 0.000006055454452393343, 0.000006055454452393343 } });
                 s.m_F_0[_intrin_wrap (static_cast<int32_t> (co + -1), 2) & 1] = _5;
                 goto _cont_0;
        }
        _ifnot_0: { div2 = static_cast<Vector<double, 2>> (s.m_x[_intrin_wrap (static_cast<int32_t> (n), 2) & 1] - s.m_x[_intrin_wrap (static_cast<int32_t> (n + 2), 2) & 1]);
                    xBar = static_cast<Vector<double, 2>> (Vector<double, 2> { { 0.5, 0.5 } } * (s.m_x[_intrin_wrap (static_cast<int32_t> (n), 2) & 1] + s.m_x[_intrin_wrap (static_cast<int32_t> (n + 2), 2) & 1]));
                    delta = xBar - static_cast<Vector<double, 2>> (s.m_x[_intrin_wrap (static_cast<int32_t> (n + 1), 2) & 1]);
                    _6 = VA___AbsADAA__Internal__F (static_cast<int32_t> (co + -1), Vector<double, 2> { { 0.5, 0.5 } } * static_cast<Vector<double, 2>> (xBar + static_cast<Vector<double, 2>> (s.m_x[_intrin_wrap (static_cast<int32_t> (n + 1), 2) & 1])), c);
                    _7 = VA___AbsADAA__Internal__F (static_cast<int32_t> (co), static_cast<Vector<double, 2>> (xBar), c);
                    _8 = VA___AbsADAA__Internal__F (static_cast<int32_t> (co + 1), static_cast<Vector<double, 2>> (xBar), c);
                    _9 = VA__vabs (static_cast<Vector<double, 2>> (delta));
                    _10 = VA__viflt (_6, (Vector<double, 2> { { 2.0, 2.0 } } / static_cast<Vector<double, 2>> (delta)) * (_7 + ((s.m_F_1[_intrin_wrap (static_cast<int32_t> (co + 1), 2) & 1] - _8) / static_cast<Vector<double, 2>> (delta))), _9, Vector<double, 2> { { 0.000006055454452393343, 0.000006055454452393343 } });

                    _11 = VA__vabs (static_cast<Vector<double, 2>> (div2));
                    _12 = VA__viflt (_10, (Vector<double, 2> { { 2.0, 2.0 } } / static_cast<Vector<double, 2>> (div2)) * (s.m_F_0[_intrin_wrap (static_cast<int32_t> (co), 2) & 1] - s.m_F_1[_intrin_wrap (static_cast<int32_t> (co), 2) & 1]), _11, Vector<double, 2> { { 0.000006055454452393343, 0.000006055454452393343 } });

                    s.m_F_0[_intrin_wrap (static_cast<int32_t> (co + -1), 2) & 1] = _12;
        }
        _cont_0: { _13 = i;
                   i = _13 + 1;
                   goto _loop_0;
        }
        _break_0: { i_2 = 1; }
        _loop_1: { if (! (i_2 > 0)) goto _break_1; }
        _body_1: { s.m_x[_intrin_wrap (static_cast<int32_t> (i_2), 2) & 1] = s.m_x[_intrin_wrap (static_cast<int32_t> (i_2 - 1), 2) & 1];
                   _14 = i_2;
                   i_2 = _14 - 1;
                   goto _loop_1;
        }
        _break_1: { s.m_F_1 = s.m_F_0;
                    return s.m_F_0[0];
        }
    }

    //==============================================================================
    void VA___AbsADAA__Internal__Processor__run (VA___AbsADAA__Internal__Processor___State& _state, VA___AbsADAA__Internal__Processor___IO& _io) noexcept
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
                   _3 = VA___AbsADAA__Internal__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    void VA___AbsADAA__Internal__Processor___run_oversampled (VA___AbsADAA__Internal__Processor___State& _state, VA___AbsADAA__Internal__Processor___IO& _io) noexcept
    {
        VA___AbsADAA__Internal__Processor___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor__run (_state, _io);
        VA___AbsADAA__Internal__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor__run (_state, _io);
        VA___AbsADAA__Internal__Processor___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA___AbsADAA__Internal__Processor___upsamplerWrite (VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA___AbsADAA__Internal__Processor___upsamplerRead (VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor___downsamplerWrite (VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor___downsamplerRead (VA___AbsADAA__Internal__Processor___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA___AbsADAA__Internal__Processor_2__run (VA___AbsADAA__Internal__Processor_2___State& _state, VA___AbsADAA__Internal__Processor_2___IO& _io) noexcept
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
                   _3 = VA___AbsADAA__Internal__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    void VA___AbsADAA__Internal__Processor_2___run_oversampled (VA___AbsADAA__Internal__Processor_2___State& _state, VA___AbsADAA__Internal__Processor_2___IO& _io) noexcept
    {
        VA___AbsADAA__Internal__Processor_2___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_2__run (_state, _io);
        VA___AbsADAA__Internal__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor_2___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_2__run (_state, _io);
        VA___AbsADAA__Internal__Processor_2___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor_2___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA___AbsADAA__Internal__Processor_2___upsamplerWrite (VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA___AbsADAA__Internal__Processor_2___upsamplerRead (VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor_2___downsamplerWrite (VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor_2___downsamplerRead (VA___AbsADAA__Internal__Processor_2___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA___AbsADAA__Internal__Processor_3__run (VA___AbsADAA__Internal__Processor_3___State& _state, VA___AbsADAA__Internal__Processor_3___IO& _io) noexcept
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
                   _3 = VA___AbsADAA__Internal__process (_state.m_s, _2, _state.m_c);
                   out_value_out = out_value_out + _3;
                   _state.m__resumePoint = 1;
                   _io.m__out_out = out_value_out;
        }
    }

    void VA___AbsADAA__Internal__Processor_3___run_oversampled (VA___AbsADAA__Internal__Processor_3___State& _state, VA___AbsADAA__Internal__Processor_3___IO& _io) noexcept
    {
        VA___AbsADAA__Internal__Processor_3___upsamplerWrite (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_3___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_3__run (_state, _io);
        VA___AbsADAA__Internal__Processor_3___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor_3___upsamplerRead (_state.m__in_src, _io.m__in_in);
        VA___AbsADAA__Internal__Processor_3__run (_state, _io);
        VA___AbsADAA__Internal__Processor_3___downsamplerWrite (_state.m__out_src, _io.m__out_out);
        VA___AbsADAA__Internal__Processor_3___downsamplerRead (_state.m__out_src, _io.m__out_out);
    }

    void VA___AbsADAA__Internal__Processor_3___upsamplerWrite (VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2> input) noexcept
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

    void VA___AbsADAA__Internal__Processor_3___upsamplerRead (VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2>& value) noexcept
    {
        value = state.m_buffer[state.m_bufferPos];
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor_3___downsamplerWrite (VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& state, Vector<double, 2> value) noexcept
    {
        state.m_buffer[state.m_bufferPos] = value;
        state.m_bufferPos = state.m_bufferPos + 1;
    }

    void VA___AbsADAA__Internal__Processor_3___downsamplerRead (VA___AbsADAA__Internal__Processor_3___SampleRateConverter_vec_2_f64_2& src, Vector<double, 2>& output) noexcept
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
    void VA___AbsADAA__Processor_2___initialise (VA___AbsADAA__Processor_2___State& _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 91;
    }

    void VA___AbsADAA__Processor_2__run (VA___AbsADAA__Processor_2___State& _state, VA___AbsADAA__Processor_2___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA___AbsADAA__Internal__Processor_2___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA___AbsADAA__Internal__Processor_2___run_oversampled (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
    }

    //==============================================================================
    void VA___AbsADAA__Processor_3___initialise (VA___AbsADAA__Processor_3___State& _state) noexcept
    {
        _state.m_internal_state.m__arrayEntry = 0;
        _state.m_internal_state.m__sessionID = _state.m__sessionID;
        _state.m_internal_state.m__processorId = 92;
    }

    void VA___AbsADAA__Processor_3__run (VA___AbsADAA__Processor_3___State& _state, VA___AbsADAA__Processor_3___IO& _io) noexcept
    {
        Vector<double, 2> _2 = {};
        VA___AbsADAA__Internal__Processor_3___IO _3 = {};

        _2 = _io.m__in_in;
        _3 = ZeroInitialiser();
        _3.m__in_in = _2;
        VA___AbsADAA__Internal__Processor_3___run_oversampled (_state.m_internal_state, _3);
        _io.m__out_out = _3.m__out_out;
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

