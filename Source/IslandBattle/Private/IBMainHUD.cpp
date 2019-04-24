// Fill out your copyright notice in the Description page of Project Settings.


#include "IBMainHUD.h"
#include "IBShipBase.h"
#include "IBPlayerController.h"

FVector2D AIBMainHUD::GetMousePos()
{
	float PosX;
	float PosY;
	APlayerController* MyPlayerController = GetOwningPlayerController();

	MyPlayerController->GetMousePosition(PosX, PosY);

	return FVector2D(PosX,PosY);
}

void AIBMainHUD::DrawHUD()
{
	if (bStartSelection)
	{
		//Update mouse current position when left mouse click 
		CurrentPosition = GetMousePos();
		FoundShip.Empty();

		DrawRect(FLinearColor(0.0f, 0.0f, 1.0f, 0.15f), InitialPosition.X, InitialPosition.Y,
			CurrentPosition.X - InitialPosition.X, CurrentPosition.Y - InitialPosition.Y);


		GetActorsInSelectionRectangle<AIBShipBase>(InitialPosition, CurrentPosition, FoundShip,false);

		if (FoundShip.Num() > 0)
		{
			AIBPlayerController* MyPC = Cast<AIBPlayerController>(GetOwningPlayerController());
			if (MyPC)
			{
				MyPC->SelectedShip = FoundShip;
			}
		}
		else
		{
			AIBPlayerController* MyPC = Cast<AIBPlayerController>(GetOwningPlayerController());
			if (MyPC)
			{
				MyPC->SelectedShip.Empty();
			}
		}
	}
}
