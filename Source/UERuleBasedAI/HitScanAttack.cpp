// Fill out your copyright notice in the Description page of Project Settings.


#include "HitScanAttack.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHitScanAttack::UHitScanAttack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UHitScanAttack::Fire()
{
	AActor* Owner = GetOwner();
	const FVector Start = Owner->GetActorLocation();
	const FVector End = Start + Owner->GetActorForwardVector() * Range;

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Owner);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AActor* HitActor = Hit.GetActor())
		{
			UGameplayStatics::ApplyPointDamage(HitActor, Damage, Owner->GetActorForwardVector(), Hit,
			                                   Owner->GetInstigatorController(), Owner, nullptr);
		}
	}

	DrawDebugLine(GetWorld(), Start, Hit.bBlockingHit ? Hit.Location : End, FColor::Red, false, 0.4f, 0, 2.0f);
}


// Called when the game starts
void UHitScanAttack::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UHitScanAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
