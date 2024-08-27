// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "APlayerAvatar.generated.h"

UCLASS()
class DEFENSETOWER_API AAPlayerAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAPlayerAvatar();

	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	int HealthPoints = 500;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Strength = 10.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float Armor = 3.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackRange = 6.0f;
	UPROPERTY(EditAnywhere, Category = "PlayerAvatar Params")
	float AttackInterval = 1.2f;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int _HealthPoints;
	float _AttackCountingDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	int GetHealthPoints();
	bool IsKilled();
	bool CanAttack();
	void Attack();
	void Hit(int damage);

protected:
	void DieProcess();
};
