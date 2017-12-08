#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Character
{
protected:
	string ten;
	int hp, level, ap, sonhanvat;
public:
	virtual void Nhap(ifstream &is) = 0;
	virtual void Xuat();
	virtual void Sleep() = 0;
	Character();
	~Character();
};

