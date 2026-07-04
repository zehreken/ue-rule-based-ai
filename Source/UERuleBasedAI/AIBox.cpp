// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBox.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAIBox::AAIBox()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	HitScanAttack = CreateDefaultSubobject<UHitScanAttack>(TEXT("HitScanAttack"));
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

void AAIBox::Fire()
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;

	if (!HitScanAttack)
	{
		UE_LOG(LogTemp, Display, TEXT("HitScanAttack not found"));
	}
	else
	{
		HitScanAttack->Fire();
	}
}

float AAIBox::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
                         AActor* DamageCauser)
{
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= Applied;
	if (Health <= 0.f) Destroy(); // later: a death state / color flash
	return Applied;
}

// Called to bind functionality to input
void AAIBox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
