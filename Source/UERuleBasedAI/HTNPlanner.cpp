// Fill out your copyright notice in the Description page of Project Settings.


#include "HTNPlanner.h"

#include "AIController.h"

// Sets default values for this component's properties
UHTNPlanner::UHTNPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHTNPlanner::BeginPlay()
{
	Super::BeginPlay();

	AAIController* OwnerController = Cast<AAIController>(GetOwner());
	if (OwnerController)
	{
		// Cache the blackboard pointer
		Blackboard = OwnerController->GetBlackboardComponent();
		if (Blackboard)
		{
			UE_LOG(LogTemp, Display, TEXT("Found blackboard component"));
		}
	}
}


// Called every frame
void UHTNPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FName name = FName(TEXT("Distance"));
	float Distance = Blackboard->GetValueAsFloat(name);
}
