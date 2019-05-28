/*
\textbf{The Purpose}
\newline
The purpose of this exercise is exactly the same as exercise 3 except instead of using points we're using arrays. This exercise shows us how much easier and cleaner structures make our code since we dont have to deal with different variable names or arrays.
\newline
\textbf{The Process}
\newline
To do this we get the x and y coordinates of all three points. For this I used a for loop in main.
*/

#include "triangle.hpp"
#include <iostream>

using namespace std;

/*
This program takes in the x and y coordinates of all three points of the triangle and stores them into an either an x array or a y array. it then passes them down to the triangle constructor to make a triangle structure. It then calls the primeter function then prints out the perimeter onto the console.
*/
int main(void)
{
	float coords[6];
	//makes the user enter x coords first
	bool x = true;

	cout << "Enter Coords:" << endl;
	for (int i = 0; i < 6; i++)
	{
		//prints out X or Y depending on x
		if (x)
		{
			cout << "X";
			//makes it print out Y next cycle
			x = false;
		}
		else
		{
			cout << "Y";
			//makes it print out X next cycle
			x = true;
		}
		//prints i/2 makes it print out 0,0,1,1,2,2
		cout << i/2 <<" :" << endl;
		cin >> coords[i];
	}

	Triangle tri(coords[0],coords[1],coords[2],coords[3],coords[4],coords[5]);
	cout << "Perimeter: " << perimeter(tri) << endl;
}

/*
\newpage
This is what the output looks like:
\newline
\includegraphics[scale = 1] {ex4.PNG}
\newpage
This is what the diagram looks like:
\newline
\includegraphics[scale = 1] {tri.PNG}
*/
