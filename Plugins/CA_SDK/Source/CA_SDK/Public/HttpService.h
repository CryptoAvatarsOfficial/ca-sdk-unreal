// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include <Http.h>
/**
 * 
 */
class CA_SDK_API HttpService
{
public:
	HttpService();
	~HttpService();
	HttpService(FString apiKey, FString baseUri);
	// Base Request
	FHttpResponsePtr HttpMethod(FHttpRequestRef request, FHttpResponsePtr responseDelegate);

	template<typename T>
	FHttpResponsePtr Post(FString endpoint, T body, FHttpResponsePtr responseDelegate);
	FHttpResponsePtr Get(FString endpoint, FHttpResponsePtr responseDelegate);
	void DownloadImage(FString url, FHttpResponsePtr responseDelegate);
	void Download3DModel(FString url, FHttpResponsePtr responseDelegate);
private:
	FString apiKey;
	FString baseUri;
};


