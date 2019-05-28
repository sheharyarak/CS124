/***********************************************************************\obeylines \obeyspaces
* File: CPPemptyHeaps.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definitions of the functions that empty the max or min heap by 
	popping all values in the heap.
	
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
/****** emptyMinHeap() Function Definition ******/
/*********************************************/

void emptyMinHeap(MinHeap<int>& minHeap)
{
	/* pop all values in minHeap */
	for(int b = 0; b < minHeap.size(); b++)
	{
		minHeap.pop();
	}
}

/*********************************************/
/****** emptyMaxHeap() Function Definition ******/
/*********************************************/

void emptyMaxHeap(MaxHeap<int>& maxHeap)
{
	/* pop all values in maxHeap */
	for(int b = 0; b < maxHeap.size(); b++)
	{
		maxHeap.pop();
	}
}
