#ifndef MERGE_H
#define MERGE_H
#include"hanshu.h"

template<class ElemType>
void Merge(ElemType elem[],int low,int mid,int high,int &x,int &y)
{
	ElemType *tmpElem=new ElemType[high+1];
	int i=low,j=mid+1,k=low;
	while(i<=mid&&j<=high)
	{
		if(elem[i]<=elem[j])
			tmpElem[k++]=elem[i++];
	    else
			tmpElem[k++]=elem[j++];
	    x+=1;
	    y+=1;
	}
	while(i<=mid) {tmpElem[k++]=elem[i++];y+=1;}
	while(j<=high) {tmpElem[k++]=elem[j++];y+=1;}
	for(i=low;i<=high;i++) {elem[i]=tmpElem[i];y+=1;}
	delete []tmpElem;
}

template<class ElemType>
void MergeSort(ElemType elem[],int n,int &x,int &y)
{
	int len=1,i;
	while(len<n)
	{
		i=0;
		while(i+2*len<=n)
		{
			Merge(elem,i,i+len-1,i+2*len-1,x,y);
			i+=2*len;
		}
		if(i+len<n) Merge(elem,i,i+len-1,n-1,x,y);
		len*=2;
	}
	
}

template<class ElemType>
void RecursionMergeSort(ElemType elem[],int low,int high,int n,int &x,int &y)
{
if(low<high)
{
	int mid=(low+high)/2;
	RecursionMergeSort(elem,low,mid,n,x,y);
	RecursionMergeSort(elem,mid+1,high,n,x,y);
	Merge(elem,low,mid,high,x,y);
}	
}

template<class ElemType>
int LinkListMerge(Node<ElemType> elem[],int p,int q,int &x,int &y)
{
    int k=0;
	while(p!=-1&&q!=-1)
	{
		if(elem[p].data<=elem[q].data)
		{
			elem[k].next=p;
			k=p;
			p=elem[p].next;
			y+=1;
		}
	    else
		{
			elem[k].next=q;
			k=q;
			q=elem[q].next;
			y+=1;
		}
		x+=1;
	}
	if(p==-1) elem[k].next=q;
	else elem[k].next=p;
	y+=1;
	return elem[0].next;
}

template<class ElemType>
int LinkListMergeSort(Node<ElemType> elem[],int low,int high,int &x,int &y)
{
if(low>=high) return low;
int mid=(low+high)/2,p,q;
p=LinkListMergeSort(elem,low,mid,x,y);
q=LinkListMergeSort(elem,mid+1,high,x,y);
return LinkListMerge(elem,p,q,x,y);
}


#endif
