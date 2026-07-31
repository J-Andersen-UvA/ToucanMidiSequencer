#include "ToucanSessionSequencerStyle.h"

#include "Brushes/SlateImageBrush.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> FToucanSessionSequencerStyle::StyleInstance;

namespace
{
    const FVector2D Icon16(16.f, 16.f);

    void SetVectorIcon(FSlateStyleSet& Style, const TCHAR* BrushName, const TCHAR* IconName)
    {
        Style.Set(
            BrushName,
            new FSlateVectorImageBrush(
                Style.RootToContentDir(IconName, TEXT(".svg")),
                Icon16,
                FLinearColor::White));
    }
}

void FToucanSessionSequencerStyle::Initialize()
{
    if (StyleInstance.IsValid())
    {
        return;
    }

    StyleInstance = MakeShared<FSlateStyleSet>(GetStyleSetName());
    StyleInstance->SetContentRoot(
        IPluginManager::Get().FindPlugin(TEXT("ToucanSessionSequencer"))->GetBaseDir()
        / TEXT("Resources/Icons"));

    SetVectorIcon(*StyleInstance, TEXT("Toucan.ControlRig"), TEXT("controlRigWhite"));
    SetVectorIcon(*StyleInstance, TEXT("Toucan.QueueClipboard"), TEXT("queueClipboardWhite"));
    SetVectorIcon(*StyleInstance, TEXT("Toucan.TabIcon"), TEXT("toucanWhite"));

    FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
}

void FToucanSessionSequencerStyle::Shutdown()
{
    if (!StyleInstance.IsValid())
    {
        return;
    }

    FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
    ensure(StyleInstance.IsUnique());
    StyleInstance.Reset();
}

const FSlateBrush* FToucanSessionSequencerStyle::GetBrush(FName BrushName)
{
    return StyleInstance.IsValid() ? StyleInstance->GetBrush(BrushName) : nullptr;
}

const FName& FToucanSessionSequencerStyle::GetStyleSetName()
{
    static const FName StyleSetName(TEXT("ToucanSessionSequencerStyle"));
    return StyleSetName;
}
