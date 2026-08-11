using UnrealBuildTool;
using System.Collections.Generic;

public class ElementalAscensionTarget : TargetRules
{
	public ElementalAscensionTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("ElementalAscension");
	}
}
