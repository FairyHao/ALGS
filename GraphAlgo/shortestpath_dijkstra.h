#include "FibHeap.h"
#include "FibNode.h"
#include "Graph.h"
#include "iostream"
#define INFINITE 0xFFFFFFFF
using namespace std;
namespace algoDisj
{
	int Vnum;
	FibHeap *fh;
	double *d1 ;//每个顶点的最短路径
	//int *par1;//每个顶点的前驱顶点
	void initialize_single_source1(Graph *g,int s)
	{
		fh = new FibHeap();
		Vnum = g->getV();
		d1 = new double[Vnum];
		//par1 = new int[Vnum];
		for (int i = 0; i < Vnum; i++)
		{
			FibNode *node = new FibNode();
			if (i != s)
			{
				node->data = INFINITE;
			}
			else
			{
				node->data = 0;
			}
			node->id = i;
			fh->Heap_Insert(node);
			//par1[i] = -1;
		}
	}
	void relax1(FibNode* u, FibNode* v, double weight)
	{
		if (v->data > (u->data) + weight)
		{
			fh->Decrease_Key(v, (u->data) + weight);
			//par1[v->id] = u->id;
		}
	}
	void dijkstra(Graph *g, int s)
	{
		initialize_single_source1(g, s);
		Graph::ArcLink* al = g->getVertices();
		while (fh->min)
		{
			FibNode *node = fh->Extract_Min();
			int u = node->id;
			d1[u] = node->data;
			Graph::ArcLink p = al[u];
			while (p)
			{
				FibNode* vnode = fh->FindNodeByid(p->adjvex);
				if (vnode)
				{
					relax1(node, vnode, p->weight);
				}
				p = p->next;
			}
			delete node;
		}
		delete fh;
		/*for (int i = 0; i < g->getV(); i++)
		{
			cout << s << "-" << i << "的路径长度为：" << d1[i] << " " << endl;
			cout << s << "-" << i << "路劲为：" << i << "<-";
			int x = par1[i];
			while (x != -1)
			{
				cout << x << "<-";
				x = par1[x];
			}
			cout << endl;
		}*/
	}
}