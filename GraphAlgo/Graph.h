#pragma once
class Graph
{
public:
	Graph();
	Graph(int V);
	virtual ~Graph();
	void AddEdge(int u,int v,double weight);
	Graph* Reverse();
	//邻接链表节点
	typedef struct ArcNode
	{
		ArcNode():adjvex(-1), next(NULL),weight(0){}
		int adjvex;
		ArcNode *next;
		double weight;
	}ArcNode, *ArcLink;
	//获取结点
	Graph::ArcLink* getVertices();
	int getV();
	int addOneV();
	int getE();
	void removeOneV();

private:
	int V;
	int E;
	Graph::ArcLink *vertices;//数组不能写vertices[]，准确的说我不知道如何写？
	//一个指针必须初始化，这个指针初始化后，里面的每个元素也必须初始化
};

