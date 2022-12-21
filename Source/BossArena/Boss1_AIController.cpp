// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss1_AIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

//인공지능 생성자
ABoss1_AIController::ABoss1_AIController()
{

}

//인공지능 빙의
void ABoss1_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//7초에 한번씩 RandomMove 호출
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoss1_AIController::RandomMove, 5.f, true);
}

//인공지능 빙의 해제
void ABoss1_AIController::OnUnPossess()
{
	Super::OnUnPossess();

	//호출한 타이머(RandomMove) 해제
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

}

//랜덤이동 Ai 함수
void ABoss1_AIController::RandomMove()
{
	auto CurrentPawn = GetPawn();
	//네비게이션 시스템
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;

	//무작위 방향으로 650 거리까지 이동
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 650, RandomLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}