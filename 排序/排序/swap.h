#ifndef SWAP_H
#define SWAP_H
#include"hanshu.h"

template <class ElemType>
void BubbleSort(ElemType elem[],int n,int &x,int &y)
{
bool finish=false;
int i=1;
while(i<n&&!finish)
 {
finish=true;
for(int j=0;j<n-i;j++)
  { 
	x+=1;
	if(elem[j]>elem[j+1])
    {
		Swap(elem[j],elem[j+1]);
		y+=3;
		finish=false;
	}
  }
 i++;
 }	
}

template<class ElemType>
void QuickSort(ElemType elem[],int low,int high,int &x,int &y)
{
ElemType e=elem[low];
int i=low,j=high;
while(i<j)
{
	while(i<j&&elem[j]>=e) {j--;x+=1;}
	if(i<j) {elem[i++]=elem[j];y+=1;}
	while(i<j&&elem[i]<=e) {i++;x+=1;}
	if(i<j) {elem[j--]=elem[i];y+=1;}
}
elem[i]=e;
y+=2;
if(low<i-1) QuickSort(elem,low,i-1,x,y);
if(i+1<high) QuickSort(elem,i+1,high,x,y);
}

#endif
