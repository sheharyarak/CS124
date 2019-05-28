/*
\textbf{The Purpose}
\newline
In this lab we want to find the perimeter of the triangle. the perimeter is the sum of all sides. a side is a line-segment. a line-segment is a line with a starting position and an ending position. a position on a cartesian plane can be represented by a point. A triangle consists of 3 points and its sides are the line segments between the points. We can use this to calculate the perimeter.
\textbf{The Proccess}
\newline
Since a triangle has three points and the line-segments between the points are the sides. And since the perimeter is the sum of of the length of all sides we can use our distance function to get the length of each of the sides and a perimeter function would just return their sum.
*/

#include "point.hpp"
#include "triangle.hpp"

using namespace std;

/*
This program gets three points using the getPoint() function which returns a point. it than creates a triangle structure using those points. Finally it prints out the perimeter onto the console using the perimeter function.
*/
int main(void)
{
	cout << "Point A:" << endl;
	Point a = getPoint();

	cout << "Point B:" << endl;
	Point b = getPoint();

	cout << "Point C:" << endl;
	Point c = getPoint();

	Triangle tri(a, b, c);

	cout << "Perimeter: " << perimeter(tri) << endl;
}

/*
\newpage
This is what the output looks like:
\newline
\includegraphics[scale = 1] {ex3.PNG}
\newpage
This is what the diagram looks like:
\newline
\includegraphics[scale = 1] {tri2.PNG}
*/
