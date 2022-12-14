// © 2023 CryptoAvatars. All rights reserved


#include "CryptoAvatars.h"

CryptoAvatars::CryptoAvatars()
{
}

CryptoAvatars::~CryptoAvatars()
{
}

CryptoAvatars::CryptoAvatars(FString apiKey)
{
	const FString URL_SERVER = "https://api.cryptoavatars.io/v1/";
	const FString URL_SERVER_TEST = "http://localhost:3000/v1/";
	this->httpService = HttpService(URL_SERVER, apiKey);
}