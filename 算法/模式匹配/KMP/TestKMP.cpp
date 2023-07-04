#include "KMP.h"		      // KMP算法
int main(void)
{
	String ob("This is a string");
	String pat="is";
	char c ='1';
	int p;
	while (c != '0'){
		cout << endl << "1. 输入字符串1";
		cout << endl << "2. 输入字符串2";  
		cout << endl << "3. 测试KMP_find()";
		cout << endl << "4. 测试kMP_findall()";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) 	{
		case '1':
			cout << endl << "输入字符串1：";
			Read(ob);
			break;
		case '2':
			cout << endl << "输入字符串2：";
			Read(pat);
			break;
		case '3':
			cout << "字符串s1为：";
			Write(ob);
			cout << "字符串s2为：";
			Write(pat);
			cout << "输入p:";
			cin >> p;
			cout << "在主串中从第"<<p<<"个位置开始寻找第一个与模式串匹配的子串"<<endl;
			cout << "查找到的匹配位置信息为："<<KMP_find(ob,pat,p)<<endl;
			break;
		case '4':
             cout << "字符串s1为：";
			 Write(ob);
			 cout << "字符串s2为：";
			 Write(pat);
             cout << "在主串中寻找所有与模式串匹配的子串信息：";
			 KMP_findall(ob,pat);
			 cout << endl;
			 break;
		}
	}
	system("PAUSE");        
	return 0;               
}
