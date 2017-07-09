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
	ArcNode *vnode = new ArcNode();//���ֱ�Ӷ���arcnode��������Ǿֲ�������
	//�����ĵ�ַ���������������壬��Ϊ�����ط��������ַ��û�������ˡ�����Ӧֱ�Ӷ���������ʽ����������Ӧ���ڶѿռ��У����˲²⣩
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
		//����ÿ�������ڽ�����
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
		ArcNode *vnode = new ArcNode();//���ֱ�Ӷ���arcnode��������Ǿֲ�������
		//�����ĵ�ַ���������������壬��Ϊ�����ط��������ַ��û�������ˡ�����Ӧֱ�Ӷ���������ʽ����������Ӧ���ڶѿռ��У����˲²⣩
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
