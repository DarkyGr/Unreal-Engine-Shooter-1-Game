// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    // UE_LOG(LogTemp, Warning, TEXT("A pawn was killed!"));

    // Get Player Controller of PawnKilled
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }
    
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    // Get all Controllers of the world    
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        /*=================================*/
        // Get the bool of the Is player controller
        // bool bIsPlayerController = Controller->IsPlayerController();        
        // if (bIsPlayerWinner)
        // {
        //     // Set the bool yes
        //     Controller->GameHasEnded(nullptr, bIsPlayerController);
        // }
        // else
        // {
        //     // Set the bool no
        //     Controller->GameHasEnded(nullptr, !bIsPlayerController);
        // }

        /*=================================*/
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
        
    }     
}
