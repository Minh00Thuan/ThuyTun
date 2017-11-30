#pragma once
#include<vector>
#include<iostream>
#include<ctime>
#include<ratio>
#include<chrono>
#include<conio.h>
using namespace std;
void Input(vector<int>&v);
void Show(vector<int>v);
void Swap(int &a, int &b);
void SelectionSort(vector<int>&v);
void QuickSort(vector<int>&v, int first, int last);
void Merger(vector<int>&a, int start, int end);


void Merger_Sort(vector<int>&a, int start, int end);