#include"swap.h"
#include"insert.h"
#include"select.h"
#include"merge.h"
#include"radix.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
fstream file("hybriddigit30.txt",ios::in);
int n;
cin>>n;
cout<<n<<"个多位随机数的序列"<<endl;
int a[n],b[n],x,y;
Node<int> c[n+1];
for(int i=0;i<n;i++) file>>a[i];
file.close();
	
    cout<<"冒泡排序:"<<endl;
    x=0;y=0;
    for(int i=0;i<n;i++) b[i]=a[i];
    BubbleSort(b,n,x,y);	
    cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	

	
	cout<<"快速排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	QuickSort(b,0,n-1,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"直接插入排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	StraightInsertSort(b,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"静态链表直接插入排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) {c[i+1].data=a[i];c[i].next=i+1;}
	c[n].next=-1;
	LinkInsertSort(c,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"希尔排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	ShellSort(b,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"简单选择排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	SimpleSelectionSort(b,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"静态链表简单选择排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) {c[i+1].data=a[i];c[i].next=i+1;}
	c[n].next=-1;
	LinkSelectionSort(c,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"堆排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	HeapSort(b,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	
	cout<<"归并排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	MergeSort(b,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	
	cout<<"递归归并排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	RecursionMergeSort(b,0,n-1,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"静态链表归并排序:"<<endl;
	x=0;y=0;
	for(int i=0;i<n;i++) {c[i+1].data=a[i];c[i].next=-1;}
	c[n].next=-1;
    LinkListMergeSort(c,1,n,x,y);	
	 cout<<"比较次数为:"<<x<<" 移动次数为:"<<y<<" 总时间复杂度为:"<<x+y<<endl;	
	
	cout<<"静态链表基数排序:"<<endl;
	x=0;
	for(int i=0;i<n;i++) {c[i+1].data=a[i];c[i].next=i+1;}
	c[n].next=-1;
	RadixSort(c,7,10,x);	
	cout<<"时间复杂度为:"<<x<<endl;
	
}
