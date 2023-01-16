// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCustomController.h"
#include "PlayerCharacterBase.h"


// ------------------------------------------------------
// 생성자 및 초기 함수
// ------------------------------------------------------
APlayerCustomController::APlayerCustomController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm & Camera 세팅
	InitCameraClass();
}

void APlayerCustomController::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCustomController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// test - Possess test 
	// Player 연결
}




// ------------------------------------------------------
// Tick 함수
// ------------------------------------------------------
void APlayerCustomController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// ------------------------------------------------------
// Input 관련 바인딩 함수
// ------------------------------------------------------
void APlayerCustomController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Jump Action 바인딩
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCustomController::Jump);

	// Movement 바인딩
	InputComponent->BindAxis("MoveForward", this, &APlayerCustomController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCustomController::MoveRight);

	// 카메라 움직임 바인딩
	InputComponent->BindAxis("Yaw", this, &APlayerCustomController::Yaw);
	InputComponent->BindAxis("Pitch", this, &APlayerCustomController::Pitch);

	// test - 플레이어 데미지 받는 것 디버그
	InputComponent->BindAction("GetDamaged", IE_Pressed, this, &APlayerCustomController::GetDamaged);
}

void APlayerCustomController::Jump()
{
	GetCharacter()->Jump();
}

void APlayerCustomController::MoveForward(float value)
{
	// Character 쪽 변수에 업데이트
	auto character = Cast<APlayerCharacterBase>(GetPawn());
	if (character)
	{
		character->SetVerticalValue(value);
	}

	GetCharacter()->AddMovementInput(GetCharacter()->GetActorForwardVector(), value);
}

void APlayerCustomController::MoveRight(float value)
{
	// Character 쪽 변수에 업데이트
	auto character = Cast<APlayerCharacterBase>(GetPawn());
	if (character)
	{
		character->SetHorizontalValue(value);
	}

	GetCharacter()->AddMovementInput(GetCharacter()->GetActorRightVector(), value);
}

void APlayerCustomController::Yaw(float value)
{
	AddYawInput(value);
}

void APlayerCustomController::Pitch(float value)
{
	AddPitchInput(value);
}

// Custom Camera Class (Blueprint) 연결
void APlayerCustomController::InitCameraClass()
{
	/**
	// TODO - 여기 픽스 필요 :: 찾아오지 못함
	static ConstructorHelpers::FObjectFinder<APlayerCameraManager> CM(TEXT("/Game/Player/Blueprints/BP_PlayerCamera.BP_PlayerCamera"));
	if (CM.Succeeded())
	{
		PlayerCameraManager = CM.Object;
	}
	*/
}


// ------------------------------------------------------
// Possess 함수
// ------------------------------------------------------
void APlayerCustomController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void APlayerCustomController::OnUnPossess()
{
	Super::OnUnPossess();
}


// test
void APlayerCustomController::GetDamaged()
{
	auto character = Cast<APlayerCharacterBase>(GetPawn());
	if (character)
	{
		character->GetDamaged(40);
	}
}