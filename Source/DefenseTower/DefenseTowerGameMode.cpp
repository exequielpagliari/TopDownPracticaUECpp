// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefenseTowerGameMode.h"
#include "DefenseTowerPlayerController.h"
#include "DefenseTowerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADefenseTowerGameMode::ADefenseTowerGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADefenseTowerPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_PlayerAvatar"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}