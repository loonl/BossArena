// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacterBaseStatComponent.h"
#include "Components/CapsuleComponent.h"


// ------------------------------------------------------
// ������ �� �ʱ� �Լ�
// ------------------------------------------------------

// Sets default values
APlayerCharacterBase::APlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Arm�� Camera ���� Init
	InitArmandCamera();

	// Rotation ���� ���� Init
	InitRotationSettings();

	// Component ���� Init
	InitBindComponent();
}

// Called when the game starts or when spawned
void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}


// ------------------------------------------------------
// Tick �Լ�
// ------------------------------------------------------

// Called every frame
void APlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// ------------------------------------------------------
// Init �Լ�
// ------------------------------------------------------

// SpringArm �� Camera ���� Init
void APlayerCharacterBase::InitArmandCamera()
{
	// springArm & camera ����
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// ����
	springArm->SetupAttachment(GetCapsuleComponent());
	camera->SetupAttachment(springArm);

	// �⺻ �߰� ����
	springArm->TargetArmLength = 500.f;
	springArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
}

// Rotation ���� ���� Init
void APlayerCharacterBase::InitRotationSettings()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	springArm->bUsePawnControlRotation = true;
	camera->bUsePawnControlRotation = false;
}

// Component ���ε� ���� Init
void APlayerCharacterBase::InitBindComponent()
{
	statComp = CreateDefaultSubobject<UPlayerCharacterBaseStatComponent>(TEXT("Stat"));
}

// Mesh ���� Init
void APlayerCharacterBase::InitMesh()
{
	// �⺻ ���� - ������ Skeletal Mesh ������ ���� Ŭ�������� ����
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
}


// ------------------------------------------------------
// Getter Setter
// ------------------------------------------------------

float APlayerCharacterBase::GetHorizontalValue()
{
	return horizontalValue;
}

float APlayerCharacterBase::GetVerticalValue()
{
	return verticalValue;
}

void APlayerCharacterBase::SetHorizontalValue(float value)
{
	horizontalValue = value;
}

void APlayerCharacterBase::SetVerticalValue(float value)
{
	verticalValue = value;
}


// test
void APlayerCharacterBase::GetDamaged(int32 damage)
{
	statComp->SetCurHP(statComp->GetCurHP() - damage);
	UE_LOG(LogTemp, Warning, TEXT("Current HP : %d"), statComp->GetCurHP());
}
