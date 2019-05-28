/***********************************************************************\obeylines \obeyspaces
* File: CPPgetMedian.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function that finds and print the median from 
	the roots of the min and max heaps.
	
	If the min heap is larger, the root of the min heap is the median.
	If the max heap is larger, the root of the max heap is the median.
	If the heaps are of equal size, the average of the roots is the median.
	
***********************************************************************/
/*
\includegraphics[scale = 0.5]{MedianDiagram.png}
*/
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
/****** getMedian() Function Definition ******/
/*********************************************/

void getMedian(ofstream& newImage, MinHeap<int>& minHeap, MaxHeap<int>& maxHeap, int count)
{
	/* cout << "getMedian: before size comparisons and median prints: " << endl;
	cout << "size of minHeap: " << minHeap.size() << endl;
	cout << "size of maxHeap: " << maxHeap.size() << endl; */
	
	if(minHeap.size() > maxHeap.size()) /* if minHeap is larger */
	{
		/* cout << "MinHeap.top: " << minHeap.top() << endl; */
		newImage << minHeap.top();
	}
	
	else if(minHeap.size() < maxHeap.size()) /* if maxHeap is larger */
	{
		/* cout << "MaxHeap.top: " << maxHeap.top() << endl; */
		newImage << maxHeap.top();
	}
	
	else /* if the heaps are equal size */
	{
		int tmp = (maxHeap.top() + minHeap.top()) / 2;
		/* cout << "Median is: " << tmp << endl; */
		newImage << tmp;
	}
	/*\newpage*/
	if(count%3 == 0)
	{
		newImage << "\n";
	}
	
	else
	{
		newImage << " ";
	}
}
