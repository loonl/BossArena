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

	// Mesh �ҷ�����
	InitMesh();

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
// Init �Լ�
// ------------------------------------------------------
// Mesh ���� Init
void APlayerSwordFormCharacter::InitMesh()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Game/Assets/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	// InitMesh �θ� �Լ� ����
	Super::InitMesh();
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
// �Ϲ� �Լ�
// ------------------------------------------------------

