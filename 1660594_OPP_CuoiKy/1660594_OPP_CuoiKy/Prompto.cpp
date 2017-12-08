#include "Prompto.h"




void Prompto::Nhap(ifstream &is)
{
	is >> ten >> hp >> level >> ap;
}

void Prompto::Xuat()
{
	Character::Xuat();
}

void Prompto::Sleep()
{
	int x = ap / 1500;
	level += x;
	hp += x * 18;
}

Prompto::Prompto()
{
}


Prompto::~Prompto()
{
}
