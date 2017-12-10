#include<iostream>
using namespace std;
void main()
{
	int r=1, t = 1, x = 1, y = 1, z = 0;
	if (!(++r > 1 && ++t > 1 && ++x > 1 && ++y < 1))
		z = x + y + t + r;
	cout<<z;
}