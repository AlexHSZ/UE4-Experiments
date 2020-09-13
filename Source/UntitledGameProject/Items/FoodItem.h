// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDGAMEPROJECT_API UFoodItem : public UItem
{
	GENERATED_BODY()

public:

	/* The health that is healed by eating the food item */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float HealthToHeal;

protected:

	virtual void Use(class ACharMovement* Character) override;
};
