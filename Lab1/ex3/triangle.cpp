#include "triangle.hpp"
#include "point.hpp"

/*
\fbox{Triangle::Triangle(Point aa, Point bb, Point cc)}
\newline
This constructor takes in three points, aa, bb, and cc, and sets them equal to a, b, and c.
*/
Triangle::Triangle(Point aa, Point bb, Point cc)
{
	a = aa;
	b = bb;
	c = cc;
}

/*
\newpage
\fbox{float	perimeter(Triangle tri)}
\newline
This function uses the distance function to calculate the distance between points A and B, B and C, and C and A it then returns the sum of these distances. This sum is the perimeter of the triangle.
\newline	
\includegraphics[scale = 0.5] {tri.PNG}
*/
float	perimeter(Triangle tri)
{
	float ab;
	float bc;
	float ca;

	ab = distance(tri.a, tri.b);
	bc = distance(tri.b, tri.c);
	ca = distance(tri.c, tri.a);
	return (ab + bc + ca);
}
