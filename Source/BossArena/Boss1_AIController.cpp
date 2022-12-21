// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss1_AIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

//�ΰ����� ������
ABoss1_AIController::ABoss1_AIController()
{

}

//�ΰ����� ����
void ABoss1_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//7�ʿ� �ѹ��� RandomMove ȣ��
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoss1_AIController::RandomMove, 5.f, true);
}

//�ΰ����� ���� ����
void ABoss1_AIController::OnUnPossess()
{
	Super::OnUnPossess();

	//ȣ���� Ÿ�̸�(RandomMove) ����
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

}

//�����̵� Ai �Լ�
void ABoss1_AIController::RandomMove()
{
	auto CurrentPawn = GetPawn();
	//�׺���̼� �ý���
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;

	//������ �������� 650 �Ÿ����� �̵�
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 650, RandomLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}