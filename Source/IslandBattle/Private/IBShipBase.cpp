 // Fill out your copyright notice in the Description page of Project Settings.


#include "IBShipBase.h"
#include "Components/StaticMeshComponent.h"
#include "IBShipAIController.h"
#include "Engine.h"

// Sets default values
AIBShipBase::AIBShipBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship"));

}

// Called when the game starts or when spawned
void AIBShipBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIBShipBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIBShipBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AIBShipBase::CommandMoveTo(const FVector& location)
{
	AIBShipAIController* ShipAIController = Cast<AIBShipAIController>(GetController());
	if (ShipAIController)
	{
		TArray<FVector> PathPoints = ShipAIController->SearchPath(location);
		if (PathPoints.Num() != 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Find Path Points"));
			for (int32 num = 0; num < PathPoints.Num(); num++)
			{
				UE_LOG(LogClass, Log, TEXT("Names: %s"), *PathPoints[num].ToString());
			}
		}
		else GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("No Path Points"));
	}
}

