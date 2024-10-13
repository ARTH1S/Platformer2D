// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyBase::AEnemyBase()
{
	Health = FullHealth;
	IsDead = false;
	
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	// Подписываемся на событие OnTakeAnyDamage
	OnTakeAnyDamage.AddDynamic(this, &AEnemyBase::onTakeAnyDamage);
}

void AEnemyBase::onTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Health > 0)
	{
		Health -= Damage;
	}
	else // PLAYER DEAD
	{
		Health = 0;
		IsDead = true;
		// TODO: ENEMY DIED FUNCTION
	}
	if (GEngine) 
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("take damage func!"));
}
