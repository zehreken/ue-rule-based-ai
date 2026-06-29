// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_FindPlayer::UBTService_FindPlayer()
{
	NodeName = "Find Player";
	Interval = 0.5f;          // run twice a second; no need every frame
	RandomDeviation = 0.1f;   // jitter so many grunts don't all tick on the same frame
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB) return;

	APawn* Player = UGameplayStatics::GetPlayerPawn(OwnerComp.GetWorld(), 0);
	BB->SetValueAsObject(TargetKey.SelectedKeyName, Player);
}