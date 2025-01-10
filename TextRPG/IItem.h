#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class IItem
{
public:
	~IItem() = default;
	virtual string getName() = 0;
	virtual void use(Character*) = 0;
};