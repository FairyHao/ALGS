#ifndef ALGO_DISJOINTSET_H__
#define ALGO_DISJOINTSET_H__

namespace algo
{
	template<class T>
	struct set
	{
		T value;
		set<T>* parent;
		int rank;
		//set() :value(-1){}
	};
	template<typename T>
	void make_set(set<T> *s)
	{
		s->parent = s;
		s->rank = 0;
	}
   template<typename T>
   void union_set(set<T> *s1, set<T> *s2)
   {
	   link(find_set(s1), find_set(s2));
   }
   template<typename T>
   void link(set<T> *s1, set<T> *s2)
   {
	   if (s1->rank < s2->rank)
	   {
		   s1->parent = s2;
	   }
	   else
	   {
		   s2->parent = s1;
		   if (s1->rank == s2->rank)
		   {
			   s1->rank++;
		   }
	   }
   }
   template<typename T>
   set<T>* find_set(set<T> *x)
   {
	   if (x->parent != x)
	   {
		   x->parent = find_set(x->parent);
	   }
	   return x->parent;
   }
}
#endif