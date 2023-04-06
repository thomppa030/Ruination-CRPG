// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModularGameplayPawn.h"

#include "ThumbnailHelpers.h"
#include "Components/GameFrameworkComponentManager.h"


void AModularGameplayPawn::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AModularGameplayPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	/**
	 *	Remove this actor from the list of actors that will receive game framework component extension events.
	 *
	 *	We do this in EndPlay() because we want to make sure that we are not receiving any more extension events.
	 *
	 *	Forget to remove this actor from the list of actors that will receive extension events, and you will get a crash when the game framework component is destroyed.
	 */
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);
	
	Super::EndPlay(EndPlayReason);
}

// Called when the game starts or when spawned
void AModularGameplayPawn::BeginPlay()
{
	Super::BeginPlay();

	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);
}