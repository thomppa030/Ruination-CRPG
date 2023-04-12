// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemInterface.h"
#include "GameplayTagAssetInterface.h"
#include "ModularGameplayCharacter.h"
#include "RUINModularGameplayCharacter.generated.h"

struct FGameplayEffectContextHandle;
class UGameplayEffect;
class USpringArmComponent;
class UCameraComponent;
class UAbilitySystemComponent;

UCLASS()
class CRPGRUINATION_API ARUINModularGameplayCharacter : public AModularGameplayCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	bool ApplyGamePlayEffectToSelf(TSubclassOf<UGameplayEffect> Effect, FGameplayEffectContextHandle InEffectContext);

protected:
	ARUINModularGameplayCharacter(const FObjectInitializer& ObjectInitializer);

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	UCameraComponent* CameraComponent;

	virtual void Landed(const FHitResult& Hit) override;
};
