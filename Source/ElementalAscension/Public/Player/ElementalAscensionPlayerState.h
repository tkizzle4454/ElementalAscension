#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "ElementalAscensionPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * AAA Authoritative PlayerState for MMORPG
 * Persistent player stats and abilities across spawns
 * Uses GAS (Gameplay Ability System) for replication
 */
UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AElementalAscensionPlayerState();

	// IAbilitySystemInterface Implementation
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintPure, Category = "GAS")
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	/** The core GAS component for the player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/** The player's attribute set (Health, Mana, etc.) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAttributeSet> AttributeSet;
};
