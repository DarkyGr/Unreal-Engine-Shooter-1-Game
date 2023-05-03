// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    // Check if AIBehavior not is null
    if (AIBehavior != nullptr)
    {
        // Run AIBehavior
        RunBehaviorTree(AIBehavior);
    }
        
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Get the player pawn
    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // if (LineOfSightTo(PlayerPawn))
    // {
    //     // Set Focus a our player
    //     SetFocus(PlayerPawn);    

    //     // Move AI to our player
    //     MoveToActor(PlayerPawn, AcceptanceRadius);        
    // }   
    // else
    // {
    //     ClearFocus(EAIFocusPriority::Gameplay);
    //     StopMovement();
    // }
}
