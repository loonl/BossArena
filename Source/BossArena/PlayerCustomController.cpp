// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCustomController.h"
#include "PlayerCharacterBase.h"


// ------------------------------------------------------
// ������ �� �ʱ� �Լ�
// ------------------------------------------------------
APlayerCustomController::APlayerCustomController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm & Camera ����
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
	// Player ����
}




// ------------------------------------------------------
// Tick �Լ�
// ------------------------------------------------------
void APlayerCustomController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// ------------------------------------------------------
// Input ���� ���ε� �Լ�
// ------------------------------------------------------
void APlayerCustomController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Jump Action ���ε�
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCustomController::Jump);

	// Movement ���ε�
	InputComponent->BindAxis("MoveForward", this, &APlayerCustomController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCustomController::MoveRight);

	// ī�޶� ������ ���ε�
	InputComponent->BindAxis("Yaw", this, &APlayerCustomController::Yaw);
	InputComponent->BindAxis("Pitch", this, &APlayerCustomController::Pitch);

	// test - �÷��̾� ������ �޴� �� �����
	InputComponent->BindAction("GetDamaged", IE_Pressed, this, &APlayerCustomController::GetDamaged);
}

void APlayerCustomController::Jump()
{
	GetCharacter()->Jump();
}

void APlayerCustomController::MoveForward(float value)
{
	// Character �� ������ ������Ʈ
	auto character = Cast<APlayerCharacterBase>(GetPawn());
	if (character)
	{
		character->SetVerticalValue(value);
	}

	GetCharacter()->AddMovementInput(GetCharacter()->GetActorForwardVector(), value);
}

void APlayerCustomController::MoveRight(float value)
{
	// Character �� ������ ������Ʈ
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

// Custom Camera Class (Blueprint) ����
void APlayerCustomController::InitCameraClass()
{
	/**
	// TODO - ���� �Ƚ� �ʿ� :: ã�ƿ��� ����
	static ConstructorHelpers::FObjectFinder<APlayerCameraManager> CM(TEXT("/Game/Player/Blueprints/BP_PlayerCamera.BP_PlayerCamera"));
	if (CM.Succeeded())
	{
		PlayerCameraManager = CM.Object;
	}
	*/
}


// ------------------------------------------------------
// Possess �Լ�
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