#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <iostream>
using namespace std;


/*
\fbox{\textbf{struct Point}}
\newline
A Point, by its mathematical, definition is a location on a plane. In our case, this is a 2D cartesian plane. This implies that in order to describe a location on a plane our Point must have and X displacement from the orgin and a Y displacement from the origin.
 Since our Point needs to values, an X-displacement and a Y-displacement, our structure contains two floats x and y. it also contains a constructor.
The constructor takes in two floats, xx and yy, and sets them equal to x and y which makes it easier (in my opinion) to define the Point. We're using floats because we want decimals.
*/
 
struct	Point
{
	float x;
	float y;
	Point(int xx, int yy);
};

float	distance(Point a, Point b);
Point	getPoint(void);

#endif
