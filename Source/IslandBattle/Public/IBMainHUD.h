// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IBMainHUD.generated.h"


class AIBShipBase;
/**
 * 
 */
UCLASS()
class ISLANDBATTLE_API AIBMainHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	//initial position is the position of mouse when left mouse click
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	FVector2D InitialPosition;

	//current position is the position of mouse exactly
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	FVector2D CurrentPosition;

	UPROPERTY(EditDefaultsOnly, Category = "Value")
	TArray<AIBShipBase*> FoundShip;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Value")
	bool bStartSelection = false;


	UFUNCTION()
	FVector2D GetMousePos();

	virtual void DrawHUD() override;
};
