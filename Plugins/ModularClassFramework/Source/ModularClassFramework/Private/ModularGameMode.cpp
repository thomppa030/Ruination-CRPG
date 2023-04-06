// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularGameMode.h"
#include "ModularGameplayPawn.h"
#include "ModularGameplayState.h"

AModularGameModeBase::AModularGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = AModularGameplayPawn::StaticClass();
	PlayerStateClass = AModularGameplayState::StaticClass();
}

AModularGameMode::AModularGameMode(const FObjectInitializer& ObjectInitializer)
{
}
