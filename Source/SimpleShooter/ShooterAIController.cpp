// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    // Check if AIBehavior not is null
    if (AIBehavior != nullptr)
    {
        // Run AIBehavior
        RunBehaviorTree(AIBehavior);
        
        // Get the player pawn
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        // Set StartLocation
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());        
    }
        
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Get the player pawn
    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // if (LineOfSightTo(PlayerPawn))
    // {
    //     // Adding a new Key to Blackboard of type Vector - Setting PLayerLocation
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        
    //     // Setting LastKnow
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnowPlayerLocation"), PlayerPawn->GetActorLocation());
    // }   
    // else
    // {
    //     // Clear PLayerLocation
    //     GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    // }
}

bool AShooterAIController::IsDead() const
{
    // Get Pawn of the Shooter Character
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }
    
    return true;
}
