/*	lab.cpp	*/

//g++ -g -I/home/debian/fltk-1.3.4-2 -I/home/debian -o "lab" *.cpp -lcurl /home/debian/catch2.o `fltk-config --cxxflags --ldflags --use-images --use-cairo`
//g++ -g -I/home/debian/fltk-1.3.4-2 -I/home/debian -o "lab" *.cpp -lcurl /home/debian/catch2.o `fltk-config --cxxflags --ldflags --use-images --use-cairo`


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <config.h>
#include <curl/curl.h>
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Anim_GIF_Image.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include "binaryTree.hpp"
#include "parseFile.hpp"


//Compilation command: 
//g++ -g -I/home/debian -o "lab" "lab.cpp" -lcurl getImageURL.cpp -I/home/debian/fltk-1.3.4-2 `fltk-config --cxxflags --ldflags --use-images --use-cairo`
//g++ -g -I/home/debian -o "lab" "lab.cpp" -lcurl getImage.cpp -I/home/debian/fltk-1.3.4-2 `fltk-config --cxxflags --ldflags --use-images --use-cairo`

//Fl_Cairo_Window cw;
const int WIDTH = 600;
const int HEIGHT = 600;
BinaryTree buildTree();
BinaryTree buildTree(std::string filename);
std::string parseJson(std::string j);
std::string getImageURL(std::string);
void getImage(std::string);

int main()
{
	/*First I build a tree using the build tree function by fassing in the file path. The I make a Traveler Node that iterates throught the list and is used to access the nodes to ask questions.*/
	BinaryTree tree = buildTree("animals.txt");
	Node *trav = tree.root;
	Fl_Cairo_Window cw(WIDTH, HEIGHT);
	
	Fl_Box b(10, 10, WIDTH, HEIGHT);
	
	string s = "cat"; //default set to cat
	
	int choice;
	string animal;
	while(true)
	{
		/*if its a nullptr or the list is empty return 0. This prevents segfault on empty list*/
		if(trav == nullptr) return 0;
		if(trav->left == nullptr && trav->right == nullptr)
		{
			/*when it reaches a leaf node it asks is it guessed the right animal. if it doesnt is asks the user for the correct animal and a question that would help it distinguish between the corect answer and the wrong answer.*/
			string q = trav->data+" Is my assessment correct?";
			choice = fl_choice(q.c_str(), "No", "Yes", 0);
			s = trav->data;
			/*
			if the user chooses no the program asks the user what his animal is and a question that could be used to differentiate between the guessed animal and the users animal. it then modifies the tree as follows:
			\newline
			sets the current node's left child (yes answer) to new node with the data animal.
			\newline
			sets the current node's right child (no answer) to the current nodes data.
			\newline
			replaces the current node's data with the question string.
			\newline
			*/
			if(choice == 0)
			{
				animal = fl_input("Enter new animal: ");
				string question = fl_input("What question would you have asked?");
				animal += ".";
				trav->left = new Node(animal);
				trav->right = new Node(trav->data);
				trav->data = question;
				s = animal;
			}
			/*
			Visual representation of the code above is explained in the figure below.
			\newline
			\includegraphics[scale = 0.65]{questiontree1.png}
			*/
			break;
		}
		else
		{
			/*Over here the program iterates over the list with user input*/
			choice = fl_choice(trav->data.c_str(), "No", "Yes", 0);
			if(choice == 1)
				trav = trav->left;
			else if(choice == 0)
				trav = trav->right;
			else
				break;
		}
	}
	/*First I get a JSON object in string format using the getImageUrl function passing s as a parameter. Then I parse the json object and updat s. finally I get the image using s which is now a proper url.*/
	s = getImageURL(s);
	s = parseJson(s);
	getImage(s);
	Fl_GIF_Image i("animal.gif");
	b.image(&i);
	
	cw.show();
	/*at the end of the function I update the file by writing the tree to it.*/
	writeTree(tree ,"animals.txt");
	return Fl::run();
	
}

/*
The gui looks as follows:
\newline
\includegraphics[scale = 0.6]{question.PNG}
\newline
\includegraphics[scale = 0.6]{result.PNG}
\newline
\includegraphics[scale = 0.6]{addAnimal.PNG}
\newline
\includegraphics[scale = 0.6]{addQuestion.PNG}
\newline
\includegraphics[scale = 0.6]{gif.PNG}
*/
