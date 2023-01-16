// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacterBaseStatComponent.h"
#include "Components/CapsuleComponent.h"


// ------------------------------------------------------
// 생성자 및 초기 함수
// ------------------------------------------------------

// Sets default values
APlayerCharacterBase::APlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Arm과 Camera 관련 Init
	InitArmandCamera();

	// Rotation 설정 관련 Init
	InitRotationSettings();

	// Component 관련 Init
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
// Tick 함수
// ------------------------------------------------------

// Called every frame
void APlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// ------------------------------------------------------
// Init 함수
// ------------------------------------------------------

// SpringArm 과 Camera 관련 Init
void APlayerCharacterBase::InitArmandCamera()
{
	// springArm & camera 생성
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// 연결
	springArm->SetupAttachment(GetCapsuleComponent());
	camera->SetupAttachment(springArm);

	// 기본 추가 설정
	springArm->TargetArmLength = 500.f;
	springArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
}

// Rotation 관련 설정 Init
void APlayerCharacterBase::InitRotationSettings()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	springArm->bUsePawnControlRotation = true;
	camera->bUsePawnControlRotation = false;
}

// Component 바인드 관련 Init
void APlayerCharacterBase::InitBindComponent()
{
	statComp = CreateDefaultSubobject<UPlayerCharacterBaseStatComponent>(TEXT("Stat"));
}

// Mesh 관련 Init
void APlayerCharacterBase::InitMesh()
{
	// 기본 세팅 - 나머지 Skeletal Mesh 설정은 하위 클래스에서 각자
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
