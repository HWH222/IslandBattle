// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBIsland.generated.h"

class UStaticMeshComponent;

UCLASS()
class ISLANDBATTLE_API AIBIsland : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIBIsland();

	UPROPERTY(EditDefaultsOnly, Category = "Resource")
	TSubclassOf<AActor>  GoldResource;

	UPROPERTY(EditDefaultsOnly, Category = "Resource")
	TSubclassOf<AActor>  TreeResource;

	UPROPERTY(EditAnywhere, Category = "MeshComp")
	UStaticMeshComponent* IslandBase;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
