#include "Player/ElementalAscensionPlayerState.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

AElementalAscensionPlayerState::AElementalAscensionPlayerState()
{
	// MMORPG PERFORMANCE: High update frequency for responsive UI
	SetNetUpdateFrequency(100.0f);

	// Create the GAS component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// AAA OPTIMIZATION: Mixed Replication Mode
	// Player sees all their detailed GAS data (cooldowns, etc.)
	// Other players only see essential attributes, saving bandwidth
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Create a basic AttributeSet (can be replaced with custom set later)
	AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AElementalAscensionPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
