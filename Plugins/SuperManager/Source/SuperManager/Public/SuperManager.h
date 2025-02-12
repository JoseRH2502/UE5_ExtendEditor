// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
class FSuperManagerModule : public IModuleInterface
   {
   public:
       /** IModuleInterface implementation */
       virtual void StartupModule() override;
       virtual void ShutdownModule() override;

       #pragma region ProccessDataForAdvanceDeletionTab
       bool DeleteSingleAssetForAssetList(const FAssetData& AssetDataToDelete);
       bool DeleteMultipleAssetsForAssetList(const TArray<FAssetData>& AssetsToDelete);
       void ListUnusedAssetsForAssetList(const TArray< TSharedPtr <FAssetData> >& AssetsDataToFilter,TArray< TSharedPtr <FAssetData> >& OutUnusedAssetsData);// Cambiado a público
	   void ListSameNameAssetsForAssetList(const TArray< TSharedPtr <FAssetData> >& AssetsDataToFilter, TArray< TSharedPtr <FAssetData> >& OutSameNameAssetsData);
       void SyncCBToClickedAssetForAssetList(const FString& AssetPathToSync);
       #pragma endregion

   private:
       #pragma region ContentBrowserMenuExtention
       void InitCBMenuExtention();
       TArray<FString> FolderPathsSelected;
       TSharedRef<FExtender> CustomCBMenuExtender(const TArray<FString>& SelectedPaths);
       void AddCBMenuEntry(class FMenuBuilder& MenuBuilder);
       void OnDeleteUnsuedAssetButtonClicked();
       void OnDeleteEmptyFoldersButtonClicked();
       void OnAdvanceDelectionButtonClicked();
       void FixUpRedirectors();
       #pragma endregion

       #pragma region CustomEditorTab
       void RegisterAdvanceDelectionTab();
       TSharedRef<SDockTab> OnSpawnAdvanceDelectionTab(const FSpawnTabArgs& Args);
       TArray< TSharedPtr <FAssetData> > GetAllAssetDataUnderSelectedFolder();
       #pragma endregion
   };

