#pragma once
#include "IMonster.h"
#include "Character.h"

using namespace std;

class GameManager
{
public:
	IMonster* GenerateMonster(int level);
	//BossMonster* generateBossMonster(int level)
	void Battle(Character* player);
	void VisitShop(Character* player);
	void DisplayInventory(Character* player);

};
