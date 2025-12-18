#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BH_GameRecorder.h"
#include "Components/Button.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"
#include "ExtendedCommonActivatableWidget.h"

#include "BH_ReportFormWidget.generated.h"

UCLASS()
class BETAHUBBUGREPORTER_API UBH_ReportFormWidget : public UCommonActivatableWidget
{
    GENERATED_BODY()

private:
    UPROPERTY()
    UBH_GameRecorder* GameRecorder;

    FString ScreenshotPath;
    FString LogFileContents;
    
    UBH_PluginSettings* Settings;

    bool bCursorStateModified;
    bool bWasCursorVisible;
    bool bWasCursorLocked;

    UFUNCTION()
    void OnCloseClicked();

    void ShowPopup(const FString& Title, const FString& Description);

protected:
    virtual void NativeDestruct() override;

public:
    // constructor
    UBH_ReportFormWidget(const FObjectInitializer& ObjectInitializer);


    UFUNCTION(BlueprintCallable, Category="BugReport")
    void Setup(UBH_PluginSettings* InSettings, UBH_GameRecorder* InGameRecorder, const FString& InScreenshotPath, const FString& InLogFileContents, bool bTryCaptureMouse);

    UFUNCTION(BlueprintCallable, Category="BugReport")
    void SubmitReport(FString BugDescription, FString StepsToReproduce, bool includeVideo, bool includeScreenshots);

    UFUNCTION(BlueprintCallable, Category = "BugReport")
    void SubmitTextReport(FString Description);

    UFUNCTION(BlueprintCallable, Category = "BugReport")
    void OnFormSubmitted(bool Success);

    UFUNCTION(BlueprintCallable, Category="Cursor")
    void SetCursorState();

    UFUNCTION(BlueprintCallable, Category="Cursor")
    void RestoreCursorState();
};