// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MobileUtilsBlueprintLibrary.generated.h"


UCLASS()
class MOBILEUTILS_API UMobileUtilsBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// Check Internet Connection
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Online)
	static bool CheckInternetConnection();

	// Check Google Play Services
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Online)
	static bool CheckGooglePlayServices();
};
