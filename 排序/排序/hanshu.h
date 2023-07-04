#ifndef HANSHU_H
#define HANSHU_H

template<class ElemType>
struct Node
{
	ElemType data;
	int next;
};

template<class ElemType>
void Swap(ElemType &a,ElemType &b)
{
	ElemType c;
	c=a;
	a=b;
	b=c;
}

#endif
