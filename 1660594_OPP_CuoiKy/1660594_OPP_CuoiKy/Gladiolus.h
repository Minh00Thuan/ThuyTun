#pragma once
#include"Character.h"
class Gladiolus:public Character
{
private:

public:
	void Nhap(ifstream &is);
	void Xuat();
	void Sleep();
	Gladiolus();
	~Gladiolus();
};

