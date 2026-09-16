// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestEnemyCharacter.h"
#include "Widget/OverHeadWidget.h"
#include "AbilitySystemComponent.h"
#include "Components/WidgetComponent.h"

ATestEnemyCharacter::ATestEnemyCharacter()
{
	OverHeadWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidgetComp"));
	OverHeadWidgetComponent->SetupAttachment(RootComponent);

	OverHeadWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	OverHeadWidgetComponent->SetDrawSize(FVector2D(150.0f, 20.0f));
	OverHeadWidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	OverHeadWidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ATestEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
	if (IsValid(AbilitiSystemComponent))
	{
		AbilitiSystemComponent->InitAbilityActorInfo(this, this);
		InitializeOverHeadWidget();
	}
}

void ATestEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	UE_LOG(LogTemp, Log, TEXT("PossessedBy"));
	
}

void ATestEnemyCharacter::InitializeOverHeadWidget()
{
	if (!OverHeadWidgetComponent) return;

	UE_LOG(LogTemp, Log, TEXT("OverHeadWidgetComponent 있음"));

	if (UUserWidget* UserWidget = OverHeadWidgetComponent->GetUserWidgetObject())
	{
		UE_LOG(LogTemp, Log, TEXT("UserWidget 있음"));
		if (UOverHeadWidget* OverHeadWidget = Cast<UOverHeadWidget>(UserWidget))
		{
			UE_LOG(LogTemp, Log, TEXT("UOverHeadWidget 캐스트 성공"));
			OverHeadWidget->InitializeWithAbilitySystem(this);
		}
	}
}
