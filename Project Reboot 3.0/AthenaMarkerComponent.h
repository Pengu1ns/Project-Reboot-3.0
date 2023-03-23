#pragma once

#include "ActorComponent.h"
#include "Vector.h"
#include "SoftObjectPtr.h"
#include "FortPlayerState.h"

struct FMarkerID { int PlayerID; int InstanceID; };

struct FFortClientMarkerRequest
{
	int& GetInstanceID()
	{
		static auto InstanceIDOffset = FindOffsetStruct("/Script/FortniteGame.FortClientMarkerRequest", "InstanceID");
		return *(int*)(__int64(this) + InstanceIDOffset);
	}

	FVector& GetWorldPosition()
	{
		static auto WorldPositionOffset = FindOffsetStruct("/Script/FortniteGame.FortClientMarkerRequest", "WorldPosition");
		return *(FVector*)(__int64(this) + WorldPositionOffset);
	}

	uint8_t& GetMarkerType()
	{
		static auto MarkerTypeOffset = FindOffsetStruct("/Script/FortniteGame.FortClientMarkerRequest", "MarkerType");
		return *(uint8_t*)(__int64(this) + MarkerTypeOffset);
	}

	FVector& GetWorldPositionOffset()
	{
		static auto WorldPositionOffsetOffset = FindOffsetStruct("/Script/FortniteGame.FortClientMarkerRequest", "WorldPositionOffset");
		return *(FVector*)(__int64(this) + WorldPositionOffsetOffset);
	}

	FVector& GetWorldNormal()
	{
		static auto WorldNormalOffset = FindOffsetStruct("/Script/FortniteGame.FortClientMarkerRequest", "WorldNormal");
		return *(FVector*)(__int64(this) + WorldNormalOffset);
	}
};

struct FFortWorldMarkerData
{
	FMarkerID& GetMarkerID()
	{
		static auto MarkerIDOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "MarkerID");
		return *(FMarkerID*)(__int64(this) + MarkerIDOffset);
	}

	FVector& GetWorldPosition()
	{
		static auto WorldPositionOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "WorldPosition");
		return *(FVector*)(__int64(this) + WorldPositionOffset);
	}

	FVector& GetWorldPositionOffset()
	{
		static auto WorldPositionOffsetOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "WorldPositionOffset");
		return *(FVector*)(__int64(this) + WorldPositionOffsetOffset);
	}

	FVector& GetWorldNormal()
	{
		static auto WorldNormalOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "WorldNormal");
		return *(FVector*)(__int64(this) + WorldNormalOffset);
	}

	TSoftObjectPtr<AActor>& GetMarkedActor()
	{
		static auto MarkedActorOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "MarkedActor");
		return *(TSoftObjectPtr<AActor>*)(__int64(this) + MarkedActorOffset);
	}

	uint8_t& GetMarkerType()
	{
		static auto MarkerTypeOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "MarkerType");
		return *(uint8_t*)(__int64(this) + MarkerTypeOffset);
	}

	TSoftObjectPtr<UClass>& GetMarkedActorClass()
	{
		static auto MarkedActorClassOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "MarkedActorClass");
		return *(TSoftObjectPtr<UClass>*)(__int64(this) + MarkedActorClassOffset);
	}

	AFortPlayerState*& GetOwner()
	{
		static auto OwnerOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "Owner");
		return *(AFortPlayerState**)(__int64(this) + OwnerOffset);
	}

	void* GetCustomDisplayInfo()
	{
		static auto CustomDisplayInfoOffset = FindOffsetStruct("/Script/FortniteGame.FortWorldMarkerData", "CustomDisplayInfo");
		return (void*)(__int64(this) + CustomDisplayInfoOffset);
	}
};

class UAthenaMarkerComponent : public UActorComponent
{
public:
	static void ServerAddMapMarkerHook(UAthenaMarkerComponent* MarkerComponent, FFortClientMarkerRequest MarkerRequest);
	static void ServerRemoveMapMarkerHook(UAthenaMarkerComponent* MarkerComponent, FMarkerID MarkerID, uint8_t CancelReason);
};