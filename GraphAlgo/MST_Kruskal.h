#include "Graph.h"
#include "DisjointSet.h"
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

namespace algo
{
	struct Edge 
	{
		int u;
		int v;
		double weight;
	};
	struct less_than_key
	{
		//return true,第一个参数在第二个参数前面；return false，第一个参数在第二个参数后面。
		inline bool operator() (const Edge& struct1, const Edge& struct2)
		{
			return (struct1.weight < struct2.weight);
		}
	};

	//bool myfunction(int i, int j) { return (i < j); }上面的struct也可以用函数代替

	struct myclass {
		bool operator() (double i, double j) { return (i < j); }
	} myobject;
	double MST_Kruskal(Graph *g)
	{
		Edge *edges = new Edge[g->getE()];
		int x = 0;
		double weight = 0;
		map<int, algo::set<int>* > m;
		for (int i = 0; i < g->getV(); i++)
		{
			algo::set<int> *vertice = new algo::set<int>();
			vertice->value = i;
			algo::make_set(vertice);
			m.emplace(i,vertice);
			Graph::ArcLink ac = g->getVertices()[i];
			while (ac)
			{
				if (ac->adjvex >= i)
				{
					Edge e;
					e.u = i;
					e.v = ac->adjvex;
					e.weight = ac->weight;
					edges[x++] = e;
				}
				ac = ac->next;
			}
		}
		std::vector<Edge> myvector(edges, edges + (g->getE() / 2));
		std::sort(myvector.begin(), myvector.end(), less_than_key());
		x = 0;
		for (std::vector<Edge>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			int u = (*it).u;
			int v = (*it).v;
			set<int> *s1 = m.find(u)->second;
			set<int> *s2 = m.find(v)->second;
			if (algo::find_set(s1) != algo::find_set(s2))
			{
				weight += (*it).weight;
				algo::union_set(s1, s2);
			}
			x++;
		}
		return weight;
	}
}