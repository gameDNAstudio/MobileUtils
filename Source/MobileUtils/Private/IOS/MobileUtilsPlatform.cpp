// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#include "MobileUtilsPlatform.h"

#import <Reachability/Reachability.h>
#import <SAMKeychain/SAMKeychain.h>


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
	NSString *PersistentUUID = [SAMKeychain passwordForService : AppName account : @"incoding"];

	if (PersistentUUID == nil)
	{
		PersistentUUID = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
		[SAMKeychain setPassword : PersistentUUID forService : AppName account : @"incoding"];
	}

	return FString(PersistentUUID);
}

FString FMobileUtilsPlatform::GetDeviceId()
{
	return GetPersistentUniqueDeviceId();
}
