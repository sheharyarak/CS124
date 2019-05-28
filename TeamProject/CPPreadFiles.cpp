/***********************************************************************\obeylines \obeyspaces
* File: CPPreadFiles.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The definition of the function that locates all image source files 
	through a system command, pipes the names to another file, reads 
	those names into a vector and then calls the function to read in 
	each file's contents to another set of vectors.
	
***********************************************************************/

/*** System Libraries ***/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*** User Libraries ***/
#include "Hlab.h"
#include "HmaxHeap.h"
#include "HminHeap.h"

/*** namespace declaration ***/
using namespace std;

/*\newpage*/
/*********************************************/
/****** readFiles() Function Definition ******/
/*********************************************/

//void readFiles(ofstream& newImage, vector<vector<int>>& pixelHolder, ofstream& debug)
void readFiles(ofstream& newImage, vector<vector<int>>& pixelHolder, string &file_list, string filePrefix)
{
		vector<string> numFiles; /* This vector will hold the names of the files */
		string line = " ";
		int counter = 0;
		
		/*system("ls image*.ppm > file.txt"); // Grabs all PPM images in current directory */
		/* system("ls test*.ppm > file.txt"); //Grabs all test PPM images in current directory */
		string command ="ls "+ filePrefix +"*.ppm > file.txt";
		system(command.c_str()); /* Grabs all test PPM images in current directory */
		
		ifstream ifs("file.txt"); /* Opens the newly created text file */

		while(getline(ifs, line)) /* Grabs the file names from text file and pushed it into vector */
		{
			numFiles.push_back(line);
			file_list += line + "\n";
			counter++;
		}
		/*\newpage*/
		/* cout << "There are " << counter << " PPM files " << endl; //Confirms how many PPM Files are in directory
		for(int i = 0; i < counter; i++)
		{
				cout << numFiles[i] << endl; //Prints out all file names
		}
		cout << "There are " << numFiles.size() << " Files" << endl; */
		readInFiles(numFiles, newImage, pixelHolder); /* Calls to next function */
}
