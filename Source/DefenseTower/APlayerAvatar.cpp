// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerAvatarAnimInstance.h"

// Sets default values
AAPlayerAvatar::AAPlayerAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	// Configure character movement
	auto characterMovement = GetCharacterMovement();
	characterMovement->bOrientRotationToMovement = true;
	characterMovement->RotationRate = FRotator(0.f, 640.f, 0.f);
	characterMovement->bConstrainToPlane = true;
	characterMovement->bSnapToPlaneAtStart = true;



	//Create the camera spring arm
	_springArmComponent = CreateDefaultSubobject<USpringArmComponent>(
		TEXT("SpringArm"));
	_springArmComponent->SetupAttachment(RootComponent);
	_springArmComponent->SetUsingAbsoluteRotation(true);
	_springArmComponent->TargetArmLength = 800.f;
	_springArmComponent->SetRelativeRotation(
		FRotator(-60.f, 0.f, 0.f));
	_springArmComponent->bDoCollisionTest = false;


	// Create the camera
	_cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_cameraComponent->SetupAttachment(_springArmComponent, USpringArmComponent::SocketName);
	//Attach to the spring arm
	_cameraComponent->bUsePawnControlRotation = false;			//Camera rotation is not controllable  
}

// Called when the game starts or when spawned
void AAPlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Inicio de Clase PlayerAvatar"));
	
}

// Called every frame
void AAPlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	UPlayerAvatarAnimInstance* animInst =
		Cast<UPlayerAvatarAnimInstance>(
			GetMesh()->GetAnimInstance());
	animInst->Speed =
		GetCharacterMovement()->Velocity.Size2D();

	if (_AttackCountingDown == AttackInterval)
	{
		animInst->State = EPlayerState::Attack;
	}

	if (_AttackCountingDown > 0.0f)
	{
		_AttackCountingDown -= DeltaTime;
	}

}

// Called to bind functionality to input
void AAPlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}

int AAPlayerAvatar::GetHealthPoints()
{
	return _HealthPoints;
}


bool AAPlayerAvatar::IsKilled()
{
	return (_HealthPoints <= 0.0f);
}
bool AAPlayerAvatar::CanAttack()
{
	UPlayerAvatarAnimInstance* animInst = Cast<UPlayerAvatarAnimInstance>(
		GetMesh()->GetAnimInstance());
	return (_AttackCountingDown <= 0.0f &&
		animInst->State == EPlayerState::Locomotion);
}

void AAPlayerAvatar::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Golpe AAPlayer"));
	_AttackCountingDown = AttackInterval;
}

void AAPlayerAvatar::Hit(int damage)
{
}

void AAPlayerAvatar::DieProcess()
{
	Destroy();
}

