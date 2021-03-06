// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IBShipBase.generated.h"


class UStaticMeshComponent;
class UINShipComponent;
UCLASS()
class ISLANDBATTLE_API AIBShipBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIBShipBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Comps")
	UStaticMeshComponent* ShipComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Comps")
	UINShipComponent* ShipMoveMentComp;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable , Category ="Ship")
	void CommandMoveTo(const FVector& location);
};
