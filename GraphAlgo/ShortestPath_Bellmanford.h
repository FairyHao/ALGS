#include "Graph.h"
#define INFINITE 0xFFFFFFFF
namespace algo
{
	int Vnum;
	double *d;
	//int *par;
	void initialize_single_source(Graph *g, int s)
	{
		Vnum = g->getV();              
		d = new double[Vnum];
//		 par = new int[Vnum];
		for (int i = 0; i < Vnum; i++)
		{
			d[i] = INFINITE;
			//par[i] = -1;
		}
		d[s] = 0;
	}
	void relax(int u, int v, double weight)
	{
		if (d[v] > d[u] + weight)
		{
			d[v] = d[u] + weight;
			//par[v] = u;
		}
	}
	//单源节点的最短路径求法
	bool BellmanFord(Graph *g, int s)
	{
		//初始化结点的距离
		initialize_single_source(g, s);
		//获取所有的邻接链表
		Graph::ArcLink* al = g->getVertices();
		int edgesNum = g->getE();
		int e = 0;
		int j = 0;
		//Bellman Ford 算法核心思想
		for (int i = 0; i < g->getV() - 1; i++)
		{
			for (int j = 0; j < g->getV(); j++)
			{
				Graph::ArcNode *p = al[j];
				while (p)
				{
					relax(j, p->adjvex, p->weight);
					p = p->next;
				}
			}
		}
		for (int u = 0; u < g->getV(); u++)
		{
			Graph::ArcNode *p = al[u];
			while (p)
			{
				int v = p->adjvex;
				if (d[v] > d[u] + p->weight)
				{
					return false;
				}
				p = p->next;
			}
		}

		/*for (int i = 0; i < g->getV(); i++)
		{
		cout << s << "-" << i <<"的路径长度为：" << d[i] << " " << endl;
		cout << s << "-" << i << "路劲为：" << i << "<-";
		int x = par[i];
		while ( x != -1 )
		{
		cout << x << "<-";
		x = par[x];
		}
		cout << endl;
		}*/
		return true;
	}
	
}