// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"


class SAdvanceDeletionTab : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SAdvanceDeletionTab) {}

		SLATE_ARGUMENT(TArray< TSharedPtr <FAssetData> >,AssetsDataToStore)
		
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);

private:
	TSharedRef< SListView< TSharedPtr <FAssetData> > > ConstructAssetListView();
	TSharedPtr< SListView< TSharedPtr <FAssetData> > > ConstructedAssetListView;
	void RefreshAssetListView();
	
	TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FAssetData> AssetDataToDisplay,const TSharedRef<STableViewBase>& OwnerTable);
	TSharedRef<SCheckBox> ConstructCheckBox(const TSharedPtr<FAssetData>& AssetDataToDisplay);
	void OnCheckBoxStateChanged(ECheckBoxState NewState, TSharedPtr<FAssetData> AssetData);

#pragma region ComboBoxForListingCondition
	TSharedRef< SComboBox < TSharedPtr <FString> > > ConstructComboBox();
	TArray< TSharedPtr <FString> > ComboBoxSourceItems;
	TSharedRef<SWidget> OnGenerateComboContent(TSharedPtr<FString> SourceItem);
	void OnComboSelectionChanged(TSharedPtr<FString> SelectedOption,ESelectInfo::Type InSelectInfo);
	TSharedPtr<STextBlock> ComboDiplayTextBlock;
#pragma endregion
	
#pragma region RowWidgetForAssetListView
	TSharedRef<STextBlock> ConstructTextForRowWidget(const FString& TextContent, const FSlateFontInfo& FontToUse);
	FSlateFontInfo GetEmboseedTextFont() const {return FCoreStyle::Get().GetFontStyle(FName("EmbossedText"));}
	TSharedRef<SButton> ConstructButtonForRowWidget(const TSharedPtr<FAssetData>& AssetDataToDisplay);
	FReply OnDeleteButtonClicked(TSharedPtr<FAssetData> ClickedAssetData);
#pragma endregion

#pragma region TabButtons
	TSharedRef<SButton> ConstructDeleteAllButton();
	TSharedRef<SButton> ConstructSelectAllButton();
	TSharedRef<SButton> ConstructDeselectAllButton();
	FReply OnDeleteAllButtonClicked();
	FReply OnSelectAllButtonClicked();
	FReply OnDeselectAllButtonClicked();
	TSharedRef<STextBlock> ConstructTextForTabButtons(const FString& TextContent);
#pragma endregion

	TArray< TSharedPtr <FAssetData> > StoredAssetsData;
	TArray< TSharedRef <SCheckBox> > CheckBoxesArray;
	TArray< TSharedPtr < FAssetData> > AssetsDataToDeleteArray;
	TArray< TSharedPtr <FAssetData> > DisplayedAssetsData;
};
