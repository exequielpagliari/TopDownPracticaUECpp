// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AProjectile.generated.h"

UCLASS()
class DEFENSETOWER_API AAProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAProjectile();
	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Speed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Lifespan = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Projectile Params")
	float Damage = 10.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float _LifeCountingDown;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
