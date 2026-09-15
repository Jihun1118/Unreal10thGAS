// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/Test01/Test01.h"
#include "Test/TestCharacter.h"
#include "GAS/StatAttributeSet.h"

void ATest01::ModifyHealth()
{
	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target is NULL!!!"));
		return;
	}

	UStatAttributeSet* Stat = Target->GetStatAttribute();
	if (!Stat)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target은 StatAttribute를 안가지고 있습니다!!!"));
		return;
	}

	const float NewHealth = Stat->GetHealth() + TestValue;
	Stat->SetHealth(NewHealth);	// 실구현에서 하지 말것
}

void ATest01::ResetHealth()
{
	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target is NULL!!!"));
		return;
	}

	UStatAttributeSet* Stat = Target->GetStatAttribute();
	if (!Stat)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target은 StatAttribute를 안가지고 있습니다!!!"));
		return;
	}

	Stat->SetHealth(Stat->GetMaxHealth());
}