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
	//�ΰ����� ���
	ABoss1_AIController();

	virtual void OnPossess(APawn* InPawn) override; //���� on
	virtual void OnUnPossess() override; //���� off

private: 
	//�����̵� ����
	void RandomMove();

private:
	FTimerHandle TimerHandle;

};
