// cs124 lab
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include "catch.hpp"
#include <chrono>


using namespace std;

int partition(int arr[], int lower, int upper, int pivot_index);

/*
\textbf{select} \newline
This is a recursive function that finds the median value of the array. 
*/

int select(int arr[], int pivot_index, int lower, int upper)
{
	int p = partition(arr, lower, upper, pivot_index);
	int n1 = p - lower;
	int n2 = 1;// this wastes memory. I suggest hardcoding 1 instead.
	int n3 = upper - (n1 + n2);// I feel that this line has no purpose. it also wastes memory.
	if (pivot_index < n1)
	{
		select (arr, pivot_index, 0, n1);//recursive case
	}
	else if (pivot_index > n1 + n2)
	{
		select(arr, pivot_index, n1 + n2, upper);//recursive case
	}
	else
	{
		return (arr[p]);//base case
	}
}

/*
\verbatiminput{resultsSelect}
*/
/*
\textbf{Reading input from file} \newline
In order to read the input from a text file i used ifstream and just stored everything in an array of size n (in this case 1000). I'm using a large value so we can see the diference in times between our sort function and the std libraries sort function.
*/

/*
\textbf{measuring time} \newline
To measure the time I used chronos::high\_resolution\_clock and increased the number of items in the array until it took long enough for a proper time output.
*/

TEST_CASE("difference between select and sort")
{
	const int n = 1000;
	
	//int a[] = {2,87,21,3,12,78,97,16,89,21};
	int a[n];
	
	ifstream file;
	file.open("shuffle.txt");
	
	for(int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	select(a, n / 2, 0, n - 1);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span1 = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	
	t1 = chrono::high_resolution_clock::now();
	std::sort(a,a+n);
	t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span2 = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	
	cout << "Select : " << time_span1.count() << " seconds" << endl;
	cout << "Sort : " << time_span2.count() << " seconds" << endl;
}

/*
\verbatiminput{resultsTime}
*/
