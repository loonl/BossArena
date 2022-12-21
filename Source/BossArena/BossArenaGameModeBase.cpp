// Copyright Epic Games, Inc. All Rights Reserved.


#include "BossArenaGameModeBase.h"
#include "PlayerSwordFormCharacter.h"

ABossArenaGameModeBase::ABossArenaGameModeBase()
{
	// 디폴트 클래스 지정
	DefaultPawnClass = APlayerSwordFormCharacter::StaticClass();
}