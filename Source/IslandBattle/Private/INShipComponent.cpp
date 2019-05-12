// Fill out your copyright notice in the Description page of Project Settings.


#include "INShipComponent.h"

UINShipComponent::UINShipComponent()
{
	bMoving = false;
	MovingSpeed = 1.0f;
	RotatingRate = 1;
	MovingOffset = 15.0f;
	OnMoveToTargetDelegate = FOnMoveToTargetDelegate::CreateUObject(this, &UINShipComponent::OnMovingToTargetComplete);
}

void UINShipComponent::StartMoving(TArray<FVector> PathPoints)
{
	bMoving = true;
	Path.Empty();
	for (int32 num = PathPoints.Num(); num >0; num--)
	{
		Path.Add(PathPoints.Pop());
	}
	if(Path.Num()>=2)
	{		
		StartPoint = Path.Pop();
		TargetPoint = Path.Pop();
	}
	else bMoving = false;

	return;
}

void UINShipComponent::Moving(float DeltaTime)
{
	if (!bMoving)   return;
	AActor* Owner = GetOwner();
	FVector CurrentLocation = Owner->GetActorLocation();
	//UE_LOG(LogClass, Log, TEXT("Dist %f"), FVector::Distance(TargetPoint,CurrentLocation));
	if (FVector::Distance(CurrentLocation,TargetPoint) <= 15.0f )
	{
		
		OnMoveToTargetDelegate.ExecuteIfBound();
		return;
	}
	FVector Nor = TargetPoint - StartPoint; 
	Nor.Normalize();
	Owner->SetActorLocation(CurrentLocation + Nor*MovingSpeed);
	//UE_LOG(LogClass, Log, TEXT("Dist  %f"), FVector::Distance(CurrentLocation, TargetPoint));
}

void UINShipComponent::OnMovingToTargetComplete()
{
	StartPoint = TargetPoint;
	if (Path.Num() > 0) 
	{
		TargetPoint = Path.Pop();
	}
	else bMoving = false;
	
}
