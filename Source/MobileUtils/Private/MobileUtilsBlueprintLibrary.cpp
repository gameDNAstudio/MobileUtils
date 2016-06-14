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
	return IMobileUtils::Get().GetPlatformInterface()->CheckInternetConnection();
}

bool UMobileUtilsBlueprintLibrary::CheckGooglePlayServices()
{
	return IMobileUtils::Get().GetPlatformInterface()->CheckGooglePlayServices();
}
