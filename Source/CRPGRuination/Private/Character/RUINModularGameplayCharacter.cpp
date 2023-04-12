// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RUINModularGameplayCharacter.h"
#include "AbilitySystemComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


ARUINModularGameplayCharacter::ARUINModularGameplayCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ARUINModularGameplayCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARUINModularGameplayCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	AbilitySystemComponent->RemoveActiveEffectsWithSourceTags(FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("State.Movement.InAir"))));
}

bool ARUINModularGameplayCharacter::ApplyGamePlayEffectToSelf(TSubclassOf<UGameplayEffect> Effect,
                                                              FGameplayEffectContextHandle InEffectContext)
{
	if (!Effect.Get())
		return false;

	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1, InEffectContext);
	if (SpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle =AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		
		return ActiveGEHandle.WasSuccessfullyApplied();
	}

	return false;
}
