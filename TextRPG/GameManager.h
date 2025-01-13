#pragma once
#include "Character.h"
#include "IMonster.h"
#include <string>
#include <vector>

using namespace std;

class GameManager
{
public:
	void Initialize();
	void Update();
	void Render();

	void Change_Level(class Level* pNewLevel);

	IMonster* GenerateMonster(int level);

	bool battle(Character* player);

	void VisitShop(Character* player);

	void Exit();


private:
	class Level_Manager* m_pLevel_Manager{ nullptr };

public:
	static GameManager* Create();
	virtual void Free();
};