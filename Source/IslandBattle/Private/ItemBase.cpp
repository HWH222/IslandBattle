// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/BoxComponent.h"




// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ItemCollision"));
	ItemCollision->SetBoxExtent(BoxExtent);
	ItemCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

