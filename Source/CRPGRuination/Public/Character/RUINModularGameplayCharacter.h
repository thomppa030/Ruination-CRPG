// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemInterface.h"
#include "GameplayTagAssetInterface.h"
#include "ModularGameplayCharacter.h"
#include "RUINModularGameplayCharacter.generated.h"

class UGroomComponent;
struct FGameplayEffectContextHandle;
class UGameplayEffect;
class USpringArmComponent;
class UCameraComponent;
class UAbilitySystemComponent;

UCLASS()
class CRPGRUINATION_API ARUINModularGameplayCharacter : public AModularGameplayCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:
	ARUINModularGameplayCharacter(const FObjectInitializer& ObjectInitializer);

public:
	// IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// End IAbilitySystemInterface
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Groom")
	UGroomComponent* Hair;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Groom")
	UGroomComponent* Eyebrows;

	
	virtual void Landed(const FHitResult& Hit) override;
};
