// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperManager/Public/ActorActions/QuickActorActionsWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickActorActionsWidget() {}

// Begin Cross Module References
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_ESearchCase();
SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickActorActionsWidget();
SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister();
SUPERMANAGER_API UEnum* Z_Construct_UEnum_SuperManager_E_DuplicationAxis();
SUPERMANAGER_API UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation();
UNREALED_API UClass* Z_Construct_UClass_UEditorActorSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_SuperManager();
// End Cross Module References

// Begin Enum E_DuplicationAxis
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_DuplicationAxis;
static UEnum* E_DuplicationAxis_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SuperManager_E_DuplicationAxis, (UObject*)Z_Construct_UPackage__Script_SuperManager(), TEXT("E_DuplicationAxis"));
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton;
}
template<> SUPERMANAGER_API UEnum* StaticEnum<E_DuplicationAxis>()
{
	return E_DuplicationAxis_StaticEnum();
}
struct Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "EDA_MAX.Comment", "/**\n * \n */" },
		{ "EDA_MAX.DisplayName", "Default Max" },
		{ "EDA_MAX.Name", "E_DuplicationAxis::EDA_MAX" },
		{ "EDA_XAxis.Comment", "/**\n * \n */" },
		{ "EDA_XAxis.DisplayName", "X Axis" },
		{ "EDA_XAxis.Name", "E_DuplicationAxis::EDA_XAxis" },
		{ "EDA_YAxis.Comment", "/**\n * \n */" },
		{ "EDA_YAxis.DisplayName", "Y Axis" },
		{ "EDA_YAxis.Name", "E_DuplicationAxis::EDA_YAxis" },
		{ "EDA_ZAxis.Comment", "/**\n * \n */" },
		{ "EDA_ZAxis.DisplayName", "Z Axis" },
		{ "EDA_ZAxis.Name", "E_DuplicationAxis::EDA_ZAxis" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_DuplicationAxis::EDA_XAxis", (int64)E_DuplicationAxis::EDA_XAxis },
		{ "E_DuplicationAxis::EDA_YAxis", (int64)E_DuplicationAxis::EDA_YAxis },
		{ "E_DuplicationAxis::EDA_ZAxis", (int64)E_DuplicationAxis::EDA_ZAxis },
		{ "E_DuplicationAxis::EDA_MAX", (int64)E_DuplicationAxis::EDA_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SuperManager,
	nullptr,
	"E_DuplicationAxis",
	"E_DuplicationAxis",
	Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SuperManager_E_DuplicationAxis()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton, Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton;
}
// End Enum E_DuplicationAxis

// Begin ScriptStruct FRandomActorRotation
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RandomActorRotation;
class UScriptStruct* FRandomActorRotation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRandomActorRotation, (UObject*)Z_Construct_UPackage__Script_SuperManager(), TEXT("RandomActorRotation"));
	}
	return Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton;
}
template<> SUPERMANAGER_API UScriptStruct* StaticStruct<FRandomActorRotation>()
{
	return FRandomActorRotation::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotYaw_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotPitch_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotRoll_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bRandomizeRotYaw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotYaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMax;
	static void NewProp_bRandomizeRotPitch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMax;
	static void NewProp_bRandomizeRotRoll_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotRoll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRandomActorRotation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotYaw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw = { "bRandomizeRotYaw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotYaw_MetaData), NewProp_bRandomizeRotYaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin = { "RotYawMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotYawMin_MetaData), NewProp_RotYawMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax = { "RotYawMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotYawMax_MetaData), NewProp_RotYawMax_MetaData) };
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotPitch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch = { "bRandomizeRotPitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotPitch_MetaData), NewProp_bRandomizeRotPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin = { "RotPitchMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotPitchMin_MetaData), NewProp_RotPitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax = { "RotPitchMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotPitchMax_MetaData), NewProp_RotPitchMax_MetaData) };
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotRoll = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll = { "bRandomizeRotRoll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotRoll_MetaData), NewProp_bRandomizeRotRoll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin = { "RotRollMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotRollMin_MetaData), NewProp_RotRollMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax = { "RotRollMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotRollMax_MetaData), NewProp_RotRollMax_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
	nullptr,
	&NewStructOps,
	"RandomActorRotation",
	Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers),
	sizeof(FRandomActorRotation),
	alignof(FRandomActorRotation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation()
{
	if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton;
}
// End ScriptStruct FRandomActorRotation

// Begin Class UQuickActorActionsWidget Function DuplicateActors
struct Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "DuplicateActors", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execDuplicateActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DuplicateActors();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function DuplicateActors

// Begin Class UQuickActorActionsWidget Function RandomizeActorTransform
struct Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "RandomizeActorTransform", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execRandomizeActorTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RandomizeActorTransform();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function RandomizeActorTransform

// Begin Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName
struct Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "SelectAllActorsWithSimilarName", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execSelectAllActorsWithSimilarName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectAllActorsWithSimilarName();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName

// Begin Class UQuickActorActionsWidget
void UQuickActorActionsWidget::StaticRegisterNativesUQuickActorActionsWidget()
{
	UClass* Class = UQuickActorActionsWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DuplicateActors", &UQuickActorActionsWidget::execDuplicateActors },
		{ "RandomizeActorTransform", &UQuickActorActionsWidget::execRandomizeActorTransform },
		{ "SelectAllActorsWithSimilarName", &UQuickActorActionsWidget::execSelectAllActorsWithSimilarName },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickActorActionsWidget);
UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister()
{
	return UQuickActorActionsWidget::StaticClass();
}
struct Z_Construct_UClass_UQuickActorActionsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ActorActions/QuickActorActionsWidget.h" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchCase_MetaData[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AxisForDuplication_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDuplicates_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetDist_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomActorRotation_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeScale_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeOffset_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EditorActorSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SearchCase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AxisForDuplication_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AxisForDuplication;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDuplicates;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetDist;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomActorRotation;
	static void NewProp_bRandomizeScale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMax;
	static void NewProp_bRandomizeOffset_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMax;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EditorActorSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors, "DuplicateActors" }, // 1487522727
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform, "RandomizeActorTransform" }, // 1305083955
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName, "SelectAllActorsWithSimilarName" }, // 329506161
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickActorActionsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase = { "SearchCase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, SearchCase), Z_Construct_UEnum_CoreUObject_ESearchCase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchCase_MetaData), NewProp_SearchCase_MetaData) }; // 1208795360
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication = { "AxisForDuplication", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, AxisForDuplication), Z_Construct_UEnum_SuperManager_E_DuplicationAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AxisForDuplication_MetaData), NewProp_AxisForDuplication_MetaData) }; // 1413148828
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates = { "NumberOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, NumberOfDuplicates), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfDuplicates_MetaData), NewProp_NumberOfDuplicates_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist = { "OffsetDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetDist), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetDist_MetaData), NewProp_OffsetDist_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation = { "RandomActorRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, RandomActorRotation), Z_Construct_UScriptStruct_FRandomActorRotation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomActorRotation_MetaData), NewProp_RandomActorRotation_MetaData) }; // 816521977
void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit(void* Obj)
{
	((UQuickActorActionsWidget*)Obj)->bRandomizeScale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale = { "bRandomizeScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeScale_MetaData), NewProp_bRandomizeScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin = { "ScaleMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleMin_MetaData), NewProp_ScaleMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax = { "ScaleMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleMax_MetaData), NewProp_ScaleMax_MetaData) };
void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit(void* Obj)
{
	((UQuickActorActionsWidget*)Obj)->bRandomizeOffset = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset = { "bRandomizeOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeOffset_MetaData), NewProp_bRandomizeOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin = { "OffsetMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetMin_MetaData), NewProp_OffsetMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax = { "OffsetMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffsetMax_MetaData), NewProp_OffsetMax_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem = { "EditorActorSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, EditorActorSubsystem), Z_Construct_UClass_UEditorActorSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EditorActorSubsystem_MetaData), NewProp_EditorActorSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams = {
	&UQuickActorActionsWidget::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuickActorActionsWidget()
{
	if (!Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton, Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton;
}
template<> SUPERMANAGER_API UClass* StaticClass<UQuickActorActionsWidget>()
{
	return UQuickActorActionsWidget::StaticClass();
}
UQuickActorActionsWidget::UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickActorActionsWidget);
UQuickActorActionsWidget::~UQuickActorActionsWidget() {}
// End Class UQuickActorActionsWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E_DuplicationAxis_StaticEnum, TEXT("E_DuplicationAxis"), &Z_Registration_Info_UEnum_E_DuplicationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1413148828U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRandomActorRotation::StaticStruct, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewStructOps, TEXT("RandomActorRotation"), &Z_Registration_Info_UScriptStruct_RandomActorRotation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRandomActorRotation), 816521977U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickActorActionsWidget, UQuickActorActionsWidget::StaticClass, TEXT("UQuickActorActionsWidget"), &Z_Registration_Info_UClass_UQuickActorActionsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickActorActionsWidget), 1555318368U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_7443432(TEXT("/Script/SuperManager"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
