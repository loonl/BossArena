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
	// Input에 바인딩할 함수
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
	// private 일반 함수
	// ------------------------------------------------------
private:
	// Init 관련 함수 - 생성자 부분 가독성 향상
	void InitCameraClass();


	// ------------------------------------------------------
	// private 일반 변수
	// ------------------------------------------------------
};
