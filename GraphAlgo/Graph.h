#pragma once
class Graph
{
public:
	Graph();
	Graph(int V);
	virtual ~Graph();
	void AddEdge(int u,int v,double weight);
	Graph* Reverse();
	//�ڽ�����ڵ�
	typedef struct ArcNode
	{
		ArcNode():adjvex(-1), next(NULL),weight(0){}
		int adjvex;
		ArcNode *next;
		double weight;
	}ArcNode, *ArcLink;
	//��ȡ���
	Graph::ArcLink* getVertices();
	int getV();
	int addOneV();
	int getE();
	void removeOneV();

private:
	int V;
	int E;
	Graph::ArcLink *vertices;//���鲻��дvertices[]��׼ȷ��˵�Ҳ�֪�����д��
	//һ��ָ������ʼ�������ָ���ʼ���������ÿ��Ԫ��Ҳ�����ʼ��
};

