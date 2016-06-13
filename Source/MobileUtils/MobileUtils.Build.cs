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

			PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject" });
			PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

			// Additional Frameworks and Libraries for iOS
			if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				PublicAdditionalFrameworks.Add(
					new UEBuildFramework(
						"Reachability",
						"../../ThirdPartyLibraries/iOS/Reachability.embeddedframework.zip"
					)
				);

				PublicFrameworks.AddRange(
					new string[]
					{
						"SystemConfiguration"
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
