// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "INShipComponent.generated.h"

/**
 * 
 */
                                                                                              
DECLARE_DELEGATE(FOnMoveToTargetDelegate);

UCLASS()
class ISLANDBATTLE_API UINShipComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShipMovement")
	bool bMoving;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ShipMovement")
	float MovingSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ShipMovement")
	float RotatingRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ShipMovement")
	float MovingOffset;

	TArray<FVector> Path;

	FVector TargetPoint;
	FVector StartPoint;
	FOnMoveToTargetDelegate OnMoveToTargetDelegate;
public:

	UINShipComponent();

	void StartMoving(TArray<FVector> PathPoints);
	void Moving(float DeltaTime);
	void OnMovingToTargetComplete();
};
