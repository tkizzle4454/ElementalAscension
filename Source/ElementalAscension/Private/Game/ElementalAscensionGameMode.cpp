#include "Game/ElementalAscensionGameMode.h"
#include "UObject/ConstructorHelpers.h"

AElementalAscensionGameMode::AElementalAscensionGameMode()
{
    // ACF base class already creates CollisionManager and RagdollManager
    // Just configure your default classes here if needed
}

void AElementalAscensionGameMode::PreLogin(const FString& Options, const FString& Address,
                                           const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
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
