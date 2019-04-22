// Fill out your copyright notice in the Description page of Project Settings.


#include "IBBuildingBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"

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
	BuildingMesh->SetWorldScale3D(FVector(0.2f));
	BuildingMesh->SetupAttachment(DamageArea);

	//Initial BuildingArea to get all resource or buildings nearby
	BuildingArea = CreateDefaultSubobject<USphereComponent>(TEXT("BuildingArea"));
	BuildingArea->SetSphereRadius(BuildingAreaRadius);
	BuildingArea->SetCollisionResponseToAllChannels(ECR_Overlap);
	BuildingArea->SetupAttachment(DamageArea);

	//Initial BuildingArea Mesh to show building area
	BuildingAreaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingAreaMesh"));
	BuildingAreaMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	BuildingAreaMesh->SetupAttachment(BuildingArea);
	
	
}

// Called when the game starts or when spawned
void AIBBuildingBase::BeginPlay()
{
	Super::BeginPlay();
	
	BuildingArea->OnComponentBeginOverlap.AddDynamic(this, &AIBBuildingBase::OnActorOverlapBuildingArea);
}

// Called every frame
void AIBBuildingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIBBuildingBase::OnActorOverlapBuildingArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{

		UE_LOG(LogTemp, Warning,TEXT("Something in it"));
	}
}

