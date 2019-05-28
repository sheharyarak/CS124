/***********************************************************************\obeylines \obeyspaces
* File: CPPmain.cpp
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	Using a median filter, this program filters out something blocking 
	the desired focal point of a series of photos.
	
***********************************************************************/

/*
Compilation Command:
g++ -g -I/home/debian -o lab CPP*.cpp -I/home/debian/fltk-1.3.4-2 `fltk-config --cxxflags --ldflags --use-images --use-cairo`
*/

/*** System Libraries ***/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*** User Libraries ***/
#include "Hlab.h"
#include "HmaxHeap.h"
#include "HminHeap.h"
/*\newpage*/
/*** FLTK Libraries***/
#include "config.h"
#include "FL/Fl_Cairo_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Value_Input.H"
#include "FL/Fl_Text_Display.H"
#include <FL/Fl_Input.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

/*** Namespace Declaration ***/
using namespace std;

/*** Global Variable(s) ***/
vector<vector<int>> pixelHolder;
string file_list;

/** FLTK Global Variables ***/
const int WIDTH = 600;
const int HEIGHT = 600;
Fl_Input* prefix = nullptr;
Fl_Button* submit = nullptr;
Fl_Button* findBut = nullptr;
Fl_Button* clearBut = nullptr;
Fl_Button* showBut = nullptr;
Fl_Text_Display* files = nullptr;
Fl_Text_Buffer* buff = nullptr;
Fl_Cairo_Window* cw = nullptr;
Fl_PNG_Image* png = nullptr;
Fl_Box* imgBox = nullptr;
/*\newpage*/
/** Global Pointers (for use in FLTK callbacks) **/
ofstream *newImagePointer;
MinHeap<int>* minHeapPointer;
MaxHeap<int>* maxHeapPointer;

/** FLTK Callback declarations **/
void submitCB(void*, void*);
void findCB(void*, void*);
void showCB(void*, void*);
void clearCB(void*, void*);

/*************************/
/****** Main Progam ******/
/*************************/

int main()
{
	ofstream debug; debug.open("debug.txt");
	
	/* cout << "avoided segv A" << endl; */
	
	ofstream newImage;
	
	/* cout << "avoided segv B" << endl; */
	
	newImage.open("output.ppm");
	
	/* cout << "avoided segv C" << endl; */
	
	MinHeap<int> minHeap;
	
	/* cout << "avoided segv D" << endl; *//*\newpage*/

	MaxHeap<int> maxHeap;
	
	/* cout << "avoided segv E" << endl; */

	newImagePointer = &newImage;
	minHeapPointer = &minHeap;
	maxHeapPointer = &maxHeap;
	
	/*
	readFiles(newImage, pixelHolder, debug);
	
	/* cout << "avoided segv F" << endl; 
	
	/* for(int i = 0; i < pixelHolder.size(); i++)
	{
		cout << "There are " << pixelHolder[i].size() << " pixels in each picture" << endl;
	} */
	/* cout << "avoided segv G" << endl; 
	heapStuff(newImage, minHeap, maxHeap, pixelHolder);
	*/
	
	cw = new Fl_Cairo_Window(WIDTH,HEIGHT);
	
	int w, h, x, y;
	
	w = WIDTH * 0.3;
	h = HEIGHT * 0.1;
	x = WIDTH * 0.6;
	y = HEIGHT * 0.65;
	findBut = new Fl_Button(x, y, w, h, "Find Files");
	findBut->callback((Fl_Callback*)findCB);
/*\newpage*/
	w = WIDTH * 0.3;
	h = HEIGHT * 0.1;
	x = (WIDTH - w) * 0.5;
	y = HEIGHT * 0.85;
	submit = new Fl_Button(x, y, w, h, "Remove Noise");
	submit->callback((Fl_Callback*)submitCB);

	w = WIDTH * 0.3;
	h = HEIGHT * 0.1;
	x = WIDTH * 0.6;
	y = HEIGHT * 0.5;
	clearBut = new Fl_Button(x, y, w, h, "Clear");
	clearBut->callback((Fl_Callback*)clearCB);
	
	w = WIDTH * 0.3;
	h = HEIGHT * 0.1;
	x = WIDTH * 0.6;
	y = HEIGHT * 0.3;
	showBut = new Fl_Button(x, y, w, h, "Show");
	showBut->callback((Fl_Callback*)showCB);
	
	w = WIDTH * 0.5;
	h = HEIGHT * 0.5;
	x = WIDTH * 0.1;
	y = HEIGHT * 0.1;
	files = new Fl_Text_Display(x, y, w, h, "Files Found:");
/*\newpage*/
	w = WIDTH * 0.3;
	h = HEIGHT * 0.1;
	x = WIDTH * 0.3;
	y = HEIGHT * 0.65;
	prefix = new Fl_Input(x, y, w, h, "File Prefix:");
	buff = new Fl_Text_Buffer;

	files->buffer(*buff);
	cw->show();
	
    return Fl::run();
} /* End of Main */

/*********************************/
/*** FLTK Callback Definitions ***/
/*********************************/

/******************* Remove Noise Button's Callback ********************/
/*
This is the callback for the remove noise button. It was previously labeled submit but I thought that "remove noise" suited it better. This function calls the heapStuff function. Th heapStuff function the the backbone of the labe and removes the noise.
*/
void submitCB(void*, void*)
{
	cout << "removing noise" << endl;
	for(int i = 0; i < pixelHolder.size(); i++)
	{
			cout << "There are " << pixelHolder[i].size() << " pixels in each picture" << endl;
	}
	heapStuff(*newImagePointer, *minHeapPointer, *maxHeapPointer, pixelHolder);
	cw->redraw();
	system("wc -w output.ppm > size.txt");
	ifstream ifs("size.txt");
	int pixels = 0;
	ifs >> pixels;
	cout<<"output file has " << pixels <<" pixels." <<endl;
	cout << "noise removed" << endl;
}/*\newpage*/

/******************* Find Button's Callback ********************/
/*
This is the find button callback. It finds the files based on the file prefix. For example if the file prefix is "image" it will finde all the files with that prefix and the .ppm extension.
\newline
\includegraphics[scale = 0.75]{findCB.png}
*/
void findCB(void*, void*)
{
	cout << "finding" << endl;
	readFiles(*newImagePointer, pixelHolder, file_list, prefix->value());
	buff->append(file_list.c_str());
	file_list = "";
	cw->redraw();
	cout << "found" << endl;
}
/*\newpage*/
/******************* Clear Button's Callback ********************/
/*
This is the clearCB callback. empties the file list, the vector and the buffer. First it empties the buffer by settting the buffer text to an empty string so that it becomes empty. then it sets the file list to an empty string so that it becomes empty. Finally the pixelHolder vector is emptied using the vector::clear() funcction.
*/
void clearCB(void*, void*)
{
	cout << "clearing" << endl;
	buff->text("");
	file_list = "";
	pixelHolder.clear();
	cw->redraw();
	cout << "cleared" << endl;
}
/*\newpage*/
/******************* Show Button's Callback ********************/
/*
The showCB displays the image using the system command "display" followed by the image name. 
*/
void showCB(void*, void*)
{
	cout << "displaying" << endl;
	system("display output.ppm");
	cout << "displayed" << endl;
}
/*
\newpage
The GUI looks as follows.
\newline
\includegraphics[scale = 0.75]{start.PNG}
\newline
\includegraphics[scale = 0.75]{findCB.PNG}
\newline
\includegraphics[scale = 0.75]{submitCB.PNG}
\newline
As you can see the number of pixels in the output files are are significantly less than the number of pixels in the input files. This means we are losing pixels somewhere. Losing these pixels causes the resulting image to be distorted.
\newline
\includegraphics[scale = 0.75]{showCB.PNG}
\newline
We spent a whole day trying to figure out where these pixels go but we did not succeed in resolving the issue. 
*/
