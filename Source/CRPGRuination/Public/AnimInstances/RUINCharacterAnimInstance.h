// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RUINCharacterAnimInstance.generated.h"

class UCharacterAnimationDataAsset;

UCLASS(Blueprintable)
class CRPGRUINATION_API URUINCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable, Category="Animation", meta=(BlueprintThreadSafe))
	UBlendSpace* GetMovementBlendSpace() const;

	UFUNCTION(BlueprintCallable, Category="Animation", meta=(BlueprintThreadSafe))
	UAnimSequenceBase* GetIdleAnimation() const;
	
	UPROPERTY(EditDefaultsOnly, Category="DefaultAnimations")
	UCharacterAnimationDataAsset* DefaultCharacterAnimationDataAsset;
};
