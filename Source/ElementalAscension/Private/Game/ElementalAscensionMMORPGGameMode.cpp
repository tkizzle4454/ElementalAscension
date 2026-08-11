// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/ElementalAscensionMMORPGGameMode.h"
#include "Player/ElementalAscensionPlayerState.h"
#include "Game/ElementalAscensionGameState.h"
#include "UObject/ConstructorHelpers.h"

AElementalAscensionMMORPGGameMode::AElementalAscensionMMORPGGameMode()
{
	// ACF base class (AACFGameMode) already creates:
	// - CollisionManager
	// - RagdollManager
	// We inherit these automatically

	// Set the custom GameState with ACF Team Manager Component
	GameStateClass = AElementalAscensionGameState::StaticClass();

	// Set the Player State class
	PlayerStateClass = AElementalAscensionPlayerState::StaticClass();

	// Note: DefaultPawnClass and PlayerControllerClass should be set in DefaultEngine.ini
	// to allow Blueprint customization without recompiling
}

void AElementalAscensionMMORPGGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

#if WITH_SERVER_CODE
	UE_LOG(LogTemp, Log, TEXT("SERVER: Validating incoming connection from %s"), *Address);

	// Add your validation here:
	// - Check ban list
	// - Verify UniqueId
	// - Rate limiting
	// If invalid: ErrorMessage = "Reason"; return;
#endif
}
