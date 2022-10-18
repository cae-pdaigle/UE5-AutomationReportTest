#include "SimpleTest.h"
#include "Misc/AutomationTest.h"

void AScreenshotTest::OnScreenshotTakenAndCompared()
{
    Super::OnScreenshotTakenAndCompared();
    bIsFinished = true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(SimpleTest, "AutomationReportTest.SimpleTest", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext);

bool SimpleTest::RunTest(const FString& Parameters)
{
    UWorld* World = GEngine->GameViewport->GetWorld();

    FActorSpawnParameters SpawnParams;
    AScreenshotTest* TestActor = World->SpawnActor<AScreenshotTest>(SpawnParams);
    TestActor->TestLabel = "SimpleTestScreenshot";

    TArray<FString> FuncTestParams;
    bool bStarted = TestActor->RunTest(FuncTestParams);
    if (!bStarted)
    {
        UE_LOG(LogTemp, Error, TEXT("Test failed to start"));
        return false;
    }

    ADD_LATENT_AUTOMATION_COMMAND(FFunctionLatentCommand([TestActor]() {
        return TestActor->bIsFinished;
    }));

    return true;
}
