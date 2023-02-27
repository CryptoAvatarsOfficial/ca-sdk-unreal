// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ca_unreal_sdkEditorTarget : TargetRules
{
	public ca_unreal_sdkEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("ca_unreal_sdk");
        ExtraModuleNames.AddRange(new string[] { "VRM4U", "CA_SDK" });
    }
}
