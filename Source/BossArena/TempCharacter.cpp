// Fill out your copyright notice in the Description page of Project Settings.


#include "TempCharacter.h"

// Sets default values
ATempCharacter::ATempCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATempCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATempCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATempCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ATempCharacter::Jump);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ATempCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ATempCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &ATempCharacter::Yaw);
}

void ATempCharacter::UpDown(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);
	//UpDownValue = Value;
	if (Value == 0.f) return;
	AddMovementInput(GetActorForwardVector(), Value);
}

void ATempCharacter::LeftRight(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
	//LeftRightValue = Value;
	if (Value == 0.f) return;
	AddMovementInput(GetActorRightVector(), Value);
}

void ATempCharacter::Yaw(float Value)
{
	AddControllerYawInput(Value);
}