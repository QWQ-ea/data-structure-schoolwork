#ifndef HEAP_H
#define HEAP_H
#include "Assistance.h"					// 辅助软件包
template<class ElemType> class MinHeap{
private:
	ElemType *heapArr;
	int CurrentSize;
	int MaxSize;
	void FilterDown(int Start);
	void FilterUp(int End);
public :
	MinHeap(int maxSize=150001);
	MinHeap(ElemType a[],int maxsize,int n);
	~MinHeap(){delete []heapArr;}
	Status Insert(const ElemType &e);
	Status DeleteTop();
	ElemType GetTop();
	bool IsEmpty()const{return CurrentSize == 0;}
	bool IsFull()const{return CurrentSize == MaxSize;}
	int SizeOfHeap(){return CurrentSize;}
	void SetEmpty(){CurrentSize=0;}
	void Traverse(void (*Visit)(const ElemType &)) const;
};
template<class ElemType>
MinHeap<ElemType>::MinHeap(int maxSize)
{
    if (maxSize <= 0)		{
	    cerr << "堆的大小不能小于1" << endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new ElemType[MaxSize];
	CurrentSize = 0;
}

template<class ElemType>
MinHeap<ElemType>::MinHeap(ElemType a[],int maxSize,int n)
{
	if(n <= 0)	{
	    cerr << "堆的大小不能小于1" << endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new ElemType [MaxSize];
	CurrentSize=0;
	while(CurrentSize<n) Insert(a[CurrentSize]);
}

template<class ElemType>
void MinHeap<ElemType>::FilterDown(const int Start)
{
	int i = Start,j;
	ElemType temp = heapArr[i];
	j = 2 * i + 1;
	while(j <= CurrentSize - 1)		{
		if(j < CurrentSize - 1 && heapArr[j] > heapArr[j+1])
			j++;
		if(temp <= heapArr[j]) break;
		else {
			heapArr[i] = heapArr[j];
			i = j;
            j = 2*j+1;
		}
	}
	heapArr[i] = temp;
}

template<class ElemType>
void MinHeap<ElemType>::FilterUp(int End)
{
	int j = End,i;
	ElemType temp = heapArr[j];
	i = (j - 1) / 2;
	while(j > 0)	{
		if (heapArr[i] <= temp) break;
		else {
			heapArr[j] = heapArr[i];
			j = i;
			i = (j - 1) / 2;
		}
		heapArr[j] = temp;
	}
}

template<class ElemType>
Status MinHeap<ElemType>::Insert(const ElemType &e)
{
	if (IsFull())
		return OVER_FLOW;
	heapArr[CurrentSize] = e;
	FilterUp(CurrentSize);
	CurrentSize++;
	return SUCCESS;
}
	
template<class ElemType>
Status MinHeap<ElemType>::DeleteTop()
{
	if(IsEmpty())
    	return UNDER_FLOW;
	heapArr[0] = heapArr[CurrentSize-1];
	CurrentSize--;
	FilterDown(0);
	return SUCCESS;
}

template<class ElemType>
ElemType MinHeap<ElemType>::GetTop()
{
	if(IsEmpty())
    	return UNDER_FLOW;
	else return heapArr[0];
}

template<class ElemType>
void MinHeap<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	for(int i = 0; i < CurrentSize; i++)
		(*Visit)(heapArr[i]);
}





template<class ElemType> class MaxHeap{
private:
	ElemType *heapArr;
	int CurrentSize;
	int MaxSize;
	void FilterDown(int Start);
	void FilterUp(int End);
public :
	MaxHeap(int maxSize=150001);
	MaxHeap(ElemType a[],int maxsize,int n);
	~MaxHeap(){delete []heapArr;}
	Status Insert(const ElemType &e);
	Status DeleteTop();
	ElemType GetTop();
	bool IsEmpty()const{return CurrentSize == 0;}
	bool IsFull()const{return CurrentSize == MaxSize;}
	int SizeOfHeap()const{return CurrentSize;}
	void SetEmpty(){CurrentSize=0;}
	void Traverse(void (*Visit)(const ElemType &)) const;
};
template<class ElemType>
MaxHeap<ElemType>::MaxHeap(int maxSize)
{
	if (maxSize <= 0)		{
		cerr << "堆的大小不能小于1" << endl;
		exit(1);
	}
	MaxSize = maxSize;
	heapArr = new ElemType[MaxSize];
	CurrentSize = 0;
}

template<class ElemType>
MaxHeap<ElemType>::MaxHeap(ElemType a[],int maxSize,int n)
{
	if(n <= 0)	{
		cerr << "堆的大小不能小于1" << endl;
		exit(1);
	}
	MaxSize = maxSize;
	heapArr = new ElemType [MaxSize];
	CurrentSize=0;
	while(CurrentSize<n) Insert(a[CurrentSize]);
}

template<class ElemType>
void MaxHeap<ElemType>::FilterDown(const int Start)
{
	int i = Start,j;
	ElemType temp = heapArr[i];
	j = 2 * i + 1;
	while(j <= CurrentSize - 1)		{
		if(j < CurrentSize - 1 && heapArr[j] < heapArr[j+1])
			j++;
		if(temp >= heapArr[j]) break;
		else {
			heapArr[i] = heapArr[j];
			i = j;
			j = 2*j+1;
		}
	}
	heapArr[i] = temp;
}

template<class ElemType>
void MaxHeap<ElemType>::FilterUp(int End)
{
	int j = End,i;
	ElemType temp = heapArr[j];
	i = (j - 1) / 2;
	while(j > 0)	{
		if (heapArr[i] >= temp) break;
		else {
			heapArr[j] = heapArr[i];
			j = i;
			i = (j - 1) / 2;
		}
		heapArr[j] = temp;
	}
}

template<class ElemType>
Status MaxHeap<ElemType>::Insert(const ElemType &e)
{
	if (IsFull())
		return OVER_FLOW;
	heapArr[CurrentSize] = e;
	FilterUp(CurrentSize);
	CurrentSize++;
	return SUCCESS;
}

template<class ElemType>
Status MaxHeap<ElemType>::DeleteTop()
{
	if(IsEmpty())
		return UNDER_FLOW;
	heapArr[0] = heapArr[CurrentSize-1];
	CurrentSize--;
	FilterDown(0);
	return SUCCESS;
}

template<class ElemType>
ElemType MaxHeap<ElemType>::GetTop()
{
	if(IsEmpty())
		return UNDER_FLOW;
	else return heapArr[0];
}

template<class ElemType>
void MaxHeap<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	for(int i = 0; i < CurrentSize; i++)
		(*Visit)(heapArr[i]);
}
#endif
