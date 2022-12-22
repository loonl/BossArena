// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterBase.h"
#include "PlayerSwordFormCharacter.generated.h"

UCLASS()
class BOSSARENA_API APlayerSwordFormCharacter : public APlayerCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerSwordFormCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;


	// ------------------------------------------------------
	// Init ÇÔ¼ö
	// ------------------------------------------------------
private:
	virtual void InitMesh() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};