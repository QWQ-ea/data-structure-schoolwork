#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include"AdjMatrixUndirNetwork.h"

template<class ElemType,class WeightType>
void ShortpathDij(const AdjMatrixUndirNetwork<ElemType,WeightType> &g,int v0,int v1)
{
int path[g.GetVexNum()];
WeightType dist[g.GetVexNum()];
WeightType minval,infinity=g.GetInfinity();
int v,u;
for(v=0;v<g.GetVexNum();v++)
 {
	dist[v]=g.GetWeight(v0,v);
	if(dist[v]==infinity) path[v]=-1;
	else path[v]=v0;
	g.SetTag(v,UNVISITED);
 }
g.SetTag(v0,VISITED);
for(int i=1;i<g.GetVexNum();i++)
 {
	minval=infinity;
	u=v0;
	for(v=0;v<g.GetVexNum();v++)
		if(g.GetTag(v)==UNVISITED&&dist[v]<minval)
	     {
		  u=v;
		  minval=dist[v];
	     }
	g.SetTag(u,VISITED);
	for(v=g.FirstAdjVex(u);v!=-1;v=g.NextAdjVex(u,v))
	    if(g.GetTag(v)==UNVISITED&&minval+g.GetWeight(u,v)<dist[v]) 
	     {
          dist[v]=minval+g.GetWeight(u,v);
		  path[v]=u;
	     }
 }
ElemType e,f;
g.GetElem(v0,e);
g.GetElem(v1,f);
cout<<e<<"->"<<f<<":"<<dist[v1]<<" "<<path[v1]<<endl;
}
#endif
