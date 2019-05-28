#include "point.hpp"
#include <math.h>
#include <iostream>

//initializes the point to (0,0)
Point::Point()
{
	x = 0;
	y = 0;
}
//previously explained in ex1.
Point::Point(int xx , int yy)
{
	x = xx;
	y = yy;
}
//previously explained in ex1.
float distance(Point a, Point b)
{
	return (sqrt(((b.y- a.y) * (b.y - a.y)) + ((b.x - a.x) * (b.x - a.x))));
}
//previously explained in ex2.
Point midpoint(Point a, Point b)
{
	int x;
	int y;

	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;
	Point mid(x,y);
	return (mid);
}
//previously explained in ex2.
void	showCoords(Point a)
{
	cout << "X: " << a.x <<endl;
	cout << "Y: " << a.y <<endl;
	cout << endl;
}
//previously explained in ex1.
Point getPoint(void)
{
	int x;
	int y;

	cout << "Enter X coordinate:" << endl;
	cin >> x;
	cout << "Enter Y coordinate:" << endl;
	cin >> y;
	Point p(x,y);
	return (p);
}
