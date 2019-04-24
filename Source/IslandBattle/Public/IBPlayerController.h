// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IBPlayerController.generated.h"
/**
 * 
 */

class AIBMainHUD;
class AIBShipBase;
UCLASS()
class ISLANDBATTLE_API AIBPlayerController : public APlayerController
{
	GENERATED_BODY()


	

public:
	AIBPlayerController();


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category = "Resource")
	float SumOfGold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Resource")
	float SumOfWood;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Value")
	TArray<AIBShipBase*> SelectedShip;

	AIBMainHUD* MainHUD;

	void SourceIncrease();

	void SelectionPressed();

	void SelectionReleased();

	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
};
