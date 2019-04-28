// Fill out your copyright notice in the Description page of Project Settings.


#include "IBShipAIController.h"
#include "NavigationSystem.h"

TArray<FVector> AIBShipAIController::SearchPath(const FVector & location)
{
	TArray<FVector> Result;
	FPathFindingQuery Query;
	FAIMoveRequest MoveRequest(location);
	MoveRequest.SetUsePathfinding(true);
	const bool bValidQuery = BuildPathfindingQuery(MoveRequest, Query);
	if (bValidQuery)
	{
		UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
		FPathFindingResult PathResult;

		if (NavSys)
		{
			PathResult = NavSys->FindPathSync(Query);
			if (PathResult.Result != ENavigationQueryResult::Error)
			{
				if (PathResult.IsSuccessful() && PathResult.Path.IsValid())
				{
					for (FNavPathPoint point : PathResult.Path->GetPathPoints())
					{
						Result.Add(point.Location);
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Pathfinding failed."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Can't find navigation system."));
		}

	}
	else UE_LOG(LogTemp, Log, TEXT("INvalid Query."));
	return Result;
}
