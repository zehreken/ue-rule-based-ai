// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_FindCover.generated.h"

UCLASS()
class UERULEBASEDAI_API UBTService_FindCover : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_FindCover();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
