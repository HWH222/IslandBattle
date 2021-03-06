// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IBCameraPawn.generated.h"

class UCameraComponent;
class USceneComponent;
class USpringArmComponent;

UCLASS()
class ISLANDBATTLE_API AIBCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIBCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category = "Paramter")
	float CameraSpeed = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Paramter")
	float CameraRotateRate = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Paramter")
	float CameraArmLength = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Comps")
	USceneComponent* RootComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Comps")
	USpringArmComponent* CameraArm;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Comps")
	UCameraComponent* PlayerCamera;

	UFUNCTION()
	void CameraMovement();

	UFUNCTION()
	void CameraRotation();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
