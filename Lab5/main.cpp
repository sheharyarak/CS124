/* File Block Handler
Since files can be created and deleted, we use blocks of fixed size
to hold the data in the file. We need to maintain a set of blocks that
are free to be used for a file, and when file is deleted, to add those
blocks to a queue of files waiting to have their blocks freed.
 
i.e. There are 2 sets: free blocks and used blocks. A file is a subset
of the used blocks. The queue has the files that are waiting to be freed.
*/

/*
\newpage
\fbox{\textbf{Included Libraries}}
\newline I have used many libraries in this program. many of which were required.
\newline FL/Fl\_Cairo\_Window.H : required in order to use an fltk cairo window with cairo graphics and the cairo functions.
\newline FL/Fl\_Button.H : required in order to use fltk buttons
\newline FL/Fl\_Value\_Input.H : required in order to use fltk input boxes
\newline config.h : required in order to configure fltk
\newline <iomanip> : required in order to use setw function
\newline <cmath> : required in order to use sqrt function
\newline <set> : required in order to use sets
\newline <map> : required in order to use maps
\newline <iterator> : required in order to use iterators
\newline <sstream> : required in order to use osstream
\newline <algorithm> : required in order to use set\_union
*/
#include "config.h"
#include "main.h"
#include <iomanip>
#include "FL/Fl_Cairo_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Value_Input.H"
#include <iostream>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
/*
\newpage
\fbox{\textbf{Global Variables}}
\newline Although the use of global variables is discouraged and may be considered bad practice, I had to use several in order to make this program work. They had to be made global because if I would have to pass all of them by reference into each of the functions being called. We can acheive the same goal by making the variables global and simplify our code.
\newline Queue deleted : deleted is a Queue structure. it is the queue that will hold all the deleted files and delete them after a certain period.
\newline Fl\_Input* fileName : this is a pointer to the fltk input box we use to get the file name from the user.
\newline Fl\_Input* fileBlocks : this is a pointer to the fltk input box we use to get the number of memory blocks to allocate to the file from the user.
\newline int WIDTH : this is the width of the window.
\newline int HEIGHT : this is the height of the window.
\newline Fl\_Button* bc : this is pointer to an fltk button. we will later use this pointer to point to the create button in our program.
\newline Fl\_Button* bd : this is pointer to an fltk button. we will later use this pointer to point to the delete button in our program.
\newline typedef unsigned int BLOCKS : this is a type definition. it allows us to substitute a word for a type. in this case we are substituting the word BLOCKS for the type unsigned int.
\newline std::set<BLOCKS> allBlocks : this creates a set of blocks called allBlocks. This is an empty set for now.
\newline std::set<BLOCKS> usedBlocks : this creates a set of blocks called usedBlocks. This is an empty set for now.
\newline std::set<BLOCKS> freeBlocks : this creates a set of blocks called freeBlocks. This set has the number from 0 to 15.
\newline std::map<std::string,std::set<BLOCKS>> files : this creates a map from a string to a set of blocks.
\newline Fl\_Cairo\_Window cw(WIDTH,HEIGHT) : This make an fltk cairo window of  dimensions WIDTH*HEIGHT by calling an overloaded constructor. this will allow us to call redraw in all of the below functions without passing it as a parameter. the redraw function is essential for this program because we need to remove text and in order to do that we need to redraw the window.
\newline const int N = 16 : Right now we're assuming that the number of memory blocks on the disk is 16.
*/
Queue deleted;
Fl_Input* fileName;
Fl_Input* fileBlocks;
const int WIDTH = 400;
const int HEIGHT = 400;
Fl_Button* bc;
Fl_Button* bd;
typedef unsigned int BLOCKS;
std::set<BLOCKS> allBlocks; /*  empty set   */
std::set<BLOCKS> usedBlocks;
std::set<BLOCKS> freeBlocks = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
std::map<std::string,std::set<BLOCKS>> files;
Fl_Cairo_Window cw(WIDTH,HEIGHT);
const int N = 16;    /* for now, assume 16 blocks on disk */

/*
\newpage
\fbox{\textbf{displayState()}}
\newline The display state function displays the state of the blocks and the queue on to the console.
\newline we're using a range based loop. auto allows the compiler to selct whichever data type fits best instead of having to manually type it in. the ':' makes the a "for each" loop and this is a new kind of for loop that traverses through each of the elements without the progammer having to worry about the when the list ends.
*/
std::string displayState(){
	std::cout<<"==========================================="<<std::endl;
	std::cout<<"Current State"<<std::endl;
	std::cout<<"==========================================="<<std::endl;
    std::cout << "All blocks:" << std::endl;
    for (auto e:allBlocks) std::cout << e <<" ";
    std::cout<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
    std::cout << "Free blocks:" << std::endl;
    for (auto e:freeBlocks) std::cout << e <<" ";
    std::cout<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
    std::cout << "Used blocks:" << std::endl;
    for (auto e:usedBlocks) std::cout << e <<" ";
    std::cout<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
    std:: ostringstream oss;
    std::cout << "file blocks:"<< std::endl;
    std::cout << "File Name"<< "\t" << "Memory Blocks" << std::endl;
    std::cout << "---------"<< "\t" << "-------------" << std::endl;
    for (auto f:files)
    {
		oss << f.first << std::setw(16);
        for (auto e:f.second)
            oss << e <<" ";
        oss << std::endl;
	}
    std::cout<<oss.str()<<std::endl;
    std::cout<<"==========================================="<<std::endl;
	std::cout<<"Deletion Queue " << std::endl;
	std::cout<<"==========================================="<<std::endl;
	Node*tmp = deleted.head;
    while(tmp != nullptr)
    {
	   std::cout << tmp->key << std::endl;
	   tmp = tmp->next;
	}
	std::cout<<std::endl;
	std::cout<<"==========================================="<<std::endl;
    cw.redraw();
    return oss.str();
}
/*
\newpage
This is console output by the program but mostly the displayState function.
\verbatiminput{LabOut.txt}
*/
/*
\newpage
\fbox{\textbf{createCB}}
\newline This is the callback for the create button. It selects random blocks of free memory. it adds thos blocks to a new set, adds them to the usedBlocks set, and removes the block from the freeBlocks set. it then maps the new set to the filename provided by the user. It then redraws the image.
*/
void createCB(void*, void*){
	std::cout<<"==========================================="<<std::endl;
    std::cout << "Created file description" << std::endl;
    std::cout << "File Name: " << fileName->value()<<std::endl;
    std::cout << "Memory Blocks: " << fileBlocks->value()<<std::endl;
    std::cout<<"==========================================="<<std::endl;
    /* Select users number of blocks needed from free set*/
    /* move those from free set */
    std::set<BLOCKS> f;     int x = 3;
    std::set<BLOCKS>::iterator i;
    int BLKS = atoi(fileBlocks->value());
    int found = 0;
    while(found < BLKS && !freeBlocks.empty())
    {
		i = freeBlocks.find(rand() % (N));// find block 3
		if(i != freeBlocks.end())
		{
			f.insert(*i);
			usedBlocks.insert(*i);
			freeBlocks.erase(*i);
			found++;
		}
	}
    std::string filename = fileName->value();
    files[filename] = f;
    displayState();
    cw.redraw();
}
/*
\newpage
\fbox{\textbf{callback}}
\newline This is the callback function. it gets called every 10 seconds. id pops one element from the queue and adds the blocks associated to that file back to freeBlocks set and removes it from the used block set. It then redraws the window.
*/
void callback(void*){
	if(deleted.head != nullptr){
		std::string key = deleted.head->key;
    //pop 1 file of blocks from 0 (if not empty)
    deleted.pop();
    //add to free set and delete from used set
		for(auto block:files[key])
		{
			usedBlocks.erase(block); freeBlocks.insert(block);
		}    
		files.erase(key);
	}
    Fl::repeat_timeout(10.0, callback);    //call every 10 seconds
    cw.redraw();
}
/*
\newpage
\fbox{\textbf{deleteCB}}
\newline This function is a callback for the delete button it pushes the selected file to the queue for deletion. then it displays the state and redraws the window.
*/
void deleteCB(void*, void*){
    //push this file of blocks on the queue
    std::cout<<"file added to deletion queue: ";
    std::string key = fileName->value();
	std::cout << key << std::endl;
    deleted.push(key);
    displayState();
    cw.redraw();
}
/*
\newpage
\fbox{\textbf{drawCB}}
\newline This function draws the blocks, displays the file names, and displays the deletion queue. 
*/
void drawCB(Fl_Cairo_Window* win, cairo_t* cr){
    cairo_set_font_size(cr,20);
    const int s = 35; //scale: pixels per unit
    const int offset = 5; //moving text away from corner
    int COLS = std::sqrt(N);
    int ROWS = COLS;
    for(int i = 0; i < COLS; i++){
        for (int j=0; j < ROWS; j++){
            cairo_set_source_rgb(cr,0,1,0); //green
            cairo_rectangle(cr,i*s,j*s,s,s);
            cairo_stroke(cr);
           
            cairo_move_to(cr,i*s+offset,j*s+s-offset);
            int blockNumber = i+j*std::sqrt(N);
            std::string b = std::to_string(blockNumber);
            if(freeBlocks.find(blockNumber) != freeBlocks.end())
                    cairo_set_source_rgb(cr,1,0,0);//red
                else
                    cairo_set_source_rgb(cr,0,0,1);//blue
            cairo_show_text(cr,b.c_str());
		}
    }
    std::string str;
    int i = 0;
    for(auto file:files)
    {
		str = file.first;
		cairo_set_source_rgb(cr,0,0,0);
		cairo_move_to(cr,180,25+20*i);
		cairo_show_text(cr,str.c_str());
		i++;
	}
	cairo_move_to(cr,5,180);
	cairo_set_source_rgb(cr,0,0,0);
	str = "Deletion Queue:";
	cairo_show_text(cr,str.c_str());
	cairo_move_to(cr,5,215);
	i = 1;
	Node* trav = deleted.head;
	while(trav != nullptr)
	{
		str = trav->key;
		cairo_show_text(cr,str.c_str());
		cairo_move_to(cr,5,215+25*i);
		trav = trav->next;
		i++;
	}
}

/*
\newpage
\fbox{\textbf{main}}
\newline The main function runs the program. and places the button on their position on the window.
*/
int main (void)
{
    Fl::add_timeout(1.0, callback);
    std::cout << std::endl;
    std::set_union(usedBlocks.begin(),usedBlocks.end(),
                    freeBlocks.begin(),freeBlocks.end(),
                    std::inserter(allBlocks,allBlocks.begin()));
    displayState();
    cw.set_draw_cb(drawCB);
    int x =3*WIDTH/4; int y = 3*HEIGHT/4; const char* tc = "Create";
    int w = WIDTH/5; int h = HEIGHT/20;
    bc = new Fl_Button(x,y,w,h,tc);    bc->callback((Fl_Callback*)createCB);
        x=3*WIDTH/4; y = 7*HEIGHT/8; const char* td = "Delete";
    bd = new Fl_Button(x,y,w,h,td);    bd->callback((Fl_Callback*)deleteCB);
    fileName = new Fl_Input(x,y-80-h,w,h,"Filename: ");
    fileBlocks = new Fl_Input(x,y-80,w,h,"Blocks: ");
    cw.show();
    return Fl::run();
}
/*
\newpage
I've Include screenshots from the program.
\newline
\includegraphics[scale = 0.7]{1.PNG}
\newpage
\includegraphics[scale = 0.7]{2.PNG}
\newpage
\includegraphics[scale = 0.7]{3.PNG}
\newpage
\includegraphics[scale = 0.7]{4.PNG}
\newpage
\includegraphics[scale = 0.7]{5.PNG}
\newpage
\includegraphics[scale = 0.7]{6.PNG}
\newpage
\includegraphics[scale = 0.7]{7.PNG}
*/
