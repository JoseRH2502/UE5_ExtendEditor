// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActorActions/QuickActorActionsWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERMANAGER_QuickActorActionsWidget_generated_h
#error "QuickActorActionsWidget.generated.h already included, missing '#pragma once' in QuickActorActionsWidget.h"
#endif
#define SUPERMANAGER_QuickActorActionsWidget_generated_h

#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_25_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics; \
	SUPERMANAGER_API static class UScriptStruct* StaticStruct();


template<> SUPERMANAGER_API UScriptStruct* StaticStruct<struct FRandomActorRotation>();

#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRandomizeActorTransform); \
	DECLARE_FUNCTION(execDuplicateActors); \
	DECLARE_FUNCTION(execSelectAllActorsWithSimilarName);


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickActorActionsWidget(); \
	friend struct Z_Construct_UClass_UQuickActorActionsWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickActorActionsWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperManager"), NO_API) \
	DECLARE_SERIALIZER(UQuickActorActionsWidget)


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuickActorActionsWidget(UQuickActorActionsWidget&&); \
	UQuickActorActionsWidget(const UQuickActorActionsWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickActorActionsWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickActorActionsWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickActorActionsWidget) \
	NO_API virtual ~UQuickActorActionsWidget();


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_55_PROLOG
#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_58_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMANAGER_API UClass* StaticClass<class UQuickActorActionsWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h


#define FOREACH_ENUM_E_DUPLICATIONAXIS(op) \
	op(E_DuplicationAxis::EDA_XAxis) \
	op(E_DuplicationAxis::EDA_YAxis) \
	op(E_DuplicationAxis::EDA_ZAxis) 

enum class E_DuplicationAxis : uint8;
template<> struct TIsUEnumClass<E_DuplicationAxis> { enum { Value = true }; };
template<> SUPERMANAGER_API UEnum* StaticEnum<E_DuplicationAxis>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
