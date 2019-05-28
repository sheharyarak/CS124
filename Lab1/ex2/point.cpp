#include "point.hpp"
#include <math.h>
#include <iostream>

/*
\obeylines \obeyspaces
This function was previously explained in exercise 1.
*/
Point::Point(float xx , float yy)
{
	x = xx;
	y = yy;
}

/*
\newpage
\fbox{\textbf{Point midpoint(Point a, Point b)}}
\newline
This function uses the midpoint formula to calculate the midpoint.
\newline
\[
	\left(\frac{x_2 - x_2}{2} , \frac{y_2 - y_1}{2}\right)
\]
\newline
\includegraphics[scale = 0.6] {mid.png}
*/ 
Point midpoint(Point a, Point b)
{
	float x;
	float y;

	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;
	Point mid(x,y);
	return (mid);
}

/*
\fbox{\textbf{void	showCoords(Point a)}}
\newline
This function takes in a Point and prints out its x and y values on to the console.
*/
void	showCoords(Point a)
{
	cout << "X: " << a.x <<endl;
	cout << "Y: " << a.y <<endl;
	cout << endl;
}

/*
This function was previously explained in ex1.
*/
Point getPoint(void)
{
	float x;
	float y;

	cout << "Enter X coordinate:" << endl;
	cin >> x;
	cout << "Enter Y coordinate:" << endl;
	cin >> y;
	Point p(x,y);
	return (p);
}
