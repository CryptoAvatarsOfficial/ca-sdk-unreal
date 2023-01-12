// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Structs/Structs.h"
/**
 * 
 */
//class FHttpRequestRef;

class CA_SDK_API HttpService
{
public:
	HttpService();
	~HttpService() = default;
	HttpService(FString apiKey, FString baseUri);
	// Base Request
	void HttpMethod(FHttpRequestRef request, TFunction<void(FHttpResponsePtr)> callback);
	template<typename T>
	void Post(FString endpoint, T body, TFunction<void(FHttpResponsePtr)> callback);
	void Get(FString endpoint, TFunction<void(FHttpResponsePtr)> callback);
	void DownloadImage(FString url, FHttpResponsePtr responseDelegate);
	void Download3DModel(FString url, FHttpResponsePtr responseDelegate);
private:
	FString apiKey;
	FString baseUri;
};


