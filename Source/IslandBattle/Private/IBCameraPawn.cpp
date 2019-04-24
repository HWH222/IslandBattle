// Fill out your copyright notice in the Description page of Project Settings.


#include "IBCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
AIBCameraPawn::AIBCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initial  Camera Components and some components relative with camera component
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->TargetArmLength = CameraArmLength;
	CameraArm->bDoCollisionTest = false;
	CameraArm->SetWorldRotation(FRotator(-30.0f, 0.0f, 0.0f));
	CameraArm->SetupAttachment(RootComp);

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraArm);
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

