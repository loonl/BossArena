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
	// Input�� ���ε��� �Լ�
	// ------------------------------------------------------
public:
	void MoveForward(float value);
	void MoveRight(float value);
	void Yaw(float value);

	// ------------------------------------------------------
	// Movement ���� ����
	// ------------------------------------------------------
public:
	UPROPERTY()
		float horizontalValue = 0.f;

	UPROPERTY()
		float verticalValue = 0.f;


	// ------------------------------------------------------
	// private �Ϲ� �Լ�
	// ------------------------------------------------------
private:
	// Init ���� �Լ� - ������ �κ� ������ ���
	void InitArm_Camera();
	void InitMesh();
	void InitControllerRotation();


	// ------------------------------------------------------
	// private �Ϲ� ����
	// ------------------------------------------------------
private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* camera;

};
