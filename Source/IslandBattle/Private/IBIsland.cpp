// Fill out your copyright notice in the Description page of Project Settings.


#include "IBIsland.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AIBIsland::AIBIsland()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IslandBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IslandBase"));
	RootComponent = IslandBase;

	
}

// Called when the game starts or when spawned
void AIBIsland::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIBIsland::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

