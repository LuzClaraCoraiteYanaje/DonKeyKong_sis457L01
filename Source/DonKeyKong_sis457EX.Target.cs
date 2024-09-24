// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DonKeyKong_sis457EXTarget : TargetRules
{
	public DonKeyKong_sis457EXTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("DonKeyKong_sis457EX");
	}
}
