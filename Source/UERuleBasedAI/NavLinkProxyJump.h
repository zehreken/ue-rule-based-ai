// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "NavLinkProxyJump.generated.h"

class UNavLinkCustomComponent;
/**
 * 
 */
UCLASS()
class UERULEBASEDAI_API ANavLinkProxyJump : public ANavLinkProxy
{
	GENERATED_BODY()

public:
	ANavLinkProxyJump(const FObjectInitializer& ObjectInitializer);

protected:
	void HandleLinkReached(UNavLinkCustomComponent* LinkComp, UObject* PathingAgent, const FVector& DestPoint);

	// 0 = flat/fast arc, 1 = high lob
	UPROPERTY(EditAnywhere, Category = "Navlink|Jump", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ArcParam = 0.5f;
};
