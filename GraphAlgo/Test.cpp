// GraphAlgo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include "ReadFileTools.h"
using namespace std;
#include <queue>
#include <iostream>
#include "FibHeap.h"
#include <windows.h>
#include "DisjointSet.h"
#include "MST_Prim.h"
#include "MST_Kruskal.h"
#include "ConnectComponent.h"
#include "ShortestPath_Bellmanford.h"
#include "shortestpath_dijkstra.h"
#include "ShortestPath_Johnson.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Fibonacci test
	
	//vector<int> *result = ReadFileTools::readFileToArray("Sort_data/repeat.txt");
	//FibHeap *fh = new FibHeap();
	//vector<int>::iterator it;
	//for (it = (*result).begin(); it != (*result).end(); it++)//����pre��С�����˳��
	//{
	//	int x = *it;
	//	FibNode *fn = new FibNode(x);
	//	fh->Heap_Insert(fn);
	//}
	//result->clear();
	//DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	//start1 = GetTickCount();
	//while (fh->Minimum())
	//{
	//	FibNode *tmp = fh->Extract_Min();
	//	result->push_back(tmp->data);
	//	delete tmp;
	//}
	//end1 = GetTickCount();//��ȡ��������                                                            
	//double elapsedtime1 = double(end1 - start1);//������������ʱ��
	//cout << "run time" << elapsedtime1 << endl;
	//ReadFileTools::writeFile(result,"Sort_data/tt_order.txt");
	//Fibonacci test
	
	//MST_Prim test
	/*Graph* g = ReadFileTools::readFile("MinCreateTree/Ol.txt");
	DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	double weight = algo::MST_Prim(g, 0);
	end1 = GetTickCount();//��ȡ��������                                                            
	double elapsedtime1 = double(end1 - start1);//������������ʱ��
	cout << "weight" << weight << endl;
	cout << "Ol run time" << elapsedtime1 << endl;
	if (g) delete g;*/
	//MST_Prim test

	//Disjointset test
	/*
	algo::set<int> s1;
	algo::set<int> s2;

	algo::make_set(&s1);
	algo::make_set(&s2);

	map<int, algo::set<int> > m;

	algo::set<int> *x1 = algo::find_set(&s1);
	algo::set<int> *x2 = algo::find_set(&s2);

	algo::union_set(&s1, &s2);

	x1 = algo::find_set(&s1);
	x2 = algo::find_set(&s2);*/
	//Disjointset test

	//Kruskal MST algorithms test
	/*Graph* g = ReadFileTools::readFile("MinCreateTree/SAN.txt");
	DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	double weight = algo::MST_Kruskal(g);
	end1 = GetTickCount();//��ȡ��������
	double elapsedtime1 = double(end1 - start1);//������������ʱ��
	cout << "weight" << weight << endl;
	cout << "run time" << elapsedtime1 << endl;
	if (g) delete g;*/
	//Kruskal MST algorithms test

	//ConnectComponent test
	//Graph* g = ReadFileTools::readFileUdg("ConnectedComponents/uniprot22m.txt");
	//DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	//start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	//int num = algo::getCCNumBylink(g);
	//end1 = GetTickCount();//��ȡ��������
	//double elapsedtime1 = double(end1 - start1);//������������ʱ��
	//cout << "num " << num << endl;
	//cout << "run time" << elapsedtime1 << endl;
	//if (g) delete g;
	//ConnectComponent test

	//Bellman Ford algorithm test
	//Graph* g = ReadFileTools::readFileToDg("ShortestPath/san.txt");
	//DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	//start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	//bool b = algo::BellmanFord(g,0);
	//end1 = GetTickCount();//��ȡ��������
	//double elapsedtime1 = double(end1 - start1);//������������ʱ��
	//string s = b ? "�������·��" : "���������·��";
	//cout << s << endl;
	//cout << "run time" << elapsedtime1 << endl;
	//if (g) delete g;
	//Bellman Ford algorithm test

	//Dijkstra test 
	//Graph* g = ReadFileTools::readFileToDg("ShortestPath/ol.txt");
	//DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	//start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	//algoDisj::dijkstra(g, 0);
	//end1 = GetTickCount();//��ȡ��������
	//double elapsedtime1 = double(end1 - start1);//������������ʱ��
	//cout << "run time" << elapsedtime1 << endl;
	//if (g) delete g;
	//Dijkstra test
	//johnson test
	Graph* g = ReadFileTools::readFileToDg("ShortestPath/tgroad.txt");
	DWORD start1, end1;//DWORD is 32 bit unsigned long;����Χ��0-4294967295�������windows�ṩ�ģ���include window.h
	start1 = GetTickCount();//��ȡ��ϵͳ����֮���ȥ�ĺ�������return DWORD��ÿ����.����飰
	algo::Johnson(g);
	end1 = GetTickCount();//��ȡ��������
	double elapsedtime1 = double(end1 - start1);//������������ʱ��
	cout << "run time" << elapsedtime1 << endl;
	if (g) delete g;
	//johnson test
	while (1);
	return 0;
}
