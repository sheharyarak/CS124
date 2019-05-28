#ifndef TRIANGLE_H
#define TRIANGLE_H

/*

*/
struct	Triangle
{
	float x[3];
	float y[3];

	Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
};

float	perimeter(Triangle tri);

#endif
