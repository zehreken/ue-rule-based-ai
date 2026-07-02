// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBox.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
APlayerBox::APlayerBox()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	if (UCharacterMovementComponent* const CM = GetCharacterMovement())
	{
		CM->bOrientRotationToMovement = false;
	}
}

// Called when the game starts or when spawned
void APlayerBox::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		PC->bShowMouseCursor = true;
		if (auto* Subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsys->AddMappingContext(DefaultContext, 0);
		}
	}
}

// Called every frame
void APlayerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) return;

	FVector WorldLoc, WorldDir;
	if (!PC->DeprojectMousePositionToWorld(WorldLoc, WorldDir)) return;

	// Intersect the camera ray with the horizontal plane at the box's height
	if (FMath::IsNearlyZero(WorldDir.Z)) return;
	const float T = (GetActorLocation().Z - WorldLoc.Z) / WorldDir.Z;
	if (T <= 0.f) return;
	const FVector AimPoint = WorldLoc + WorldDir * T;

	FVector ToAim = AimPoint - GetActorLocation();
	ToAim.Z = 0.f;
	if (ToAim.IsNearlyZero()) return;

	SetActorRotation(FRotator(0.f, ToAim.Rotation().Yaw, 0.f));
}

// Called to bind functionality to input
void APlayerBox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveBack, ETriggerEvent::Triggered, this, &APlayerBox::Move, FVector(-1, 0, 0));
		EIC->BindAction(MoveForward, ETriggerEvent::Triggered, this, &APlayerBox::Move, FVector(1, 0, 0));
		EIC->BindAction(MoveRight, ETriggerEvent::Triggered, this, &APlayerBox::Move, FVector(0, 1, 0));
		EIC->BindAction(MoveLeft, ETriggerEvent::Triggered, this, &APlayerBox::Move, FVector(0, -1, 0));
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
}

void APlayerBox::Move(const struct FInputActionValue& Value, FVector WorldDir)
{
	AddMovementInput(WorldDir, 1.f);
}
