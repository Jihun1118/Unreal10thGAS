// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/Test02/Test02_1.h"
#include "Test/TestCharacter.h"
#include "AbilitySystemComponent.h"
#include "GAS/StatAttributeSet.h"

void ATest02_1::ApplyGameplayEffect()
{
	if (!Target) return;
	if (!GameplayEffectClass) return;

	UAbilitySystemComponent* TargetASC = Target->GetAbilitySystemComponent();
	if (!TargetASC) return;

	// 컨택스트 설정(이펙트의 정보들을 설정)
	FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	EffectContext.AddInstigator(this, this);

	// 이팩트 스팩 설정
	FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, EffectLevel, EffectContext);
	if (!SpecHandle.IsValid()) return;

	// TargetASC가 자기자신에게 스팩 적용
	FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	//if (ActiveEffectHandle.WasSuccessfullyApplied())
	//{
	//	// 성공
	//}
	//else
	//{
	//	// 실패
	//}
	
	// 이펙트 개별 제거는 아래와 같이
	//TargetASC->RemoveActiveGameplayEffect(ActiveEffectHandle);
}

void ATest02_1::RemoveAllEffects()
{
	if (!Target) return;

	UAbilitySystemComponent* TargetASC = Target->GetAbilitySystemComponent();
	if (!TargetASC) return;

	FGameplayEffectQuery Query;	// 모든 것
	TargetASC->RemoveActiveEffects(Query);	// 모든 이펙트 삭제
}

void ATest02_1::ResetTarget()
{
	RemoveAllEffects();

	if (!Target) return;
	UStatAttributeSet* Stat = Target->GetStatAttribute();
	Stat->SetHealth(Stat->GetHealth());
}
