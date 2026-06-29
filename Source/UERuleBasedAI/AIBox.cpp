// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBox.h"

// Sets default values
AAIBox::AAIBox()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIBox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

