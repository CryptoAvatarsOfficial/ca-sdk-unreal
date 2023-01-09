// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Structs.generated.h"
/**
 * Structs for DTOs
 */
USTRUCT(BlueprintType)
struct FLoginRequestDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString email;
	UPROPERTY()
		FString password;
};
USTRUCT(BlueprintType)
struct FLoginMetamaskDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString wallet;
	UPROPERTY()
		FString signature;
};
USTRUCT(BlueprintType)
struct FLoginResponseDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString userId;
	UPROPERTY()
		FString wallet;
};
USTRUCT(BlueprintType)
struct FDefaultSearchAvatarsDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString license;
};
USTRUCT(BlueprintType)
struct FSearchAvatarByNameDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString name;
	UPROPERTY()
		FString license;
};
USTRUCT(BlueprintType)
struct FOwnerAvatarsDto
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString owner;
};
USTRUCT(BlueprintType)
struct FOwnerAvatarsDtoCollectionName
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString collectionName;
	UPROPERTY()
		FString owner;
};
USTRUCT(BlueprintType)
struct FDefaultSearchAvatarsDtoCollectionName
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString collectionName;
	UPROPERTY()
		FString license;
};
USTRUCT(BlueprintType)
struct FAvatar
{
	GENERATED_BODY()
public:
	struct FMetadata {


	public:
		UPROPERTY()
			FString name;
		UPROPERTY()
			FString description;
		UPROPERTY()
			FString image;
		UPROPERTY()
			FString asset;
		UPROPERTY()
			FString createdBy;
		UPROPERTY()
			FString createdAt;
		UPROPERTY()
			TArray<FString> tags;
	};
		FMetadata metadata;
};
USTRUCT(BlueprintType)
struct FAvatarsArray
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TArray<FAvatar> avatars;
	UPROPERTY()
		FString license;
};
USTRUCT(BlueprintType)
struct FNft
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FString owner;
	struct FMetadata {
	public:
		UPROPERTY()
			FString name;
		UPROPERTY()
			FString descritpion;
		UPROPERTY()
			FString image;
		UPROPERTY()
			FString asset;
		UPROPERTY()
			FString createdy;
		UPROPERTY()
			FString createdAt;
		UPROPERTY()
			TArray<FString> tags;
	};
		FMetadata metadata;
};
USTRUCT(BlueprintType)
struct FNftsArray
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TArray<FNft> nfts;
	UPROPERTY()
		int32 totalNfts;
	UPROPERTY()
		int32 currentPage;
	UPROPERTY()
		int32 totalPages;
	UPROPERTY()
		FString next;
	UPROPERTY()
		FString prev;
};
USTRUCT(BlueprintType)
struct FNftsCollection {
	GENERATED_BODY()
public:
	UPROPERTY()
		bool isEnabled;
	UPROPERTY()
		FString logoImage;
	UPROPERTY()
		FString bannerImage;
	UPROPERTY()
		FString id;
	UPROPERTY()
		FString name;
	struct FCollectionContracts {


	public:
		UPROPERTY()
			FString contractAddress;
		UPROPERTY()
			FString chainId;
	};
	
		FCollectionContracts collectionContracts;
	UPROPERTY()
		int32 __v;
	UPROPERTY()
		int32 owners;
	UPROPERTY()
		FString description;
	struct FSocialLinks {

	public:
		UPROPERTY()
			FString twitter;
		UPROPERTY()
			FString website;
		UPROPERTY()
			FString discord;
		UPROPERTY()
			FString instagram;
		UPROPERTY()
			FString twitch;
	};
	
		FSocialLinks socialLinks;
	UPROPERTY()
		int32 totalSupply;
	UPROPERTY()
		int32 floorPrice;
	UPROPERTY()
		int32 volume;
	UPROPERTY()
		int32 bestOffer;
	UPROPERTY()
		FString mobileBannerImage;
};
