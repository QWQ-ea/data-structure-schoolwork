#include"Point2D.h"
#include<cmath>
#include<stdlib.h>
Point2D::Point2D(double a,double b)
{
	x=a;y=b;
}
double Point2D::Getx() const
{
return x;
}
double Point2D::Gety() const
{
	return y;
}
void Point2D::Setxy(double a,double b)
{
	x=a;y=b;
}
double Point2D::mochang() const
{
double c;	
c=x*x+y*y;
c=sqrt(c);
return c;
}
void xiangliang(const Point2D &a,const Point2D &b)
{
cout<<"方向向量为："<<"("<<a.x-b.x<<","<<a.y-b.y<<")"<<endl;
}
double juli(const Point2D &a,const Point2D &b) 
{
double c;
c=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
c=sqrt(c);
return c;
}
ostream & operator<<(ostream &out,const Point2D &a)
{
	out<<"("<<a.x<<","<<a.y<<")"<<endl;
	return out;
}
istream & operator>>(istream &in,Point2D &a)
{ char str1[80];
in.getline(str1,80,'(');
in.getline(str1,80,',');
if(!in) return in;
a.x=atof(str1);
in.getline(str1,80,')');
if(!in) return in;
a.y=atof(str1);
return in;
}
