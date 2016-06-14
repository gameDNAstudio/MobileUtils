// Mobile Utils Plugin
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "MobileUtilsPrivatePCH.h"
#include "MobileUtilsPlatform.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>

FMobileUtilsPlatform::FMobileUtilsPlatform()
{
}

FMobileUtilsPlatform::~FMobileUtilsPlatform()
{
}

bool FMobileUtilsPlatform::CheckInternetConnection()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckInternetConnection", "()Z", false);
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return bResult;
}

bool FMobileUtilsPlatform::CheckGooglePlayServices()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckGooglePlayServices", "()Z", false);
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return bResult;
}
