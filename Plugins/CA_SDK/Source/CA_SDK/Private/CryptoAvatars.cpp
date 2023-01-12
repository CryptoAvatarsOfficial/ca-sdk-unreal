// © 2023 CryptoAvatars. All rights reserved


#include "CryptoAvatars.h"
#include "Engine/Engine.h"
#include "ImageUtils.h"
CryptoAvatars::CryptoAvatars(FString apiKey)
{
	const FString URL_SERVER = "https://api.cryptoavatars.io/v1/";
	const FString URL_SERVER_TEST = "http://localhost:3000/v1/";
	this->httpService = HttpService(apiKey, URL_SERVER);
}

void CryptoAvatars::UserLogin(FString email, FString password, TFunction<void(FHttpResponsePtr)> callback)
{
	FLoginRequestDto dto;
	FString resource = "login-pass";
	dto.email = email;
	dto.password = password;
	httpService.Post(resource, dto, callback);
}

void CryptoAvatars::UserLoginWithMetamaskToCA(FString wallet, FString signature, TFunction<void(FHttpResponsePtr)> callback)
{
	FLoginMetamaskDto dto;
	FString resource = "login";
	dto.wallet = wallet;
	dto.signature = signature;
	httpService.Post(resource, dto, callback);
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

void CryptoAvatars::GetAvatarPreviewImage(FString imageUrl, TFunction<UTexture2D* (UTexture2D*)> response)
{
	imageUrl = imageUrl.Replace(TEXT("gateway.pinata.cloud"), TEXT("usercollection.mypinata.cloud"));
	DownloadImage(imageUrl, response);
}

void CryptoAvatars::DownloadImage(FString url, TFunction<void(UTexture2D*)> callback)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->OnProcessRequestComplete().BindLambda
	([callback](FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			UTexture2D* AvatarTexture = NewObject<UTexture2D>();
			// Load the image data into the texture object
			AvatarTexture = FImageUtils::ImportBufferAsTexture2D(response->GetContent());
			callback(AvatarTexture);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Response Failed: %s"), response->GetResponseCode());
			callback(nullptr);
		}
		});
	Request->ProcessRequest();
}


