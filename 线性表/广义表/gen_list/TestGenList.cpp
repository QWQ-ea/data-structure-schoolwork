#include "GenList.h"			// 广义表
#define NUM 1000
int main(void)
{
	
	GenList<char> g,g1;
	char c = '*',e,s[NUM];
    int i;
    Status sta;
     
	while (c != '0')
	{
        cout << endl << "1. 生成广义表.";
        cout << endl << "2. 显示广义表.";
        cout << endl << "3. 在表头插入原子元素.";
        cout << endl << "4. 在表头插入子表元素.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 求广义表的深度.";
        cout << endl << "7. 求广义表的长度.";
		cout << endl << "8. 在指定位置插入原子元素.";
		cout << endl << "9. 在指定位置插入子表元素.";
		cout << endl << "A. 倒置非递归广义表.";
		cout << endl << "B. 取表头表尾.";
  		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~7):";
		cin >> c;
		switch (c) 	{
			case '1':
				GetChar();				// 读入输入的回车符 
				cout << "请输入广义表eg: (a,(b,c)):";
				g.Input();
				break;
			case '2':
				if (!g.IsEmpty())	{
					g.Show();
					cout << endl;
				}
				else
					cout  << "广义表为空表。" << endl;
				break;
			case '3':
			    cout << endl << "输入原子元素:";
			    cin >> e;
			    g.Insert(e);
			    break;
			case '4':
				GetChar();				// 读入输入的回车符 
				cout << "请输入子表eg: (a,(b,c)):";
				g1.Input();
			    g.Insert(g1);
			    break;
			case '5':
			    cout << endl << "输入位置:";
			    cin >> i;
			    if (g.Delete(i) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
			    break;
			case '6':
				cout << endl << "深度为:" << g.GetDepth() << endl;
			    break;
			case '7':
				cout << endl << "长度为:" << g.GetLength() << endl;
			    break;
		    case '8':
				cout << endl << "输入位置:";
				cin>>i;
				cout << endl << "输入原子元素:";
				cin>>e;
				g.Insert(i,e);
				break;
			case '9':
					GetChar();				// 读入输入的回车符 
					cout << "请输入子表eg: (a,(b,c)):";
					g1.Input();
					cout << endl << "输入位置:";
					cin>>i;
					g.Insert(i,g1);
					break;
		    case 'A':
				    if(g.transpose(g.GetHead())==RANGE_ERROR) cout<<"空表！"<<endl;
					break;
		    case 'B':
				    cout<<"请输入字符串s:";
					getchar();
					cin.getline(s,NUM);
					g.show(s);
       	}
	}


	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


