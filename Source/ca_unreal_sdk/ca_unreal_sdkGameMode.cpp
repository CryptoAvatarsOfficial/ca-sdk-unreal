// Copyright Epic Games, Inc. All Rights Reserved.

#include "ca_unreal_sdkGameMode.h"
#include "ca_unreal_sdkCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aca_unreal_sdkGameMode::Aca_unreal_sdkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
