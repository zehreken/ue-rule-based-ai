// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIBox.generated.h"

UENUM(BlueprintType)
enum class ECombatRange : uint8
{
	TooClose,
	InRange,
	TooFar
};

UCLASS()
class UERULEBASEDAI_API AAIBox : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, Category = "AI")
	float ChaseRange;

	UPROPERTY(EditAnywhere, Category = "AI")
	float RunAwayRange;
};
