// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/TestGASHUD.h"
#include "Widget/HUDWidget.h"
#include "Blueprint/UserWidget.h"

void ATestGASHUD::InitHUD(APawn* InPawn)
{
	if (!InPawn) return;
	if (!HUDWidgetClass) return;
	APlayerController* PC = GetOwningPlayerController();
	if (!PC) return;

	if (!HUDWidget)
	{
		HUDWidget = CreateWidget<UHUDWidget>(PC, HUDWidgetClass);
		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
			HUDWidget->InitializeWithAbilitySystem(InPawn);
		}
	}
}

void ATestGASHUD::BeginPlay()
{
	Super::BeginPlay();

	if (APawn* OwningPawn = GetOwningPawn())
	{
		InitHUD(OwningPawn);
	}
}
