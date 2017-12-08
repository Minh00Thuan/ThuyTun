#pragma once
#include"Character.h"
class NocTic:public Character
{
private:

public:
	void Nhap(ifstream &is);
	void Xuat();
	void Sleep();
	NocTic();
	~NocTic();
};

