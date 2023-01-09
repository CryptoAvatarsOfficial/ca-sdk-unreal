// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "ca_unreal_sdkGameMode.generated.h"
UCLASS(minimalapi)
class Aca_unreal_sdkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Aca_unreal_sdkGameMode();
	virtual void StartPlay() override;
	void GetRequestExample();
	void PostRequestExample();
private:
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	template<typename T>
	void GetData(FString& data,T& dataStruct);
};



