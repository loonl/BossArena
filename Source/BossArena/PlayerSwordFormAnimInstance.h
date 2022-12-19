// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerSwordFormAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOSSARENA_API UPlayerSwordFormAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPlayerSwordFormAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	// ------------------------------------------------------
	// Animation 관련 변수
	// ------------------------------------------------------
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool isFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		UAnimMontage* animMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float horizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float vertical;

};
