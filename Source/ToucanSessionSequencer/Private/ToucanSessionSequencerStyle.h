#pragma once

#include "CoreMinimal.h"

struct FSlateBrush;
class FSlateStyleSet;

class FToucanSessionSequencerStyle
{
public:
    static void Initialize();
    static void Shutdown();

    static const FSlateBrush* GetBrush(FName BrushName);
    static const FName& GetStyleSetName();

private:
    static TSharedPtr<FSlateStyleSet> StyleInstance;
};
