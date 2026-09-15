// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Test/TestBaseActor.h"
#include "Test01.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL10THGAS_API ATest01 : public ATestBaseActor
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor, Category = "GAS|Test")
	void ModifyHealth();

	UFUNCTION(CallInEditor, Category = "GAS|Test")
	void ResetHealth();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|Test")
	float TestValue = 10.0f;
};
