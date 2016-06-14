// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "MobileUtilsPrivatePCH.h"
#include "MobileUtilsPlatform.h"

#import <Reachability/Reachability.h>


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
