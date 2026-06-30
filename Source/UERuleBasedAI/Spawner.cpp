// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBox.h"
#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		SpawnTimerHandle, this, &ASpawner::Spawn, SpawnPeriod, true);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawner::Spawn()
{
	FVector Location = GetActorLocation();
	AAIBox* Enemy = GetWorld()->SpawnActor<AAIBox>(SpawnClass,
	                                               FVector(Location.X, Location.Y,
	                                                       150.0f),
	                                               FRotator::ZeroRotator);
}
