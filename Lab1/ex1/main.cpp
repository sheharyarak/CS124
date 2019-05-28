/*
\textbf{The Purpose}
\newline
The purpose of this exercise is to revise the concepts of C++ structures. Structure are a core part of data storage in C++ and it is crucial that we know how to use them.
\newline
In this exercise we want to use a structure that holds an x coordinate and a y coordinate and calculate the distance between them.
\newline
\textbf{The Proccess}
\newline
To do this we will use the distance formula derived by mathematicians years ago. In this program we're using two functions, a structure, and a constructor. These will be explained below.
*/

#include "point.hpp"
#include <iostream>

using namespace std;

/*
\obeylines \obeyspaces
The main function gets the points from the user using the \textit{getPoint()} function and prints out the distance to the console using the \textit{distance(Point a, Point b)} function.
*/

int main(void)
{
	cout << "Point A:" << endl;
	Point a = getPoint();

	cout << "Point B:" << endl;
	Point b = getPoint();

	cout << "Distance: " << distance(a,b) << endl;
	return (0);
}

/*
This is what the output looks like:
\newline
\includegraphics{ex1.PNG}
\newpage
*/
/*
This is what the diagram looks like:
\newline
\includegraphics{dis1.PNG}
\newpage
*/
