// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSuperManagerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

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
