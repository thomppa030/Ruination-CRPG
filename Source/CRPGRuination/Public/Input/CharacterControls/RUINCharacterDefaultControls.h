// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Input/AbilityInputBindingComponent.h"
#include "RUINCharacterDefaultControls.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class CRPGRUINATION_API URUINCharacterDefaultControls : public UAbilityInputBindingComponent
{
	GENERATED_BODY()
	
protected:
	virtual void SetupPlayerControls_Implementation(UEnhancedInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveForwardInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Category= "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveRightInputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Category= "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	UInputAction* LookUpInputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category= "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	UInputAction* TurnAtRateInputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category= "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpInputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category= "DefaultAbilityInput", meta=(AllowPrivateAccess = "true"))
	float TurnAtRate{50.f};

	void OnMoveForward(const FInputActionValue& Value);
	void OnMoveRight(const FInputActionValue& Value);

	void OnLookUp(const FInputActionValue& Value);
	void OnTurnAtRate(const FInputActionValue& Value);

	void OnJump(const FInputActionValue& Value);
};
