/***********************************************************************\obeylines \obeyspaces
* File: CPPreadInFiles.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of a function that opens input streams for all the 
	source files, reads a line of input from each file, then pushs it to 
	a vector to store the int values of the pixels for later processing.
	
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
/****** readInFiles() Function Definition ******/
/*********************************************/
//void readInFiles(vector<string>& fNames, ofstream& newImage, vector<vector<int>>& pixelHolder, ofstream& debug) 
void readInFiles(vector<string>& fNames, ofstream& newImage, vector<vector<int>>& pixelHolder) 
{
	string header[3] = {};
	
	int numbers = 0;
	
	vector<int> tempFileHolder; /* Temp vector which holds all the pixels for one image */
	
	for(int i = 0; i < fNames.size(); i++)
	{
		//debug << "File #" << i << endl;
		
		const char * fileOpen = fNames[i].c_str();
		
		/* cout << "Opening: " << fileOpen << endl; */
		
		ifstream data(fileOpen);
		
		for(int j = 0; j < 3; j++) /* Grabs the header for each picture so only pixels are left in each picture */
		{
				getline(data,header[j]);
				/* cout << "The header value is: " << header[j] << endl; */
		}
		
		while(data >> numbers)
		{
			tempFileHolder.push_back(numbers);
		}
		
		//debug << "size of temp vector: " << tempFileHolder.size() << endl;
		
		pixelHolder.push_back(tempFileHolder);
		
		//debug << "size of pixelHolder: " << pixelHolder.size() << endl;
		
		tempFileHolder.clear();
	}
	
	addHeaderData(header, newImage);
}
/*
\includegraphics[scale = 0.5]{Pixel.png}
*/
