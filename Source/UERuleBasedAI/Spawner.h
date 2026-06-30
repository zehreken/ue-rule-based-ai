// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AAIBox;

UCLASS()
class UERULEBASEDAI_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AAIBox> SpawnClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	float SpawnPeriod = 5.0f;
	
	FTimerHandle SpawnTimerHandle;

	void Spawn();
};
