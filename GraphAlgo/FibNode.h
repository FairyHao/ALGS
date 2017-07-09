#pragma once
class FibNode
{
public:
	FibNode();
	FibNode(double x);
	FibNode(double x, int vertice);
	~FibNode();
public:
	int id;
	double data;
	FibNode *left;
	FibNode *right;
	FibNode *parent;
	FibNode *child;
	bool mark;
	int degree;
};

