#include "stdafx.h"
#include "FibHeap.h"
#include <math.h> 
#include <iostream>
using namespace std;

FibHeap::FibHeap()
{
	this->n = 0;
	this->min = NULL;
	this->m = new map<int, FibNode*>();
}
void FibHeap::Heap_Insert(FibNode* fn)
{
	if (this->min == NULL)
	{
		this->min = fn;
		fn->left = fn;
		fn->right = fn;
		fn->parent = NULL;
		fn->degree = 0;
		fn->child = NULL;
		fn->mark = false;
	}
	else
	{
		fn->right = this->min;
		fn->left = this->min->left;
		this->min->left->right = fn;
		this->min->left = fn;
		fn->parent = NULL;
		fn->degree = 0;
		fn->child = NULL;
		fn->mark = false;
		if (fn->data < this->min->data)
		{
			this->min = fn;
		}
	}
	this->m->insert(pair<int,FibNode*>(fn->id,fn));
	this->n++;
	this->d = floor(log2(double(this->n)));
}

FibNode* FibHeap::FindNodeByid(int x)
{
	std::map<int, FibNode*>::iterator it;
	it =this-> m->find(x);
	if (it != this->m->end())
		return it->second;
	else
	 return NULL;
}
FibNode* FibHeap::Minimum()
{
	return this->min;
}
//获取最小结点，并删除
FibNode* FibHeap::Extract_Min()
{
	FibNode *mn = this->min;
	if (mn)
	{
		//删除最小结点，先将最小结点的所有孩子添加在跟链表上。
		FibNode *firstchild = mn->child;
		
		if (firstchild)
		{
			//把孩子链表放在min指针旁边。
			FibNode *temp = firstchild->left;
			this->min->left->right = firstchild;
			firstchild->left = this->min->left;
			temp->right = this->min;
			this->min->left = temp;
			firstchild->parent = NULL;
		}
		//删除min指针。
		mn->left->right = mn->right;
		mn->right->left = mn->left;
		//删除min指针结束
		//调整min指针
		if (mn == mn->right)
		{ 
			this->min = NULL;
		}
		else
		{
			this->min = mn->right;
			CONSOLIDATE();
		}
		//FibNode* node = FindNodeByid(mn->id);
		//cout << "I am in fibHeap" << node->id << endl;
		this->m->erase(mn->id);
		//cout << "I am in fibHeap" << endl;
		//cout << "I am in fibHeap" << this << endl;
		this->n--;

	}
	return mn;
}

void FibHeap::CONSOLIDATE()
{
	FibNode* *A = new FibNode*[(this->d)+1];
	for (int i = 0; i <= (this->d);i++)
	{
		A[i] = NULL;
	}
	
	//遍历所有的根节点，对其进行合并
	FibNode *w = this->min;
	FibNode *start = this->min;//起始结点；为了判断所有的结点遍历完成
	do 
	{
		FibNode *x = w;
		FibNode *nextW = w->right;//下一个应该遍历的结点
		int d = x->degree;
		while (d <= (this->d) && A[d] != NULL)
		{
			FibNode* y = A[d];
			if (x->data > y->data)
			{
				//交换p和y，使p总是值小的结点
				FibNode *temp = x;
				x = y;
				y = temp;
			}
			if (y == start)
			{
				start = start->right;
			}
			if (y == nextW) {
				// If we wrapped around we need to check for this case.
				nextW = nextW->right;
			}
			//把y结点从跟链表中删除
			y->right->left = y->left;
			y->left->right = y->right;
			//把y结点从跟链表中删除end
			//把y结点加到孩子链表上
			if (x->child)
			{
				y->right = x->child->right;
				x->child->right->left = y;
				x->child->right = y;
				y->left = x->child;
			}
			else
			{
				x->child = y;
				y->right = y;
				y->left = y;
			}
			y->parent = x;
			y->mark = false;
			x->degree++;
			//把y结点加到孩子链表上end
			A[d] = NULL;
			d++;
		}			
		A[d] = x;
		w = nextW;
	} while (w != start);
	//遍历所有的根节点，对其进行合并处理，最后所有根结点的度都不同。
	this->min = NULL;
	for (int i = 0; i <= this->d;i++)
	{
		if (A[i]!= NULL)
		{
			if (this->min==NULL)
			{
				A[i]->left = A[i];
				A[i]->right = A[i];
				A[i]->parent = NULL;
				this->min = A[i];
			}
			else
			{
				A[i]->right = this->min;
				A[i]->left = this->min->left;
				this->min->left->right = A[i];
				this->min->left = A[i];
				A[i]->parent = NULL;
				if (A[i]->data < this->min->data)
				{
					this->min = A[i];
				}
			}
		}
	}
}

void FibHeap::Decrease_Key(FibNode* x, double k)
{
	if (k > x->data)
	{
		return;
	}
	x->data = k;
	FibNode *y = x->parent;
	if (y && x->data < y->data)
	{
		Cut(x,y);
		Cascading_cut(y);
	}
	if (x->data < this->min->data)
	{
		this -> min = x;
	}
}
void FibHeap::Cut(FibNode* x, FibNode* y)
{
	//remove x from child list
	if (x->right == x)
	{
		y->child = NULL;
	}
	else
	{
		x->left->right = x->right;
		x->right->left = x->left;
		y->child = x->right;
	}	
	y->degree--;
	//remove x from child list

	//add x to the root list 
	x->right = this->min;
	x->left = this->min->left;
	this->min->left->right = x;
	this->min->left = x;
	//add x to the root list 
	x->mark = false;
	x->parent = NULL;
}
void FibHeap::Cascading_cut(FibNode* y)
{
	FibNode *z = y->parent;
	if (z)
	{
		if (y->mark == false)
		{
			y->mark = true;
		}
		else
		{
			Cut(y,z);
			Cascading_cut(z);
		}
	}
}
FibHeap::~FibHeap()
{
	FibNode* p = min;
	while (p&&p!=min)
	{
		FibNode* q = p->right;
		delete p;
		p = q;
	}
	std::map<int, FibNode*>::iterator it;
	for (it = this->m->begin(); it != this->m->end(); it++)
		if(it->second)delete (*it).second;
	if(m)delete m;
}
