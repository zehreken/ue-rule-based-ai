// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "NavigationSystem.h"
#include "AIBoxController.h"

void AAIBoxController::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TH;
	GetWorldTimerManager().SetTimer(TH, this, &AAIBoxController::TryMove, 2.0f, false);
}

void AAIBoxController::TryMove()
{
	APawn* P = GetPawn();
	if (!P) { UE_LOG(LogTemp, Warning, TEXT("TryMove: no pawn")); return; }

	UNavigationSystemV1* Nav = UNavigationSystemV1::GetCurrent(GetWorld());
	ANavigationData* Data = Nav ? Nav->GetDefaultNavDataInstance() : nullptr;
	UE_LOG(LogTemp, Warning, TEXT("Nav=%s  NavData=%s"),
		*GetNameSafe(Nav), *GetNameSafe(Data));

	const FVector Dest = P->GetActorLocation() + P->GetActorForwardVector() * 500.f;
	EPathFollowingRequestResult::Type R =
		MoveToLocation(Dest, -1.f, true, true, /*bProjectDestinationToNavigation=*/ true);
	UE_LOG(LogTemp, Warning, TEXT("MoveTo result=%d"), (int32)R);
}