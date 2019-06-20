// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class MobileUtils : ModuleRules
	{
		public MobileUtils(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            PrecompileForTargets = PrecompileTargetsType.Any;

            PublicDefinitions.Add("WITH_MOBILEUTILS=1");

			PrivateIncludePaths.Add("MobileUtils/Private");

            PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "OnlineSubsystem" });

			PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				PrivateIncludePaths.Add("MobileUtils/Private/IOS");
			}
			else if (Target.Platform == UnrealTargetPlatform.Android)
			{
				PrivateIncludePaths.Add("MobileUtils/Private/Android");
			}

			// Additional Frameworks and Libraries for IOS
			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				PublicAdditionalFrameworks.Add(
					new Framework(
						"Reachability",
						"../ThirdParty/IOS/Reachability.embeddedframework.zip"
					)
				);

				PublicAdditionalFrameworks.Add(
					new Framework(
						"SAMKeychain",
						"../ThirdParty/IOS/SAMKeychain.embeddedframework.zip",
                        "SAMKeychain.bundle"
                    )
				);

				PublicFrameworks.AddRange(
					new string[]
					{
						"SystemConfiguration",
						"Security"
					}
				);

				PublicAdditionalLibraries.Add("z");
				PublicAdditionalLibraries.Add("sqlite3");

				string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
				AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(PluginPath, "MobileUtils_UPL_IOS.xml"));
			}
			// Additional Frameworks and Libraries for Android
			else if (Target.Platform == UnrealTargetPlatform.Android)
			{
				PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
				string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
				AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "MobileUtils_UPL_Android.xml"));
			}
		}
	}
}
