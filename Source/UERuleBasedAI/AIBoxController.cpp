// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBox.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "AIBoxController.h"

void AAIBoxController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAIBox* Box = Cast<AAIBox>(InPawn);
	if (!Box || !Box->BehaviorTree) return;

	RunBehaviorTree(Box->BehaviorTree);   // creates the Blackboard + BT components
}