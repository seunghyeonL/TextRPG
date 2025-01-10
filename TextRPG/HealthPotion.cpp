#include "HealthPotion.h"
#include "Character.h"
#include <iostream>
HealthPotion::HealthPotion()
	: name("Red Potion"), healthRestore(50) {}

string HealthPotion::getName()
{
    return name;
}

void HealthPotion::use(Character*)
{
}
