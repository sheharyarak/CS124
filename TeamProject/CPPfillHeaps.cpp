/***********************************************************************\obeylines \obeyspaces
* File: CPPfillHeaps.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function where the heaps are filled and then 
	calls the function to check if they need to be rebalanced.
	
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
/****** fillHeaps() Function Definition ******/
/*********************************************/

void fillHeaps(int a, MinHeap<int>& minHeap, MaxHeap<int>& maxHeap, vector<vector<int>>& pixelHolder)
{
	/* compare the current value of the first two files */
	if(pixelHolder[0][a] > pixelHolder[1][a])
	{
		minHeap.push(pixelHolder[0][a]);
		
		maxHeap.push(pixelHolder[1][a]);
	}
	
	else if(pixelHolder[0][a] < pixelHolder[1][a])
	{
		maxHeap.push(pixelHolder[0][a]);
		
		minHeap.push(pixelHolder[1][a]);
	}
	/*\newpage*/
	/* iterate through rest of files */
	for(int i = 2; i < pixelHolder.size(); i++) 
	{
		if(pixelHolder[i][a] < minHeap.top())
		{
			maxHeap.push(pixelHolder[i][a]);
			checkBalance(minHeap, maxHeap);
		}
		
		else if(pixelHolder[i][a] > minHeap.top())
		{
			minHeap.push(pixelHolder[i][a]);
			checkBalance(minHeap, maxHeap);
		}
	}
	
	/* cout << "fillHeaps: after filling the heaps: " << endl;
	cout << "size of minHeap: " << minHeap.size() << endl;
	cout << "size of maxHeap: " << maxHeap.size() << endl; */
}
