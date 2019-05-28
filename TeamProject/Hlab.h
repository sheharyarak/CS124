/***********************************************************************\obeylines \obeyspaces
* File: Hlab.h
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The class file containing declarations of all the functions needed for 
	the project.
	
***********************************************************************/

/*** Duplication Protection ***/
#ifndef LAB_H
#define LAB_H

/*** System Libraries ***/
#include <fstream>
#include <iostream>
#include <vector>

/*** User Libraries ***/
#include "HmaxHeap.h"
#include "HminHeap.h"

/*** Namespace Declaration ***/
using namespace std;
/*\newpage*/
/*** Function Declarations ***/

void addHeaderData(string[], ofstream&);

//void readInFiles(vector<string>&, ofstream&, vector<vector<int>>&, ofstream&);
void readInFiles(vector<string>&, ofstream&, vector<vector<int>>&);

//void readFiles(ofstream&, vector<vector<int>>&, ofstream&);
void readFiles(ofstream&, vector<vector<int>>&, string &file_list, string filePrefix);

void heapRebalance(MinHeap<int>&, MaxHeap<int>&);

void checkBalance(MinHeap<int>&, MaxHeap<int>&);

void getMedian(ofstream&, MinHeap<int>&, MaxHeap<int>&, int);

void fillHeaps(int, MinHeap<int>&, MaxHeap<int>&, vector<vector<int>>&);

void emptyMinHeap(MinHeap<int>&);

void emptyMaxHeap(MaxHeap<int>&);

void heapStuff(ofstream&, MinHeap<int>&, MaxHeap<int>&, vector<vector<int>>&);	

#endif /* end of LAB.H */

/*
\includegraphics[scale = 0.75]{heap1.PNG}
\newline
1. First, add a vacant slot to the end of the tree.
\newline
2. Next, demote the parent of the empty slot if it is smaller than the element to be inserted. That is, move the parent value into the vacant slot, and move the vacant slot up. Repeat this demotion as long as the parent of the vacant slot is smaller than the element to be inserted.
\newline
3. At this point, either the vacant slot is at the root, or the parent of the vacant slot is larger than the element to be inserted. Insert the element into the vacant slot.
(copied from book)
\newline
\includegraphics[scale = 0.75]{heap2.PNG}
\newline
\includegraphics[scale = 0.75]{heap3.PNG}
*/
