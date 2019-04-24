// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPCharacterBase.generated.h"

UCLASS()
class STUDYPROJECT_API ASPCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASPCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// DefaultPawn 참고
	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void MoveForward(float Val);

	// DefaultPawn 참고
	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void ZoomIn();

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void ZoomOut();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

	// 줌 정도
	float ZoomValue;

};
