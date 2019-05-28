/*	buildTree.cpp	*/

#include "binaryTree.hpp"
#include "parseFile.hpp"

/*This function returns a binaryTree with hardcodes values*/
BinaryTree buildTree() 
{
	BinaryTree question_tree(
		BinaryTree("Is it a mammal?",
			BinaryTree("Does it have stripes?",
				BinaryTree("Is it a carnivore?",
					BinaryTree("It is a tiger."),
					BinaryTree("It is a zebra.")),
				BinaryTree("It is a pig.")),
			BinaryTree("Does it fly?",
				BinaryTree("It is an eagle."),
				BinaryTree("Does it swim?",
					BinaryTree("It is a penguin."),
					BinaryTree("It is an ostrich.")))));
	return question_tree;
}
/*
The resulting tree would look like this. 
\newline
\includegraphics[scale = 0.65]{questiontree.png}
*/

/*This function builds a tree by reading it from a file.*/
BinaryTree buildTree(std::string filename) 
{
	BinaryTree tree = readFile(filename);
	return tree;
}
