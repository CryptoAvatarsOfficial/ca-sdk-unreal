// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ca_unreal_sdk : ModuleRules
{
	public ca_unreal_sdk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "VRM4U", "HTTP","Json", "JsonUtilities", "CA_SDK" });
    }
}
