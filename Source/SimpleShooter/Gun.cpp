// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adding Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

void AGun::PullTrigger()
{
	// UE_LOG(LogTemp, Warning, TEXT("Shoot!"));

	// Set Particles when you shoot
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	FHitResult Hit;
	FVector ShotDirection;

	bool bSuccess = GunTrace(Hit, ShotDirection);
	
	if (bSuccess)
	{
		// Draw Point on the hit
		// DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);

		// Adding Particle to Bullet Hit		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEffect, Hit.Location, ShotDirection.Rotation());
		
		// Set Actor based ond Hit actor
		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{			
			// Adding Damage
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);

			AController* OwnerController = GetOwnerController();

			// Adding Damage
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
		
	}

	// Draw debug camera when you shoot
	// DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);	
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)	return false;
	
	FVector Location;
	FRotator Rotation;

	// Get Player View Point and save in Location and Rotation
	OwnerController->GetPlayerViewPoint(Location, Rotation);

	// Get Shot Direction
	ShotDirection = -Rotation.Vector();	

	// Set The End Point
	FVector End = Location + Rotation.Vector() * MaxRange;

	// Adding Ignores to Collisions with the AI Shooter
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	// Set the Pawn of the shooter character
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) 
		return nullptr;

	// get and set the Owner Controller of the Owner Pawn
	return OwnerPawn->GetController();
	
}

