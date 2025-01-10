#include "HealthPotion.h"
#include "Character.h"
#include <iostream>
HealthPotion::HealthPotion()
	: Name("Red Potion"), HealthRestore(50) {}

string HealthPotion::GetName()
{
    return Name;
}

void HealthPotion::Use(Character*)
{
}
