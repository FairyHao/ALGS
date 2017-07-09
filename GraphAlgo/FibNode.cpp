#include "stdafx.h"
#include "FibNode.h"


FibNode::FibNode()
{
}
FibNode::FibNode(double x)
{
	this->data = x;
	this->parent = NULL;
	this->child = NULL;
	this->mark = false;
	this->right = NULL;
	this->left = NULL;
	this->degree = 0;
}
FibNode::FibNode(double x,int id)
{
	this->data = x;
	this->parent = NULL;
	this->child = NULL;
	this->mark = false;
	this->right = NULL;
	this->left = NULL;
	this->degree = 0;
	this->id = id;
}

FibNode::~FibNode()
{
}
