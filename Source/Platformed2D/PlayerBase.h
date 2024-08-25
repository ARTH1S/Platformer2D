// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Characters/CharacterMovement.h"
#include "PlayerBase.generated.h"

class UArrowComponent;
class USpringArmComponent;
class UCameraComponent;
class UPaperFlipbook;
class UPaperFlipbookComponent;

UCLASS()
class PLATFORMED2D_API APlayerBase : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	APlayerBase();
	virtual void Tick(float DeltaTime) override;

	/*
	================
		MOVEMENT
	================
	*/

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveRight(float Value);
	void Jump() override;

	UFUNCTION(BlueprintCallable, Category = "Flipbook")
	void UpdateAnimation();

	UFUNCTION(BlueprintCallable, Category = "Flipbook")
	void UpdateRotation();

protected:
	virtual void BeginPlay() override; 

	/*********** PAPERS **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* RunAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* JumpAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* FallAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* DefaultAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbookComponent* FPComponent;

private: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere)
	float Health = 0;
	
	UPROPERTY(VisibleAnywhere)
	float FullHealth = 100;


};
