#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Floyd.h"

int main()
{
int n,m,k,a,b,c;
cin>>n>>m;
char es[n+1],x,y;
int infity=DEFAULT_INFINITY;
for(int i=0;i<n;i++) cin>>es[i];
AdjMatrixUndirNetwork<char,int> net(es,n);
for(int i=0;i<m;i++) 
 {
	cin>>a>>b>>c;
	net.InsertArc(a,b,c);
 }
for(int i=0;i<k;i++)
{
	cin>>x>>y;
	a=net.GetOrder(x);
	b=net.GetOrder(y);
	ShortpathDij(net,a,b);
	ShortpathBellmanFord(net,a,b);
	ShortpathFloyd(net,a,b);
}
}
