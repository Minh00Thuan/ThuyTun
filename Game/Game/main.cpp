#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
//Hàm thay đổi kích cở khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, cursor_an_Pos);
}
// Xóa màng hình
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void VeHinh(int x, int y, string str, int color)
{
	gotoxy(x, y);//Cho con trỏ nhảy đến tọa độ x, y.
	textcolor(color);//Tô màu.
	cout << str;
	textcolor(7);// trở về như bình thường.
}
int main()
{
	/*resizeConsole(800, 600);
	textcolor(14);
	cout << "HELLO";
	textcolor(12);
	gotoxy(20, 15);
	cout << "phung thi thuy \n";
	while (true)
	{
		//fflush(stdin);
		if (_kbhit())
		{
			char c = _getch();
			//cout << "\n ban dang nhap vao 1 phim ";
			cout << "\n ban nhan vao phim " << c << endl;
		}
		cin.clear();
		fflush(stdin);
		cin.ignore(256, '\n');
	}
	//XoaManHinh();
	system("pause");*/
	VeHinh(10, 13, "\t\t\t\t\t\t", 176);
	VeHinh(10, 14, "\t\t\t\t\t\t", 176);
	VeHinh(10, 15, "\t\t\t\t\t\t", 176);
	VeHinh(10, 16, "\t\t\t\t\t\t", 176);
	VeHinh(10, 17, "\t\t\t\t\t\t", 176);
	VeHinh(12, 14, "Ban co muon choi lai?", 190);
	VeHinh(13, 15, "Yes\tNo", 190);
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			VeHinh(13, 15, "YES", 185);
			VeHinh(17, 15, "NO", 190);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			VeHinh(13, 15, "YES", 190);
			VeHinh(17, 15, "NO", 185);
		}
	}
	cout << "\n\n\n\n";
	return 0;
}