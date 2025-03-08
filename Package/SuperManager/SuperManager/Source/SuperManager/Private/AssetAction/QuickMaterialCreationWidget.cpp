// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickMaterialCreationWidget.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "DebugHeader.h"
#include "AssetToolsModule.h"
#include "Factories/MaterialFactoryNew.h"
#include "Materials/MaterialExpressionTextureSampleParameter.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"


#pragma region QuickMaterialCreationCore

void UQuickMaterialCreationWidget::CreateMaterialFromSelectedTextures()
{
	if(bCustomMaterialName)
	{
		if(MaterialName.IsEmpty() || MaterialName.Equals(TEXT("M_")))
		{
			DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please enter a valid name"));
			return;
		}
	}
	
	TArray<FAssetData> SelectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<UTexture2D*> SelectedTexturesArray;
	FString SelectedTextureFolderPath;
	uint32 PinsConnectedCounter = 0;

	if(!ProcessSelectedData(SelectedAssetsData, SelectedTexturesArray, SelectedTextureFolderPath)) {MaterialName = TEXT("M_"); return;}
	if(CheckIsNameUsed(SelectedTextureFolderPath, MaterialName)) {MaterialName = TEXT("M_"); return;}

	UMaterial* CreatedMaterial = CreateMaterialAsset(MaterialName,SelectedTextureFolderPath);

	if(!CreatedMaterial)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Failed to create material"));
		return;
	}
	
	for(UTexture2D* SelectedTexture:SelectedTexturesArray)
	{
		if(!SelectedTexture) continue;

		switch(ChannelPackingType)
		{
		case E_ChannelPackingType::ECPT_NoChannelPacking:

			Default_CreateMaterialNodes(CreatedMaterial,SelectedTexture,PinsConnectedCounter);
			break;

		case E_ChannelPackingType::ECPT_ORM:

			ORM_CreateMaterialNodes(CreatedMaterial,SelectedTexture,PinsConnectedCounter);
			break;

		case E_ChannelPackingType::ECPT_MAX:
			break;

		default:
			break;
		}		
	}
	if(bCreateMaterialInstance)
	{
		CreateMaterialInstanceAsset(CreatedMaterial,MaterialName,SelectedTextureFolderPath);
	}
	MaterialName = TEXT("M_");
}

bool UQuickMaterialCreationWidget::ProcessSelectedData(const TArray<FAssetData>& SelectedDataToProccess,
	TArray<UTexture2D*>& OutSelectedTexturesArray, FString& OutSelectedTexturePackagePath)
{
	if(SelectedDataToProccess.Num()==0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No texture selected"));
		return false;
	}

	bool bMaterialNameSet = false;

	for(const FAssetData& SelectedData:SelectedDataToProccess)
	{
		UObject* SelectedAsset = SelectedData.GetAsset();

		if(!SelectedAsset) continue;

		UTexture2D* SelectedTexture = Cast<UTexture2D>(SelectedAsset);

		if(!SelectedTexture)
		{
			DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please select only textures\n") + 
			SelectedAsset->GetName() + TEXT(" is not a texture"));

			return false;
		}

		OutSelectedTexturesArray.Add(SelectedTexture);

		if(OutSelectedTexturePackagePath.IsEmpty())
		{
			OutSelectedTexturePackagePath = SelectedData.PackagePath.ToString();
		}

		if(!bCustomMaterialName && !bMaterialNameSet)
		{
			MaterialName = SelectedAsset->GetName();
			MaterialName.RemoveFromStart(TEXT("T_"));
			MaterialName.InsertAt(0,TEXT("M_"));

			bMaterialNameSet = true;
		}		
	}

	return true;
}

bool UQuickMaterialCreationWidget::CheckIsNameUsed(const FString& FolderPathToCheck, const FString& MaterialNameToCheck)
{
	TArray<FString> ExistingAssetsPaths = UEditorAssetLibrary::ListAssets(FolderPathToCheck,false);

	for(const FString& ExistingAssetPath:ExistingAssetsPaths)
	{
		const FString ExistingAssetName = FPaths::GetBaseFilename(ExistingAssetPath);

		if(ExistingAssetName.Equals(MaterialNameToCheck))
		{
			DebugHeader::ShowMsgDialog(EAppMsgType::Ok,MaterialNameToCheck + 
			TEXT(" is already used by asset"));

			return true;
		}
	}

	return false;
}

UMaterial* UQuickMaterialCreationWidget::CreateMaterialAsset(const FString& NameOfTheMaterial,
	const FString& PathToPutMaterial)
{
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));

	UMaterialFactoryNew* MaterialFactory = NewObject<UMaterialFactoryNew>();

	UObject* CreatedObject = AssetToolsModule.Get().CreateAsset(NameOfTheMaterial,PathToPutMaterial,
	UMaterial::StaticClass(),MaterialFactory);

	return Cast<UMaterial>(CreatedObject);
}

void UQuickMaterialCreationWidget::Default_CreateMaterialNodes(UMaterial* CreatedMaterial, UTexture2D* SelectedTexture, uint32& PinsConnectedCounter)
{
	UMaterialExpressionTextureSample* TextureSampleNode =  NewObject<UMaterialExpressionTextureSample>(CreatedMaterial);

	if(!TextureSampleNode) return;

	if(!CreatedMaterial->GetEditorOnlyData()->BaseColor.IsConnected())
	{
		if(TryConnectBaseColor(TextureSampleNode,SelectedTexture,CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}
	
	if(!CreatedMaterial->GetEditorOnlyData()->Metallic.IsConnected())
	{
		if(TryConnectMetalic(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	
	if(!CreatedMaterial->GetEditorOnlyData()->Roughness.IsConnected())
	{
		if(TryConnectRoughness(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	if(!CreatedMaterial->GetEditorOnlyData()->Normal.IsConnected())
	{
		if(TryConnectNormal(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	if(!CreatedMaterial->GetEditorOnlyData()->AmbientOcclusion.IsConnected())
	{
		if(TryConnectAO(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	DebugHeader::Print(TEXT("Failed to connect the texture: ") + SelectedTexture->GetName(),FColor::Red);
}

void UQuickMaterialCreationWidget::ORM_CreateMaterialNodes(UMaterial* CreatedMaterial, UTexture2D* SelectedTexture,
	uint32& PinsConnectedCounter)
{
	UMaterialExpressionTextureSample* TextureSampleNode =
	NewObject<UMaterialExpressionTextureSample>(CreatedMaterial);

	if(!TextureSampleNode) return;

	if(!CreatedMaterial->GetEditorOnlyData()->BaseColor.IsConnected())
	{
		if(TryConnectBaseColor(TextureSampleNode,SelectedTexture,CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	if(!CreatedMaterial->GetEditorOnlyData()->Normal.IsConnected())
	{
		if(TryConnectNormal(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter++;
			return;
		}
	}

	if(!CreatedMaterial->GetEditorOnlyData()->Roughness.IsConnected())
	{
		if(TryConnectORM(TextureSampleNode, SelectedTexture, CreatedMaterial))
		{
			PinsConnectedCounter+=3;
			return;
		}
	}
	
}

#pragma endregion

#pragma region CreateMaterialNodes

bool UQuickMaterialCreationWidget::TryConnectBaseColor(UMaterialExpressionTextureSample * TextureSampleNode, UTexture2D * SelectedTexture, UMaterial * CreatedMaterial)
{
	for (const FString& BaseColorName : BaseColorArray)
	{
		
		if (SelectedTexture->GetName().Contains(BaseColorName))
		{
			TextureSampleNode->Texture = SelectedTexture;
			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->BaseColor.Expression = TextureSampleNode;
			CreatedMaterial->PostEditChange();

			TextureSampleNode->MaterialExpressionEditorX -=600;
			
			return true;
		}
	}

	return false;
}

bool UQuickMaterialCreationWidget::TryConnectMetalic(UMaterialExpressionTextureSample* TextureSampleNode,
	UTexture2D* SelectedTexture, UMaterial* CreatedMaterial)
{

	for (const FString& MetalicName:MetallicArray)
	{
		
		if(SelectedTexture->GetName().Contains(MetalicName))
		{
			SelectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			SelectedTexture->SRGB = false;
			SelectedTexture->PostEditChange();

			TextureSampleNode->Texture = SelectedTexture;
			TextureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;

			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->Metallic.Expression = TextureSampleNode;
			CreatedMaterial->PostEditChange();

			TextureSampleNode->MaterialExpressionEditorX -=600;
			TextureSampleNode->MaterialExpressionEditorY +=240;

			return true;
		}
	}

	return false;
}

bool UQuickMaterialCreationWidget::TryConnectRoughness(UMaterialExpressionTextureSample* TextureSampleNode,
	UTexture2D* SelectedTexture, UMaterial* CreatedMaterial)
{
	for(const FString& RoughnessName:RoughnessArray)
	{
		if(SelectedTexture->GetName().Contains(RoughnessName))
		{
			SelectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			SelectedTexture->SRGB = false;
			SelectedTexture->PostEditChange();

			TextureSampleNode->Texture = SelectedTexture;
			TextureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;

			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->Roughness.Expression = TextureSampleNode;
			CreatedMaterial->PostEditChange();

			TextureSampleNode->MaterialExpressionEditorX -=600;
			TextureSampleNode->MaterialExpressionEditorY +=480;

			return true;
		}
	}

	return false;
}

bool UQuickMaterialCreationWidget::TryConnectNormal(UMaterialExpressionTextureSample* TextureSampleNode,
	UTexture2D* SelectedTexture, UMaterial* CreatedMaterial)
{
	for(const FString& NormalName:NormalArray)
	{	
		if(SelectedTexture->GetName().Contains(NormalName))
		{
			TextureSampleNode->Texture = SelectedTexture;
			TextureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_Normal;

			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->Normal.Expression = TextureSampleNode;
			CreatedMaterial->PostEditChange();

			TextureSampleNode->MaterialExpressionEditorX -= 600;
			TextureSampleNode->MaterialExpressionEditorY += 720;

			return true;
		}
	}

	return false;
}

bool UQuickMaterialCreationWidget::TryConnectAO(UMaterialExpressionTextureSample* TextureSampleNode,
	UTexture2D* SelectedTexture, UMaterial* CreatedMaterial)
{
	for(const FString& AOName:AmbientOcclusionArray)
	{	
		if(SelectedTexture->GetName().Contains(AOName))
		{
			SelectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			SelectedTexture->SRGB = false;
			SelectedTexture->PostEditChange();

			TextureSampleNode->Texture = SelectedTexture;
			TextureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;

			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->AmbientOcclusion.Expression = TextureSampleNode;
			CreatedMaterial->PostEditChange();


			TextureSampleNode->MaterialExpressionEditorX -= 600;
			TextureSampleNode->MaterialExpressionEditorY += 960;

			return true;
		}
	}

	return false;
}

bool UQuickMaterialCreationWidget::TryConnectORM(UMaterialExpressionTextureSample* TextureSampleNode,
	UTexture2D* SelectedTexture, UMaterial* CreatedMaterial)
{
	for(const FString& ORM_Name:ORMArray)
	{
		if(SelectedTexture->GetName().Contains(ORM_Name))
		{
			SelectedTexture->CompressionSettings = TextureCompressionSettings::TC_Masks;
			SelectedTexture->SRGB = false;
			SelectedTexture->PostEditChange();

			TextureSampleNode->Texture = SelectedTexture;
			TextureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_Masks;

			CreatedMaterial->GetEditorOnlyData()->ExpressionCollection.AddExpression(TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->AmbientOcclusion.Connect(1,TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->Roughness.Connect(2,TextureSampleNode);
			CreatedMaterial->GetEditorOnlyData()->Metallic.Connect(3,TextureSampleNode);
			CreatedMaterial->PostEditChange();

			TextureSampleNode->MaterialExpressionEditorX -= 600;
			TextureSampleNode->MaterialExpressionEditorY += 960;

			return true;
		}
	}
	return false;
}

class UMaterialInstanceConstant* UQuickMaterialCreationWidget::CreateMaterialInstanceAsset(UMaterial* CreatedMaterial,
	FString NameOfMaterialInstance, const FString& PathToPutMI)
{
	NameOfMaterialInstance.RemoveFromStart(TEXT("M_"));
	NameOfMaterialInstance.InsertAt(0,TEXT("MI_"));

	UMaterialInstanceConstantFactoryNew* MIFactoryNew = NewObject<UMaterialInstanceConstantFactoryNew>();

	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));

	UObject* CreatedObject = AssetToolsModule.Get().CreateAsset(NameOfMaterialInstance,PathToPutMI,
	UMaterialInstanceConstant::StaticClass(),MIFactoryNew);

	if(UMaterialInstanceConstant* CreatedMI = Cast<UMaterialInstanceConstant>(CreatedObject))
	{
		CreatedMI->SetParentEditorOnly(CreatedMaterial);

		CreatedMI->PostEditChange();
		CreatedMaterial->PostEditChange();

		return CreatedMI;
	}

	return nullptr;
}

#pragma endregion
