// Copyright Epic Games, Inc. All Rights Reserved.


#include "BossArenaGameModeBase.h"
#include "Boss1.h"

ABossArenaGameModeBase::ABossArenaGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprints/BP_TempCharacter.BP_TempCharacter_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}

}