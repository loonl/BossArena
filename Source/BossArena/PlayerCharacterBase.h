// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterBase.generated.h"

UCLASS()
class BOSSARENA_API APlayerCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ------------------------------------------------------
	// Init 관련 함수	
	// ------------------------------------------------------
protected:
	virtual void InitMesh();
	void InitArmandCamera();
	void InitRotationSettings();
	void InitBindComponent();


	// ------------------------------------------------------
	// Movement 관련 변수
	// ------------------------------------------------------
private:
	UPROPERTY()
		float horizontalValue = 0.f;

	UPROPERTY()
		float verticalValue = 0.f;

	// ------------------------------------------------------
	// Getter & Setter	
	// ------------------------------------------------------
public:
	float GetHorizontalValue();
	float GetVerticalValue();
	void SetHorizontalValue(float value);
	void SetVerticalValue(float value);

	// test
	void GetDamaged(int32 damage);


	// ------------------------------------------------------
	// private 변수
	// ------------------------------------------------------
private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere)
	class UPlayerCharacterBaseStatComponent* statComp;
};
