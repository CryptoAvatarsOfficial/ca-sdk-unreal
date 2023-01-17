// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Json.h"
#include "Structs/Structs.h"
#include "HttpService.h"


// class FHttpResponsePtr;
// class HttpService;
/**
 * CryptoAvatars Core Functions
 */
class CA_SDK_API CryptoAvatars
{

public:
	CryptoAvatars() = default;
	~CryptoAvatars() = default;
	CryptoAvatars(FString apiKey);
	void UserLogin(FString email, FString password, TFunction<void(FHttpResponsePtr)> callback);
	void UserLoginWithMetamaskToCA(FString wallet, FString signature, TFunction<void(FHttpResponsePtr)> callback);
	void GetUserAvatars(FString owner, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatars(FString licenseType, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatarsByName(FString licenseType, FString pageUrl, FString name, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatarsByCollectionName(FString licenseType, FString pageUrl,FString collectionName, TFunction<void(FHttpResponsePtr)> callback);
	void GetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback);
	/**
	 * Convert bytes to texture. This is fully engine-based functionality and may not be well optimized
	 *
	 * @param Bytes Byte array to convert to texture
	 * @return Converted texture or nullptr on failure
	 */
	void GetAvatarPreviewImage(FString imageUrl, TFunction<void(UTexture2D*)> response);
	void GetAvatarVRMModel(FString vrmUrl, TFunction<void(FHttpResponsePtr)> response);
	void GetNFTsCollections(FString pageUrl, TFunction<void(FHttpResponsePtr)> response);

	
protected:
	HttpService httpService;
	void DownloadImage(FString url, TFunction<void(UTexture2D*)> response);
	/**
	 * Broadcast the progress both multi-cast and single-cast delegates
	 * @note To get the download percentage, divide the BytesReceived value by the ContentLength
	 */
	void BroadcastProgress(const int32 BytesReceived, const int32 ContentLength) const;
	AActor* ImportVRMModel(FString path);
	
};
