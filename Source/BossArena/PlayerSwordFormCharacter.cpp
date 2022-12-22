// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSwordFormCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// ------------------------------------------------------
// 생성자 및 초기 함수
// ------------------------------------------------------

// Sets default values
APlayerSwordFormCharacter::APlayerSwordFormCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh 불러오기
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
// Init 함수
// ------------------------------------------------------
// Mesh 관련 Init
void APlayerSwordFormCharacter::InitMesh()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Game/Assets/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	// InitMesh 부모 함수 실행
	Super::InitMesh();
}

// ------------------------------------------------------
// Tick 함수
// ------------------------------------------------------

// Called every frame
void APlayerSwordFormCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ------------------------------------------------------
// 일반 함수
// ------------------------------------------------------

