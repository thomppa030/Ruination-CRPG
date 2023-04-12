// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ModularGameplayCharacter.h"
#include "RUINModularGameplayCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAbilitySystemComponent;

UCLASS()
class CRPGRUINATION_API ARUINModularGameplayCharacter : public AModularGameplayCharacter
{
	GENERATED_BODY()

protected:
	ARUINModularGameplayCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	UCameraComponent* CameraComponent;
};
