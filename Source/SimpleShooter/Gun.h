// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	// Method to show when the player shoot
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Create USceneComponent Variable
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// Create USkeletalMeshComponent Variable
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	// Create UParticle System when you shoot
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	// Create UParticle System when bullet hit
	UPROPERTY(EditAnywhere)
	UParticleSystem* HitEffect;

	// Create Variable to the Max Range but the bullet hit
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.f;
};
