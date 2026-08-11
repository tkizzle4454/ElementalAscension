// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ElementalAscensionGameState.generated.h"

/**
 * Custom GameState for ElementalAscension MMORPG
 * Holds the ACF Team Manager Component required for ACF AI team system
 */
UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AElementalAscensionGameState();

	/** Returns the team manager component */
	UFUNCTION(BlueprintPure, Category = "ACF")
	FORCEINLINE class UACFTeamManagerComponent* GetTeamManager() const { return TeamManagerComponent; }

protected:
	/** Team manager component - Required for ACF AI to recognize teams/enemies */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ACF")
	TObjectPtr<class UACFTeamManagerComponent> TeamManagerComponent;
};
