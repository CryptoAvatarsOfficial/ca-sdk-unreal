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
	struct FMetadataAvatar {
		GENERATED_BODY()
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
		FMetadataAvatar() {
			name = "";
			description = "";
			image = "";
			asset = "";
			createdBy = "";
			createdAt = "";
			tags = TArray<FString>();
		}
	};
	USTRUCT(BlueprintType)
		struct FAvatar
	{
		GENERATED_BODY()
	public:
	
		FMetadataAvatar metadata;
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
		struct FMetadataNft {
		GENERATED_BODY()
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
				FString createdy;
			UPROPERTY()
				FString createdAt;
			UPROPERTY()
				TArray<FString> tags;
			FMetadataNft() {
				name = "";
				description = "";
				image = "";
				asset = "";
				createdy = "";
				createdAt = "";
				tags = TArray<FString>();
			}
	};
	USTRUCT(BlueprintType)
		struct FNft
	{
		GENERATED_BODY()
	public:
		UPROPERTY()
			FString owner;
		UPROPERTY()
		FMetadataNft metadata;
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
		UPROPERTY()
			int totalItemsCount;
		FNftsArray() {
			nfts = TArray<FNft>();
			totalNfts = 0;
			currentPage = 0;
			totalPages = 0;
			next = "";
			prev = "";
		}
	};
	USTRUCT(BlueprintType)
	struct FCollectionContracts {
		GENERATED_BODY()
	public:
		UPROPERTY()
			FString contractAddress;
		UPROPERTY()
			FString chainId;
	};
	USTRUCT(BlueprintType)
	struct FSocialLinks {
		GENERATED_BODY()
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
			UPROPERTY()
			FCollectionContracts collectionContracts;
			UPROPERTY()
				int32 __v;
			UPROPERTY()
				int32 owners;
			UPROPERTY()
				FString description;
			UPROPERTY()
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
			FNftsCollection() {
				isEnabled = false;
				logoImage = "";
				bannerImage = "";
				id = "";
				name = "";
				__v = 0;
				owners = 0;
				description = "";
				totalSupply = 0;
				floorPrice = 0;
				volume = 0;
				bestOffer = 0;
				mobileBannerImage = "";
			}

		
	};
	
	USTRUCT(BlueprintType)
		struct FNftsCollectionsArray {
		GENERATED_BODY()
		public:
			UPROPERTY()
			TArray<FNftsCollection> collections;
	};