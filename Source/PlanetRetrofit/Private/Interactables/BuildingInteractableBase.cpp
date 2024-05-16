// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/BuildingInteractableBase.h"

#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"


#include "DefaultGameInstance.h"
#include "Kismet/GameplayStatics.h"

#include "Sound/SoundCue.h"

#include "DataAssets/BuildingsConfig.h"


ABuildingInteractableBase::ABuildingInteractableBase()
{

}

void ABuildingInteractableBase::BeginPlay()
{
    Super::BeginPlay();

    GameInstance = Cast<UDefaultGameInstance>(GetGameInstance());
}


void ABuildingInteractableBase::Interact()
{
    if(Spawned)
    {
        return;
    }
    Interacting.ExecuteIfBound();
}

void ABuildingInteractableBase::BuildBuilding()
{
    if(!GameInstance->BuildingConfig->Buildings[BuildingIndex].ActorToSpawn)
    {
        UE_LOG(LogTemp, Error, TEXT("Actor to Spawn for %s is Empty!!!"), *GameInstance->BuildingConfig->Buildings[BuildingIndex].BuildingName);
        return;
    }

    UGameplayStatics::PlaySoundAtLocation(GetWorld(), BuildingSound, GetActorLocation());
    FTimerHandle TimerHandle;

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() 
    {
        FActorSpawnParameters SpawnParams;

        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        GetWorld()->SpawnActor(GameInstance->BuildingConfig->Buildings[BuildingIndex].ActorToSpawn, &BuildingTransform, SpawnParams);
        Spawned = true;
    }, 1.5f, false);
}

bool ABuildingInteractableBase::CanOutline()
{
    if(Spawned)
    {
        return false;
    }
    else
    {
        return true;
    }
}
