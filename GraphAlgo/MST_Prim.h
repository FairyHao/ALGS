#include "Graph.h"
#include "FibHeap.h"

using namespace std;
namespace algo{
double MST_Prim(Graph *g, int r)
{
	double weight = 0;
	int V = g->getV();
	//int *par = new int[V];//如果需要计算出路径，则可以用这个。
	FibHeap *fh = new FibHeap();
	for (int i = 0; i < V; i++)
	{
		FibNode *fn = new FibNode(10000000000, i);
		fh->Heap_Insert(fn);
		//par[i] = -1;
	}
	fh->Decrease_Key(fh->FindNodeByid(r), 0);
	while (fh->Minimum())
	{
		FibNode *x = fh->Extract_Min();
		//FibNode *xnnn = fh->FindNodeByid(1);
		weight += x->data;
		Graph::ArcLink ac = g->getVertices()[x->id];
		while (ac)
		{
			FibNode *tmp = fh->FindNodeByid(ac->adjvex);
			if (tmp && tmp->data > ac->weight)
			{
				fh->Decrease_Key(tmp, ac->weight);
				//par[ac->adjvex] = x->id;
			}
			ac = ac->next;
		}
	}
	/*for (int i = 0; i < V;i++)
	{
	cout << par[i] << endl;
	}*/
	//std::cout << weight << endl;
	if (fh)
	{
		delete fh;
	}
	return weight;
}
}