// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedNavLinksProxyJump.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/PathFollowingComponent.h"

UWorld* UGeneratedNavLinksProxyJump::GetWorld() const
{
	// Do NOT call Super::GetWorld() — that symbol is not exported from AIModule (unresolved external).
	// ARecastNavMesh::CreateAndRegisterJumpLinksProxy creates the proxy with the navmesh as outer,
	// so the outer chain resolves to the right world in both PIE and the editor.
	const UObject* MyOuter = GetOuter();
	return MyOuter ? MyOuter->GetWorld() : nullptr;
}

bool UGeneratedNavLinksProxyJump::OnLinkMoveStarted(UObject* PathComp, const FVector& DestPoint)
{
	UPathFollowingComponent* PFComp = Cast<UPathFollowingComponent>(PathComp);
	if (!PFComp)
	{
		return false;
	}

	ACharacter* Agent = nullptr;
	AActor* PathOwner = PFComp->GetOwner();
	if (const AController* Ctrl = Cast<AController>(PathOwner))
	{
		Agent = Cast<ACharacter>(Ctrl->GetPawn());
	}
	else
	{
		Agent = Cast<ACharacter>(PathOwner);
	}

	if (!Agent)
	{
		// Not a character — let path following walk the link the default way.
		return false;
	}

	const FVector Start = Agent->GetActorLocation();

	FVector LaunchVel = FVector::ZeroVector;
	if (!UGameplayStatics::SuggestProjectileVelocity_CustomArc(
		this, LaunchVel, Start, DestPoint, /*OverrideGravityZ (0 = world gravity)*/0.f, ArcParam))
	{
		// No ballistic solution (very short or near-vertical link): approximate with a plain jump.
		const UCharacterMovementComponent* Movement = Agent->GetCharacterMovement();
		LaunchVel = (DestPoint - Start).GetSafeNormal2D() * FallbackHorizontalSpeed;
		LaunchVel.Z = Movement ? Movement->JumpZVelocity : 500.f;
	}

	Agent->LaunchCharacter(LaunchVel, /*bXYOverride*/true, /*bZOverride*/true);

	// The launch is instantaneous and path following is never blocked by a custom link
	// (UPathFollowingComponent::FollowPathSegment keeps steering regardless), so release the
	// link immediately instead of holding it for the duration of the jump.
	PFComp->FinishUsingCustomLink(this);

	return true;
}
