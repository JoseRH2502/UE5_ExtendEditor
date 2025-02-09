#pragma once
#include "Misc/MessageDialog.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

namespace DebugHeader
{
		static void Print (const FString& Message,const FColor& Color)
	{
		/**
	 * @brief Muestra un mensaje en la pantalla como un debug message en Unreal Engine.
	 *
	 * @param Message El mensaje a mostrar en pantalla.
	 * @param Color El color del mensaje.
	 * 
	 * @note La función solo muestra el mensaje si `GEngine` está disponible.
	 */
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,8.f,Color,Message);
		}
	}


	static void PrintLog (const FString& Message)
	{
		/**
	 * @brief Imprime un mensaje en la consola de salida como una advertencia en Unreal Engine.
	 *
	 * @param Message El mensaje a imprimir en la consola.
	 * 
	 * @note Usa el sistema de logging de Unreal Engine (`UE_LOG`) con la categoría `LogTemp` y nivel de advertencia (`Warning`).
	 */
		UE_LOG(LogTemp,Warning,TEXT("%s"),*Message);
	}


	static EAppReturnType::Type ShowMsgDialog(EAppMsgType::Type MsgType,const FString& Message, bool bShowMsgAsWarning = true)
	{
		/**
	 * @brief Muestra un cuadro de diálogo con un mensaje en Unreal Engine, opcionalmente con un título de advertencia.
	 *
	 * @param MsgType El tipo de mensaje a mostrar (EAppMsgType), como `Ok`, `YesNo`, etc.
	 * @param Message El mensaje a mostrar en el cuadro de diálogo.
	 * @param bShowMsgAsWarning Indica si el mensaje debe mostrarse con el título `"Warning"` (`true`) o sin título (`false`).
	 * 
	 * @return Un valor del tipo `EAppReturnType::Type` que indica la respuesta del usuario.
	 * 
	 * @note Si `bShowMsgAsWarning` es `true`, el cuadro de diálogo mostrará `"Warning"` como título del mensaje.
	 *       Si `bShowMsgAsWarning` es `false`, el mensaje se mostrará sin título.
	 */
		if (bShowMsgAsWarning)
		{
			FText MsgTitle = FText::FromString("Warning");
			return  FMessageDialog::Open(MsgType, FText::FromString(Message), MsgTitle);
		}
		else
		{
			return  FMessageDialog::Open(MsgType, FText::FromString(Message));
		}
		
	}

	static void ShowNotifyInfo(const FString& Message)
	{
		/**
	 * @brief Muestra una notificación en pantalla en Unreal Engine.
	 *
	 * @param Message El mensaje a mostrar en la notificación.
	 * 
	 * @note La notificación usa una fuente grande y desaparece después de 7 segundos.
	 *       Se gestiona a través de `FSlateNotificationManager`.
	 */
		FNotificationInfo NotifyInfo(FText::FromString(Message));
		NotifyInfo.bUseLargeFont = true;
		NotifyInfo.FadeOutDuration = 7.f;
		FSlateNotificationManager::Get().AddNotification(NotifyInfo);
	}
	
}


