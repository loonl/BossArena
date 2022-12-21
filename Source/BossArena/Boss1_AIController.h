// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Boss1_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSARENA_API ABoss1_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	//인공지능 모듈
	ABoss1_AIController();

	virtual void OnPossess(APawn* InPawn) override; //빙의 on
	virtual void OnUnPossess() override; //빙의 off

private: 
	//랜덤이동 구현
	void RandomMove();

private:
	FTimerHandle TimerHandle;

};
