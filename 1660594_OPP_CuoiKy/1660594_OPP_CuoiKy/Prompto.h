#pragma once
#include"Character.h"
class Prompto:public Character
{
private:

public:
	void Nhap(ifstream &is);
	void Xuat();
	void Sleep();
	Prompto();
	~Prompto();
};

