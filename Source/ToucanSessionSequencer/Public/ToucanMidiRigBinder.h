#pragma once
#include "CoreMinimal.h"
#include "ControlRig.h"
#if WITH_MIDIMAPPER
#include "MidiTypes.h"
#endif

class UMovieSceneSequence;

class FToucanMidiRigBinder
{
public:
    static void RegisterRigControls();
    static void BindRigChangeListener();

#if WITH_MIDIMAPPER
    // Handle incoming MIDI control input
    static void OnMidiControlInput(const FString& FunctionId, const FMidiControlValue& V);
#endif
    static void KeyframeRigControlNow(UControlRig* Rig, const FName& ControlName, float NormalizedValue);
    static void KeyframeRigControlAt(UControlRig* Rig, const FName& ControlName, int32 FrameNumber, float NormalizedValue, UMovieSceneSequence* Sequence);
};
