// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GameFramework/GameStateBase.h"
#include "UObject/Object.h"
#include "ModularGameState.generated.h"

 /** Pair this with a ModularGameModeBase*/
UCLASS(Blueprintable)
class MODULARCLASSFRAMEWORK_API AModularGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};

/** Pair this with a ModularGameState*/
UCLASS(Blueprintable)
class MODULARCLASSFRAMEWORK_API AModularGameState : public AGameState
{
	GENERATED_BODY()

public:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	virtual void HandleMatchHasStarted() override;
};


