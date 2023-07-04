#include"AdjMatrixUndirNetwork.h"

struct Arc {
	int a, b, c;
};
int main() {
	system("chcp 65001");
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	char es[n + 1], x, y;
	Arc arc[m];
	int infity = DEFAULT_INFINITY;
	cout << "请输入顶点:" << endl;
	for (int i = 0; i < n; i++) cin >> es[i];
	AdjMatrixUndirNetwork<char, int> net(es, n);
	cout << "请输入边:" << endl;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		int j = i;
		while (j - 1 >= 0 && c < arc[j - 1].c) {
			arc[j] = arc[j - 1];
			j--;
		}
		arc[j].a = a;
		arc[j].b = b;
		arc[j].c = c;
	}
	cout << "请输入两顶点:" << endl;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		for (int i = 0; i < m; i++) {
			net.InsertArc(arc[i].a, arc[i].b, arc[i].c);
			net.Getpath(x, y);
			if (net.Tag == 1) {
				cout << "最大噪声值为:" << arc[i].c << endl;
				for (int j = i; j >= 0; j--) net.DeleteArc(arc[j].a, arc[j].b);
				break;
			}
		}
	}
}
