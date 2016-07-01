// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "MobileUtilsPrivatePCH.h"
#include "MobileUtilsBlueprintLibrary.h"


UMobileUtilsBlueprintLibrary::UMobileUtilsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UMobileUtilsBlueprintLibrary::CheckInternetConnection()
{
#if PLATFORM_ANDROID || PLATFORM_IOS
	return IMobileUtils::Get().GetPlatformInterface()->CheckInternetConnection();
#else
	return true;
#endif
}

bool UMobileUtilsBlueprintLibrary::CheckGooglePlayServices()
{
#if PLATFORM_ANDROID || PLATFORM_IOS
	return IMobileUtils::Get().GetPlatformInterface()->CheckGooglePlayServices();
#else
	return false;
#endif
}
