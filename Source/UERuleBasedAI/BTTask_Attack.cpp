// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"

#include "AIController.h"
#include "AIBox.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Cont = OwnerComp.GetAIOwner();
	if (!Cont) return EBTNodeResult::Failed;

	AAIBox* Box = Cast<AAIBox>(Cont->GetPawn());
	if (!Box) return EBTNodeResult::Failed;

	Box->Fire();
	return EBTNodeResult::Succeeded;
}
