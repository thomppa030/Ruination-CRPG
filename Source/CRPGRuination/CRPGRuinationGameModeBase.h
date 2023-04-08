// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CRPGRuinationGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CRPGRUINATION_API ACRPGRuinationGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	UFUNCTION(BlueprintCallable, Category="GameFeatures")
	void ToggleGameFeaturePlugin(FString GameFeaturePluginName, bool bEnable);

private:
	void UnloadPluginsPreWorldTick(UWorld* World, ELevelTick TickType, float DeltaTime);
	
	TSet<FString> PluginsToUnloadPreWorldTick;
};
