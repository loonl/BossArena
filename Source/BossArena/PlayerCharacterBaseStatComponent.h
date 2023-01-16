// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCustomController.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "PlayerCharacterBaseStatComponent.generated.h"

// ------------------------------------------------------
// Delegate ����
// ------------------------------------------------------
DECLARE_MULTICAST_DELEGATE(FOnHpChanged);


// ------------------------------------------------------
// Player Stat ��� ����ü
// ------------------------------------------------------
USTRUCT(BlueprintType)
struct FPlayerCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 maxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 currentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 attack;

	// �ӽ� - �̵��ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float speed;
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BOSSARENA_API UPlayerCharacterBaseStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCharacterBaseStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	// ------------------------------------------------------
	// Init �Լ�
	// ------------------------------------------------------
private:
	void InitStats();

	// ------------------------------------------------------
	// private Stat ����
	// ------------------------------------------------------
private:
	UPROPERTY(VisibleAnywhere)
	FPlayerCharacterData stat;


	// ------------------------------------------------------
	// Stat ���� Getter & Setter
	// ------------------------------------------------------
public:
	int32 GetMaxHP();
	int32 GetCurHP();
	int32 GetAttack();
	float GetSpeed();
	void SetMaxHP(int32 value);
	void SetCurHP(int32 value);
	void SetAttack(int32 value);
	void SetSpeed(float value);

	// Delegate
public:

	// HP ����� ȣ��Ǵ� ��������Ʈ
	FOnHpChanged OnHpChanged;

};
