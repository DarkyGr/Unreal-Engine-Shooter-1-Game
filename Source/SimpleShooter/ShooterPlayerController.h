// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Method to Game Over
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:
	// Widget of UI HUD
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	// Variable to HUD
	UPROPERTY(EditAnywhere)
	class UUserWidget* HUD;

	// Widget of UI Win
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;

	// Widget of UI Lose
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	// Variable to Restart Delay
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.f;

	//Varibale FTimerHandle to Restart the game
	FTimerHandle RestartTimer;
	
};
