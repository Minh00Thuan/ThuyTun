#include"Gladiolus.h"
#include"lgnis.h"
#include"Prompto.h"
#include"NocTic.h"
void main()
{
	Character *gl = new Gladiolus;
	Character *lg = new lgnis;
	Character *no = new NocTic;
	Character *pro = new Prompto;
	ifstream is;
	is.open("save01.txt", ios::in);
	gl->Nhap(is);
	lg->Nhap(is);
	no->Nhap(is);
	pro->Nhap(is);
	is.close();
	gl->Xuat();
	lg->Xuat();
	no->Xuat();
	pro->Xuat();
	system("pause");
}