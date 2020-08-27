// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodWaterActor.h"
#include "CharMovement.h"

// Sets default values
AFoodWaterActor::AFoodWaterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));

	RootComponent = SceneRoot;
	StaticMesh->SetupAttachment(RootComponent);

	SphereCollision->SetupAttachment(StaticMesh);
	SphereCollision->SetSphereRadius(100.f);
	SphereCollision->bHiddenInGame = false;
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AFoodWaterActor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AFoodWaterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodWaterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodWaterActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharMovement* Character = Cast<ACharMovement>(OtherActor);

	if (Character)
	{
		switch (Type)
		{
		case 1: 
			Character->Hunger <= Character->MaxHunger - 10.f ? Character->Hunger += 10.f : Character->MaxHunger;
			break;
		case 2:
			Character->Thirst <= Character->MaxThirst - 20.f ? Character->Thirst += 10.f : Character->MaxThirst;
			break;
		case 3:
			Character->Hunger <= Character->MaxHunger - 10.f ? Character->Hunger += 10.f : Character->MaxHunger;
			Character->Thirst <= Character->MaxThirst - 20.f ? Character->Thirst += 10.f : Character->MaxThirst;
			break;
		default:
			break;
		}
	}

	Destroy();
}

