#include "GameManager.h"
#include "IMonster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Troll.h"
#include "Orc.h"

IMonster* GenerateMonster(int level)
{
	switch (level % 4)
	{
	case 0: return Slime::Create(); break;
	case 1: return Goblin::Create(); break;
	case 2: return Orc::Create(); break;
	case 3: return Troll::Create(); break;
	// case : return new BossMonster(level); break;
	}
}

bool battle(Character* player)
{
	if(player->GetLevel() == 10)
	{
		// 보스 몬스터 조우
	}
	else
	{
		// 일반 몬스터 조우
		// 전투 진행
	}
}

void VisitShop(Character* player)
{

}

void Exit()
{

}