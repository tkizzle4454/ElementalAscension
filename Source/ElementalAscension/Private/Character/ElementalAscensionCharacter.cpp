#include "Character/ElementalAscensionCharacter.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

AElementalAscensionCharacter::AElementalAscensionCharacter(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , DefaultMappingContext(nullptr)
    , MappingPriority(0)
{
    // ACF base class already has all the components
    // Configure your character-specific settings here
    PrimaryActorTick.bCanEverTick = true;
}

void AElementalAscensionCharacter::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("=== PLAYER CHARACTER DEBUG ==="));
    UE_LOG(LogTemp, Warning, TEXT("Character: %s"), *GetName());
    UE_LOG(LogTemp, Warning, TEXT("Has Controller: %s"), GetController() ? TEXT("YES") : TEXT("NO"));

    if (GetController())
    {
        UE_LOG(LogTemp, Warning, TEXT("Controller: %s"), *GetController()->GetName());
        UE_LOG(LogTemp, Warning, TEXT("Is Player Controller: %s"),
            GetController()->IsA<APlayerController>() ? TEXT("YES") : TEXT("NO"));
    }
}

void AElementalAscensionCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Log every 60 frames (about once per second at 60fps)
    static int FrameCounter = 0;
    if (++FrameCounter >= 60)
    {
        FrameCounter = 0;

        FVector Velocity = GetVelocity();
        UE_LOG(LogTemp, Log, TEXT("Velocity: %s (Speed: %.2f)"), *Velocity.ToString(), Velocity.Size());

        if (GetController())
        {
            FRotator ControlRotation = GetController()->GetControlRotation();
            UE_LOG(LogTemp, Log, TEXT("Control Rotation: %s"), *ControlRotation.ToString());
        }
    }
}

void AElementalAscensionCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    UE_LOG(LogTemp, Warning, TEXT("=== POSSESSED BY CONTROLLER ==="));
    UE_LOG(LogTemp, Warning, TEXT("Controller: %s"), NewController ? *NewController->GetName() : TEXT("NULL"));

    if (APlayerController* PC = Cast<APlayerController>(NewController))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller Class: %s"), *PC->GetClass()->GetName());

        // Add Input Mapping Context
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            UE_LOG(LogTemp, Warning, TEXT("Enhanced Input Subsystem: FOUND"));

            // Add the default mapping context if provided
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, MappingPriority);
                UE_LOG(LogTemp, Warning, TEXT("Added Input Mapping Context: %s"), *DefaultMappingContext->GetName());
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("DefaultMappingContext is NULL! Set it in Blueprint Class Defaults."));
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Enhanced Input Subsystem: NOT FOUND - INPUT WILL NOT WORK!"));
        }
    }
}

void AElementalAscensionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UE_LOG(LogTemp, Warning, TEXT("=== SETUP PLAYER INPUT ==="));
    UE_LOG(LogTemp, Warning, TEXT("Input Component: %s"), PlayerInputComponent ? TEXT("Valid") : TEXT("NULL"));

    if (PlayerInputComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Input Component Class: %s"), *PlayerInputComponent->GetClass()->GetName());

        if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
        {
            UE_LOG(LogTemp, Warning, TEXT("Enhanced Input Component: YES"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Enhanced Input Component: NO (using legacy input)"));
        }
    }
}
