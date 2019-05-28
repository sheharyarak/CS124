/***********************************************************************\obeylines \obeyspaces
* File: CPPaddHeaderData.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	Using a median filter, this program filters out something blocking 
	the desired focal point of a series of photos.
	
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
/****** addHeaderData() Function Definition ******/
/*********************************************/

void addHeaderData(string header[], ofstream& newImage)
{
	for(int i = 0; i < 3; i++)
	{
		newImage.write(header[i].c_str(), header[i].length());
		newImage << "\n";
	}
}
