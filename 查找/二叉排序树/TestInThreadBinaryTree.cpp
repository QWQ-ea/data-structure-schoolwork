#include "BinarySortTree.h"		  // 中序线索二叉树类

int main(void)
{
	int pre[]={39,11,8,23,34,68,46,75,71,86};		// 先序序列
	int in[]={8,11,23,34,39,46,68,71,75,86};		// 中序序列
	int n = 10;						  // 结点个数
	BinarySortTree<int> bt;
	char c = 'x', e;
	BinTreeNode<int> *p;
    BinTreeNode<int> *q;
	bt = CreateBinarySortTree(pre, in, n);// 构造二叉树
	cout << "由先序：39,11,8,23,34,68,46,75,71,86和中序：8,11,23,34,39,46,68,71,75,86构造的二叉树:" << endl;
	DisplayBTWithTreeShape<int>(bt);
	cout << endl;
	system("PAUSE");	

	cout << "中序索化后的线索二叉树:" << endl;
	BinarySortTree<int> thrBt(bt);
	DisplayBTWithTreeShape<int>(thrBt);
	system("PAUSE");	
	
   	while (c != '0'){
        cout << endl << "1.查找值等于指定值的节点并返回其父亲节点";
		cout << endl << "2.插入节点";
		cout << endl << "3.删除节点";
		cout << endl << "4.判断二叉树是否为二叉排序树";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~4):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	p=thrBt.Find(46,q);
				cout<<p->data<<endl;
				cout<<q->data<<endl;
			    break;
           	case '2':
            	thrBt.Insert(17);
			    DisplayBTWithTreeShape<int>(thrBt);
			    break;
	         case '3':
			    p=thrBt.Find(68,q);
				thrBt.Delete(p);
				DisplayBTWithTreeShape<int>(thrBt);
				break;
	         case '4':
			    cout<<thrBt.BinarySorttreejudge()<<endl;
				break;
		}
	}
	
	system("PAUSE");	
	return 0;				
}

