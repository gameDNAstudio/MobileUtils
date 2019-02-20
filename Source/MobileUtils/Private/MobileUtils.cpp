// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#include "IMobileUtils.h"
#include "MobileUtilsBlueprintLibrary.h"


DEFINE_LOG_CATEGORY(LogMobileUtils);

#define LOCTEXT_NAMESPACE "MobileUtils"

class FMobileUtils : public IMobileUtils
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FMobileUtils, MobileUtils)

// Startup Module
void FMobileUtils::StartupModule()
{	
#if PLATFORM_ANDROID || PLATFORM_IOS
	PlatformInterface = MakeShareable(new FMobileUtilsPlatform());
#endif
}

// Shutdown Module
void FMobileUtils::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE
