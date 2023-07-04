#ifndef RADIX_H
#define RADIX_H
#include"hanshu.h"
#include<math.h>

template<class ElemType>
void RadixSort(Node<ElemType> elem[],const int d,const int radix,int &x)
{
	int e[radix],f[radix],p,i,j,k,power;
	for(i=0;i<d;i++)
	{
		for(j=0;j<radix;j++) f[j]=0;
		power=(int)pow((double)radix,i);
		p=elem[0].next;
		while(p!=-1)
		{
			k=(elem[p].data/power)%radix;
			if(f[k]==0) f[k]=p;
			else elem[e[k]].next=p;
			x+=1;
			e[k]=p;
			p=elem[p].next;
		}
		j=0;
		while(f[j]==0) j++;
		elem[0].next=f[j];
		p=e[j];
		x+=1;
		for(k=j+1;k<radix;k++)
		{
			if(f[k]!=0)
			{
			    elem[p].next=f[k];	
				p=e[k];
			}
			x+=1;
		}
		elem[p].next=-1;
	}
}
#endif
