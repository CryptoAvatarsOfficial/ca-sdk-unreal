// Copyright Epic Games, Inc. All Rights Reserved.

#include "ca_unreal_sdkGameMode.h"
#include "ca_unreal_sdkCharacter.h"
#include "Json.h"
#include "CA_SDK/Public/Structs/Structs.h"
#include "JsonObjectConverter.h"
#include "UObject/ConstructorHelpers.h"

Aca_unreal_sdkGameMode::Aca_unreal_sdkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void Aca_unreal_sdkGameMode::StartPlay() {
	Super::StartPlay();
	PostRequestExample();
	//GetRequestExample();
}

void Aca_unreal_sdkGameMode::GetRequestExample()
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	Request->SetURL("https://api.cryptoavatars.io/v1/collections/total");
	Request->SetHeader("API-KEY", "$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}
void Aca_unreal_sdkGameMode::PostRequestExample() {
	#pragma region Body Part
	FString RequestBody = "{}";
	TSharedRef<FJsonObject> RequestObj = MakeShared<FJsonObject>();
	
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(RequestObj, Writer);
	
	#pragma endregion Body Part
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	// We can parametrize OnResponseReceived delegate
	Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	// Parametrize part of the URL
	Request->SetURL("https://api.cryptoavatars.io/v1/nfts/avatars/list?skip=0&limit=20");
	// This will always be the same
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	// Parametrize the API-KEY Value
	Request->SetHeader("API-KEY", "$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
	Request->SetContentAsString(RequestBody);
	Request->ProcessRequest();
}
void Aca_unreal_sdkGameMode::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	TSharedPtr<FJsonObject> ResponseObj;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	FJsonSerializer::Deserialize(Reader, ResponseObj);
	FNftsArray nfts;
	UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(*Response->GetContentAsString());
	
	TArray<TSharedPtr<FJsonValue>> nftsArray = ResponseObj->GetArrayField("nfts");
	
	for (int i = 0; i < nftsArray.Num(); i++) {
		FNft nft;
		FJsonObjectConverter::JsonObjectToUStruct(nftsArray[i]->AsObject().ToSharedRef(), &nft, 0, 0);
		nfts.nfts.Add(nft);
		UE_LOG(LogTemp, Display, TEXT("Response %s"), *nft.metadata.name);
	}
	
	/*for (int32 i = 0; i < nftsArray.Num(); ++i) {
		nfts.nfts[i] = nftsArray[i];
	}*/
	//FJsonObjectConverter::JsonObjectStringToUStruct(*Response->GetContentAsString(), &nfts, 0, 0);
	
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), "PARSING SUCCESS");
	////UE_LOG(LogTemp, Display, TEXT("Respones %s", n))
	//for(auto nft : nftsArray)
	//{
	//	UE_LOG(LogTemp, Display, TEXT("Response %s"), *nft->AsString());
	//}
	
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), bConnectedSuccessfully);
	//UE_LOG(LogTemp, Display, TEXT("Name %s"), *ResponseObj->GetIntegerField("name"));
}
template <typename T>
void Aca_unreal_sdkGameMode::GetData(FString& data, T& dataStruct) {
	FJsonObjectConverter::JsonObjectStringToUStruct(data, &dataStruct,0,0);
}
