// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

#include "MobileUtilsBlueprintLibrary.h"
#include "MobileUtilsPrivatePCH.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"


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

FString UMobileUtilsBlueprintLibrary::GetPersistentUniqueDeviceId()
{
#if PLATFORM_ANDROID || PLATFORM_IOS
	return IMobileUtils::Get().GetPlatformInterface()->GetPersistentUniqueDeviceId();
#else
	return UKismetSystemLibrary::GetUniqueDeviceId();
#endif
}
