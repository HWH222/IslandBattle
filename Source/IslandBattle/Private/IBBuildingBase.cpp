// Fill out your copyright notice in the Description page of Project Settings.


#include "IBBuildingBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AIBBuildingBase::AIBBuildingBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initial DamageArea to get damage
	DamageArea = CreateDefaultSubobject<USphereComponent>(TEXT("DamageArea"));
	DamageArea->SetSphereRadius(DamageAreaRadius);
	RootComponent = DamageArea;

	//Initial MeshComp 
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuidlingMesh"));
	BuildingMesh->SetupAttachment(DamageArea);

	//Initial BuildingArea to get all recouse or buildings nearby
	BuildingArea = CreateDefaultSubobject<USphereComponent>(TEXT("BuildingArea"));
	BuildingArea->SetSphereRadius(BuildingAreaRadius);
	BuildingArea->SetupAttachment(DamageArea);

	//Initial BuildingArea Mesh to show building area
	BuildingAreaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingAreaMesh"));
	BuildingAreaMesh->SetCollisionResponseToChannels(ECR_Ignore);
	BuildingAreaMesh->SetupAttachment(BuildingArea);
	
	
}

// Called when the game starts or when spawned
void AIBBuildingBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIBBuildingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

