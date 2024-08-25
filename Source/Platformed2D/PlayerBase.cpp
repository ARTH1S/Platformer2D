// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

#include "PaperFlipbookComponent.h"


APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject <USpringArmComponent>(TEXT("SringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 600.f;
	if (SpringArm)
	{
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bInheritRoll = false;
	}
	
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);


	/* огран по оси Y, что бы перс не выпал */
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.f, 1.f, 0.f));
	
	// Config character capsule
	GetCapsuleComponent()->SetCapsuleHalfHeight(52.8f);
	GetCapsuleComponent()->SetCapsuleRadius(42.f);


	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
}

void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();
	UpdateRotation();
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &APlayerBase::Jump);
}

void APlayerBase::MoveRight(float Value)
{
	/*const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);*/

	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void APlayerBase::Jump()
{
	Super::Jump();
}

void APlayerBase::UpdateAnimation()
{
	//Check if NOT moving, in air or ground
	if (GetCharacterMovement()->Velocity.Size() != 0)
	{
		//Check Ground Movement 
		if (GetCharacterMovement()->IsFalling())
		{
			//Check for Air Movement/Velocity
			if (GetCharacterMovement()->Velocity.Z <= 0) GetSprite()->SetFlipbook(FallAnimation);
			else GetSprite()->SetFlipbook(JumpAnimation);
		}
		else GetSprite()->SetFlipbook(RunAnimation);
	}
	else GetSprite()->SetFlipbook(IdleAnimation);
}


void APlayerBase::UpdateRotation()
{

		const FVector PlayerVelocity = GetVelocity();
		float TravelDirection = PlayerVelocity.X;
		if (Controller != nullptr)
		{
			if (TravelDirection < 0.0f)
			{
				Controller->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));
			}
			else if (TravelDirection > 0.0f)
			{
				Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
			}
		}
}


void APlayerBase::BeginPlay()
{
	Super::BeginPlay();


}
