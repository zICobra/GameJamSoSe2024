// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLANETRETROFIT_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SettingsMenuCalled();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UCommonUserWidget> MainMenuUIBase;
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UMainMenuUI> MainMenuUI;
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class USettingsMenuBase> SettingsMenu;

public:
	class UMainMenuWidgetBase* CreatedMainMenuBase = nullptr;
	class UMainMenuUI* CreatedMainMenuUI = nullptr;
	class USettingsMenuBase* CreatedSettingsMenu = nullptr;
};
