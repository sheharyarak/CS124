/*	binaryTree.cpp	*/
/********************************************/
/********************************************/
/*
This file contains definitions for the functions declared in binaryTree.hpp
*/
#include <algorithm>
#include "binaryTree.hpp"
/*
This is a default constructor that sets the root equal to nullptr.
*/
BinaryTree::BinaryTree()
{
	root = nullptr;
} 
/*
This is a constructor that creates a new root node and sets its data equal to the root\_data passed as parameter.
*/
BinaryTree::BinaryTree(string root_data) 
{
	root = new Node;
	root->data = root_data;
	root->left = nullptr;
	root->right = nullptr;
}
/*
This is a constructor that creates a new root node and sets its data equal to the root\_data passed as parameter as well as setting the new nodes left and right nodes to the left and right nodes passed as parameters.
*/
BinaryTree::BinaryTree(string root_data, BinaryTree left, BinaryTree right)
{
	root = new Node;
	root->data = root_data;
	root->left = left.root;
	root->right = right.root;
}
/*
	this function returns the height of the binary tree from a node down using recursion and max from the standard library.
*/
int BinaryTree::height(const Node* n) const
{
	if (n == nullptr) { return 0; }
	else { return 1 + max(height(n->left), height(n->right)); }
}
/*
	this function returns the height of the binary tree from the root using recursion and max from the standard library.
*/
int BinaryTree::height() const 
{ 
	return height(root); 
}
/*
	this function checks if the tree is empty.
*/
bool BinaryTree::empty() const 
{ 
	return root == nullptr; 
}
/*
	this function returns the data of the root.
*/
string BinaryTree::data() 
{ 
	return root->data; 
}
/*
	this function returns a binaryTree with the left node as a the root. 
*/
BinaryTree BinaryTree::left() 
{ 
	BinaryTree result;
	result.root = root->left; 
	return result;
}
/*
	this function returns a binaryTree with the right node as a the root. 
*/
BinaryTree BinaryTree::right() 
{ 
	BinaryTree result;
	result.root = root->right; 
	return result;
}

/********************************************/
/********************************************/
