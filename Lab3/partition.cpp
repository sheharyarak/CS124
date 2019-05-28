/* \todo[inline]{Lab3 partition} */

#include <iostream>
#include "catch.hpp"
/*
\textbf{Partition} \newline 
\newline In this function we want to partition the array in a way so that all the numbers less than the pivot are on the left and all the values greater than the pivot are on the right side of the pivot. If the value on the left is greater than the pivot then its swapped with the value on the right. 
\newline @param arr[] : this parameter takes in the array whose median is to be found and returned.
\newline @param pivotIndex : this parameter takes in the pivot index.
\newline @param lower : this parameter takes in the starting index from which the median is supposed to be found.
\newline @param upper : this parameter takes in the last index upto which the median is supposed to be found.
*/
int partition(int a[], int lower, int upper, int pivotIndex)
{
	int pivot = a[pivotIndex]; int left = lower; int right = upper-1;
	std::swap(a[pivotIndex], a[upper]);
	while(left <= right)
	{
		if(a[left] <= pivot) 
			left++;
		else {
			std::swap(a[left],a[right]);
			right--;
			}
    }
    std::swap(a[left],a[upper]);
	return left;
}


TEST_CASE("Test Partition")
{
	int a[] = {2,87,3,12,78,97,16,89,21};
	int b[] = {2,16,3,12,21,78,89,87,97};
	int n = (sizeof(a) / sizeof(a[0]));
	partition(a, 0, n - 1, n/2);
	for (int i=0; i < n; i++)
	{
		CHECK(a[i] == b[i]);
	}	
}

/*
\verbatiminput{resultsPartition}
*/

/*
In order to illustrate the changes occuring in memory i have made a table with records of all the changes made in the array during this function call and i have also included a GIF animation that shows memory changes step by step.
\newpage \fbox{\textbf{FIG.1  Array Change Table}}
\newline
\newline \includegraphics[scale = 0.75]{Steps.PNG}
\newpage \fbox{\textbf{FIG.1  Step by Step by step gif}}
\newline
\newline \includemovie{18cm}{11.5cm}{Lab3.gif}
*/

