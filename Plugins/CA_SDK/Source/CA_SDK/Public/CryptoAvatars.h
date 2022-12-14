// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include <HttpService.h>
#include "Structs/Structs.h"

DECLARE_DELEGATE_OneParam(OnLoginResult, FLoginResponseDto);
DECLARE_DELEGATE_OneParam(OnAvatarsResult, FNftsArray);
DECLARE_DELEGATE_OneParam(OnImage, UTexture2D*);
DECLARE_DELEGATE_OneParam(OnCollectionsResult, FNftsCollectionsArray);
DECLARE_DELEGATE_TwoParams(OnModelResult, AActor*, FString);
/**
 * CryptoAvatars Core Functions
 */
class CA_SDK_API CryptoAvatars
{
protected:
	OnLoginResult OnLoginResultDelegate;
	OnAvatarsResult OnAvatarsResultDelegate;
	OnImage OnImageDelegate;
	OnCollectionsResult OnCollectionsResultDelegate;
	OnModelResult OnModelResultDelegate;
public:
	CryptoAvatars();
	CryptoAvatars(FString apiKey);
	void UserLogin(FString email, FString password, OnLoginResult response);
	void UserLoginWithMetamaskToCA(FString wallet, FString signature, OnLoginResult response);
	void GetUserAvatars(FString owner, FString pageUrl, OnAvatarsResult response);
	void GetAvatars(FString licenseType, FString pageUrl, OnAvatarsResult response);
	void GetAvatarsByName(FString licenseType, FString pageUrl, FString name, OnAvatarsResult response);
	void GetAvatarsByCollectionName(FString licenseType, FString pageUrl,FString collectionName, OnAvatarsResult response);
	void GetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, OnAvatarsResult response);
	/**
	 * Convert bytes to texture. This is fully engine-based functionality and may not be well optimized
	 *
	 * @param Bytes Byte array to convert to texture
	 * @return Converted texture or nullptr on failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Avatars")
	void GetAvatarPreviewImage(FString imageUrl, OnImage response);
	void GetAvatarVRMModel(FString vrmUrl, OnModelResult response);
	void GetNFTsCollections(FString pageUrl, OnCollectionsResult response);
	~CryptoAvatars();

	
protected:
	HttpService httpService;
	/**
	 * Broadcast the progress both multi-cast and single-cast delegates
	 * @note To get the download percentage, divide the BytesReceived value by the ContentLength
	 */
	void BroadcastProgress(const int32 BytesReceived, const int32 ContentLength) const;
	AActor* ImportVRMModel(FString path);
	
};
