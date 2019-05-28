/***********************************************************************\obeylines \obeyspaces
* File: CPPheapRebalance.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function that rebalances the min and max heap 
	when the size of one is greater than the other by two or more values.
	
	This is accomplished by removing and storing the root value of the 
	larger heap, reHeaping the reduced heap to maintain the desired 
	priority order and then pushing the stored value to the other heap.
	
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
/****** heapRebalance() Function Definition ******/
/*********************************************/

void heapRebalance(MinHeap<int>& minHeap, MaxHeap<int>& maxHeap)
{
	if(minHeap.size() > maxHeap.size()) /* if minHeap is larger */
	{
		/* cout << "more min" << endl; */
		
		minHeap.fix_heap_public();
		
		/* cout << "heapRebalance: after fixHeap: " << endl;
		cout << "size of minHeap: " << minHeap.size() << endl; */
		
		int temp = minHeap.top();
		
		/* cout << "temp value: " << temp << endl; */
		
		minHeap.pop();
		
		/* cout << "heapRebalance: after minHeap.pop(): " << endl;
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl; */
		/*\newpage*/
		maxHeap.push(temp);
		
		/* cout << "heapRebalance: after maxHeap.push(temp): " << endl;
		
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl;
		
		cout << "MinHeap" << endl;
		minHeap.printHeapPublic();
		
		cout << "MaxHeap" << endl;
		maxHeap.printHeapPublic(); */
	}
	/*\newpage*/
	else if(minHeap.size() < maxHeap.size()) /* if maxHeap is larger */
	{
		/* cout << "more max" << endl; */
		
		maxHeap.fix_heap_public();
		
		/* cout << "heapRebalance: after fixHeap: " << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl; */
		
		int temp = maxHeap.top();
		
		/* cout << "temp value: " << temp << endl; */
		
		maxHeap.pop();
		
		/* cout << "heapRebalance: after maxHeap.pop(): " << endl;
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl; */
		/*\newpage*/
		minHeap.push(temp);
		
		/* cout << "heapRebalance: after minHeap.push(temp): " << endl;
		
		cout << "size of minHeap: " << minHeap.size() << endl;
		cout << "size of maxHeap: " << maxHeap.size() << endl;
		
		cout << "MinHeap" << endl;
		minHeap.printHeapPublic();
		
		cout << "MaxHeap" << endl;
		maxHeap.printHeapPublic(); */
	}
	
	else /* if heaps are equal */
	{
		/* cout << "Heaps are equal" << endl; */
	}
}
