/*	binaryTree.hpp	*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>

using namespace std;

/*I have made the Node class public because it is easier to work directly with the Node object than with getters and setters in the binary tree */
class Node
{
	public:
		string data;
		Node* left = nullptr;
		Node* right = nullptr;
		friend class BinaryTree; 
		Node(){}
		Node(string data){this->data=data;}

};

/*A binary tree in which each node has two children.*/
class BinaryTree
{

/********************************************************/

	public:
	
		/**	Constructs an empty tree.   */
		BinaryTree();
		
		/********************************************************/
		
		/**	Constructs a tree with one node and no children. */
		BinaryTree(string root_data);	/** @param root\_data the data for the root */
		
		/********************************************************/
		
		/** Constructs a binary tree. */
		BinaryTree(string root_data, BinaryTree left, BinaryTree right);
			/** @param root\_data the data for the root
			@param left the left subtree
			@param right the right subtree */
		
		/********************************************************/
		
		/**	Returns the height of this tree. */
		int height() const; /** returns the height */
		
		/********************************************************/
		
		/** Checks whether this tree is empty.*/
		bool empty() const;	/** @return true if this tree is empty */
	
		/********************************************************/
		
		/** Gets the data at the root of this tree. */
		string data();	/** @return the root data */
		
		/********************************************************/
		
		/** Gets the left subtree of this tree. */
		BinaryTree left();	/** @return the left child of the root */

		/********************************************************/

		/** Gets the right subtree of this tree. */
		BinaryTree right();	/** @return the right child of the root */

/********************************************************/

		/** Returns the height of the subtree whose root is the given node. */
		int height(const Node* n) const;
			/** @param n a node or nullptr
			@return the height of the subtree, or 0 if n is nullptr */
		
		/********************************************************/
		
		/*This constructor creates a binary tree object with the passed node*/
		BinaryTree(Node * node){
			this->root = node;
		}
		
		Node* root = nullptr;
};
#endif

/********************************************/
/********************************************/
