#pragma once
#include <string>

using namespace std;

class IMonster abstract
{
protected:
	IMonster();
	virtual ~IMonster() = default;

public:
	virtual void Initialize(string name, int health, int attack) = 0;
	virtual void Update() = 0;
	
	virtual string Get_Name() { return mName; }

	virtual int Get_Health() { return mHealth; }
	virtual int Get_Attack() { return mAttack; }
protected:
	string		mName{};
	int			mHealth{ 0 };
	int			mAttack{ 0 };
public:
	virtual void Free();
};