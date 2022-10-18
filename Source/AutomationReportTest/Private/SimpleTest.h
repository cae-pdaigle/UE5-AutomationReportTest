#pragma once

#include "CoreMinimal.h"
#include "ScreenshotFunctionalTest.h"
#include "SimpleTest.generated.h"

UCLASS()
class AScreenshotTest : public AScreenshotFunctionalTest
{
    GENERATED_BODY()

public:
    virtual void OnScreenshotTakenAndCompared() override;

    bool bIsFinished = false;
};
