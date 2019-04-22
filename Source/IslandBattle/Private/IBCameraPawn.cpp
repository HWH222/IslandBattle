// Fill out your copyright notice in the Description page of Project Settings.


#include "IBCameraPawn.h"

// Sets default values
AIBCameraPawn::AIBCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIBCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIBCameraPawn::CameraMovement()
{

}


void AIBCameraPawn::CameraRotation()
{

}


// Called every frame
void AIBCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIBCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

