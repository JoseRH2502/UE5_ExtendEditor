// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Styling/SlateStyle.h"
class FSuperManagerStyle
{
public:
	static void InitializeIcons();
	static void ShutDown();

	static FName GetStyleSetName(){return StyleSetName;}
	static TSharedRef<FSlateStyleSet> GetCreatedSlateStyleSet() {return CreatedSlateStyleSet.ToSharedRef(); }

private:
	static FName StyleSetName;
	static TSharedRef<FSlateStyleSet> CreateSlateStyleSet();
	static TSharedPtr<FSlateStyleSet> CreatedSlateStyleSet;
	
};