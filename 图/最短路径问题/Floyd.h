#ifndef _FLOYD_H_
#define _FLOYD_H_

#include"AdjMatrixUndirNetwork.h"

template<class ElemType,class WeightType>
void ShortpathFloyd(const AdjMatrixUndirNetwork<ElemType,WeightType> &g,int v0,int v1)
{
	WeightType infinity=g.GetInfinity();
	int v,u,k,vexnum=g.GetVexNum();
	int path[vexnum][vexnum];
	WeightType dist[vexnum][vexnum];
	for(u=0;u<vexnum;u++)
	 for(v=0;v<vexnum;v++)
    	{
		dist[u][v]=g.GetWeight(u,v);
		if(u!=v&&dist[u][v]<infinity) path[u][v]=u;
		else path[u][v]=-1;
	    }
	for(k=0;k<vexnum;k++)
		for(v=0;v<vexnum;v++)
		 for(u=0;u<vexnum;u++)
			 if(dist[v][k]+dist[k][u]<dist[v][u])
	          {
	           dist[v][u]=dist[v][k]+dist[k][u];
			   path[v][u]=path[k][u];
	          }
ElemType e,f;
g.GetElem(v0,e);
g.GetElem(v1,f);
cout<<e<<"->"<<f<<":"<<dist[v0][v1]<<" "<<path[v0][v1]<<endl;
}
#endif
