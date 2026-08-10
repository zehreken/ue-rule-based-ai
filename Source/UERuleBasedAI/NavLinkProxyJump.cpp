// Fill out your copyright notice in the Description page of Project Settings.


#include "NavLinkProxyJump.h"
#include "NavLinkCustomComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

ANavLinkProxyJump::ANavLinkProxyJump(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GetSmartLinkComp()->SetMoveReachedLink(this, &ANavLinkProxyJump::HandleLinkReached);

	bSmartLinkIsRelevant = true;
}

void ANavLinkProxyJump::HandleLinkReached(UNavLinkCustomComponent* LinkComp, UObject* PathingAgent,
                                          const FVector& DestPoint)
{
	UPathFollowingComponent* PFComp = Cast<UPathFollowingComponent>(PathingAgent);

	auto Resume = [&]()
	{
		if (PFComp)
		{
			PFComp->FinishUsingCustomLink(LinkComp);
		}
	};

	ACharacter* Character = nullptr;
	if (PFComp)
	{
		AActor* O = PFComp->GetOwner();
		if (AController* C = Cast<AController>(O))
		{
			Character = Cast<ACharacter>(C->GetPawn());
		}
		else
		{
			Character = Cast<ACharacter>(O);
		}
	}

	if (!Character)
	{
		Resume();
		return;
	}

	const FVector Start = Character->GetActorLocation();

	if (DestPoint.Z <= Start.Z + 1.0f)
	{
		Resume();
		return;
	}

	FVector LaunchVel = FVector::ZeroVector;
	const bool bSolved = UGameplayStatics::SuggestProjectileVelocity_CustomArc(
		this, LaunchVel, Start, DestPoint, 0.0f, ArcParam);

	if (bSolved)
	{
		Character->LaunchCharacter(LaunchVel, true, true);
	}
	else
	{
		Character->SetActorLocation(DestPoint, false, nullptr, ETeleportType::TeleportPhysics);
	}

	Resume();
}
