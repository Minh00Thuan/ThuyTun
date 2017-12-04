#include<iostream>
#include<ctime>
#include<string>
#include<windows.h>
using namespace std;

char map[50][50];
// Thay doi kich co khung
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// dich chuyen toa do
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD cursor_an_Pos = { y - 1, x - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, cursor_an_Pos);
}
// Xoa mang hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void VeDuongDua_1()
{
	for (int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if (i % 2 == 0)
		{
			map[i][14] = '|';
		}
		for (int j = 1; j < 29 && j!=14; j++)
		{
			map[i][j] = ' ';
		}
	}
}
void VeDuongDua_2()
{
	for (int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29]='|';
		if (i % 2 != 0)
		{
			map[i][14] = '|';
		}
		for (int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}
void InDuongDua()
{
	resizeConsole(800, 600);
	for (int i = 0; i < 30; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < 30; j++)
		{/*in duong dua */
			if (j == 0 || j == 29)
			{
				textcolor(191);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}
			else if (j == 14)
			{
				textcolor(159);
				cout << map[i][j];
				textcolor(7);
				map[i][j] = ' ';//xoa lan di
			}
			//in xe
			else if (map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#')
			{
				textcolor(14);//Mau vang
				cout << map[i][j];
				textcolor(7);// tro lai mau
			}
			/*in xe computer*/
			else if (map[i][j] == '!')
			{
				map[i][j] = ' ';
				textcolor(200);
				cout << map[i][i];
				textcolor(7);
			}
			else
			{
				cout << map[i][j];//nhung ki tu khong phai xe
			}
		}
		cout << endl;
	}
}
void VeXePlayer(int x, int y)
{
	map[x][y] = 'X';//Than xe
	map[x][y - 1] = '#';//Ben trai than xe
	map[x][y + 1] = '#';//Ben phai than xe
	map[x - 1][y - 1] = '@';//Banh xe tren ben trai
	map[x + 1][y - 1] = '@';//Banh xe tren ben phai
	map[x - 1][y + 1] = '@';//Banh xe duoi ben trai
	map[x + 1][y + 1] = '@';//Banh xe duoi ben phai
}
void VeXeChuongNgaiVat(int x, int y)
{
	map[x][y] = '!';
	map[x][y - 1] = '!';
	map[x][y + 1] = '!';
	map[x - 1][y + 1] = '!';
	map[x - 1][y - 1] = '!';
	map[x + 1][y + 1] = '!';
	map[x + 1][y - 1] = '!';
}
void DiChuyenXe(int &x, int &y)//x, y la toa do hien tai cua xe
{
	map[x][y] = ' ';
	map[x][y - 1] = ' ';
	map[x][y + 1] = ' ';
	map[x + 1][y + 1] = ' ';
	map[x + 1][y - 1] = ' ';
	map[x - 1][y + 1] = ' ';
	map[x - 1][y - 1] = ' ';
	//qua trai
	if (GetAsyncKeyState(VK_LEFT))
	{
		if(y>2)
		y--;//giai cot
	}
	//Qua phai
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if(y<27)
		y++;
	}
	//Di len
	if (GetAsyncKeyState(VK_UP))
	{
		if(x>1)
		x--;
	}
	//Di xuong
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if(x<28)
		x++;
	}
	VeXePlayer(x, y);
}
int main()
{
	srand((unsigned)time(NULL));
	int count = 5;
	int a = 0;
	int x = 28, y = 14;//toa do xe player
	int x1 = 2, y1;// toa do xe chuong ngai vat dong
	int x2 = 5, y2 = 10;//Toa do xe chuong ngai vat tinh
	int x3 = 2, y3;
		while (true)
		{
			a++;
			if (a % 2 != 0)
			{
				VeDuongDua_1();
			}
			else
			{
				VeDuongDua_2();
			}
			y3 = rand() % 26 + 2;
			y1 = rand() % 26 + 2;
			XoaManHinh();
			VeXePlayer(x, y);
			VeXeChuongNgaiVat(x1, y1);// xe dong
			VeXeChuongNgaiVat(x3, y3);
			VeXeChuongNgaiVat(x2, y2);//xe tinh;
			InDuongDua();
			DiChuyenXe(x, y);
			x1++;
			if (x1 == 31)
			{
				x1 = 2;
			}
			x3++;
			if (x3 == 31)
			{
				x3 = 2;
			}
			x2++;
			if (x2 == 31)
			{
				x2 = 5;
				y2 = rand() % 26 + 2;
			}
			if (x - 1 <= x2 + 1 && (y - 1 <= y2 + 1) && y + 1 >= y2 - 1)
			{
				printf("\a");
				count--;
				if (count < 0)
				{
					break;
				}
			}
			if (x - 1 <= x1 + 1 && (y + 1 >= y1 - 1) && (y - 1 <= y1 + 1))
			{
				printf("\a");
				count--;
				if (count < 0)
				{
					break;
				}
			}
			if (x - 1 <= x3 + 1 && (y + 1 >= y3 + 1) && y + 1 >= y3 - 1)
			{
				printf("\a");
				count--;
				if (count < 0)
				{
					break;
				}
			}
			Sleep(1);
		}
	InDuongDua();
	//system("pause");
	return 0;
}