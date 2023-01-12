// © 2023 CryptoAvatars. All rights reserved

#include "HttpService.h"
#include "JsonObjectConverter.h"

template void HttpService::Post(FString endpoint, struct FDefaultSearchAvatarsDto body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FSearchAvatarByNameDto body, TFunction<void(FHttpResponsePtr)> callback);

HttpService::HttpService() {
	this->apiKey = "";
	this->baseUri = "";
}

HttpService::HttpService(FString apiKey, FString baseUri)
{
	this->apiKey = apiKey;
	this->baseUri = baseUri;
}
//
//auto lambda = [this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
//	if (!bWasSuccessful) {
//		// Fail function
//		return;
//	}
//	// Check the status code if needed (the api might not return a status code, and just return a json string directly)
//	const int32 code = Response->GetResponseCode();
//	if (code == 200)
//	{
//		// Do stuff with your response, like parse JSON->Ustruct member of your class
//		const auto result = Response->GetContentAsString();
//		FJsonObjectConverter::JsonObjectStringToUStruct(result, &memberUStruct);

//		// Can call a function or event to alert other classes/Blueprint that the API call completed.
//		CallYourSuccessFunction();
//		return;
//	}
//}
//request = FHttpModule::Get().CreateRequest();
void HttpService::HttpMethod(FHttpRequestRef request, TFunction<void(FHttpResponsePtr)> callback)
{
	request->SetHeader("API-KEY", this->apiKey);
	request->SetHeader("Content-Type", "application/json");
	request->OnProcessRequestComplete().BindLambda
	([callback](FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			UE_LOG(LogTemp, Warning, TEXT("Got Response: %s"), *response->GetContentAsString());
			callback(response);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Response Failed: %s"), response->GetResponseCode());
		}
		});
	request->ProcessRequest();
}
//
// ESTO PETA IDK
void HttpService::Get(FString endpoint, TFunction<void(FHttpResponsePtr)> callback)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	//Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	Request->SetURL(this->baseUri + endpoint);
	Request->SetVerb("GET");
	HttpMethod(Request, callback);
}

template<typename T>
void HttpService::Post(FString endpoint, T body, TFunction<void(FHttpResponsePtr)> callback)
{
	FString bodyJson;
	FJsonObjectConverter::UStructToJsonObjectString(body, bodyJson,0,0);
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	UE_LOG(LogTemp, Warning, TEXT("URI SENT: %s"), *FString(this->baseUri + endpoint));
	Request->SetURL(this->baseUri + endpoint);
	Request->SetVerb("POST");
	Request->SetContentAsString(bodyJson);
	HttpMethod(Request, callback);
}

