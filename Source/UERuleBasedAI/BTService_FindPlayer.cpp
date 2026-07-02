// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindPlayer.h"

#include "AIBox.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_FindPlayer::UBTService_FindPlayer()
{
	NodeName = "Find Player";
	Interval = 0.5f; // run twice a second; no need every frame
	RandomDeviation = 0.1f; // jitter so many grunts don't all tick on the same frame
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB) return;

	APawn* Player = UGameplayStatics::GetPlayerPawn(OwnerComp.GetWorld(), 0);
	if (!Player) return;

	AActor* Self = OwnerComp.GetAIOwner()->GetPawn();
	const float Dist = FVector::Dist(Self->GetActorLocation(), Player->GetActorLocation());

	AAIBox* Box = Cast<AAIBox>(Self);
	if (!Box) return;
	ECombatRange CombatRange;
	FVector EscapeLocation;
	if (Dist < Box->RunAwayRange)
	{
		CombatRange = ECombatRange::TooClose;
		FVector EscapeDirection = (Self->GetActorLocation() - Player->GetActorLocation()).GetSafeNormal();
		EscapeLocation = Self->GetActorLocation() + EscapeDirection * 500.0f;
		DrawDebugDirectionalArrow(GetWorld(), Self->GetActorLocation(), EscapeLocation, 10.0f, FColor::Red, false,
		                          0.4f, 0.0f, 5.0f);
	}
	else if (Dist > Box->ChaseRange)
		CombatRange = ECombatRange::TooFar;
	else
		CombatRange = ECombatRange::InRange;

	BB->SetValueAsObject(TargetKey.SelectedKeyName, Player);
	BB->SetValueAsFloat(DistanceKey.SelectedKeyName, Dist);
	BB->SetValueAsEnum(CombatRangeKey.SelectedKeyName, static_cast<uint8>(CombatRange));
	BB->SetValueAsVector(EscapeLocationKey.SelectedKeyName, EscapeLocation);
}
