// © 2023 CryptoAvatars. All rights reserved


#include "CryptoAvatars.h"
#include "Engine/Engine.h"

CryptoAvatars::CryptoAvatars(FString apiKey)
{
	const FString URL_SERVER = "https://api.cryptoavatars.io/v1/";
	const FString URL_SERVER_TEST = "http://localhost:3000/v1/";
	this->httpService = HttpService(apiKey, URL_SERVER);
}

void CryptoAvatars::GetAvatars(FString licenseType, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback)
{
	FDefaultSearchAvatarsDto dto;
	dto.license = licenseType;
	httpService.Post(pageUrl, dto, callback);
}
