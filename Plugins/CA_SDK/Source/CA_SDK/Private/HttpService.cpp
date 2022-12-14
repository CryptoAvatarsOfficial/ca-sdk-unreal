// © 2023 CryptoAvatars. All rights reserved


#include "HttpService.h"
HttpService::HttpService()
{
}

HttpService::~HttpService()
{
}

HttpService::HttpService(FString apiKey, FString baseUri)
{
	this->apiKey = apiKey;
	this->baseUri = baseUri;
}
//
FHttpResponsePtr HttpService::HttpMethod(FHttpRequestRef request, FHttpResponsePtr responseDelegate)
{
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
	request->SetHeader("API-KEY", this->apiKey);
	request->SetHeader("Content-Type", "application/json");
	request->OnProcessRequestComplete().BindLambda
	([responseDelegate](FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
			 request->GetResponse();
		}
	);
	request->ProcessRequest();
	return responseDelegate;
}
//
// ESTO PETA IDK
//FHttpResponsePtr HttpService::Get(FString endpoint, FHttpResponsePtr responseDelegate)
//{
//	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
//	//Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
//	Request->SetURL("https://api.cryptoavatars.io/v1/collections/total");
//	Request->SetHeader("API-KEY", "$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
//	Request->SetVerb("GET");
//	Request->ProcessRequest();
//	return HttpMethod(Request, responseDelegate);
//}

template<typename T>
FHttpResponsePtr HttpService::Post(FString endpoint, T body, FHttpResponsePtr responseDelegate)
{
	TSharedPtr<FJsonObject> bodyJson;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(body->GetContentAsString());
	FJsonSerializer::Serialize(Reader, bodyJson);
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(this->baseUri + endpoint);
	Request->SetVerb("POST");
	Request->SetContentAsString(*bodyJson->GetContentAsString());
	return HttpMethod(Request, responseDelegate);
}

