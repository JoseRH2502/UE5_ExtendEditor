// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickAssetAction.h"
#include "DebugHeader.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"

void UQuickAssetAction::DuplicateAssets(int32 NumOfDuplicate)
{
	/**
 * @brief Duplica los activos seleccionados en el editor de Unreal Engine.
 *
 * @param NumOfDuplicate Número de copias que se deben realizar por cada activo seleccionado.
 * 
 * @note 
 * - Si `NumOfDuplicate` es menor que 0, muestra un mensaje de error y no realiza ninguna duplicación.
 * - Obtiene los activos seleccionados mediante `UEditorUtilityLibrary::GetSelectedAssetData()`.
 * - Cada activo se duplica `NumOfDuplicate` veces, añadiendo un sufijo `_1`, `_2`, etc.
 * - Los activos duplicados se guardan automáticamente con `UEditorAssetLibrary::SaveAsset()`.
 * - Muestra una notificación si al menos un activo fue duplicado exitosamente.
 */
	if (NumOfDuplicate < 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("Please enter VALID number"));
		return;
	}
	TArray<FAssetData> SelectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	uint32 Counter = 0;
	for (const FAssetData& AssetData : SelectedAssetsData)
	{
		for (int32 i = 0; i < NumOfDuplicate; i++)
		{
			const FString SourceAssetPath = AssetData.GetObjectPathString();
			const FString NewDuplicatedAssetName = AssetData.AssetName.ToString() + TEXT("_") + FString::FromInt(i+1);
			const FString NewPathName = FPaths::Combine(AssetData.PackagePath.ToString(),NewDuplicatedAssetName);

			if(UEditorAssetLibrary::DuplicateAsset(SourceAssetPath, NewPathName))
			{	
				UEditorAssetLibrary::SaveAsset(NewPathName,false);
				++Counter;
			}
		}
	}
	if(Counter>0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully duplicated " + FString::FromInt(Counter) + " files"));
	}
}

void UQuickAssetAction::AddPrefixes()
{
	/**
 * @brief Renombra los activos seleccionados en el editor de Unreal Engine, añadiendo el prefijo correcto según su clase.
 * 
 * @note
 * - Obtiene los activos seleccionados mediante `UEditorUtilityLibrary::GetSelectedAssets()`.
 * - Para cada activo seleccionado, busca el prefijo correspondiente en `PrefixMap` según su clase.
 * - Si un activo tiene un prefijo incorrecto, el prefijo es eliminado antes de añadir el prefijo correcto.
 * - Si un activo no tiene prefijo o tiene un prefijo incorrecto, se renombra automáticamente.
 * - Si al menos un activo es renombrado, se muestra una notificación con el número de activos renombrados exitosamente.
 */

	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter = 0;
	for (UObject* SelectedObject : SelectedObjects)
	{
		if (!SelectedObject) continue;

		// Buscar el prefijo correspondiente
		FString* PrefixFound = PrefixMap.Find(SelectedObject->GetClass());
		if (!PrefixFound || PrefixFound->IsEmpty())
		{
			DebugHeader::Print(TEXT("Failed to find prefix for class ") + SelectedObject->GetClass()->GetName(), FColor::Red);
			continue;
		}

		FString OldName = SelectedObject->GetName();

		// Verificar y eliminar el prefijo incorrecto si es necesario
		for (auto& Entry : PrefixMap)
		{
			if (OldName.StartsWith(Entry.Value))
			{
				// Eliminar el prefijo incorrecto
				OldName.RemoveFromStart(Entry.Value);
			}
		}

		// Agregar el prefijo correcto
		const FString NewNameWithPrefix = *PrefixFound + OldName;

		// Renombrar el asset
		UEditorUtilityLibrary::RenameAsset(SelectedObject, NewNameWithPrefix);
		++Counter;
	}

	if (Counter > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully renamed " + FString::FromInt(Counter) + " assets"));
	}

	
}

void UQuickAssetAction::RemoveUnusedAssets()
{
	/**
 * @brief Elimina los activos no utilizados entre los activos seleccionados en el editor de Unreal Engine.
 * 
 * @note
 * - Obtiene los activos seleccionados mediante `UEditorUtilityLibrary::GetSelectedAssetData()`.
 * - Ejecuta `FixUpRedirectors()` para corregir referencias de activos.
 * - Para cada activo seleccionado, verifica si tiene referencias utilizando `UEditorAssetLibrary::FindPackageReferencersForAsset()`.
 * - Si un activo no tiene referencias, se considera no utilizado y se agrega a una lista de eliminación.
 * - Si no se encuentran activos no utilizados, muestra un mensaje indicando que no hay activos para eliminar.
 * - Los activos no utilizados se eliminan utilizando `ObjectTools::DeleteAssets()`.
 * - Si se eliminan activos con éxito, se muestra una notificación con el número de activos eliminados.
 */
	TArray<FAssetData> SelectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<FAssetData> UnusedAssetsData;
	FixUpRedirectors();
	for (const FAssetData&  SelectedAssetData : SelectedAssetsData)
	{
		TArray<FString> AssetRefrencers = UEditorAssetLibrary::FindPackageReferencersForAsset(SelectedAssetData.ObjectPath.ToString());
		if (AssetRefrencers.Num() == 0)
		{
			UnusedAssetsData.Add(SelectedAssetData);
		}
	}
	if (UnusedAssetsData.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused asset found among selected assets"), false);
		return;
	}
	int32 NumAssetsDeleted = ObjectTools::DeleteAssets(UnusedAssetsData);
	if (NumAssetsDeleted > 0) return;
	DebugHeader::ShowNotifyInfo(TEXT("Successfully removed "+ FString::FromInt(NumAssetsDeleted) + " unused assets"));
}

void UQuickAssetAction::FixUpRedirectors()
{
	/**
 * @brief Busca y corrige los redireccionadores de objetos no referenciados en el directorio `/Game`.
 * 
 * @note
 * - Utiliza `FAssetRegistryModule` para obtener una lista de todos los objetos de tipo `UObjectRedirector` en el directorio `/Game`.
 * - Filtra los activos para encontrar los redireccionadores mediante `FARFilter`.
 * - Castea cada activo a `UObjectRedirector` y lo almacena en `RedirectorsToFixArray`.
 * - Llama a `FixupReferencers()` de `FAssetToolsModule` para corregir los redireccionadores detectados.
 */
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
