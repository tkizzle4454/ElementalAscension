#pragma once

#include "CoreMinimal.h"
#include "Actors/ACFCharacter.h"  // ← ACF BASE!
#include "ElementalAscensionCharacter.generated.h"

UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionCharacter : public AACFCharacter
{
    GENERATED_BODY()

public:
    AElementalAscensionCharacter(const FObjectInitializer& ObjectInitializer);

    // Debug functions
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void PossessedBy(AController* NewController) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // Input Mapping Context - set this in Blueprint
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputMappingContext* DefaultMappingContext;

    // Input priority
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    int32 MappingPriority = 0;

public:
    // ACF provides:
    // - AbilitySystemComponent
    // - Team system (via ACF Team Component in Blueprint)
    // - Damage handling
    // - Combat system
    // - Inventory system
    // - Equipment system

    // Only add YOUR unique features here
};
