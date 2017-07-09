// SortingAlgo.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"
#include "iostream"
#include "SelectAlgo.h"
#include "SelectAlgo_linear.h"
#include "readfile.h"
#include "windows.h"
using namespace std;

int main()
{
	vector<int>* result = readfileToArray("sortingdata/repeat.txt");
	int length = result->size();
	int* a = result->data();
	DWORD start, end;
	start = GetTickCount();
	cout<<"run result:"<<algo::randomized_select(a,0,length-1,3434);
	end = GetTickCount();
	cout << "run time:" << end - start << endl;

	/*vector<int>* result = readfileToArray("sortingdata/repeat.txt");
	int length = result->size();
	int* a = result->data();
	DWORD start, end;
	start = GetTickCount();
	cout<<"run result:"<<algo::randomized_select(a,0,length-1,234534);
	end = GetTickCount();
	cout << "run time:" << end - start << endl;*/
	
	while(true)
	{ }
    return 0;
}

