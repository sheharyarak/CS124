#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.hpp"

/*
\fbox{\textbf{struct	Triangle}}
\newline
This structure consists of three points. It also has two Triangle constructors. A default constructor that just makes a Triangle and a Constructor that takes in three Points.
*/
struct	Triangle
{
	Point a;
	Point b;
	Point c;
	Triangle(void);
	Triangle(Point aa, Point bb, Point cc);
};

float	perimeter(Triangle tri);

#endif
