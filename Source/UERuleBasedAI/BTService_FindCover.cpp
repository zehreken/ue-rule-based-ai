// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_FindCover.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


UBTService_FindCover::UBTService_FindCover()
{
}

void UBTService_FindCover::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB) return;

	APawn* Player = UGameplayStatics::GetPlayerPawn(OwnerComp.GetWorld(), 0);
	if (!Player) return;

	TArray<AActor*> CoverActors;
	UGameplayStatics::GetAllActorsWithTag(OwnerComp.GetWorld(), FName("Cover"), CoverActors);

	FVector PlayerLocation = Player->GetActorLocation();
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Player);
	bool bCoverFound = false;
	FVector CoverLocation;

	for (AActor* CoverActor : CoverActors)
	{
		bool bHit = OwnerComp.GetWorld()->LineTraceSingleByChannel(HitResult, PlayerLocation,
		                                                           CoverActor->GetActorLocation(),
		                                                           ECC_Visibility, QueryParams);
		if (bHit) // This means there is an obstacle between the cover and the player, so enemy can hide
		{
			bCoverFound = true;
			CoverLocation = CoverActor->GetActorLocation();
			break;
		}
	}

	BB->SetValueAsBool(CoverFoundKey.SelectedKeyName, bCoverFound);
	BB->SetValueAsVector(CoverLocationKey.SelectedKeyName, CoverLocation);
}
