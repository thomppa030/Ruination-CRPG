//Copyright by Epic Games, Inc. All Rights Reserved.


#include "ModularGameplayCharacter.h"

#include "Components/GameFrameworkComponentManager.h"

void AModularGameplayCharacter::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	/**
	 * Add this actor to the list of actors that will receive game framework component extension events.
	 *
	 * Any game framework component that is added to the game will send an extension event to this actor.
	 * If this actor is not in the list of actors that will receive extension events, then the component will not be added to this actor.
	 */
	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AModularGameplayCharacter::BeginPlay()
{

	/**
	 *	Notify all game framework components that this actor is ready to receive extensions.
	 */	
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);
	
	Super::BeginPlay();
}

void AModularGameplayCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
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

