#include<iostream>
#include<windows.h>
using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void main()
{
	int i = 0;
	while (i <= 255)
	{
		textcolor(i);
		cout << "\n =>i = " << i;
		i++;
	}
	system("pause");
}