#include "MedianFinder"
int main()
{
	MedianFinder<int> finder,finder1,finder2,Finder;
	int a[12]={80,57,99,35,23,11,74,29,62,16,9,100};
	int b[13]={99,1000,233,22,11,3,7,86,108,89,66,78,666};
	int e;
	char c = 'x',s='x'; 
	cout<<endl;
    while (c != '0')	{
        cout << endl << "1. 找出集合a或b中的中位数(输入0代表a,1代表b)";
        cout << endl << "2. 找出任意集合中的中位数";
		cout << endl << "3. 测试文件中的30万个数据";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "输入指定的集合:";//(0代表a,1代表b)
			    cin >> e;
				if(e==0) {for(int i=0;i<12;i++) finder1.Makeheap(a[i]);cout<<endl<<"中位数为："<<finder1.findMedian()<<endl;}
				else if(e==1) {for(int i=0;i<13;i++) finder2.Makeheap(b[i]);cout<<endl<<"中位数为："<<finder2.findMedian()<<endl;}
			    break;
		    case '2':
				cout<<"输入要测试的集合：";
			    while(s!='\n')
				{
				cin>>e;
				s=getchar();
				finder.Makeheap(e);
				}
				cout<<endl<<"要测试的集合中位数为："<<finder.findMedian()<<endl;
				break;
		     case '3':
				for(int i=1;i<=300000;i++)
				{
					cin>>e;
					Finder.Makeheap(e);
				}
				cout<<Finder.findMedian()<<endl;
				break;
		}
	}

	
	system("pause");
	return 0;
}
