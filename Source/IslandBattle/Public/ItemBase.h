// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class  EItemType : uint8
{
	gold,
	wood,
	nothing
};

UCLASS()
class ISLANDBATTLE_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Comps")
	UBoxComponent* ItemCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Value")
	FVector BoxExtent =  FVector(9.0f, 9.0f, 15.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
	EItemType SourceType = EItemType::nothing;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
