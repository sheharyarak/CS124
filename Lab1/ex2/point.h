#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <iostream>
using namespace std;

/*
This structure was previously explained in ex1.
*/
struct	Point
{
	float x;
	float y;
	Point(float xx, float yy);
};

Point	midpoint(Point a, Point b);
void	showCoords(Point a);
Point	getPoint(void);

#endif
