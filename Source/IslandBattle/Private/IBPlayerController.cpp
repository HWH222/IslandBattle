// Fill out your copyright notice in the Description page of Project Settings.


#include "IBPlayerController.h"
#include "IBMainHUD.h"
#include "IBShipBase.h"
AIBPlayerController::AIBPlayerController()
{
	//Initial PC Setting
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	//Initial PC Resource value
	SumOfGold = 0.0f;
	SumOfWood = 0.0f;
}



void AIBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AIBPlayerController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &AIBPlayerController::SelectionReleased);
}

void AIBPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MainHUD = Cast<AIBMainHUD>(GetHUD());
	if (!MainHUD)
	{
		UE_LOG(LogTemp, Warning, TEXT("THERE IS No HUD,Please Check it out"));
	}
}

void AIBPlayerController::SourceIncrease()
{

}

void AIBPlayerController::SelectionPressed()
{
	MainHUD->InitialPosition = MainHUD->GetMousePos();
	MainHUD->bStartSelection = true;
}

void AIBPlayerController::SelectionReleased()
{
	MainHUD->bStartSelection = false;
}