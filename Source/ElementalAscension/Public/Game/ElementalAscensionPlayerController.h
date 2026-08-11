// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Game/ACFPlayerController.h"
#include "ElementalAscensionPlayerController.generated.h"

/**
 * MMORPG PlayerController for ElementalAscension
 * Inherits ACF team system and entity interfaces
 * Identical to ACFUltimatePlayerController functionality
 */
UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionPlayerController : public AACFPlayerController
{
	GENERATED_BODY()

public:
	AElementalAscensionPlayerController();

	// IACFEntityInterface - Override to delegate to possessed pawn
	virtual bool IsEntityAlive_Implementation() const override;
	virtual float GetEntityExtentRadius_Implementation() const override;
};
