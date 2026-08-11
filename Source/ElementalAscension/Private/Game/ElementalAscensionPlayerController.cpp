// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/ElementalAscensionPlayerController.h"
#include "Actors/ACFCharacter.h"

AElementalAscensionPlayerController::AElementalAscensionPlayerController()
{
	// Inherits all ACF functionality from AACFPlayerController:
	// - Team system (IACFEntityInterface, IGenericTeamAgentInterface)
	// - Possession tracking (PossessedCharacter, PossessedEntity)
	// - Camera input tracking (RotationInput, secondsFromLastCameraInput)
	// - Death handling (OnPossessedPawnDeath)
	// - Tick enabled by default
}

// IACFEntityInterface implementations (delegate to possessed pawn)
bool AElementalAscensionPlayerController::IsEntityAlive_Implementation() const
{
	if (GetPawn() && GetPawn()->Implements<UACFEntityInterface>())
	{
		return IACFEntityInterface::Execute_IsEntityAlive(GetPawn());
	}
	return true;
}

float AElementalAscensionPlayerController::GetEntityExtentRadius_Implementation() const
{
	if (GetPawn() && GetPawn()->Implements<UACFEntityInterface>())
	{
		return IACFEntityInterface::Execute_GetEntityExtentRadius(GetPawn());
	}
	return 100.f;
}
