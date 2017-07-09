#pragma once
#include "FibNode.h"
#include <map>
using namespace std;
class FibHeap
{
public:
	FibHeap();
	~FibHeap();
	void Heap_Insert(FibNode* fn);
	FibNode* Minimum();//获取最小值，只是获取，不删除最小值
	FibNode* Extract_Min();
	FibNode* FindNodeByid(int x);
	void Decrease_Key(FibNode* x,double k);
	void CONSOLIDATE();
	void Cut(FibNode* x,FibNode* y);
	void Cascading_cut(FibNode* y);
public:
	int n;
	FibNode *min;
	int d;
    map<int, FibNode*> *m;
};

