// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "EnemyBat.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMED2D_API AEnemyBat : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AEnemyBat();
	virtual void Tick(float DeltaTime) override;

	void ChoosingSide();

	UFUNCTION(BlueprintCallable, Category = "Flipbook")
	void UpdateFacingDirection();

protected:
	virtual void BeginPlay() override;

private:
	bool SelectSideMovement;

	int MoveSide;
	int MoveRight = 1;
	int MoveLeft = -1;
};
