// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBoxController.h"
#include "AIBox.h"
#include "NavigationSystem.h"

AAIBoxController::AAIBoxController()
{
	HTNPlanner = CreateDefaultSubobject<UHTNPlanner>(TEXT("HTNPlanner"));
}

void AAIBoxController::BeginPlay()
{
	Super::BeginPlay();
}

void AAIBoxController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAIBox* Box = Cast<AAIBox>(InPawn);
	if (!Box || !Box->BehaviorTree) return;

	RunBehaviorTree(Box->BehaviorTree);   // creates the Blackboard + BT components
}
