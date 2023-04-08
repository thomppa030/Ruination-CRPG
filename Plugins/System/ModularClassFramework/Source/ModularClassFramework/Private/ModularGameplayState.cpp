// Copyrigth Epic Games, Inc. All rights reserved.


#include "ModularGameplayState.h"

#include "Components/GameFrameworkComponentManager.h"
#include "Components/PlayerStateComponent.h"


void AModularGameplayState::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AModularGameplayState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);
	Super::EndPlay(EndPlayReason);
}

void AModularGameplayState::Reset()
{
	Super::Reset();

	TArray<UPlayerStateComponent*> ModularComponents;
	GetComponents(ModularComponents);
	for (UPlayerStateComponent* Component : ModularComponents)
	{
		Component->Reset();
	}
}

void AModularGameplayState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);

	/**
	 * TInlineComponentArray is simply a TArray that reserves a fixed amount of space on the stack
	 * to try to avoid heap allocation when there are fewer than a specified number of elements expected in the result.
	 */
	TInlineComponentArray<UPlayerStateComponent*> PlayerStateComponents;
	/**
	 * Get all components derived from class 'ComponentType' and fill in the OutComponents array with the result.
	 * It's recommended to use TArrays with a TInlineAllocator to potentially avoid memory allocation costs.
	 **/
	GetComponents(PlayerStateComponents);
	for (auto* SourceComponent : PlayerStateComponents)
	{
		UPlayerStateComponent *TargetComponent = Cast<UPlayerStateComponent>(static_cast<UObject*>(FindObjectWithOuter(PlayerState, SourceComponent->GetClass(), SourceComponent->GetFName())));
		if (TargetComponent)
		{
			SourceComponent->CopyProperties(TargetComponent);
		}
	}
}

// Called when the game starts or when spawned
void AModularGameplayState::BeginPlay()
{
	Super::BeginPlay();

	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);
}
