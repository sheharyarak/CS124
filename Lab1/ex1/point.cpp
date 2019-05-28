#include "point.hpp"
#include <math.h>
#include <iostream>

using namespace std;

/*
\obeylines \obeyspaces
\fbox{\textbf{Point(float xx, float yy)}}
\textit{Point(float xx, float yy)} is a customized constructor for the structure Point.
It takes in the X coordinate and the Y coordinates as arguments and sets them equal to X and Y accordingly.
*/
Point::Point(float xx , float yy)
{
	x = xx;
	y = yy;
}

/*
\newpage
\fbox{\textbf{float distance(Point a, Point b)}}
\newline
This function implements the distance formula and returns the result.
\newline
The distance formula is shown below:
\newline
\[d = \sqrt {\left( {x_1 - x_2 } \right)^2 + \left( {y_1 - y_2 } \right)^2 }\]
\newline
This diagram illustrates the distance formula:
\newline
\includegraphics[scale = 0.7] {dis.PNG}
*/
float distance(Point a, Point b)
{
	return (sqrt(((b.y- a.y) * (b.y - a.y)) + ((b.x - a.x) * (b.x - a.x))));
}

/*
\fbox{\textbf{Point getPoint(void)}}
\newline
This function takes input from the user.
It then creates a point using the Point constructor and the values provided and returns the Point.
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
