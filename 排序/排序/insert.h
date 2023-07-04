#ifndef INSERT_H
#define INSERT_H
#include"hanshu.h"

template<class ElemType>
void StraightInsertSort(ElemType elem[],int n,int &x,int &y)
{
int i,j;
for(i=1;i<n;i++)
{
ElemType e=elem[i];
for(j=i-1;j>=0&&e<elem[j];j--) {elem[j+1]=elem[j];y+=1;x+=1;}
x+=1;
elem[j+1]=e;
y+=2;
}	
}

template<class ElemType>
void LinkInsertSort(Node<ElemType> elem[],int &x,int &y)
{
int p,q,pre,r;
p=elem[0].next;
elem[0].next=-1;
y+=1;
while(p!=-1)
{
q=elem[0].next;
pre=0;
while(q!=-1&&elem[q].data<=elem[p].data)
 {
 pre=q;
 q=elem[q].next;
 x+=1;
 }
x+=1;
r=elem[p].next;
elem[p].next=q;
elem[pre].next=p;
y+=2;
p=r;
}	
}

template<class ElemType>
void ShellSort(ElemType elem[],int n,int &x,int &y)
{
 int i,j,d=n/2;
 ElemType e;
 while(d>0)
 {
	for(i=d;i<n;i++)
	{
		e=elem[i];
		j=i-d;
		while(j>=0&&e<elem[j])
		{
			elem[j+d]=elem[j];
			j-=d;
			x+=1;
			y+=1;
		}
		x+=1;
		elem[j+d]=e;
		y+=2;
	}
	d=d/2;
 }
	
}

#endif 
