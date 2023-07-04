#include "AdjMatrixUndirNetwork.h"					// Kruskal算法

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
	int infity = -1;
	char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int m[6][6] = {
		{0, 12, 3, infity, 9, 10},
		{12, 0, infity, 2, 6, infity},
		{3, infity, 0, 2, infity, 6},
		{infity, 2, 2, 0, 4, 7},
		{9, 6, infity, 4, 0, 4},
		{10, infity, 6, 7, 4, 0}
	};
		int n = 6;

		AdjMatrixUndirNetwork<char, int> net(vexs, n,10,infity);

		for (int u = 0; u < n; u++)	// 生成邻接矩阵的行
			for (int v = u + 1; v < n; v++)	// 生成邻接矩阵元素的值
				if (m[u][v] != 0&&m[u][v]!=infity) net.InsertArc(u, v, m[u][v]);

		cout << "原网:" << endl;
		net.Display();					// 显示网net
		cout << endl;
		system("PAUSE");
		cout << "破圈法法产生最小生成树的边:" << endl;
	    net.DFSpoquan();		// 破圈法
		cout << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}

