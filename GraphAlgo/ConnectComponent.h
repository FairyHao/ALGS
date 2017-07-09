#include "Graph.h"
#include "DisjointSet.h"
#include "DisjointsetByLink.h"
#include <map>

using namespace std;

namespace algo
{
	int getCCNum(Graph *g)
	{
		int num = g->getV();
		int Vnum = g->getV();
		//map<int, algo::set<int>* > m;
		algo::set<int>* *sets = new algo::set<int>*[Vnum];//顶点与并查集的对应关系
		for (int i = 0; i < Vnum; i++)
		{
			algo::set<int> *vertice = new algo::set<int>();
			algo::make_set(vertice);
			sets[i] = vertice;
		}
		set<int> *s1 = NULL;
		set<int> *s2 = NULL;

		for (int i = 0; i < Vnum; i++)
		{
			s1 = sets[i];

			Graph::ArcLink ac = g->getVertices()[i];
			while (ac)
			{
				int v = ac->adjvex;
		
				s2 = sets[v];
				
				if (algo::find_set(s1) != algo::find_set(s2))
				{
					algo::union_set(s1, s2);
					num--;
				}
				ac = ac->next;
			}
		}
		return num;
	}
	int getCCNumBylink(Graph *g)
	{
		int num = g->getV();
		int Vnum = g->getV();
		//map<int, algo::set<int>* > m;
		algo::Node<int>* *nodes = new algo::Node<int>*[Vnum];//顶点与并查集的对应关系
		for (int i = 0; i < Vnum; i++)
		{
			algo::setlink<int> *vertice = new algo::setlink<int>();
			algo::Node<int> *node = new algo::Node<int>();
			node->value = i;
			algo::make_set_link(vertice,node);
			nodes[i] = node;
		}
		Node<int> *n1 = NULL;
		Node<int> *n2 = NULL;

		for (int i = 0; i < Vnum; i++)
		{
			n1 = nodes[i];

			Graph::ArcLink ac = g->getVertices()[i];
			while (ac)
			{
				int v = ac->adjvex;

				n2 = nodes[v];

				setlink<int> *s1 = algo::find_set_link(n1);
				setlink<int> *s2 = algo::find_set_link(n2);

				if (s1 != s2)
				{
					algo::union_set_link(s1, s2);
					num--;
				}
				ac = ac->next;
			}
		}
		return num;
	}
}