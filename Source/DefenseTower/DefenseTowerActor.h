// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DefenseTowerActor.generated.h"

UCLASS(Blueprintable)
class DEFENSETOWER_API ADefenseTowerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefenseTowerActor();
	UPROPERTY(EditAnywhere, Category = "Tower Params")
	int HealthPoints = 100;
	UPROPERTY(EditAnywhere, Category = "Tower Params")
	int ShellDefense = 2;
	UPROPERTY(EditAnywhere, Category = "Tower Params")
	float AttackRange = 15.0f;
	UPROPERTY(EditAnywhere, Category = "Tower Params")
	float ReloadInterval = 1.0f;

	FORCEINLINE UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int _HealthPoints;
	float _ReloadCountingDown;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		Category = "Tower Component",
		meta = (AllowPrivateAccess = "true"))
	UBoxComponent* _BoxComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		Category = "Tower Component",
		meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|Defense Tower",
		meta = (DisplayName = "GetHP"))
	int GetHealthPoints();
	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|Defense Tower")
	bool IsDestroyed();
	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|Defense Tower")
	bool CanFire();
	void Fire();
	void Hit(int damage);

protected:
	void DestroyProcess();
};
