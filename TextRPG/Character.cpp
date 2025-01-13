#include <iostream>
#include "Character.h"

Character* Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), MaxLevel(10), Health(200),
    MaxHealth(200), Attack(30), Experience(0), Gold(0)
{
}

Character* Character::GetInstance(string name)
{
    if (!Instance && !name.empty()) {
        Instance = new Character(name);
    }
    return Instance;
}

string Character::GetName()
{
    return Name;
}

int Character::GetLevel()
{
    return Level;
}

int Character::SetLevel(int level)
{
    Level = level;
}

int Character::GetMaxLevel()
{
    return MaxLevel;
}

double Character::GetHealth()
{
    return Health;
}

void Character::SetHealth(double health)
{
    if (health >= MaxHealth)
    {
        Health = MaxHealth;
    }
    else if (health > 0 && health < MaxHealth)
    {
        Health = health;
    }
    else if (Health <= 0)
    {
        Health = 0;
    }
}

double Character::GetAttack()
{
    return Attack;
}

void Character::SetAttack(double attack)
{
    Attack = attack;
}

void Character::TakeDamage(double damage)
{
    Health -= damage;
    if (Health < 0) Health = 0;
}

double Character::GetExperience()
{
    return Experience;
}

double Character::GetMaxExperience()
{
    return MaxExperience;
}

double Character::GetGold()
{
    return Gold;
}

void Character::DisplayStatus()
{
    cout << "\n현재 레벨 : " << Level << "레벨 " << Experience / MaxExperience * 100 << "경험치\n";
    cout << "현재 체력 : " << Health << " / " << MaxHealth << "(" << Health / MaxHealth << ")\n";
    cout << "현재 공격력 : " << Attack << "\n";
    cout << "현재 보유 골드 : " << Gold << "\n\n";
}
