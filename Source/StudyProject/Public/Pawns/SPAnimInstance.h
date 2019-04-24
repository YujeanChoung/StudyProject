// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API USPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	USPAnimInstance();	

	virtual void NativeUpdateAnimation(float DeltaSecond) override;
	
private:
	/** 폰 스피드 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentSpeed;

	/** 공중에 있는가 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	/** 죽었는가 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
