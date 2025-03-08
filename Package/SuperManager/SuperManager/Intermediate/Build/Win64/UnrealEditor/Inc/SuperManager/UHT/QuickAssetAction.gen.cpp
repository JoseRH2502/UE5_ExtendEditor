// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperManager/Public/AssetAction/QuickAssetAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickAssetAction() {}

// Begin Cross Module References
BLUTILITY_API UClass* Z_Construct_UClass_UAssetActionUtility();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickAssetAction();
SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_SuperManager();
// End Cross Module References

// Begin Class UQuickAssetAction Function AddPrefixes
struct Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "AddPrefixes", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickAssetAction_AddPrefixes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_AddPrefixes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execAddPrefixes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddPrefixes();
	P_NATIVE_END;
}
// End Class UQuickAssetAction Function AddPrefixes

// Begin Class UQuickAssetAction Function DuplicateAssets
struct Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics
{
	struct QuickAssetAction_eventDuplicateAssets_Parms
	{
		int32 NumOfDuplicate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumOfDuplicate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumOfDuplicate = { "NumOfDuplicate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuickAssetAction_eventDuplicateAssets_Parms, NumOfDuplicate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumOfDuplicate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "DuplicateAssets", nullptr, nullptr, Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers), sizeof(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::QuickAssetAction_eventDuplicateAssets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::QuickAssetAction_eventDuplicateAssets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execDuplicateAssets)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumOfDuplicate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DuplicateAssets(Z_Param_NumOfDuplicate);
	P_NATIVE_END;
}
// End Class UQuickAssetAction Function DuplicateAssets

// Begin Class UQuickAssetAction Function RemoveUnusedAssets
struct Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "RemoveUnusedAssets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickAssetAction::execRemoveUnusedAssets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveUnusedAssets();
	P_NATIVE_END;
}
// End Class UQuickAssetAction Function RemoveUnusedAssets

// Begin Class UQuickAssetAction
void UQuickAssetAction::StaticRegisterNativesUQuickAssetAction()
{
	UClass* Class = UQuickAssetAction::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddPrefixes", &UQuickAssetAction::execAddPrefixes },
		{ "DuplicateAssets", &UQuickAssetAction::execDuplicateAssets },
		{ "RemoveUnusedAssets", &UQuickAssetAction::execRemoveUnusedAssets },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickAssetAction);
UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister()
{
	return UQuickAssetAction::StaticClass();
}
struct Z_Construct_UClass_UQuickAssetAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "AssetAction/QuickAssetAction.h" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrefixMap_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Assets Actors type" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PrefixMap_ValueProp;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PrefixMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PrefixMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickAssetAction_AddPrefixes, "AddPrefixes" }, // 2680261355
		{ &Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets, "DuplicateAssets" }, // 3041018528
		{ &Z_Construct_UFunction_UQuickAssetAction_RemoveUnusedAssets, "RemoveUnusedAssets" }, // 3823384106
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickAssetAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap_ValueProp = { "PrefixMap", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap_Key_KeyProp = { "PrefixMap_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap = { "PrefixMap", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickAssetAction, PrefixMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrefixMap_MetaData), NewProp_PrefixMap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickAssetAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickAssetAction_Statics::NewProp_PrefixMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuickAssetAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetActionUtility,
	(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams = {
	&UQuickAssetAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuickAssetAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuickAssetAction()
{
	if (!Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton, Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton;
}
template<> SUPERMANAGER_API UClass* StaticClass<UQuickAssetAction>()
{
	return UQuickAssetAction::StaticClass();
}
UQuickAssetAction::UQuickAssetAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickAssetAction);
UQuickAssetAction::~UQuickAssetAction() {}
// End Class UQuickAssetAction

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickAssetAction, UQuickAssetAction::StaticClass, TEXT("UQuickAssetAction"), &Z_Registration_Info_UClass_UQuickAssetAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickAssetAction), 3835292823U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_3349181980(TEXT("/Script/SuperManager"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
