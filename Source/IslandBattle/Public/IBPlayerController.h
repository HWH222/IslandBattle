// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IBPlayerController.generated.h"

/**
 * 
 */
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


	void SourceIncrease();
};
