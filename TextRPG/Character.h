#pragma once

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Character
{
private:
	static Character* Instance;
	string Name;
	int Level;
	int Health;
	int MaxHealth;
	int Attack;
	int Experience;
	int Gold;
	vector<Item*> Inventory;
public:
	Character(string name)
		: Name(name), Level(1), Health {}
	static Character* GetInstnace(string name = "");
	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	void VisitShop();
};