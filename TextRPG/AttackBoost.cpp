#include "AttackBoost.h"


AttackBoost::AttackBoost();

string AttackBoost::getName()
{
    string InputName;
    cout << "����� �������� �����Դϱ�?" << endl;
    cin.ignore();
    getline(cin, InputName);
    Name = InputName;
}

void AttackBoost::use(character:Character*)
{

}