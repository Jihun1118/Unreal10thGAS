// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Framework/TestGASHUD.h"

ATestPlayerCharacter::ATestPlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}

void ATestPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (APlayerController* PC = Cast<APlayerController>(NewController))
	{
		// 플레이어 일때만 처리
		if (ATestGASHUD* TestGASHUD = Cast<ATestGASHUD>(PC->GetHUD()))
		{
			TestGASHUD->InitHUD(this);	// 레이스 컨디션 대비
		}
	}
}
