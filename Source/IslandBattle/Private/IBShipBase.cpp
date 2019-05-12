 // Fill out your copyright notice in the Description page of Project Settings.


#include "IBShipBase.h"
#include "Components/StaticMeshComponent.h"
#include "IBShipAIController.h"
#include "INShipComponent.h"

// Sets default values
AIBShipBase::AIBShipBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship"));

	ShipMoveMentComp = CreateDefaultSubobject<UINShipComponent>(TEXT("ShipMoveMentComp"));
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
	ShipMoveMentComp->Moving(DeltaTime);
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
			ShipMoveMentComp->StartMoving(PathPoints);
			for (int32 num = 0; num < PathPoints.Num(); num++)
			{
				UE_LOG(LogClass, Log, TEXT("Names: %s"), *PathPoints[num].ToString());
			}

		}
		else UE_LOG(LogClass, Log, TEXT("No Path Points"));;
	}
}


