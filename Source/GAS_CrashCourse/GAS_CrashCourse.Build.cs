// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_CrashCourse : ModuleRules
{
	public GAS_CrashCourse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core",
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTasks",
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	
	}
}
