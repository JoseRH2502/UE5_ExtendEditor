// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AssetAction/QuickMaterialCreationWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERMANAGER_QuickMaterialCreationWidget_generated_h
#error "QuickMaterialCreationWidget.generated.h already included, missing '#pragma once' in QuickMaterialCreationWidget.h"
#endif
#define SUPERMANAGER_QuickMaterialCreationWidget_generated_h

#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCreateMaterialFromSelectedTextures);


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickMaterialCreationWidget(); \
	friend struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickMaterialCreationWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperManager"), NO_API) \
	DECLARE_SERIALIZER(UQuickMaterialCreationWidget)


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuickMaterialCreationWidget(UQuickMaterialCreationWidget&&); \
	UQuickMaterialCreationWidget(const UQuickMaterialCreationWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickMaterialCreationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickMaterialCreationWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickMaterialCreationWidget) \
	NO_API virtual ~UQuickMaterialCreationWidget();


#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_23_PROLOG
#define FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMANAGER_API UClass* StaticClass<class UQuickMaterialCreationWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickMaterialCreationWidget_h


#define FOREACH_ENUM_E_CHANNELPACKINGTYPE(op) \
	op(E_ChannelPackingType::ECPT_NoChannelPacking) \
	op(E_ChannelPackingType::ECPT_ORM) 

enum class E_ChannelPackingType : uint8;
template<> struct TIsUEnumClass<E_ChannelPackingType> { enum { Value = true }; };
template<> SUPERMANAGER_API UEnum* StaticEnum<E_ChannelPackingType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
