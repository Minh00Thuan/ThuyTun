#include"Header.h"
void main()
{
	vector<int>v;
	Input(v);
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//SelectionSort(v);
	//QuickSort(v, 0, v.size() - 1);
	//Merger_Sort(v, 0, v.size() - 1);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double, std::milli>time_span = t2 - t1;
	cout << time_span.count() << " millisecond.";
	_getch();
}