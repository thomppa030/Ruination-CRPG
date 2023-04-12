// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "CharacterAnimationDataAsset.generated.h"

class UBlendSpace;
class UAnimSequenceBase;

USTRUCT(BlueprintType, Blueprintable)
struct FCharacterAnimationData 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimationData",meta=(BlueprintThreadSafe))
	UBlendSpace* MovementBlendspace = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimationData",meta=(BlueprintThreadSafe))
	UAnimSequenceBase* IdleAnimationAsset = nullptr;
};

UCLASS(BlueprintType, Blueprintable)
class CRPGRUINATION_API UCharacterAnimationDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FCharacterAnimationData CharacterAnimationData;
};
