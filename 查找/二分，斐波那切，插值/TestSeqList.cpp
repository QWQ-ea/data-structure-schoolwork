#include "SeqList.h"	// 顺序表类
#include<conio.h>
int main(void)
{
	char c = '*';
	int i;
    Status sta;
	int b=Fib(6)-1;
	cout<<b<<endl;
	long long int elem[20]={1,10,90,1000,3000,15000,80000};
    SeqList<long long int> a(elem,b,2*b);
	while(c!='0')
	{
	 cout << endl << "1.二分递归查找";
	 cout << endl << "2.二分迭代查找";
	 cout << endl << "3.斐波那切查找";
	 cout << endl << "4.插值查找";
	 cout << endl << "0.退出";
	 cout << endl << "请选择功能:";
	 cin>>c;
	 switch(c)
	 {
	 case '1':
		 cout<<a.BinSearch(0,b-1,1000)<<endl;
		 break;
	 case '2':
		 cout<<a.BinSearch(b,1000)<<endl;
		 break;
	 case '3':
		 cout<<a.FibSearch(6,1000)<<endl;
		 break;
	 case '4':
		 cout<<a.ChaSearch(b,1000)<<endl;
		 break;
	 }
	}

   	system("PAUSE");        		// 调用库函数system()，暂停程序运行 
   	return 0;               		// 返回操作系统
}


