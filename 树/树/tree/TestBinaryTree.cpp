#include "Tree.h"		// 二叉链表类

int main(void)
{
	TreeNode<char> *p;
	char pre[]={'A','B','E','F','K','L','C','G','D','H','I','M','N','J'}; // 先序序列
	char post[]={'E','K','L','F','B','G','C','H','M','N','I','J','D','A'};  // 后序序列
	int n = 14,i;						                  // 结点个数
    Tree<char> bt;
    char c = 'x', e;
	
	
	bt = CreateTree(pre, post, n);           // 构造树
		
	cout << "由先序：A,B,D,E,G,H,C,F,I和后序：D,B,G,E,H,A,C,F,I构造的树:" << endl;
	DisplayTWithTreeShape<char>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. 插入孩子.";
        cout << endl << "2. 删除以指定节点为根的子树.";
        cout << endl << "3. 删除以指定节点为根的第i个子树";
        cout << endl << "4. 先序遍历.";
        cout << endl << "5. 后序遍历.";
		cout << endl << "6. 求树的度.";
        cout << endl << "7. 求树的结点数.";
        cout << endl << "8. 求树的高度.";
        cout << endl << "9. 显示树.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "输入被插入元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else {
            		cout << endl << "输入插入元素的值:";
			    	cin >> e;
					bt.InsertChild(p, e);	// 插入左孩子
			    }
			    break;
           	case '2':
            	cout << endl << "输入删除子树根元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else 
					bt.DeleteSubTree(p);					
			    break;
		    case '3':
				cout << endl << "输入删除子树双亲元素的值:";
				cin >> e;
				p = bt.Find(e);
				if (p == NULL)
					cout << "该结点不存在！" << endl;
				else 
				{
				cout<<endl<<"输入删除的第i个子树：";
				cin>>i;
				bt.DeleteChild(p,i);
				}
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<char>);
				break;
	         case '5':
				cout << endl;
				bt.PostOrder(Write<char>);
				break;
	         case '6':
				cout << endl;
			    cout << "树的度为："<<bt.degreeCount()<<endl;
				break;
	         case '7':
				cout << endl;
				cout << "树的结点数为：" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "树的高度为：" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayTWithTreeShape(bt);
				break;
		}                              
	}

	system("PAUSE");
	return 0;
}

