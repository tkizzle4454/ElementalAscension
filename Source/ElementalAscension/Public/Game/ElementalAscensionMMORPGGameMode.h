// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Game/ACFGameMode.h"
#include "ElementalAscensionMMORPGGameMode.generated.h"

/**
 * MMORPG GameMode with ACF support + server authority
 * Supports 100-200 players per instance with Iris replication
 */
UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionMMORPGGameMode : public AACFGameMode
{
	GENERATED_BODY()

public:
	/** Constructor */
	AElementalAscensionMMORPGGameMode();

	/** AAA Authoritative Login: Validation happens here */
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	// ACF base class already provides:
	// - GetCollisionsManager()
	// - GetRagdollManager()
	// No need to duplicate them here
};
