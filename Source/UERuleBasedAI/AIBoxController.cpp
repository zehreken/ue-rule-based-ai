// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBoxController.h"
#include "AIBox.h"
#include "NavigationSystem.h"

void AAIBoxController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAIBox* Box = Cast<AAIBox>(InPawn);
	if (!Box || !Box->BehaviorTree) return;

	RunBehaviorTree(Box->BehaviorTree);   // creates the Blackboard + BT components
}