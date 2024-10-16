// Copyright Epic Games, Inc. All Rights Reserved.

#include "TacticalTrialsGameMode.h"
#include "TacticalTrialsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATacticalTrialsGameMode::ATacticalTrialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
