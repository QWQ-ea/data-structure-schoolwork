#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class Point2D
{
private:
double x,y;
public:
Point2D(double a=0,double b=0);
double Getx() const;
double Gety() const;
void Setxy(double a,double b);
double mochang() const;
friend void xiangliang(const Point2D &a,const Point2D &b);
friend double juli(const Point2D &a,const Point2D&b);
friend ostream & operator<<(ostream &out,const Point2D &a);
friend istream & operator>>(istream &in,Point2D &a);
friend bool operator!=(const Point2D &a,const Point2D &b);
};
#endif
