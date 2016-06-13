// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

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
};
