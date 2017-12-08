#include "Gladiolus.h"



void Gladiolus::Nhap(ifstream &is)
{
	string temp;
	getline(is, temp);
	is>> ten >> hp >> level >> ap;
}

void Gladiolus::Xuat()
{
	Character::Xuat();
}

void Gladiolus::Sleep()
{
	int x = ap / 800;
	level += x;
	hp += x * 30;
}

Gladiolus::Gladiolus()
{
}


Gladiolus::~Gladiolus()
{
}
