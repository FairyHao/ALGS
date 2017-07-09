#pragma once
#include <time.h>   
#include <iostream>
using namespace std;
namespace algo
{
	void exch(int* A, int p, int q)
	{
		int temp = A[p];
		A[p] = A[q];
		A[q] = temp;
	}
	int partition(int* A, int p, int q)
	{
		//srand(time(NULL));
		int x = rand()%(q-p+1)+p;//����p��q֮���һ���������
		exch(A,p,x);
		int pivot = A[p];
		int low = p;
		int high = q + 1;
		while (true)
		{
			while (A[--high] > pivot) if (high <= low) break;
			while (A[++low] < pivot) if (low >= high) break;
			if (low >= high)
			{
				break;
			}
			exch(A, low, high);//������������λ�õ�Ԫ�ء�
		}
		exch(A, high, p);
		return high;
	}
	//��A�����±�p��r�У�ѡ���iС�������ء�
	int randomized_select(int* A,int p,int r,int i)
	{
		if (p == r)
		{
			return A[p];
		}
		//ѡ�����࣬��A�ֳ�������
		int x = partition(A,p,r);
		int k = x - p + 1;
		if (i == k)
		{
			return A[x];
		}
		else if (i < k)
		{
			randomized_select(A, p, x - 1, i);
		}
		else
		{
			randomized_select(A,x+1,r,i-k);
		}
	}
}