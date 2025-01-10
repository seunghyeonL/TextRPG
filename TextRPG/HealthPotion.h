#include "Item.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class HealthPotion : public IItem
{
private:
	const string Name;
	const int HealthRestore;

public:
	HealthPotion();
	string HetName() override;
	void Use(Character*) override;
};