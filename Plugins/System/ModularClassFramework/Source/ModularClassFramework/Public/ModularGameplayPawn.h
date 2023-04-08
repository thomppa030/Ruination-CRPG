// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ModularGameplayPawn.generated.h"

UCLASS(Blueprintable)
class MODULARCLASSFRAMEWORK_API AModularGameplayPawn : public APawn
{
	GENERATED_BODY()

public:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
