echo off

del *.sln
rmdir /s /q .vs
rmdir /s /q Binaries
rmdir /s /q Intermediate
rem rmdir /s /q Saved
rmdir /s /q DerivedDataCache

rmdir /s /q Plugins\System\ModularClassFramework\Binaries
rmdir /s /q Plugins\System\ModularClassFramework\Intermediate

rmdir /s /q Plugins\EditorAssetActions\Binaries
rmdir /s /q Plugins\EditorAssetActions\Intermediate

rmdir /s /q Plugins\GASGameplayFeatureActions\Binaries
rmdir /s /q Plugins\GASGameplayFeatureActions\Intermediate

rmdir /s /q Plugins\GASFramework\Binaries
rmdir /s /q Plugins\GASFramework\Intermediate

rmdir /s /q Plugins\GameFeatures\MandoMove\Binaries
rmdir /s /q Plugins\GameFeatures\MandoMove\Intermediate

set MyUVS="C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe"

set MyUBT="R:\Unreal Engine\UE_5.2\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"

rem change Transformation to your own project name
set MyFullPath="%cd%\CRPGRuination"


%MyUVS% /projectfiles %MyFullPath%.uproject

%MyUBT% Development Win64 -Project=%MyFullPath%.uproject -TargetType=Editor -Progress -NoEngineChanges -NoHotReloadFromIDE

%MyFullPath%.uproject

%MyFullPath%.sln