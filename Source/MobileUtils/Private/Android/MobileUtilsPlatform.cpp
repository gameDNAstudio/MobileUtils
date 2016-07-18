// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "MobileUtilsPrivatePCH.h"
#include "MobileUtilsPlatform.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"


jmethodID FMobileUtilsPlatform::CheckInternetConnectionMethod;
jmethodID FMobileUtilsPlatform::CheckGooglePlayServicesMethod;

FMobileUtilsPlatform::FMobileUtilsPlatform()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		CheckInternetConnectionMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckInternetConnection", "()Z", false);
		CheckGooglePlayServicesMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckGooglePlayServices", "()Z", false);
	}
}

FMobileUtilsPlatform::~FMobileUtilsPlatform()
{
}

bool FMobileUtilsPlatform::CheckInternetConnection()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FMobileUtilsPlatform::CheckInternetConnectionMethod);
	}
	return bResult;
}

bool FMobileUtilsPlatform::CheckGooglePlayServices()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FMobileUtilsPlatform::CheckGooglePlayServicesMethod);
	}
	return bResult;
}

FString FMobileUtilsPlatform::GetPersistentUniqueDeviceId()
{
	return UKismetSystemLibrary::GetUniqueDeviceId();
}
