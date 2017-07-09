#pragma once
#include <time.h>   
#include <iostream>
#include "SelectAlgo.h"
using namespace std;
namespace algo
{
	//插入排序算法
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
	//每5个元素分成一组,找到一个中位数,返回中位数
	int selectMidNum(int* A, int p, int q)
	{
		if (p==q)
		{
			return A[p];
		}
		int k = (q - p + 1) / 5 + 1;//5个元素一组，总共需要分成多杀组。
		int *B = new int[k];
		int j = 0;

		//对每5个元素寻找中位数start
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
		//对每5个元素寻找中位数end
		int m = selectMidNum(B, 0, k - 1);
		return m;
	}
	//根据中位数对数组进行分组。
	int partition(int* A,int p,int q,int pivot)
	{
		//循环不变量：x<=i时，A[x]<=pivot;i<x<j时，A[x]>pivot;x>=j时，未知。
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