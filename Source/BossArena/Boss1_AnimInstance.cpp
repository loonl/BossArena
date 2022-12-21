 // Fill out your copyright notice in the Description page of Project Settings.


#include "Boss1_AnimInstance.h"
#include "Boss1.h"

//�ִϸ��̼� �ν��Ͻ� ������
UBoss1_AnimInstance::UBoss1_AnimInstance()
{

}
void UBoss1_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn)) {
		Speed = Pawn->GetVelocity().Size();
	}
}
