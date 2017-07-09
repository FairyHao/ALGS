#pragma once
#include <time.h>   
#include <iostream>
#include "SelectAlgo.h"
using namespace std;
namespace algo
{
	//���������㷨
	void Insertion_sort(int* A, int p, int q)
	{
		for (int i = p; i < q; i++)
		{
			for (int j = i + 1; j > p && A[j] < A[j - 1]; j--)
			{
				exch(A, j - 1, j);
			} 
		}
	}
	//ÿ5��Ԫ�طֳ�һ��,�ҵ�һ����λ��,������λ��
	int selectMidNum(int* A, int p, int q)
	{
		if (p==q)
		{
			return A[p];
		}
		int k = (q - p + 1) / 5 + 1;//5��Ԫ��һ�飬�ܹ���Ҫ�ֳɶ�ɱ�顣
		int *B = new int[k];
		int j = 0;

		//��ÿ5��Ԫ��Ѱ����λ��start
		int i = p;
		while (i + 4 <= q)
		{
			Insertion_sort(A, i, i + 4);
			B[j++] = A[i + 2];
			i += 5;
		}
		if (i <= q)
		{
			Insertion_sort(A, i, q);
			B[j++] = A[i + (q-i)/2];
		}
		//��ÿ5��Ԫ��Ѱ����λ��end
		int m = selectMidNum(B, 0, k - 1);
		return m;
	}
	//������λ����������з��顣
	int partition(int* A,int p,int q,int pivot)
	{
		//ѭ����������x<=iʱ��A[x]<=pivot;i<x<jʱ��A[x]>pivot;x>=jʱ��δ֪��
		int i = p - 1;
		for (int j = p;j <= q;j++)
		{
			if (A[j] <= pivot)
			{
				exch(A,j,++i);
			}
		}
		return i;
	}
	
	int select(int* A, int p, int q, int i)
	{
		if (p == q)
		{
			return A[p];
		}
		
		int m = selectMidNum(A, p, q);
		int x = partition(A, p, q, m);
		int k = x - p + 1;
		if (i == k)
		{
			return m;
		}
		else if (i < k)
		{
			select(A, p, x, i);
		}
		else
		{
			select(A, x + 1, q, i - k);
		}
	}
}