// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ca_unreal_sdkTarget : TargetRules
{
	public ca_unreal_sdkTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("ca_unreal_sdk");
        ExtraModuleNames.AddRange(new string[] { "VRM4U" });
    }
}
