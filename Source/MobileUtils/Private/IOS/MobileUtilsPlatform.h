// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#pragma once

#include "Interfaces/MobileUtilsInterface.h"

class FMobileUtilsPlatform : public IMobileUtilsInterface
{
public:
	FMobileUtilsPlatform();
	virtual ~FMobileUtilsPlatform();

	virtual bool CheckInternetConnection() override;
	virtual bool CheckGooglePlayServices() override;
	virtual FString GetPersistentUniqueDeviceId() override;
};
