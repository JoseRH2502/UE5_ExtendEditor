// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperManager.h"
#include "ContentBrowserModule.h"
#include "DebugHeader.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "SlateWidgets/AdvanceDeletionWidget.h"
#include "CustomStyle/SuperManagerStyle.h"
#include "LevelEditor.h"
#include "Engine/Selection.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "CustomUICommands/SuperManagerUICommands.h"
#include "SceneOutlinerModule.h"
#include "CustomOutlinerColumn/OutlinerSelectionLockColumn.h"

#define LOCTEXT_NAMESPACE "FSuperManagerModule"

void FSuperManagerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	InitCBMenuExtention();
	RegisterAdvanceDelectionTab();
	FSuperManagerUICommands::Register();
	InitCustomUICommands();
	InitLevelEditorExtention();
	InitCustomSelectionEvent();
	InitSceneOutlinerColumnExtension();
	FSuperManagerStyle::InitializeIcons();
}
#pragma region ContentBrowserMenuExtention
void FSuperManagerModule::InitCBMenuExtention()
{	
	FContentBrowserModule& ContentBrowserModule =
	FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
	TArray<FContentBrowserMenuExtender_SelectedPaths>& ContentBrowserModuleMenuExtenders =
	ContentBrowserModule.GetAllPathViewContextMenuExtenders();
	ContentBrowserModuleMenuExtenders.Add(FContentBrowserMenuExtender_SelectedPaths::
	CreateRaw(this,&FSuperManagerModule::CustomCBMenuExtender));
	
}

TSharedRef<FExtender> FSuperManagerModule::CustomCBMenuExtender(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> MenuExtender (new FExtender());
	if(SelectedPaths.Num()>0)
	{
		MenuExtender->AddMenuExtension(FName("Delete"),
		EExtensionHook::After,
		TSharedPtr<FUICommandList>(),
		FMenuExtensionDelegate::CreateRaw(this,&FSuperManagerModule::AddCBMenuEntry));

		FolderPathsSelected = SelectedPaths;
	}
	return MenuExtender;
}

void FSuperManagerModule::AddCBMenuEntry(class FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete Unused Assets")),
		FText::FromString(TEXT("Safely delete all unused assets under folder")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.DeleteUnusedAssets"),	//Custom icon
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnDeleteUnsuedAssetButtonClicked)
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete Empty Folders")), //Title text for menu entry
		FText::FromString(TEXT("Safely delete all empty folders")), //Tooltip text
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.DeleteEmptyFolders"),	
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnDeleteEmptyFoldersButtonClicked) //The actual function to excute
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Advance Deletion")), //Title text for menu entry
		FText::FromString(TEXT("List assets by specific condition in a tab for deleting")), //Tooltip text
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.AdvanceDeletion"),	//Custom icon
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnAdvanceDelectionButtonClicked) //The actual function to excute
	);
}

void FSuperManagerModule::OnDeleteEmptyFoldersButtonClicked()
{
	if(ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}
	FixUpRedirectors();
	TArray<FString> FolderPathsArray = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0],true,true);
	uint32 Counter = 0;
	FString EmptyFolderPathsNames;
	TArray<FString> EmptyFoldersPathsArray;
	for(const FString& FolderPath:FolderPathsArray)
	{
		if(FolderPath.Contains(TEXT("Developers"))||
		FolderPath.Contains(TEXT("Collections")) ||
		FolderPath.Contains(TEXT("__ExternalActors__")) ||
		FolderPath.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
		if(!UEditorAssetLibrary::DoesDirectoryExist(FolderPath)) continue;
		if(!UEditorAssetLibrary::DoesDirectoryHaveAssets(FolderPath))
		{
			EmptyFolderPathsNames.Append(FolderPath);
			EmptyFolderPathsNames.Append(TEXT("\n"));
			EmptyFoldersPathsArray.Add(FolderPath);
		}		
	}
	if(EmptyFoldersPathsArray.Num()==0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No empty folder found under selected folder"),false);
		return;
	}
	EAppReturnType::Type ConfirmResult = DebugHeader::ShowMsgDialog(EAppMsgType::OkCancel,
	TEXT("Empty folders found in:\n") + EmptyFolderPathsNames +TEXT("\nWould you like to delete all?"),false);
	if(ConfirmResult==EAppReturnType::Cancel) return;

	for (const FString& EmptyFolderPath : EmptyFoldersPathsArray)
	{
		if (UEditorAssetLibrary::DeleteDirectory(EmptyFolderPath))
		{
			++Counter;
		}
		else
		{
			DebugHeader::Print(TEXT("Failed to delete " + EmptyFolderPath), FColor::Red);
		}
	}
	
	if(Counter>0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully deleted ") + FString::FromInt(Counter) + TEXT("folders"));
	}
}

void FSuperManagerModule::OnAdvanceDelectionButtonClicked()
{
	FixUpRedirectors();
	FGlobalTabmanager::Get()->TryInvokeTab(FName("AdvanceDeletion"));
}

void FSuperManagerModule::OnDeleteUnsuedAssetButtonClicked()
{
	if(ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}
	
	if(FolderPathsSelected.Num()>1)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("You can only do this to one folder"));
		return;
	}
	TArray<FString> AssetsPathNames = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0]);
	if(AssetsPathNames.Num()==0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No asset found under selected folder"), false);
		return;
	}
	EAppReturnType::Type ConfirmResult =
	DebugHeader::ShowMsgDialog(EAppMsgType::YesNo,TEXT("A total of ") + FString::FromInt(AssetsPathNames.Num()) + TEXT(" assets need to be checked.\nWoudl you like to procceed?"));
	if(ConfirmResult == EAppReturnType::No) return;

	FixUpRedirectors();
	TArray<FAssetData> UnusedAssetsDataArray;
	for(const FString& AssetPathName:AssetsPathNames)
	{
		//Don't touch root folder
		if(AssetPathName.Contains(TEXT("Developers"))||
			AssetPathName.Contains(TEXT("Collections")) ||
			AssetPathName.Contains(TEXT("__ExternalActors__")) ||
			AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
		if(!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;
		TArray<FString> AssetReferencers =
		UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPathName);
		if(AssetReferencers.Num()==0)
		{
			const FAssetData UnusedAssetData = UEditorAssetLibrary::FindAssetData(AssetPathName);
			UnusedAssetsDataArray.Add(UnusedAssetData);
		}
	}
	if(UnusedAssetsDataArray.Num()>0)
	{
		ObjectTools::DeleteAssets(UnusedAssetsDataArray);
	}
	else
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused asset found under selected folder"), false);
	}
	
}

void FSuperManagerModule::FixUpRedirectors()
{
	TArray<UObjectRedirector*> RedirectorsToFixArray;
	FAssetRegistryModule& AssetRegistryModule =
	FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	FARFilter Filter;
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Emplace("/Game");
	Filter.ClassNames.Emplace("ObjectRedirector");
	TArray<FAssetData> OutRedirectors;
	AssetRegistryModule.Get().GetAssets(Filter,OutRedirectors);
	for(const FAssetData& RedirectorData:OutRedirectors)
	{
		if(UObjectRedirector* RedirectorToFix = Cast<UObjectRedirector>(RedirectorData.GetAsset()))
		{
			RedirectorsToFixArray.Add(RedirectorToFix);
		}
	}
	FAssetToolsModule& AssetToolsModule =
	FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	AssetToolsModule.Get().FixupReferencers(RedirectorsToFixArray);
}

#pragma endregion

#pragma region CustomEditorTab
void FSuperManagerModule::RegisterAdvanceDelectionTab()
{
	//FGlobalTabmanager is used to register an editor tab 
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(FName("AdvanceDeletion"),
		FOnSpawnTab::CreateRaw(this,&FSuperManagerModule::OnSpawnAdvanceDelectionTab))
	    .SetDisplayName(FText::FromString(TEXT("Advance Deletion")))
        .SetIcon(FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"ContentBrowser.AdvanceDeletion"));
}

TSharedRef<SDockTab> FSuperManagerModule::OnSpawnAdvanceDelectionTab(const FSpawnTabArgs& Args)
{
	if(FolderPathsSelected.Num()==0) return SNew(SDockTab).TabRole(ETabRole::NomadTab);

	ConstructedDockTab = SNew(SDockTab).TabRole(ETabRole::NomadTab)
	[
		SNew(SAdvanceDeletionTab)
		.AssetsDataToStore(GetAllAssetDataUnderSelectedFolder())
		.CurrentSelectedFolder(FolderPathsSelected[0])
	];

	ConstructedDockTab->SetOnTabClosed(
	SDockTab::FOnTabClosedCallback::CreateRaw(this,&FSuperManagerModule::OnAdvanceDeletionTabClosed));

	return ConstructedDockTab.ToSharedRef();
}

TArray<TSharedPtr<FAssetData>> FSuperManagerModule::GetAllAssetDataUnderSelectedFolder()
{
	TArray<TSharedPtr<FAssetData>> AvailableAssetsData;
    
    // Validar si hay carpetas seleccionadas
    if (FolderPathsSelected.Num() == 0) 
    {
    	DebugHeader::Print(TEXT("No folder selected. Please select a valid folder."), FColor::Red);
    	return AvailableAssetsData;
    }
    
    const FString& SelectedFolderPath = FolderPathsSelected[0];
    
    // Verificar si la carpeta seleccionada existe
    if (!UEditorAssetLibrary::DoesDirectoryExist(SelectedFolderPath))
    {
    	DebugHeader::Print(TEXT("The selected folder does not exist: " + SelectedFolderPath), FColor::Red);
    	return AvailableAssetsData;
    }
    
    // Obtener los paths de los assets
    TArray<FString> AssetsPathNames = UEditorAssetLibrary::ListAssets(SelectedFolderPath);
    
    // Validar si se encontraron activos en la carpeta seleccionada
    if (AssetsPathNames.Num() == 0) 
    {
    	DebugHeader::Print(TEXT("No assets found under the selected folder: " + SelectedFolderPath), FColor::Yellow);
    	return AvailableAssetsData;
    }
	
	for(const FString& AssetPathName:AssetsPathNames)
	{
		//Don't touch root folder
		if(AssetPathName.Contains(TEXT("Developers"))||
		AssetPathName.Contains(TEXT("Collections")) ||
		AssetPathName.Contains(TEXT("__ExternalActors__")) ||
		AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
		if(!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;
		const FAssetData Data = UEditorAssetLibrary::FindAssetData(AssetPathName);
		 AvailableAssetsData.Add(MakeShared<FAssetData>(Data));
	}
	return  AvailableAssetsData;
}

void FSuperManagerModule::OnAdvanceDeletionTabClosed(TSharedRef<SDockTab> TabToClose)
{
	if(ConstructedDockTab.IsValid())
	{
		ConstructedDockTab.Reset();
		FolderPathsSelected.Empty();
	}
}

bool FSuperManagerModule::DeleteMultipleAssetsForAssetList(const TArray<FAssetData>& AssetsToDelete)
{
	if(ObjectTools::DeleteAssets(AssetsToDelete)>0)
	{
		return true;
	}
	return false;
}

void FSuperManagerModule::ListUnusedAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetsDataToFilter,
	TArray<TSharedPtr<FAssetData>>& OutUnusedAssetsData)
{
	OutUnusedAssetsData.Empty();
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{	
		TArray<FString> AssetReferencers =
		UEditorAssetLibrary::FindPackageReferencersForAsset(DataSharedPtr->ObjectPath.ToString());
		if(AssetReferencers.Num()==0)
		{
			OutUnusedAssetsData.Add(DataSharedPtr);
		}
	}
}

void FSuperManagerModule::ListSameNameAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetsDataToFilter,
	TArray<TSharedPtr<FAssetData>>& OutSameNameAssetsData)
{
	OutSameNameAssetsData.Empty();
	//Multimap for supporting finding assets with same name
	TMultiMap<FString, TSharedPtr<FAssetData> > AssetsInfoMultiMap;
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{
		AssetsInfoMultiMap.Emplace(DataSharedPtr->AssetName.ToString(), DataSharedPtr);
	}
	for(const TSharedPtr<FAssetData>& DataSharedPtr:AssetsDataToFilter)
	{	
		TArray< TSharedPtr <FAssetData> > OutAssetsData;
		AssetsInfoMultiMap.MultiFind(DataSharedPtr->AssetName.ToString(), OutAssetsData);
		if(OutAssetsData.Num()<=1) continue;
		
		for(const TSharedPtr<FAssetData>& SameNameData:OutAssetsData)
		{
			if(SameNameData.IsValid())
			{
				OutSameNameAssetsData.AddUnique(SameNameData);
			}
		}
	}
}

void FSuperManagerModule::SyncCBToClickedAssetForAssetList(const FString& AssetPathToSync)
{
	TArray<FString> AssetsPathToSync;
	AssetsPathToSync.Add(AssetPathToSync);
	UEditorAssetLibrary::SyncBrowserToObjects(AssetsPathToSync);
}
#pragma endregion

#pragma region CustomEditorUICommands

void FSuperManagerModule::InitCustomUICommands()
{
	CustomUICommands = MakeShareable(new FUICommandList());

	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().LockActorSelection,
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnSelectionLockHotKeyPressed)
	);

	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().UnlockActorSelection,
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed)
	);
}

void FSuperManagerModule::OnSelectionLockHotKeyPressed()
{
	OnLockActorSelectionButtonClicked();
}

void FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed()
{
	OnUnlockActorSelectionButtonClicked();
}

#pragma endregion


#pragma region ProccessDataForAdvanceDeletionTab
bool FSuperManagerModule::DeleteSingleAssetForAssetList(const FAssetData & AssetDataToDelete)
{	
	TArray<FAssetData> AssetDataForDeletion;
	AssetDataForDeletion.Add(AssetDataToDelete);
	if(ObjectTools::DeleteAssets(AssetDataForDeletion)>0)
	{
		return true;
	}
	return false;
}
#pragma endregion

#pragma region LevelEditorMenuExtension

void FSuperManagerModule::InitLevelEditorExtention()
{	
	FLevelEditorModule& LevelEditorModule =
	FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

	TArray<FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors>& LevelEditorMenuExtenders =
	LevelEditorModule.GetAllLevelViewportContextMenuExtenders();
	
	TSharedRef<FUICommandList> ExistingLevelCommands = LevelEditorModule.GetGlobalLevelEditorActions();
	ExistingLevelCommands->Append(CustomUICommands.ToSharedRef());

	LevelEditorMenuExtenders.Add(FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors::
	CreateRaw(this,&FSuperManagerModule::CustomLevelEditorMenuExtender));
}

TSharedRef<FExtender> FSuperManagerModule::CustomLevelEditorMenuExtender(const TSharedRef<FUICommandList> UICommandList, 
const TArray<AActor*> SelectedActors)
{	
	TSharedRef<FExtender> MenuExtender = MakeShareable(new FExtender());

	if(SelectedActors.Num()>0)
	{
		MenuExtender->AddMenuExtension(
			FName("ActorOptions"),
			EExtensionHook::Before,
			UICommandList,
			FMenuExtensionDelegate::CreateRaw(this,&FSuperManagerModule::AddLevelEditorMenuEntry)
			);
	}

	return MenuExtender;
}

void FSuperManagerModule::AddLevelEditorMenuEntry(FMenuBuilder & MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Lock Actor Selection")),
		FText::FromString(TEXT("Prevent actor from being selected")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"LevelEditor.LockSelection"),
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnLockActorSelectionButtonClicked)
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Unlock All Actor Selection")),
		FText::FromString(TEXT("Remove the selection constraint on all actor")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(),"LevelEditor.UnlockSelection"),
		FExecuteAction::CreateRaw(this,&FSuperManagerModule::OnUnlockActorSelectionButtonClicked)
	);
}

void FSuperManagerModule::OnLockActorSelectionButtonClicked()
{
	if(!GetEditorActorSubsystem()) return;

	TArray<AActor*> SelectedActors = WeakEditorActorSubsystem->GetSelectedLevelActors();

	if(SelectedActors.Num()==0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected"));
		return;
	}

	FString CurrentLockedActorNames = TEXT("Locked selection for:");

	for(AActor* SelectedActor:SelectedActors)
	{
		if(!SelectedActor) continue;

		LockActorSelection(SelectedActor);

		WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor,false);

		CurrentLockedActorNames.Append(TEXT("\n"));
		CurrentLockedActorNames.Append(SelectedActor->GetActorLabel());
	}

	RefreshSceneOutliner();
	DebugHeader::ShowNotifyInfo(CurrentLockedActorNames);
}

void FSuperManagerModule::OnUnlockActorSelectionButtonClicked()
{
	if(!GetEditorActorSubsystem()) return;

	TArray<AActor*> AllActorsInLevel = WeakEditorActorSubsystem->GetAllLevelActors();
	TArray<AActor*> AllLockedActors;

	for(AActor* ActorInLevel:AllActorsInLevel)
	{
		if(!ActorInLevel) continue;

		if(CheckIsActorSelectionLocked(ActorInLevel))
		{
			AllLockedActors.Add(ActorInLevel);
		}
	}

	if(AllLockedActors.Num()==0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No selection locked actor currently"));
		return;
	}

	FString UnlockedActorNames = TEXT("Lifted selection constraint for:");

	for(AActor* LockedActor:AllLockedActors)
	{
		UnlockActorSelection(LockedActor);

		UnlockedActorNames.Append(TEXT("\n"));
		UnlockedActorNames.Append(LockedActor->GetActorLabel());
	}

	RefreshSceneOutliner();
	DebugHeader::ShowNotifyInfo(UnlockedActorNames);
}

void FSuperManagerModule::RefreshSceneOutliner()
{
	FLevelEditorModule& LevelEditorModule =
	FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

	TSharedPtr<ISceneOutliner> SceneOutliner = LevelEditorModule.GetFirstLevelEditor()->GetSceneOutliner();

	if(SceneOutliner.IsValid())
	{
		SceneOutliner->FullRefresh();
	}
}

#pragma endregion

#pragma region SelectionLock

void FSuperManagerModule::InitCustomSelectionEvent()
{
	USelection* UserSelection = GEditor->GetSelectedActors();

	UserSelection->SelectObjectEvent.AddRaw(this,&FSuperManagerModule::OnActorSelected);
}

void FSuperManagerModule::OnActorSelected(UObject * SelectedObject)
{
	if(!GetEditorActorSubsystem()) return;
	if(AActor* SelectedActor = Cast<AActor>(SelectedObject))
	{
		if(CheckIsActorSelectionLocked(SelectedActor))
		{
			//Deselect actor right away
			WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor,false);
		}
	}
}

void FSuperManagerModule::LockActorSelection(AActor * ActorToProcess)
{
	if(!ActorToProcess) return;

	if(!ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Add(FName("Locked"));
	}	
}

void FSuperManagerModule::UnlockActorSelection(AActor * ActorToProcess)
{
	if(!ActorToProcess) return;

	if(ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Remove(FName("Locked"));
	}
}

bool FSuperManagerModule::CheckIsActorSelectionLocked(AActor * ActorToProcess)
{	
	if(!ActorToProcess) return false;

	return ActorToProcess->ActorHasTag(FName("Locked"));
}

void FSuperManagerModule::ProcessLockingForOutliner(AActor* ActorToProcess, bool bShouldLock)
{
	if(!GetEditorActorSubsystem()) return;

	if(bShouldLock)
	{
		LockActorSelection(ActorToProcess);

		WeakEditorActorSubsystem->SetActorSelectionState(ActorToProcess,false);

		DebugHeader::ShowNotifyInfo(TEXT("Locked selection for:\n") + ActorToProcess->GetActorLabel());
	}
	else
	{
		UnlockActorSelection(ActorToProcess);

		DebugHeader::ShowNotifyInfo(TEXT("Removed selection lock for:\n") + ActorToProcess->GetActorLabel());
	}
}


#pragma endregion

bool FSuperManagerModule::GetEditorActorSubsystem()
{	
	if(!WeakEditorActorSubsystem.IsValid())
	{
		WeakEditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	}

	return WeakEditorActorSubsystem.IsValid();
}

#pragma region SceneOutlinerExtension

void FSuperManagerModule::InitSceneOutlinerColumnExtension()
{	
	FSceneOutlinerModule& SceneOutlinerModule =
	FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner"));

	FSceneOutlinerColumnInfo SelectionLockColumnInfo(
		ESceneOutlinerColumnVisibility::Visible,
		1,
		FCreateSceneOutlinerColumn::CreateRaw(this,&FSuperManagerModule::OnCreateSelectionLockColumn)
	);

	SceneOutlinerModule.RegisterDefaultColumnType<FOutlinerSelectionLockColumn>(SelectionLockColumnInfo);
}

TSharedRef<ISceneOutlinerColumn> FSuperManagerModule::OnCreateSelectionLockColumn(ISceneOutliner & SceneOutliner)
{
	return MakeShareable(new FOutlinerSelectionLockColumn(SceneOutliner));
}

#pragma endregion
void FSuperManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(FName("AdvanceDeletion"));
	FSuperManagerStyle::ShutDown();
}



#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)