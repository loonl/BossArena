// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCustomController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSARENA_API APlayerCustomController : public APlayerController
{

	GENERATED_BODY()

public:
	APlayerCustomController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

	// test
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;


	// ------------------------------------------------------
	// Input�� ���ε��� �Լ�
	// ------------------------------------------------------
public:
	void Jump();
	void MoveForward(float value);
	void MoveRight(float value);
	void Yaw(float value);
	void Pitch(float value);

	// test
	void GetDamaged();

	// ------------------------------------------------------
	// private �Ϲ� �Լ�
	// ------------------------------------------------------
private:
	// Init ���� �Լ� - ������ �κ� ������ ���
	void InitCameraClass();


	// ------------------------------------------------------
	// private �Ϲ� ����
	// ------------------------------------------------------
};
