#include "lgnis.h"


void lgnis::Nhap(ifstream &is)
{
	is >> ten >> hp >> level >> ap;
}
void lgnis::Xuat()
{
	Character::Xuat();
}
void lgnis::Sleep()
{
	int x = ap / 950;
	level += x;
	hp += x * 22;
}
lgnis::lgnis()
{
}


lgnis::~lgnis()
{
}


