using UnrealBuildTool;

public class ElementalAscension : ModuleRules
{
    public ElementalAscension(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Security flag for server code stripping
        if (Target.Type == TargetRules.TargetType.Server || Target.Type == TargetRules.TargetType.Editor)
        {
            PublicDefinitions.Add("WITH_SERVER_CODE=1");
        }
        else
        {
            PublicDefinitions.Add("WITH_SERVER_CODE=0");
        }

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "UMG",
            "AIModule",
            "NavigationSystem",
            "Niagara",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "Iris",
            "NetCore",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "StateTreeModule",
            "GameplayStateTreeModule",

            // ACF Modules - Add as needed
            "AscentCoreInterfaces",   // Core interfaces (IACFEntityInterface)
            "AscentCombatFramework",  // Core ACF
            "AscentTeams",            // Team system
            "CollisionsManager",      // Combat collisions
            "AIFramework",            // ACF AI
            "AscentSaveSystem"        // Save system (required for IALSSavableInterface)
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Slate",
            "SlateCore",
            "DeveloperSettings"
        });

        // Platform-specific Steam integration
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        }
    }
}
