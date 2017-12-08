#include "Character.h"



void Character::Xuat()
{
	cout << endl << "-------------------------------";
	cout << endl << "ten: " << ten;
	cout << endl << hp << " hp";
	cout << endl << "level " << level;
	cout << endl << ap << " ap";
}

Character::Character()
{
	sonhanvat = 4;
}


Character::~Character()
{
}
