/*	treeDemo.cpp	*/
/* This program demonstrates a decision tree for an animal guessing game. */

#include <fstream>
#include <iostream>
#include <string>
#include "binaryTree.hpp"

using namespace std;

BinaryTree buildTree();
std::string getResponse(BinaryTree);


void preOrder(std::ofstream& o, BinaryTree bt)
{
	if (bt.empty())
	{
		return;
	}
	
	o << bt.data() << std::endl;
	
	preOrder(o, bt.left());
	
	preOrder(o, bt.right());
	
}



int main()
{
	/* Build a binary tree called question tree */
	BinaryTree question_tree = buildTree();	//calls 
	/* includegraphics[scale=0.7]{questionTree.png} */
	
	std::ofstream ofs("animals");
	
	preOrder(ofs, question_tree);
	
	//preOrder(std::cout, question_tree);
	
	bool done = false;

	while (!done)
	{
		BinaryTree left = question_tree.left();
		BinaryTree right = question_tree.right();

		if (left.empty() && right.empty())
		{
			cout << question_tree.data() << endl;
			done = true;
		}
		
		else
		{
			string response = getResponse(question_tree);
			
			if (response == "y"){question_tree = left;}
			
			else {question_tree = right;}         
		}
	}
	
}

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
