#include "Item.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class HealthPotion : public IItem {
private: 
	const string name;
	const int healthRestore;

public:
	HealthPotion();
	string getName() override;
	void use(Character*) override;
};