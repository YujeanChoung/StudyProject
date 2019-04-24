// Fill out your copyright notice in the Description page of Project Settings.

#include "SPPlayerController.h"


void ASPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameAndUI());
}