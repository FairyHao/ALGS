#include "stdafx.h"
#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
}
Graph::Graph(int V)
{
	this->V = V;
	this->E = 0;
	this->vertices = new Graph::ArcLink[this->V];
	for (int i = 0; i < this->V; i++)
	{
		vertices[i] = NULL;
	}
}
void Graph::AddEdge(int u, int v, double weight)
{
	ArcNode *vnode = new ArcNode();//如果直接定义arcnode，定义的是局部变量，
	//把它的地址保存下来毫无意义，因为换个地方，这个地址就没有数据了。所以应直接定义链表形式，这样对象应该在堆空间中（个人猜测）
	vnode->adjvex = v;
	vnode->next = NULL;
	vnode->weight = weight;
	if (vertices[u] != NULL)
	{
		vnode->next = vertices[u];
	}		
	vertices[u] = vnode;
	this->E++;
}
Graph* Graph::Reverse()
{
	Graph *r = new Graph(this->V);
	int i = 0;
	while (i < this->V)
	{
		//处理每个结点的邻接链表
		ArcNode *p = this->vertices[i];
		while (p)
		{
			r->AddEdge(p->adjvex,i,p->weight);
			p = p->next;
		}
		i++;
	}
	return r;
}
Graph::ArcLink* Graph::getVertices()
{
	return this->vertices;
}
int Graph::getV()
{
	return this->V;
}

int Graph::addOneV()
{
	int oldV = this->V;
	this->V ++;
	Graph::ArcLink* temp = new Graph::ArcLink[this->V];
	temp[oldV] = NULL;
	for (int i = 0; i < oldV;i++)
	{
		temp[i] = this->vertices[i];
		ArcNode *vnode = new ArcNode();//如果直接定义arcnode，定义的是局部变量，
		//把它的地址保存下来毫无意义，因为换个地方，这个地址就没有数据了。所以应直接定义链表形式，这样对象应该在堆空间中（个人猜测）
		vnode->adjvex = i;
		vnode->next = NULL;
		vnode->weight = 0;
		vnode->next = temp[oldV];
		temp[oldV] = vnode;
		this->E++;
	}
	delete[] vertices;
	this->vertices = temp;
	return oldV;
}

void Graph::removeOneV()
{
	Graph::ArcLink  p = vertices[this->V-1];
	Graph::ArcLink q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
		this->E--;
	}
	this->V--;
}

int Graph::getE()
{
	return this->E;
}
Graph::~Graph()
{
	for (int i = 0;i < V;i++)
	{
		ArcLink p = vertices[i];
		while (p)
		{
			ArcLink q = p->next;
			delete p;
			p = q;
		}
	}
	if(vertices) delete[] vertices;
}
