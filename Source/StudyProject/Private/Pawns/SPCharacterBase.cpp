// Fill out your copyright notice in the Description page of Project Settings.

#include "SPCharacterBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ASPCharacterBase::ASPCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	ZoomValue = 50.0f;
}

// Called when the game starts or when spawned
void ASPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASPCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASPCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASPCharacterBase::Jump);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ASPCharacterBase::ZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ASPCharacterBase::ZoomOut);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASPCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASPCharacterBase::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

// MoveFoward ÀÎÇ² ¹ÙÀÎµù
void ASPCharacterBase::MoveForward(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}
}

// MoveRight ÀÎÇ² ¹ÙÀÎµù
void ASPCharacterBase::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
		}
	}
}

// ZoomIn ÀÎÇ² ¹ÙÀÎµù
void ASPCharacterBase::ZoomIn()
{
	SpringArm->TargetArmLength -= ZoomValue;
}

// ZoomOut ÀÎÇ² ¹ÙÀÎµù
void ASPCharacterBase::ZoomOut()
{
	SpringArm->TargetArmLength += ZoomValue;
}