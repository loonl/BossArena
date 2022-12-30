// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBaseStatComponent.h"

// ------------------------------------------------------
// 생성자 및 초기 실행 함수
// ------------------------------------------------------

// Sets default values for this component's properties
UPlayerCharacterBaseStatComponent::UPlayerCharacterBaseStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}


// Called when the game starts
void UPlayerCharacterBaseStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerCharacterBaseStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	InitStats();
}

// ------------------------------------------------------
// Init 함수
// ------------------------------------------------------

// Stat Init
void UPlayerCharacterBaseStatComponent::InitStats()
{
	SetMaxHP(100);
	SetCurHP(100);
	SetAttack(30);
	SetSpeed(1.f);
}


// ------------------------------------------------------
// Stat 관련 Getter & Setter
// ------------------------------------------------------

int32 UPlayerCharacterBaseStatComponent::GetMaxHP()
{
	return stat.maxHp;
}

int32 UPlayerCharacterBaseStatComponent::GetCurHP()
{
	return stat.currentHP;
}

int32 UPlayerCharacterBaseStatComponent::GetAttack()
{
	return stat.attack;
}

float UPlayerCharacterBaseStatComponent::GetSpeed()
{
	return stat.speed;
}

void UPlayerCharacterBaseStatComponent::SetMaxHP(int32 value)
{
	stat.maxHp = value;
}

void UPlayerCharacterBaseStatComponent::SetCurHP(int32 value)
{
	stat.currentHP = value;
}

void UPlayerCharacterBaseStatComponent::SetAttack(int32 value)
{
	stat.attack = value;
}

void UPlayerCharacterBaseStatComponent::SetSpeed(float value)
{
	stat.speed = value;
}

