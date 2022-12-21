// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Boss1_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOSSARENA_API UBoss1_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UBoss1_AnimInstance();
	//ABP 움직임 관리
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	//속도 변수
	float Speed;

};
