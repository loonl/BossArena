// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerSwordFormCharacter.generated.h"

UCLASS()
class BOSSARENA_API APlayerSwordFormCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerSwordFormCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// ------------------------------------------------------
	// Input에 바인딩할 함수
	// ------------------------------------------------------
public:
	void MoveForward(float value);
	void MoveRight(float value);
	void Yaw(float value);

	// ------------------------------------------------------
	// Movement 관련 변수
	// ------------------------------------------------------
public:
	UPROPERTY()
		float horizontalValue = 0.f;

	UPROPERTY()
		float verticalValue = 0.f;


	// ------------------------------------------------------
	// private 일반 함수
	// ------------------------------------------------------
private:
	// Init 관련 함수 - 생성자 부분 가독성 향상
	void InitArm_Camera();
	void InitMesh();
	void InitControllerRotation();


	// ------------------------------------------------------
	// private 일반 변수
	// ------------------------------------------------------
private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* camera;

};
