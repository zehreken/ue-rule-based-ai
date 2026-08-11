// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/GeneratedNavLinksProxy.h"
#include "GeneratedNavLinksProxyJump.generated.h"

/**
 * Handles the jump links the navmesh generates by itself (as opposed to hand-placed ANavLinkProxy).
 * Set this class as LinkProxyClass on RecastNavMesh > Generation > Nav Link Jump Configs,
 * with "Generate Nav Links" enabled, then rebuild navigation.
 */
UCLASS(Blueprintable)
class UERULEBASEDAI_API UGeneratedNavLinksProxyJump : public UGeneratedNavLinksProxy
{
	GENERATED_BODY()

public:
	// 0 = flat/fast arc, 1 = high lob
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NavLink|Jump", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ArcParam = 0.5f;

	/** Horizontal speed used when no ballistic solution exists for the link. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NavLink|Jump", meta = (ClampMin = "0.0"))
	float FallbackHorizontalSpeed = 600.f;

	/**
	 * UGeneratedNavLinksProxy is MinimalAPI and its GetWorld() is not exported from AIModule,
	 * so a subclass living in another module has to override it — otherwise the subclass vtable
	 * references a symbol it cannot link against.
	 */
	virtual UWorld* GetWorld() const override;

	virtual bool OnLinkMoveStarted(UObject* PathComp, const FVector& DestPoint) override;
};
