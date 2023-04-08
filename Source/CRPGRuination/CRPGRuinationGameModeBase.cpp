// Copyright Epic Games, Inc. All Rights Reserved.


#include "CRPGRuinationGameModeBase.h"

#include "GameFeaturesSubsystem.h"

void ACRPGRuinationGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	PluginsToUnloadPreWorldTick.Empty();
	FWorldDelegates::OnWorldTickStart.RemoveAll(this);
}

void ACRPGRuinationGameModeBase::ToggleGameFeaturePlugin(FString GameFeaturePluginName, bool bEnable)
{
	FString PluginURL;
	UGameFeaturesSubsystem::Get().GetPluginURLByName(GameFeaturePluginName, PluginURL);

	if (bEnable)
	{
		UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());
	}
	else
	{
		// Unloading plugins cause garbagae collection. Delay the unload to avoid garbage collecting during a world tick.
		PluginsToUnloadPreWorldTick.Add(PluginURL);
		if (!FWorldDelegates::OnWorldTickStart.IsBoundToObject(this))
		{
			FWorldDelegates::OnWorldTickStart.AddUObject(this, &ACRPGRuinationGameModeBase::UnloadPluginsPreWorldTick);
		}
	}
}

void ACRPGRuinationGameModeBase::UnloadPluginsPreWorldTick(UWorld* World, ELevelTick TickType, float DeltaTime)
{
	for (const auto& PluginToUnload : PluginsToUnloadPreWorldTick)
	{
		UGameFeaturesSubsystem::Get().UnloadGameFeaturePlugin(PluginToUnload);
	}

	PluginsToUnloadPreWorldTick.Empty();
	FWorldDelegates::OnWorldTickStart.RemoveAll(this);
}
