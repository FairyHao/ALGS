#include "stdafx.h"
#include "ReadFileTools.h"

using namespace std;



ReadFileTools::ReadFileTools()
{
}
Graph* ReadFileTools::readFile(string fileName)
{
	string s;
	ifstream infile;
	infile.open(fileName);
	if (!infile)
	{
		cout << "error";
		exit(-1);
	}
	int Vnum = 0;
	if (infile >> s)
	{
		Vnum = stoi(s);
	}
	infile >> s;//边的个数不用赋值，所以跳过
	Graph *g = new Graph(Vnum);
	int i = 0;
	int u = -1;
	int v = -1;
	double w = -1;
	while (infile >> s)
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		else if (i==1)
		{
			u = stoi(s);
			i++;
		}
		else if (i == 2)
		{
			v = stoi(s);
			i++;
		}
		else
		{
			w = stod(s);
			g->AddEdge(u, v, w);
			g->AddEdge(v, u, w);
			i = 0;
		}
	}
	infile.close();
	return g;
}
//读文件至一颗有向图
Graph* ReadFileTools::readFileToDg(string fileName)
{
	string s;
	ifstream infile;
	infile.open(fileName);
	if (!infile)
	{
		cout << "error";
		exit(-1);
	}
	int Vnum = 0;
	if (infile >> s)
	{
		Vnum = stoi(s);
	}
	infile >> s;//边的个数不用赋值，所以跳过
	Graph *g = new Graph(Vnum);
	int i = 0;
	int u = -1;
	int v = -1;
	double w = -1;
	while (infile >> s)
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		else if (i == 1)
		{
			u = stoi(s);
			i++;
		}
		else if (i == 2)
		{
			v = stoi(s);
			i++;
		}
		else
		{
			w = stod(s);
			g->AddEdge(u, v, w);
			i = 0;
		}
	}
	infile.close();
	return g;
}
//把一个文件读为无向图
Graph* ReadFileTools::readFileUdg(string fileName)
{
	string s;
	ifstream infile;
	infile.open(fileName);
	if (!infile)
	{
		cout << "error";
		exit(-1);
	}
	int Vnum = 0;
	if (infile >> s)
	{
		Vnum = stoi(s);
	}
	Graph *g = new Graph(Vnum);
	int i = 0;
	int u = -1;
	int v = -1;
	while (infile >> s)
	{
		if (i == 0)
		{
			u = stoi(s);
			i++;
		}
		else if (i == 1)
		{
			v = stoi(s);
			i++;
			g->AddEdge(u, v,0);
			//g->AddEdge(v, u, 0);
			i = 0;
		}
	}
	infile.close();
	return g;
}
vector<int>* ReadFileTools::readFileToArray(string fileName)
{
	vector<int> *result = new vector<int>();
	string s;
	ifstream infile;
	infile.open(fileName);
	if (!infile)
	{
		cout << "error";
		exit(-1);
	}
	while (infile >> s)
	{
		result->push_back(stoi(s));
	}
	return result;
}
void ReadFileTools::writeFile(vector<int>* result,string fileName)
{
	vector<int>::iterator it;

	ofstream myfile(fileName);
	if (myfile.is_open())
	{
		for (it = (*result).begin(); it != (*result).end(); it++)//根据pre从小到大的顺序
		{
			int x = *it;
			myfile << x;
			myfile << " ";
		}
		myfile.close();
	}
	delete result;
}
ReadFileTools::~ReadFileTools()
{
}
