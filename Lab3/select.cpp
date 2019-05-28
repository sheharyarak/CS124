/* \todo[inline]{Lab3 Select} */

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include "catch.hpp"
#include <chrono>


using namespace std;

int partition(int arr[], int lower, int upper, int pivotIndex);
void quicksort(int a[], int from, int to);

/*
\textbf{select} \newline
This is a recursive function that finds and returns the median value of the array. By definition, the median value is the middle value. this means it has an equal number of elements before it and after it in a sorted list. Even if the list is unsorted if a value in a list has an equal number of values greater than it and less than it, then that value is the median. You will se that by trying to find the median we actually end up sorting the array a little bit. not all the way sorted but it brings a quite a bit closer to sorting it.
\newline @param arr[] : this parameter takes in the array whose median is to be found and returned.
\newline @param pivotIndex : this parameter takes in the pivot index.
\newline @param lower : this parameter takes in the starting index from which the median is supposed to be found.
\newline @param upper : this parameter takes in the last index upto which the median is supposed to be found.
*/

int select(int arr[], int pivotIndex, int lower, int upper)
{
	int p = partition(arr, lower, upper, pivotIndex);
	if (pivotIndex < p)
	{
		return select (arr, pivotIndex, 0, p);//recursive case
	}
	else if (pivotIndex > p)
	{
		return select(arr, pivotIndex, p+1, upper);//recursive case
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
In order to read the input from a text file i used ifstream. ifstream is basically like cin but instead of taking input from the user it takes input from the opened text file, in this case shuffle.txt. It reads in the input and just stores everything in an array of size n (in this case 1,000,000). I'm using a large value for n so we can see the diference in times between our select function and the std libraries sort function and quicksort. 
*/

TEST_CASE("Select time")
{
	const int n = 1000000;
	
	//int a[] = {2,87,21,3,12,78,97,16,89,21};
	int a[n];
	
	ifstream file;
	file.open("shuffle.txt");
	
	for(int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	select(a,n/2,0,n-1);
}

TEST_CASE("Sort time")
{
	const int n = 1000000;
	
	//int a[] = {2,87,21,3,12,78,97,16,89,21};
	int a[n];
	
	ifstream file;
	file.open("shuffle.txt");
	
	for(int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	std::sort(a,a+n);
}

TEST_CASE("Quicksort time")
{
	const int n = 1000000;
	
	//int a[] = {2,87,21,3,12,78,97,16,89,21};
	int a[n];
	
	ifstream file;
	file.open("shuffle.txt");
	
	for(int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	quicksort(a, 0, n-1);
}


TEST_CASE("Test Select")
{
	int a[] = {2,87,3,12,78,97,21,89,16};
	int n = (sizeof(a) / sizeof(a[0]));
	REQUIRE(select(a,n/2,0,n - 1) == 21);
	REQUIRE(a[n/2] == 21);
}

/*
\verbatiminput{resultsTime}
\newpage
\todo[inline]{Conclusion}
You can see that in the test result selct is much faster than sort. almost twice as fast. It is also faster than quicksort but since the array is not fully sorted after select as it is after quicksort we cannot say that select if used in a sort function will be faster than quicksort. the sort in the std library is slow because it is not optimized. it is a an unoptimized version of quicksort. this a great example of how important optimizatation is. it reduced the time it took to sort by over 30\%. this is the power of optimization.
*/
