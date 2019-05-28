/* \todo[inline]{Lab2 partition} */

/*
\textbf{The Purpose} \newline
The purpose of this lab is to make a quick sort function. The quick sort function uses divide and conquer to sort the array. its faster and is known is the most efficient way to sort a large list of data. merge sort also uses divide and conquer and is very efficient but it uses more memory as it makes a new sorted array. In quick sort we sort the array itself using swap.
*/
#include <iostream>
#include "catch.hpp"
/*
\textbf{Partition} \newline
In this function we want to partition the array in a way so that all the numbers less than the pivot are on the left and all the values greater than the pivot are on the right side of the pivot. If the value on the right is greater than the pivot then its swapped with the value on the left. 
*/
int partition(int a[], int lower, int upper, int pivot_index)
{
	int pivot = a[pivot_index]; int left = lower; int right = upper-2;
	//std::swap(a[pivot_index], a[upper - 1]);
	while(left <= right)
	{
		if(a[left] <= pivot) 
			left++;
		else {
			std::swap(a[left],a[right]);
			right--;
			}
    }
    std::swap(a[left],a[upper - 1]);
	return left;
}
/*
\verbatiminput{resultsPartition}
*/

/*
\includegraphics[scale = 0.75]{memory.PNG}
*/
//~/Labs/Lab2/partition$ g++ -g -I/home/debian -o "select" "select.cpp" "partition.cpp" ~/catch2.o -DUNIT_TEST
