#pragma once
#include "string"
#include "iostream"
#include "fstream"
#include "vector"
using namespace std;
vector<int>* readfileToArray(string filename)
{
	vector<int> *result = new vector<int>();
	string s;
	ifstream infile;
	infile.open(filename);
	if (!infile)
	{
		cout << "error";
		exit(-1);
	}
	int i = 0;
	while (infile>>s)
	{
		result->push_back(stoi(s));
	}
	return result;
}