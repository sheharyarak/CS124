#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <iostream>
using namespace std;

//previously explained in ex1.
struct	Point
{
	int x;
	int y;
	Point(void);
	Point(int xx, int yy);
};

Point	midpoint(Point a, Point b);
float	distance(Point a, Point b);
void	showCoords(Point a);
Point	getPoint(void);

#endif
