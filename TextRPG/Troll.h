#pragma once

#include "IMonster.h"

class Troll : public IMonster
{
private:
	/*
	�����ڸ� private ���� �ع����� �����Ҵ��� ������. �������
	�׷��� Create��� �Լ��� ���� ���� �����ϰ� �� �� �ִ�.	*/
	Troll();
	virtual ~Troll() = default;

public: /* IMonster �θ� Ŭ�������� �޾ƿ� �Լ��� */
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public: /* ���� �����Ҵ��� ������ִ� �Լ� */
	static Troll* Create(string name = "", int health = 10, int attack = 5);
	virtual void Free() override;
};