// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ButtonBase.h"

#include "Components/Overlay.h"
#include "CommonTextBlock.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"


void UButtonBase::NativePreConstruct()
{
    if(ButtonNameText)
    {
        ButtonNameText->SetText(FText::FromString(ButtonText));
    }
}

void UButtonBase::NativeOnClicked()
{
    UGameplayStatics::PlaySound2D(GetWorld(), ClickSound);
    OnClicked.ExecuteIfBound();
}

void UButtonBase::NativeOnHovered()
{
    UGameplayStatics::PlaySound2D(GetWorld(), HoverSound);    
    OnHovered.ExecuteIfBound();
}


void UButtonBase::OverrideButtonText(FString NewButtonName)
{
    ButtonNameText->SetText(FText::FromString(NewButtonName));
}

