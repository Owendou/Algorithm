/************************************************************************/
/* The most common sort algorithm 
/* Author: Owendou on the begin of Aug ,2016
/* Implemented in C++
/************************************************************************/

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
* Bubble
* Average time : n^2
* Worst :n^2
* Stability: stable
*/

void _mySwap(int& a, int & b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void bubbleSort(int a[], size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool isOrder = true;
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] > a[j])
			{
				_mySwap(a[i], a[j]);
			}
		}
	}
}

/*
* select sort
* Worst :0(n*n)
*/

void selectSort(int a[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		int min = a[i];
		for (int j = i + 1; j < size; j++)
		{
			if(min>a[j])
			{
				min = a[j];
				_mySwap(a[j], a[i]);
			}
		}
	}
}

/*
* Insert sort
* Worst :0(n*n)
*/

void insertSort(int a[], size_t size)
{
	for (int i = 0; i < size;i++)
	{
		//int waitInsertValue = a[i];
		for (int j = i-1; j >= 0;j--)
		{
			if (a[j] > a[j+1])
			{
				_mySwap(a[j], a[j+1]);
			}
		}
	}
}

/*
* quick sort
* Average time: 0(nlogN)
* Worst :0(n*n)
* Stability: unstable
*/


void quickSort(int a[], int first, int last)
{
	//set a pivot, p:只是用来标记新的坑位
	int p = (first + last) / 2;
	int i = first;
	int j = last;
	int pValue = a[p];
	if (i < j)
	{
		while (i < j)
		{
			while (i < j && a[i] < pValue)
				i++;

			if (i < j)
			{
				//i<j 并且基准值的左边有大于等于pValue的值
				//开始挖坑
				a[p] = a[i];
				i = p;
			}

			while (i < j && pValue > a[j])
				j--;

			if (i < j)
			{
				//_mySwap(a[i], a[j]);
				a[i] = a[j];
				j = p;
			}
		}

		if (i == j)
			a[i] = pValue; 

		quickSort(a, first, p);
		quickSort(a, p + 1, last);
	}
}

/*
* version 2: quickSort
* partition: how to optimize
*/

//以最高位为基准重排，返回下一个基准位置
int partition(int a[], int low, int heigh)
{
	int pivotValue = a[heigh];
	int i = low - 1;
	for (int j = low; j < heigh; j++)
	{
		if (pivotValue >= a[j])
		{
			i++;
			//i：要比基准值大的下标，即将被交换
			//j: 要比基准值小的小标
			if (i != j)
				_mySwap(a[j], a[i]);
		}
	}

	//之前挖坑位置的值来填充
	swap(a[i + 1], a[heigh]);

	return i + 1;
}

void quickSort2(int a[], int first, int last)
{
	if (first < last)
	{
		int nextPivot = partition(a, first, last);
		quickSort2(a, first, nextPivot - 1);
		quickSort2(a, nextPivot + 1, last);
	}
}

/*
* MergeSort
* Average time:O(nlgN)
* Worst: 0(nlogN)
* Stability: Stable
*/
void MergeSort(int a[], int first, int mid , int end, int n)
{
	int* dstArr = new int[n];
	int i = first;
	int j = mid + 1;
	int k = 0;
	
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			dstArr[k++] = a[i++];
		else
			dstArr[k++] = a[j++];
	}
	 
	//左或右两边有可能还有剩余element

	while (i < mid)
	{
		dstArr[k++] = a[i++];
	}

	while (j < end)   
	{
		dstArr[k++] = a[j++];
	}

	//放Sort完的数据放回a中
	for (int _i = first, _k = 0; _i < end; _i++,_k++)
	{
		a[_i] = dstArr[_k];
	}

	delete[]dstArr;
	dstArr = nullptr; //local ptr 可有可无
}

void Merge(int a[] , int left, int right)
{
	if (left < right)
	{
		/*
		* 最经典的分治思想
		*/
		int pivot = (left + right) / 2;
		Merge(a, left, pivot);
		Merge(a, pivot + 1, right);
		MergeSort(a, left, pivot, right, right - left + 1);
	}
}


/*
* Heap sort 
* Average time: O(nlgN)
* Worst : 0(nlogN)
* Stability: Unstable
*/


/*
* Shell Sort
* Average time: O(nlgN)
* Worst : 0(n^s) 1<s<2
* Stability: Unstable
*/


int main()
{
	int a[] = { 23, 40, 50, 60, 80, 66, 100, 300, 400, 500, 600, 44, 23, 45};
	int _size = sizeof(a) / sizeof(a[0]);
	//Merge(a, 0, _size);
	//quickSort(a, 0, _size - 1);
	//bubbleSort(a, _size);
	//selectSort(a, _size);
	//insertSort(a, _size);
	quickSort2(a, 0, _size - 1);

	for (int i = 0; i < _size; i++)
		cout << a[i] << " ";

	system("pause");
    return 0;
}




