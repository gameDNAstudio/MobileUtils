// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class MobileUtils : ModuleRules
	{
		public MobileUtils(TargetInfo Target)
		{
			Definitions.Add("WITH_MOBILEUTILS=1");

			PrivateIncludePaths.Add("MobileUtils/Private");

            PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject" });
			PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

			if (Target.Platform == UnrealTargetPlatform.IOS || Target.Platform == UnrealTargetPlatform.TVOS)
			{
				PrivateIncludePaths.Add("MobileUtils/Private/IOS");
			}
			else if (Target.Platform == UnrealTargetPlatform.Android)
			{
				PrivateIncludePaths.Add("MobileUtils/Private/Android");
			}

			// Additional Frameworks and Libraries for iOS
			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				PublicAdditionalFrameworks.Add(
					new UEBuildFramework(
						"Reachability",
						"../ThirdParty/iOS/Reachability.embeddedframework.zip"
					)
				);

				PublicAdditionalFrameworks.Add(
					new UEBuildFramework(
						"SSKeychain",
						"../ThirdParty/iOS/SSKeychain.embeddedframework.zip"
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
			}

			// Additional Frameworks and Libraries for Android
			else if (Target.Platform == UnrealTargetPlatform.Android)
			{
				PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
				string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
				AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "MobileUtils_APL.xml")));
			}
		}
	}
}
