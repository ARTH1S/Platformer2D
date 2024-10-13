// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMED2D_API AEnemyBase : public APaperCharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void onTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, 
		AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(VisibleAnywhere)
	float Health = 0.0f;

	UPROPERTY(VisibleAnywhere)
	float FullHealth = 100.0f;

	UPROPERTY(VisibleAnywhere)
	bool IsDead;

private:

};
