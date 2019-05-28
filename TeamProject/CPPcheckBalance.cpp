/***********************************************************************\obeylines \obeyspaces
* File: CPPcheckBalance.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function that checks the size of the min heap 
	and max heap and calls the function to rebalance them if the 
	difference is greater than 1 or less than -1.
	
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
/****** checkBalance() Function Definition ******/
/*********************************************/

void checkBalance(MinHeap<int>& minHeap, MaxHeap<int>& maxHeap)
{
	int check = minHeap.size() - maxHeap.size();
	
	/* cout << endl << "check is: " << check << endl; */
	
	if (check > 1 || check < (-1))
	{
		/* cout << "before heapRebalance is called" << endl;
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl; */
		heapRebalance(minHeap, maxHeap);
		/* cout << "heapRebalance called" << endl;
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl; */
	}
	
	else
	{
		return;
	}
}
