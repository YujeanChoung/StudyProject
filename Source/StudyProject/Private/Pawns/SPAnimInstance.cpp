// Fill out your copyright notice in the Description page of Project Settings.

#include "SPAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"


USPAnimInstance::USPAnimInstance()
	: Super()
{
	CurrentSpeed = 0.0f;
	IsInAir = false;
	IsDead = false;
}

void USPAnimInstance::NativeUpdateAnimation(float DeltaSecond)
{
	Super::NativeUpdateAnimation(DeltaSecond);

	APawn* Pawn = TryGetPawnOwner();
	if (false == ::IsValid(Pawn))
	{
		return;
	}

	if (false == IsDead)
	{		
		CurrentSpeed = Pawn->GetVelocity().Size();
		//UE_LOG(LogClass, Warning, TEXT("Speed: %f"), CurrentSpeed);

		ACharacter* Character = Cast<ACharacter>(Pawn);
		if (nullptr != Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}