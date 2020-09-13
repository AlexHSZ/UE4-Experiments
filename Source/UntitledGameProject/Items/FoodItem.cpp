// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "../CharMovement.h"
#include "../Public/Health/HealthComponent.h"

void UFoodItem::Use(class ACharMovement* Character)
{
	if (Character)
	{
		UHealthComponent* CharHealth = Character->FindComponentByClass<UHealthComponent>();
		CharHealth->ReceiveHealth(HealthToHeal);
	}
}