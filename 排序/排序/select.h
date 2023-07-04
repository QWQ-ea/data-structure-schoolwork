#ifndef SELECT_H
#define SELECT_H
#include"hanshu.h"

template<class ElemType>
void SimpleSelectionSort(ElemType elem[],int n,int &x,int &y)
{
	int k;
	for(int i=0;i<n-1;i++)
	{
		k=i;
		for(int j=i+1;j<n;j++)
		{
			if(elem[j]<elem[k]) k=j;
			x+=1;
		}
		if(k!=i) Swap(elem[i],elem[k]);
		y+=3;
	}
}

template<class ElemType>
void LinkSelectionSort(Node<ElemType> elem[],int &x,int &y)
{
    int p,q,pp,pq,h;	
	h=p=elem[0].next;
	elem[0].next=-1;
	while(p!=-1)
	{
	 q=pq=pp=p;
	 p=elem[p].next;
	 while(p!=-1)
	 {
		 if(elem[p].data>=elem[q].data)
		 {
			 q=p;
			 pq=pp;
		 }
		 x+=1;
		 pp=p;
		 p=elem[p].next;
	 }
	 if(h==q)
	 {
		h=elem[q].next;
		elem[q].next=elem[0].next;
		elem[0].next=q;
		 y+=2;
 	 }
	 else
	 {
		elem[pq].next=elem[q].next;
		 elem[q].next=elem[0].next;
		 elem[0].next=q;
		 y+=3;
	 }
	p=h;
	}
}

template<class ElemType>
void FilterDown(ElemType elem[],int low,int high,int &x,int &y)
{
    int f=low,i=2*low+1;
	ElemType e=elem[low];
	while(i<=high)
	{
		if(i<high&&elem[i]<elem[i+1]) i++;
		x+=1;
		if(e<elem[i])
		{
			elem[f]=elem[i];
			f=i;
			i=2*f+1;
			y+=1;
		}
		else break;
		x+=1;
	}
	elem[f]=e;
	y+=2;
}

template<class ElemType>
void HeapSort(ElemType elem[],int n,int &x,int &y)
{
	int i;
	for(i=(n-2)/2;i>=0;--i) FilterDown(elem,i,n-1,x,y);
	for(i=n-1;i>0;--i)
	{
		Swap(elem[0],elem[i]);
		y+=3;
		FilterDown(elem,0,i-1,x,y);
	}
}

#endif
