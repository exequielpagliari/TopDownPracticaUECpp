// Fill out your copyright notice in the Description page of Project Settings.


#include "DefenseTowerActor.h"

// Sets default values
ADefenseTowerActor::ADefenseTowerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(
		TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);
	_MeshComponent = CreateDefaultSubobject
		<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);

}

// Called when the game starts or when spawned
void ADefenseTowerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefenseTowerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ADefenseTowerActor::GetHealthPoints()
{
	return _HealthPoints;
}

bool ADefenseTowerActor::IsDestroyed()
{
	return (_HealthPoints > 0.0f);
}

bool ADefenseTowerActor::CanFire()
{
	return (_ReloadCountingDown <= 0.0f);
}

