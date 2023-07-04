#ifndef _BELLMANFORD_H_
#define _BELLMANFORD_H_

#include"AdjMatrixUndirNetwork.h"

template<class ElemType,class WeightType>
void ShortpathBellmanFord(const AdjMatrixUndirNetwork<ElemType,WeightType> &g,int v0,int v1)
{
	WeightType *disttemp,minval,infinity=g.GetInfinity();
	int v,u,vexnum=g.GetVexNum();
	int path[vexnum];
	WeightType dist[vexnum];
	disttemp=new WeightType[vexnum];
	for(v=0;v<vexnum;v++)
	{
		dist[v]=g.GetWeight(v0,v);
		if(dist[v]==infinity) path[v]=-1;
		else path[v]=v0;
	}
	for(int i=2;i<vexnum;i++)
	{
	 for(v=0;v<vexnum;v++) disttemp[v]=dist[v];
	 for(u=0;u<vexnum;u++)
		 if(u!=v0)
			 for(v=0;v<vexnum;v++)
				 if(v!=v0&&disttemp[u]>dist[v]+g.GetWeight(v,u))
	              {  
                     disttemp[u]=dist[v]+g.GetWeight(v,u);
					 path[u]=v;
	              }
	 for(v=0;v<vexnum;v++) dist[v]=disttemp[v];
	}
	ElemType e,f;
	g.GetElem(v0,e);
	g.GetElem(v1,f);
	cout<<e<<"->"<<f<<":"<<dist[v1]<<" "<<path[v1]<<endl;
}
#endif
