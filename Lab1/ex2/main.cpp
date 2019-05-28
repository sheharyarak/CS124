/*
\textbf{The Purpose}
\newline
The Purpose of this exercise and the entire lab is to review basic C++ concepts before moving forward with the semester. In this exercise we are required to find a point that lies directly in between two points.
\newline
\textbf{The Process}
\newline
Exactly like in ex1, we will first get two points from the user and then display the midpoint onto the console using the midpoint function.
*/

#include "point.hpp"

using namespace std;
/*
\obeylines \obeyspaces
The main function gets the points from the user and prints out the coordinates of the midpoint to the console.
*/
int main(void)
{
	cout << "Point A:" << endl;
	Point a = getPoint();

	cout << "Point B:" << endl;
	Point b = getPoint();

	cout << "Midpoint Coords: " << endl;
	showCoords(midpoint(a,b));

	return (0);
}

/*
\newpage
This is what the output looks like:
\newline
\includegraphics[scale = 1] {ex2.PNG}
\newpage
This is what the diagram looks like:
\newline
\includegraphics[scale = 1] {mid2.PNG}
*/
