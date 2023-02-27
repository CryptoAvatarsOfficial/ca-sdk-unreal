// Copyright Epic Games, Inc. All Rights Reserved.

#include "CA_SDK.h"

#define LOCTEXT_NAMESPACE "FCA_SDKModule"

void FCA_SDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FCA_SDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCA_SDKModule, CA_SDK)