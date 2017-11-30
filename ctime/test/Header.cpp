#include"Header.h"
void Input(vector<int>&v)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 2000; i++)
	{
		int x = rand() % 1000;
		v.push_back(x);
	}
}
void Show(vector<int>v)
{
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = a;
}
void SelectionSort(vector<int>&v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				Swap(v[i], v[j]);
			}
		}
	}
}
void QuickSort(vector<int>&v, int first, int last)
{
	int i, j, temp, mid;
	mid = v[(first + last) / 2];
	i = first;
	j = last;
	do
	{
		while (v[i] < mid)
		{
			i++;
		}
		while (v[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(v[i++], v[j--]);
		}
	} while (i < j);
	if (first < j)
	{
		QuickSort(v, first, j);
	}
	if (first < last)
	{
		QuickSort(v, i, last);
	}
}
void Merger(vector<int>&a, int start, int end)
{
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int temp;
	while (i <= j && j <= end)
	{
		if (a[i] > a[j])
		{
			temp = a[j];
			for (int k = j; k > i; k--)
				a[k] = a[k - 1];
			a[i] = temp;
			j++;
		}
		i++;
	}
}

void Merger_Sort(vector<int>&a, int start, int end)
{
	if (end - start < 1)
		return;
	int mid = (start + end) / 2;
	Merger_Sort(a, start, mid);
	Merger_Sort(a, mid + 1, end);
	Merger(a, start, end);
}