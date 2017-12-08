#include "NocTic.h"




void NocTic::Nhap(ifstream &is)
{
	is >> ten >> hp >> level >> ap;
}

void NocTic::Xuat()
{
	Character::Xuat();
}

void NocTic::Sleep()
{
	int x = ap / 1200;
	level += x;
	hp = x * 15;
}

NocTic::NocTic()
{
}


NocTic::~NocTic()
{
}
