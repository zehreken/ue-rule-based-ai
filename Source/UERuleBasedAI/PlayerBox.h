// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBox.generated.h"

UCLASS()
class UERULEBASEDAI_API APlayerBox : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputMappingContext* DefaultContext;
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveW;
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveS;
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveA;
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveD;

	void Move(const struct FInputActionValue& Value, FVector WorldDir);
};
