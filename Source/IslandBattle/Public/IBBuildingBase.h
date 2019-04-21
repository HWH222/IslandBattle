// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBBuildingBase.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ISLANDBATTLE_API AIBBuildingBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIBBuildingBase();

	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Value")
	float BuildingAreaRadius = 200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	float DamageAreaRadius = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	TArray<AActor*> Resource;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	TArray<AActor*> Buildings;

	UPROPERTY(VisibleAnywhere, Category = "Comps")
	UStaticMeshComponent* BuildingMesh;

	UPROPERTY(VisibleAnywhere, Category = "Comps")
	USphereComponent* DamageArea;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Comps")
	USphereComponent* BuildingArea;

	UPROPERTY(VisibleAnywhere, Category = "Comps")
	UStaticMeshComponent* BuildingAreaMesh;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
