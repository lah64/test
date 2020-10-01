#pragma once

#include "IPlug_include_in_plug_hdr.h"

const int kNumPresets = 1;

enum EParams {
    kIn1 = 0,
    kIn2,
    kAttack1,
    kAttack2,
    kThreshold1,
    kThreshold2,
    kRatio1,
    kRatio2,
    kRelease1,
    kRelease2,
    kOut1,
    kOut2,
    kMix,
    kLink,
    kMSLR,
    kOnOff,
    kView,
    kOverSampling,
    kL,
    kR,
    kNumParams
};

enum EOnOff {
    kOn = 0,
    kOff,
    OnOff
};

enum ELink {
    kLinkOn = 0,
    kLinkOff,
    Link
};

enum EMSLR {
    kLR = 0,
    kMS,
    MSLR
};

enum ELayout
{
    kWidth = PLUG_WIDTH,
    kHeight = PLUG_HEIGHT,
    kKnob_N = 128,
    kSwitch_N = 2,    // # of sub-bitmaps.

    kIn1_X = 156,
    kIn1_Y = 80,
    kIn2_X = 156,
    kIn2_Y = 316,
    kThresh1_X = 604,
    kThresh1_Y = 80,
    kThresh2_X = 604,
    kThresh2_Y = 316,
    kRatio1_X = 828,
    kRatio1_Y = 80,
    kRatio2_X = 828,
    kRatio2_Y = 316,
    kAttack1_X = 379,
    kAttack1_Y = 80,
    kAttack2_X = 379,
    kAttack2_Y = 316,
    kRelease1_X = 1052,
    kRelease1_Y = 80,
    kRelease2_X = 1052,
    kRelease2_Y = 316,
    kOut1_X = 1276,
    kOut1_Y = 80,
    kOut2_X = 1276,
    kOut2_Y = 316,
    kMixX = 1500,
    kMixY = 80,
    kLinkX = 1492,
    kLinkY = 260,
    kMSLRX = 1497,
    kMSLRY = 390,
    kLED_X = 2390,
    kLED_Y = 63,
    kOnOffX = 2400,
    kOnOffY = 325,
    kMeterL_X = 1705,
    kMeterL_Y = 160,
    kMeterR_X = 2055,
    kMeterR_Y = 160
};

using namespace iplug;
using namespace igraphics;

class IPlugEffect final : public Plugin
{
public:
  IPlugEffect(const InstanceInfo& info);

#if IPLUG_DSP // http://bit.ly/2S64BDd
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
#endif
};
