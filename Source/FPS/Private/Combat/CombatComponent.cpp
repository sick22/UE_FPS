// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/CombatComponent.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCombatComponent::Initiate_CycleWeapon()
{
	UE_LOG(LogTemp, Log, TEXT("Cycle"));
}

void UCombatComponent::Initiate_FireWeapon_Pressed()
{
	UE_LOG(LogTemp, Log, TEXT("FireWeapon_Pressed"));
}

void UCombatComponent::Initiate_FireWeapon_Released()
{
	UE_LOG(LogTemp, Log, TEXT("FireWeapon_Released"));
}

void UCombatComponent::Initiate_ReloadWeapon()
{
	UE_LOG(LogTemp, Log, TEXT("ReloadWeapon"));
}

void UCombatComponent::Initiate_Aim_Pressed()
{
	UE_LOG(LogTemp, Log, TEXT("Aim_Pressed"));
}

void UCombatComponent::Initiate_Aim_Released()
{
	UE_LOG(LogTemp, Log, TEXT("Aim_Released"));
}

