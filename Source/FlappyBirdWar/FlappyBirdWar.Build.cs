// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FlappyBirdWar : ModuleRules
{
	public FlappyBirdWar(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D", "Niagara"});

		PublicIncludePaths.AddRange(new string[] {
		  "E:\epic\UE_4.25\Engine\Plugins\FX\Niagara\Source\Niagara\Public"
		});


	}
}
