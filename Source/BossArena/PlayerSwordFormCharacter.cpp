// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSwordFormCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// ------------------------------------------------------
// ������ �� �ʱ� �Լ�
// ------------------------------------------------------

// Sets default values
APlayerSwordFormCharacter::APlayerSwordFormCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm & Camera ����
	InitArm_Camera();

	// Mesh �ҷ�����
	InitMesh();

	// Controller Rotation ���� ����
	InitControllerRotation();

	// test code
	//GetWorld()->GetFirstPlayerController()->Possess(this);

}

void APlayerSwordFormCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void APlayerSwordFormCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// ------------------------------------------------------
// Tick �Լ�
// ------------------------------------------------------

// Called every frame
void APlayerSwordFormCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ------------------------------------------------------
// ���ε� �Լ�
// ------------------------------------------------------

// Called to bind functionality to input
void APlayerSwordFormCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Jump Action ���ε�
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerSwordFormCharacter::Jump);

	// Movement ���ε�
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerSwordFormCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerSwordFormCharacter::MoveRight);

	// ī�޶� ������ ���ε�
	PlayerInputComponent->BindAxis("Yaw", this, &APlayerSwordFormCharacter::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &APlayerSwordFormCharacter::Pitch);
}

void APlayerSwordFormCharacter::MoveForward(float value)
{
	// TODO - Null Check
	verticalValue = value;
	AddMovementInput(GetActorForwardVector(), value);
}

void APlayerSwordFormCharacter::MoveRight(float value)
{
	// TODO - Null Check
	horizontalValue = value;
	AddMovementInput(GetActorRightVector(), value);
}

void APlayerSwordFormCharacter::Yaw(float value)
{
	// TODO - Null Check
	AddControllerYawInput(value);
}

void APlayerSwordFormCharacter::Pitch(float value)
{
	// TODO - Null Check
	AddControllerPitchInput(value);
}


// ------------------------------------------------------
// Init �Լ�
// ------------------------------------------------------

// �����ڿ��� ���̴� ī�޶� Init �Լ�
void APlayerSwordFormCharacter::InitArm_Camera()
{
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	springArm->SetupAttachment(GetCapsuleComponent());
	camera->SetupAttachment(springArm);

	springArm->TargetArmLength = 500.f;
	springArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
}

// Mesh Init �Լ�
void APlayerSwordFormCharacter::InitMesh()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Game/Assets/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
}

// TPS ���� �⺻���� ���� Init �Լ�
void APlayerSwordFormCharacter::InitControllerRotation()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	// test code
	springArm->bUsePawnControlRotation = true;
	camera->bUsePawnControlRotation = false;
}


// ------------------------------------------------------
// �Ϲ� �Լ�
// ------------------------------------------------------

