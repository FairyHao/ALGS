#include "Graph.h"
#include "iostream"
//#include "ShortestPath_Bellmanford.h"//不用写这两句，写了反倒报错，原因不详
//#include "shortestpath_dijkstra.h"
#define INFINITE 0xFFFFFFFF
using namespace std;

namespace algo
{
	double recomputeWeight(double weight, int u, int v)
	{
		double newweight = weight + algo::d[u]-algo::d[v];
		return newweight;
	}
	void Johnson(Graph *g)
	{
		//step1:add a vertex to Graph;
		int s = g->addOneV();
		//step2:compute  shortest path of s to all nodes
		bool b = algo::BellmanFord(g, s);
		if (!b)
		{
			cout << "the input graph contains a negative-weight cycle";
		}
		else
		{
			//step3:compute new weight of g;
			Graph::ArcLink* vertices = g->getVertices();
			for (int i = 0; i < g->getV(); i++)
			{
				Graph::ArcLink p = vertices[i];
				while (p)
				{
					p->weight = recomputeWeight(p->weight,i,p->adjvex);
					p = p->next;
				}
			}
			//step4:using dijkstra algorithms to compute shortest path of g;
			//创建一个二维数组 start
			double** dd = new double*[g->getV()-1];
			for (int i = 0; i < g->getV()-1;i++)
			{
				dd[i] = new double[g->getV()-1];
			}
			g->removeOneV();
			//创建一个二维数组 end
			for (int i = 0; i < g->getV();i++)
			{
				algoDisj::dijkstra(g, i);
				for (int j = 0; j < g->getV(); j++)
				{
					dd[i][j] = algoDisj::d1[j] + algo::d[j] - algo::d[i];
					//cout << i << "->" << j << " "<<dd[i][j] << " ";
				} 
				cout <<i<< endl;
			}
		}

	}
}