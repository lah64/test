#include "IPlugEffect.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"

const int kNumPrograms = 2;
bool linkflag = false;

IPlugEffect::IPlugEffect(const InstanceInfo& info)
        : Plugin(info, MakeConfig(kNumParams, kNumPrograms))
    {

      //MakePreset("preset 1", ... );
      MakeDefaultPreset((char*)"-", kNumPrograms);
        mMakeGraphicsFunc = [&]() {
          return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen(PLUG_HEIGHT));
        };
        mLayoutFunc = [&](IGraphics* pGraphics) {

          pGraphics->Resize(kWidth, kHeight, 0.58);
            
          pGraphics->AttachPanelBackground(COLOR_GRAY);
          pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);
          pGraphics->EnableMouseOver(true);
          pGraphics->AttachTextEntryControl();
            
          IBitmap bitmap = pGraphics->LoadBitmap(BG_FN);
          pGraphics->AttachControl(new IBitmapControl(0, 0, bitmap));
          
          bitmap = pGraphics->LoadBitmap(METER_FN, 2);
          pGraphics->AttachControl(new IBitmapControl(1705, 160, bitmap, kOnOff));

          bitmap = pGraphics->LoadBitmap(ARROW_FN, 128);
          pGraphics->AttachControl(new IBitmapControl(1705, 160, bitmap, kL));
          pGraphics->AttachControl(new IBitmapControl(2055, 160, bitmap, kR));
        
        };
    }


void IPlugEffect::ProcessBlock(double** inputs, double** outputs, int nFrames)
{
    double* in1 = inputs[0];
    double* in2 = inputs[1];
    double* out1 = outputs[0];
    double* out2 = outputs[1];
    double peakL = 0.0;
    double peakR = 0.0;
    double mPrevL = 0.0;
    double mPrevR = 0.0;

    for (int s = 0; s < nFrames; ++s, ++in1, ++in2, ++out1, ++out2)
    {
        *out1 = *in1;
        *out2 = *in2;
    }
    
    const double METER_ATTACK = 0.5, METER_DECAY = 0.5;
    
    double xL = (*out1 < mPrevL ? METER_DECAY : METER_ATTACK);
    double xR = (*out2 < mPrevR ? METER_DECAY : METER_ATTACK);

    peakL = peakL * xL + mPrevL * (1.0 - xL);
    peakR = peakR * xR + mPrevR * (1.0 - xR);

    mPrevL = peakL;
    mPrevR = peakR;

}
