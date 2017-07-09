//链表实现的并查集，uniprot22m运行时间为810000ms。证明比路径运行时间长。
namespace algo
{
	template <typename T>
	void exch(T* s1, T* s2)
	{
		T *temp = s1;
		s1 = s2;
		s2 = temp;
	}
	template <typename T>
	struct setlink;
	template <typename T>
	struct Node
	{
		T value;
		setlink<T> *header;
		Node<T> *next;
	};
	template <typename T>
	struct setlink
	{
		int length;
		Node<T> *head;
		Node<T> *tail;
	};
	
	template <typename T>
	void make_set_link(setlink<T> *s, Node<T> *node)
	{
		s->length = 1;
		s->head = node;
		s->tail = node;
		node->next = NULL;
		node->header = s;
	}
	template <typename T>
	void union_set_link(setlink<T> *s1, setlink<T> *s2)
	{
		if (s1->length < s2->length)
		{
			exch(s1,s2);	
		}
		s1->tail->next = s2->head;
		s1->tail = s2->tail;

		Node<int>* p = s2->head;
		while (p)
		{
			p->header = s1;
			p = p->next;
		}
		s1->length += s2->length;
		if (s2)
		{
			delete s2;
		}
	}
	template <typename T>
	setlink<T>* find_set_link(Node<T>* node)
	{
		return node->header;
	}
}