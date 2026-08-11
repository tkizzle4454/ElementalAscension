#pragma once

#include "CoreMinimal.h"
#include "Game/ACFGameMode.h"  // ← INHERIT FROM ACF, NOT GameModeBase!
#include "ElementalAscensionGameMode.generated.h"

/**
 * GameMode with ACF support + AAA server security
 */
UCLASS()
class ELEMENTALASCENSION_API AElementalAscensionGameMode : public AACFGameMode  // ← ACF base!
{
    GENERATED_BODY()

public:
    AElementalAscensionGameMode();

    /** AAA Authoritative Login: Validation happens here */
    virtual void PreLogin(const FString& Options, const FString& Address,
                         const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

    // ACF already provides:
    // - CollisionManager
    // - RagdollManager
    // No need to add them again!
};
