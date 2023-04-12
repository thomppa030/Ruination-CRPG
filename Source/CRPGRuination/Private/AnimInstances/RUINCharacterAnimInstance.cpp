// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/RUINCharacterAnimInstance.h"

#include "DataAssets/CharacterAnimationDataAsset.h"

UBlendSpace* URUINCharacterAnimInstance::GetMovementBlendSpace() const
{
	return DefaultCharacterAnimationDataAsset ? DefaultCharacterAnimationDataAsset->CharacterAnimationData.MovementBlendspace : nullptr;
}

UAnimSequenceBase* URUINCharacterAnimInstance::GetIdleAnimation() const
{
	return DefaultCharacterAnimationDataAsset ? DefaultCharacterAnimationDataAsset->CharacterAnimationData.IdleAnimationAsset : nullptr;
}
