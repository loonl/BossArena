// Copyright Epic Games, Inc. All Rights Reserved.


#include "BossArenaGameModeBase.h"
#include "PlayerSwordFormCharacter.h"

ABossArenaGameModeBase::ABossArenaGameModeBase()
{
	// ����Ʈ Ŭ���� ����
	DefaultPawnClass = APlayerSwordFormCharacter::StaticClass();
}