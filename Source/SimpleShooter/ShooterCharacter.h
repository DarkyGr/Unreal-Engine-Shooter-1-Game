// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Method to set Move WS
	void MoveForward(float AxisValue);

	// Method to set Move AD
	void MoveRight(float AxisValue);

	// Method to set Mouse
	// void LookUp(float AxisValue);

	// Method to set Gamepad Look Up
	void LookUpRate(float AxisValue);

	// Method to set Gamepad Look Right
	void LookRightRate(float AxisValue);

	// Varibale to Rotation (Affect FPS)
	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;

};
