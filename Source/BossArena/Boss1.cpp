// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss1.h"
#include "Boss1_AIController.h"
#include "Boss1_AnimInstance.h"

// Sets default values
ABoss1::ABoss1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Game/Assets/ParagonRampage/Characters/Heroes/Rampage/Meshes/Rampage.Rampage"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	AIControllerClass = ABoss1_AIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ABoss1::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABoss1::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AnimInstance = Cast<UBoss1_AnimInstance>(GetMesh()->GetAnimInstance());
}
// Called every frame
void ABoss1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoss1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ABoss1::UpDown);

}

void ABoss1::UpDown(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);
	UpDownValue = Value;
	AddMovementInput(GetActorForwardVector(), Value);
}

