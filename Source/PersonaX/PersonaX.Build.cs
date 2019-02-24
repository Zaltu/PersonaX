// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PersonaX : ModuleRules
{
	public PersonaX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //bEnableExceptions = true; // Enabled /EHsc, which is required for nlohmann::json

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore"});
        PublicIncludePaths.Add("C:/LUA");
		PublicIncludePaths.Add("K:/Framework/cincludes");
        PublicAdditionalLibraries.Add("C:/LUA/lua51.lib");
    }
}
