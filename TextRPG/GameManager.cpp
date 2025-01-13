#include "GameManager.h"
#include "IMonster.h"

IMonster* GameManager::GenerateMonster(int level)
{
	switch (level % 4)
	{
	case 0: return new Troll(level); break;
	case 1: return new Slime(level); break;
	case 2: return new Goblin(level); break;
	case 3: return new Orc(level); break;
		// case : return new BossMonster(level); break;
	}
	return nullptr;
}

bool GameManager::battle(Character* player)
{
	if (player->GetLevel() == 10)
	{
		// 보스 몬스터 조우

	}
	else
	{
		GenerateMonster(player->GetLevel());
		// 일반 몬스터 조우
		// 전투 진행
	}
	return false;
}

void GameManager::VisitShop(Character* player)
{
}

void GameManager::Exit()
{
}
