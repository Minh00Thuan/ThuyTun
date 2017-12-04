#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;
int main()
{
	ifstream fileIn;
	fileIn.open("GioiThieu.txt", ios::in);
	while (!fileIn.eof())
	{
		char c;
		fileIn.get(c);
		Sleep(100);
		cout << c;
		if (c == 10)
		{
			cout << "\t\t\t";
		}
		if (_kbhit())// tuong tac mot phim bat ki se ket thuc.
		{
			return 0;
		}
	}
	fileIn.close();
	system("pause");
	return 0;
}