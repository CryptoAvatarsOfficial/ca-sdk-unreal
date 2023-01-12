// © 2023 CryptoAvatars. All rights reserved


#include "CryptoAvatars.h"
#include "Engine/Engine.h"

CryptoAvatars::CryptoAvatars(FString apiKey)
{
	const FString URL_SERVER = "https://api.cryptoavatars.io/v1/";
	const FString URL_SERVER_TEST = "http://localhost:3000/v1/";
	this->httpService = HttpService(apiKey, URL_SERVER);
}

void CryptoAvatars::GetUserAvatars(FString owner, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback)
{
	FOwnerAvatarsDto dto;
	dto.owner = owner;
	httpService.Post(pageUrl, dto, callback);
}

void CryptoAvatars::GetAvatars(FString licenseType, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback)
{
	FDefaultSearchAvatarsDto dto;
	dto.license = licenseType;
	httpService.Post(pageUrl, dto, callback);
}

void CryptoAvatars::GetAvatarsByName(FString licenseType, FString pageUrl, FString name, TFunction<void(FHttpResponsePtr)> callback)
{
	FSearchAvatarByNameDto dto;
	dto.license = licenseType;
	dto.name = name;
	httpService.Post(pageUrl, dto, callback);
}

void CryptoAvatars::GetAvatarsByCollectionName(FString licenseType, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback)
{
	FDefaultSearchAvatarsDtoCollectionName dto;
	dto.collectionName = collectionName;
	httpService.Post(pageUrl, dto, callback);
}

void CryptoAvatars::GetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback)
{
	FOwnerAvatarsDtoCollectionName dto;
	dto.owner = owner;
	dto.collectionName = collectionName;
	httpService.Post(pageUrl, dto, callback);
}

