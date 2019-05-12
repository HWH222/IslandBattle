// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "IBShipAIController.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDBATTLE_API AIBShipAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	TArray<FVector> SearchPath(const FVector& location);

};
