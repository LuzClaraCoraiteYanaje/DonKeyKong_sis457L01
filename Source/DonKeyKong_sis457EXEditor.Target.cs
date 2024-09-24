// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DonKeyKong_sis457EXEditorTarget : TargetRules
{
	public DonKeyKong_sis457EXEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("DonKeyKong_sis457EX");
	}
}
