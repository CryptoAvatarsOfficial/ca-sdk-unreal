// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"

/**
 * Structs
 */
class CA_SDK_API FStructs
{
public:
	FStructs();
	~FStructs();
	

	USTRUCT(BlueprintType)
	struct LoginRequestDto 
	{
	public:
		FString email;
		FString password;
	};
	
	USTRUCT(BlueprintType)
	struct LoginMetamaskDto
	{
	public:
		FString wallet;
		FString signature;
	};
	
	USTRUCT(BlueprintType)
		struct LoginResponseDto
	{
	public:
		FString userId;
		FString wallet;
	};

	USTRUCT(BlueprintType)
		struct DefaultSearchAvatarsDto
	{
	public:
		FString license;
	};
	USTRUCT(BlueprintType)
		struct SearchAvatarByNameDto
	{
	public:
		FString name;
		FString license;
	};
	USTRUCT(BlueprintType)
		struct OwnerAvatarsDto
	{
	public:
		FString owner;
	};
	USTRUCT(BlueprintType)
		struct OwnerAvatarsDtoCollectionName
	{
	public:
		FString collectionName;
		FString owner;
	};
	USTRUCT(BlueprintType)
		struct DefaultSearchAvatarsDtoCollectionName
	{
	public:
		FString collectionName;
		FString license;
	};
	USTRUCT(BlueprintType)
		struct Avatar
	{
	public:
		USTRUCT(BlueprintType)
		struct Metadata {
			public:
				FString name;
				FString description;
				FString image;
				FString asset;
				FString createdBy;
				FString createdAt;
				TArray<FString> tags;
		};
		Metadata metadata;
	};
	
	USTRUCT(BlueprintType)
		struct AvatarsArray
	{
	public:
		TArray<Avatar> avatars;
		FString license;
	};
	
	USTRUCT(BlueprintType)
		struct Nft
	{
	public:
		FString owner;
		USTRUCT(BlueprintType)
		struct Metadata {
		public:
			FString name;
			FString descritpion;
			FString image;
			FString asset;
			FString createdBy;
			FString createdAt;
			TArray<FString> tags;
		};
		Metadata metadata;
	};
	USTRUCT(BlueprintType)
	struct NftsArray
	{
	public:
		TArray<Nft> nfts;
		int totalNfts;
		int currentPage;
		int totalPages;
		FString next;
		FString prev;
	};
	USTRUCT(BlueprintType)
	struct NftsCollection {
	public:
		bool isEnabled;
		FString logoImage;
		FString bannerImage;
		FString id;
		FString name;
		USTRUCT(BlueprintType)
		struct CollectionContracts {
		public:
			FString contractAddress;
			FString chainId;
		};
		CollectionContracts collectionContracts;
		int __v;
		int owners;
		FString description;
		USTRUCT(BlueprintType)
		struct SocialLinks{
			FString twitter;
			FString website;
			FString discord;
			FString instagram;
			FString twitch;
		};
		SocialLinks socialLinks;
		int totalSupply;
		int floorPrice;
		int volume;
		int bestOffer;
		FString mobileBannerImage;
	};
};
