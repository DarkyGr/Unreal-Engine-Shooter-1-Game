// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	virtual void BeginPlay() override;

private:
	// Variable to Radius to Enemy Close
	// UPROPERTY(EditAnywhere)
	// float AcceptanceRadius = 200.f;

	// Variable to Behavior tree
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
