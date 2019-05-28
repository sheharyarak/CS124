#include "triangle.hpp"
#include <math.h>

/*
\fbox{Triangle::Triangle (float x1, float y1, float x2, float y2, float x3, float y3)}
\newline
This constructor takes in the x and y coords and puts them in either the x array or the y array in the triangle structure.
*/
Triangle::Triangle (float x1, float y1, float x2, float y2, float x3, float y3)
{
	x[0] = x1;
	y[0] = y1;

	x[1] = x2;
	y[1] = y2;
	
	x[2] = x3;
	y[2] = y3;
}

/*
\newpage
\fbox{float	perimeter(Triangle tri)}
\newline
This function calculates the perimeter using the distance formula. Its exactly the same as the previous function but instead of using points this function uses the x an y coordinates from the arrays inside the triangle structure and uses the distance formula to get the lenght of each of the sides then returns their sum.
\newline
\includegraphics[scale = 0.7] {tri4.png}
*/
float	perimeter(Triangle tri)
{
	float ab;
	float bc;
	float ca;

	ab = sqrt((tri.x[1] - tri.x[0]) * (tri.x[1] - tri.x[0]) + (tri.y[1] - tri.y[0]) * (tri.y[1] - tri.y[0]));
	bc = sqrt((tri.x[2] - tri.x[1]) * (tri.x[2] - tri.x[1]) + (tri.y[2] - tri.y[1]) * (tri.y[2] - tri.y[1]));
	ca = sqrt((tri.x[0] - tri.x[2]) * (tri.x[0] - tri.x[2]) + (tri.y[1] - tri.y[2]) * (tri.y[0] - tri.y[2]));

	return (ab + bc + ca);
}
