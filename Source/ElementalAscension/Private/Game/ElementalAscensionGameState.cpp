// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/ElementalAscensionGameState.h"
#include "Components/ACFTeamManagerComponent.h"
#include "ACFTeamsConfigDataAsset.h"
#include "UObject/ConstructorHelpers.h"

AElementalAscensionGameState::AElementalAscensionGameState()
{
	// Create ACF Team Manager Component for ACF AI support
	TeamManagerComponent = CreateDefaultSubobject<UACFTeamManagerComponent>(TEXT("TeamManagerComponent"));

	// Load ACF Team Configuration Data Asset
	static ConstructorHelpers::FObjectFinder<UACFTeamsConfigDataAsset> TeamConfigAsset(TEXT("/AscentCombatFramework/Configuration/DA_ACFTeamsConfig.DA_ACFTeamsConfig"));
	if (TeamConfigAsset.Succeeded() && TeamManagerComponent)
	{
		TeamManagerComponent->SetTeamConfigDataAsset(TeamConfigAsset.Object);
	}
}
