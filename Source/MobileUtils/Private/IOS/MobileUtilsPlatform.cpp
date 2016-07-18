// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "MobileUtilsPrivatePCH.h"
#include "MobileUtilsPlatform.h"

#import <Reachability/Reachability.h>
#import <SSKeychain/SSKeychain.h>


FMobileUtilsPlatform::FMobileUtilsPlatform()
{
}

FMobileUtilsPlatform::~FMobileUtilsPlatform()
{
}

bool FMobileUtilsPlatform::CheckInternetConnection()
{
	Reachability *reachability = [Reachability reachabilityForInternetConnection];
	NetworkStatus networkStatus = [reachability currentReachabilityStatus];
	return networkStatus != NotReachable;
}

bool FMobileUtilsPlatform::CheckGooglePlayServices()
{
	return false;
}

FString FMobileUtilsPlatform::GetPersistentUniqueDeviceId()
{
	NSString *AppName = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString*)kCFBundleNameKey];
	NSString *PersistentUUID = [SSKeychain passwordForService : AppName account : @"incoding"];

	if (PersistentUUID == nil)
	{
		PersistentUUID = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
		[SSKeychain setPassword : PersistentUUID forService : AppName account : @"incoding"];
	}

	return FString(PersistentUUID);
}
