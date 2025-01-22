#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1500
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define FETT263_BATTLE_MODE_START_OFF
#define FETT263_LOCKUP_DELAY 450
#define FETT263_TWIST_ON
#define FETT263_TWIST_OFF
#define MOTION_TIMEOUT 60 * 15 * 1000
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
   { "Default", "tracks/default.wav",
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>> ,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "cyan"},

   { "Blue", "tracks/blue.wav",
    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "blue"},

   { "Green", "tracks/green.wav",
    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>> ,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "green"},

   { "Purple", "tracks/purple.wav",
    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<48,0,105>>>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "purple"},

   { "Yellow", "tracks/yellow.wav",  StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<130,150,0>>,RotateColorsX<Variation,Rgb<70,70,0>>> ,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,BlastL<White>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "yellow"},

   { "Orange", "tracks/orange.wav",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,34,0>>>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,BlastL<White>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "orange"},

   { "Cyan", "tracks/cyan.wav",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,50,128>>> ,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,BlastL<White>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "cyan"},

   { "Red", "tracks/red.wav",
    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>> ,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_NORMAL>,LockupTrL<BrownNoiseFlickerL<White,Int<200>>,TrConcat<TrInstant,White,TrFade<300>>,TrFade<300>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,SimpleClashL<White>,InOutTrL<TrInstant,TrFade<300>,Black>>>(), "red"}


};
BladeConfig blades[] = {
 { 0, SimpleBladePtr<CreeXPE2RedTemplate<1000>, CreeXPE2GreenTemplate<0>, CreeXPE2BlueTemplate<240>, NoLED, bladePowerPin1, bladePowerPin2, bladePowerPin3, -1>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
