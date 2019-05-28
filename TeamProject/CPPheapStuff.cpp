/***********************************************************************\obeylines \obeyspaces
* File: CPPheapStuff.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function that calls functions to create and fill 
	the min and max heaps, find, retrieve and print the median values, and 
	reset the heaps.
	
***********************************************************************/

/*** System Libraries ***/
#include <fstream>
#include <iostream>
#include <vector>

/*** User Libraries ***/
#include "Hlab.h"
#include "HmaxHeap.h"
#include "HminHeap.h"

/*** namespace declaration ***/
using namespace std;

/*\newpage*/
/*********************************************/
/****** heapStuff() Function Definition ******/
/*********************************************/

void heapStuff(ofstream& newImage, MinHeap<int>& minHeap, MaxHeap<int>& maxHeap, vector<vector<int>>& pixelHolder)
{
	MinHeap<int> minHeapTemp = minHeap;
	MaxHeap<int> maxHeapTemp = maxHeap;
	int count = 1;
	
	for(int a = 0; a < pixelHolder[0].size(); a++) 
	{/* iterate through all lines/vector values */
		
		/********* Heaps filled **********/
		fillHeaps(a, minHeapTemp, maxHeapTemp, pixelHolder);
		
		/* cout << "avoided segv 01" << endl; */
		
		/******** Median Obtained ********/
		/* cout << "heapStuff: before getMedian: " << endl;
		cout << "size of minHeap: " << minHeapTemp.size() << endl;
		cout << "size of maxHeap: " << maxHeapTemp.size() << endl; */
		if(minHeapTemp.size() != 0 && maxHeapTemp.size() != 0)
		{
			getMedian(newImage, minHeapTemp, maxHeapTemp, count);
		
			count++;
		}
		
		/* cout << "avoided segv 02" << endl; *//*\newpage*/
		/******** Heaps emptied ********/
		emptyMinHeap(minHeapTemp);
		
		/* cout << "avoided segv 03" << endl; */
		
		minHeapTemp = minHeap;
		
		/* cout << "avoided segv 04" << endl; */
		
		emptyMaxHeap(maxHeapTemp);
		
		/* cout << "avoided segv 05" << endl; */
		
		maxHeapTemp = maxHeap;
		
		/* cout << "avoided segv 06" << endl; */
	}
	
	/* cout << "avoided segv 07" << endl; */
}
