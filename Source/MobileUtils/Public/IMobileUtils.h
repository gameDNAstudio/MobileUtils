// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "EngineMinimal.h"
#include "Core.h"
#include "Interfaces/MobileUtilsInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMobileUtils, Log, All);

typedef TSharedPtr<IMobileUtilsInterface, ESPMode::ThreadSafe> FMobileUtilsPlatformPtr;

class IMobileUtils : public IModuleInterface
{
public:
	static inline IMobileUtils& Get()
	{
		return FModuleManager::LoadModuleChecked< IMobileUtils >("MobileUtils");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("MobileUtils");
	}

	inline FMobileUtilsPlatformPtr GetPlatformInterface() const
	{
		return PlatformInterface;
	}

protected:
	FMobileUtilsPlatformPtr PlatformInterface;
};
