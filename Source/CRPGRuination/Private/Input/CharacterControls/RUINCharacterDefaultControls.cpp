// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/CharacterControls/RUINCharacterDefaultControls.h"

#include "GameFramework/Character.h"

void URUINCharacterDefaultControls::SetupPlayerControls_Implementation(UEnhancedInputComponent* PlayerInputComponent)
{
	if (InputComponent)
	{
		if (MoveForwardInputAction)
		{
			InputComponent->BindAction(MoveForwardInputAction,ETriggerEvent::Triggered, this, &URUINCharacterDefaultControls::OnMoveForward);
		}
		if (MoveRightInputAction)
		{
			InputComponent->BindAction(MoveRightInputAction,ETriggerEvent::Triggered, this, &URUINCharacterDefaultControls::OnMoveRight);
		}
		if (LookUpInputAction)
		{
			InputComponent->BindAction(LookUpInputAction,ETriggerEvent::Triggered, this, &URUINCharacterDefaultControls::OnLookUp);
		}
		if (TurnAtRateInputAction)
		{
			InputComponent->BindAction(TurnAtRateInputAction,ETriggerEvent::Triggered, this, &URUINCharacterDefaultControls::OnTurnAtRate);
		}
		if (JumpInputAction)
		{
			InputComponent->BindAction(JumpInputAction,ETriggerEvent::Started, this, &URUINCharacterDefaultControls::OnJump);
		}
	}
}

void URUINCharacterDefaultControls::OnMoveForward(const FInputActionValue& Value)
{
	ACharacter* MyCharacter = GetPawn<ACharacter>();
	const APlayerController* Controller = Cast<APlayerController>(MyCharacter->GetController());
	
	const float ForwardValue = Value.Get<float>();
	if (Controller != nullptr && ForwardValue != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		MyCharacter->AddMovementInput(Direction, ForwardValue);
	}
}

void URUINCharacterDefaultControls::OnMoveRight(const FInputActionValue& Value)
{
	ACharacter* MyCharacter = GetPawn<ACharacter>();
	const APlayerController* Controller = Cast<APlayerController>(MyCharacter->GetController());
	
	const float RightValue = Value.Get<float>();
	if (Controller != nullptr && RightValue != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		MyCharacter->AddMovementInput(Direction, RightValue);
	}
}

void URUINCharacterDefaultControls::OnLookUp(const FInputActionValue& Value)
{
	APawn* MyPawn = GetPawn<APawn>();
	MyPawn->AddControllerPitchInput(Value.GetMagnitude() * TurnAtRate * GetWorld()->GetDeltaSeconds());
}

void URUINCharacterDefaultControls::OnTurnAtRate(const FInputActionValue& Value)
{
	APawn* MyPawn = GetPawn<APawn>();
	MyPawn->AddControllerYawInput(Value.GetMagnitude() * TurnAtRate * GetWorld()->GetDeltaSeconds());
}

void URUINCharacterDefaultControls::OnJump(const FInputActionValue& Value)
{
	ACharacter* MyCharacter = GetPawn<ACharacter>();
	
	if ((MyCharacter != nullptr) && MyCharacter->CanJump())
		MyCharacter->Jump();
}
