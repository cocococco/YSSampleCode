// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "YSTicketBook.generated.h"

UENUM()
enum class EYSTicketType : uint8
{
	Enter,
	Reward,
	None = 255 UMETA(Hidden)
};

UENUM()
enum class EYSTicketContentType : uint8
{
	Dungeon,
	Mission,
	Exploration,
	Raid,
	None = 255 UMETA(Hidden)
};

UENUM()
enum class EYSTicketUseType : uint8
{
	ConsumeAfterEnter,
	ConsumeAfterReward,
	None = 255 UMETA(Hidden)
};

struct FYSCachedTicket
{
	int32 Id;
	int32 PriceId;
	int32 PriceValue;
	int32 TicketInitCount;
	int32 TicketMaxCount;
	//
};

struct FYSTicketGroupKey
{
	EYSTicketContentType ContentType;
	int32 ContentId;
	EYSTicketType TicketType;

	FYSTicketGroupKey()
		: ContentType(EYSTicketContentType::None)
		, ContentId(0)
		, TicketType(EYSTicketType::None)
	{}

	FYSTicketGroupKey(EYSTicketContentType InContentsType, int32 InContentsID, EYSTicketType InTicketType)
		: ContentType(InContentsType)
		, ContentId(InContentsID)
		, TicketType(InTicketType)
	{}

	bool IsValid() const;

	bool operator==(const FYSTicketGroupKey& InOther) const;
	bool operator!=(const FYSTicketGroupKey& InOther) const;
};

FORCEINLINE uint32 GetTypeHash(const FYSTicketGroupKey& InOther)
{
	const uint32 hash = HashCombine(GetTypeHash(InOther.ContentType), GetTypeHash(InOther.ContentId));
	return HashCombine(hash, GetTypeHash(InOther.TicketType));
}

struct FYSCachedContentTicket
{
	FYSTicketGroupKey TicketGroupKey;
	int32 TicketId;
	int32 TicketCount;
	EYSTicketUseType UseType;

	FYSCachedContentTicket()
		: TicketId(0)
		, TicketCount(0)
		, UseType(EYSTicketUseType::None)
	{}

};

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTicketBook : public UObject
{
	GENERATED_BODY()
	
public:
	// ticket functions

private:
	TMap<int32, FYSCachedTicket> CachedRewardTicketMap;
	TMap<int32, FYSCachedTicket> CachedEnterTicketMap;
	TMap<FYSTicketGroupKey, FYSCachedContentTicket> CachedContentTicketMap;
};
