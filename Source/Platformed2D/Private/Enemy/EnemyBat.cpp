// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBat.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SceneComponent.h"
#include "PaperFlipbookComponent.h"

AEnemyBat::AEnemyBat()
{
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		MovementComponent->DefaultLandMovementMode = EMovementMode::MOVE_Flying;
	}

	SelectSideMovement = FMath::RandBool();

}

void AEnemyBat::BeginPlay()
{
	Super::BeginPlay();

	UpdateFacingDirection();
}


void AEnemyBat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ChoosingSide();

	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), MoveSide);
}

void AEnemyBat::ChoosingSide()
{
	if (SelectSideMovement)
		MoveSide = MoveRight;
	else
		MoveSide = MoveLeft;
}

void AEnemyBat::UpdateFacingDirection()
{
	UPaperFlipbookComponent* Sprite = GetSprite();
	if (Sprite)
	{
		FVector ActorScale = GetActorScale3D();
		Sprite->SetWorldScale3D(ActorScale);
		FVector ChangedSide(FMath::Abs(ActorScale.X) * MoveSide, ActorScale.Y, ActorScale.Z); 

	}



	//UPaperFlipbookComponent* Sprite = GetSprite();
	//Sprite = GetActorScale();
	

//	SetActorScale3D(ChangedSide);
}
