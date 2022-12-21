// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSwordFormAnimInstance.h"
#include "PlayerSwordFormCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

UPlayerSwordFormAnimInstance::UPlayerSwordFormAnimInstance()
{
}

void UPlayerSwordFormAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// Pawn 찾아서 veritcal, horizontal value 넣어주기
	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		speed = pawn->GetVelocity().Size();

		// Pawn을 PlayerSwordCharacter로 형변환
		auto character = Cast<APlayerSwordFormCharacter>(pawn);
		if (character)
		{
			isFalling = character->GetMovementComponent()->IsFalling();

			vertical = character->verticalValue;
			horizontal = character->horizontalValue;
		}
	}
}

