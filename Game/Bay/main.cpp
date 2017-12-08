#pragma once
#include<iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
char map[30][100];
void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void GoToXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, cursor_an_Pos);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void InDuongBay()
{
	cout << "\n\n\n";
	ResizeConsole(800, 500);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			if (i == 0 || i == 19)
			{
				TextColor(223);
				cout << map[i][j];
				TextColor(7);
			}
			else
			{
				TextColor(158);
				cout << map[i][j];
				TextColor(7);
			}
		}
		cout << endl;
	}
}
void VeQua(int x, int y)
{
	map[x][y] = '@';
}
void DiChuyenQua(int &x, int &y)
{
	map[x][y] = ' ';
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (y > 0)
		{
			y--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (y < 89)
		{
			y++;
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (x > 1)
		{
			x--;
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (x < 18)
		{
			x++;
		}
	}
	VeQua(x, y);
}
void VeDuongDua()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			if (i == 0 || i == 19)
			{
				map[i][j] = '-';
			}
			else if(map[i][j]!='#')
			{
				map[i][j] = ' ';
			}
		}
	}
}
void VeChuongNgaiVat(int &y, int hight)
{

	for (int x = 0; x < 16; x++)
	{
		map[x][y - 1] = ' ';
		map[x][y] = ' ';
		map[x][y + 1] = ' ';
	}
	y--;
	if (hight % 2 == 0)
	{
		for (int x = 1; x < hight; x++)
		{
			map[x][y - 1] = '#';
			map[x][y] = '#';
			map[x][y + 1] = '#';
		}
	}
	else
	{
		for (int x = 17; x > x - hight; x--)
		{
			map[x][y - 1] = '#';
			map[x][y] = '#';
			map[x][y + 1] = '#';
		}
	}
	
}
void main()
{
	
	srand((unsigned)time(NULL));
	int three = 0;
	int x = 9, y = 0;
	int y1 = 80, hight1 = 8;
	int y2 = 83, hight2 = 10;
	int y3 = 86, hight3 = 10;
	int y4 = 88, hight4 = 10;
	VeQua(x, y);
	while (true)
	{
		VeDuongDua();
		XoaManHinh();
		DiChuyenQua(x, y);
		InDuongBay();

		while (three < 3)
		{
			VeChuongNgaiVat(y1, hight1);
			if (y1 < 2)
			{
				y1 = 80;
				hight1 = rand() % 10+2;
			}
			three++;
		}
		three = 0;
		while (three < 3)
		{
			VeChuongNgaiVat(y2, hight2);
			if (y2 < 2)
			{
				y2 = 83;
				hight2 = rand() % 10+2;
			}
			three++;
		}
		three = 0;
		while (three < 3)
		{
			VeChuongNgaiVat(y3, hight3);
			if (y3 < 2)
			{
				y3 = 86;
				hight3 = rand() % 10+2;
			}
			three++;
		}
		three = 0;
		while (three < 3)
		{
			VeChuongNgaiVat(y4, hight4);
			if (y4 < 2)
			{
				y4 = 88;
				hight4 = rand() % 10;
			}
			three++;
		}
	}
}