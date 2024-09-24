// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DonKeyKong_sis457EX : ModuleRules
{
	public DonKeyKong_sis457EX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
