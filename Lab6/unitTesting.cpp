/*
These are all the unit tests I ran to check my code was working.
\verbatiminput{unitTests.txt}
*/

#include "catch.hpp"
#include "binaryTree.hpp"
#include <iostream>
#include <string>

using namespace std;

BinaryTree tree("root");

TEST_CASE("Add")
{
	CHECK((tree.left()).empty() == true);
	tree.root->left = new Node("Left");
	CHECK((tree.left()).empty() == false);
	CHECK((tree.left()).data() == "Left");
}

TEST_CASE("Traverse Right")
{
	tree.root->right = new Node("Right");
	Node* trav = tree.root;
	CHECK(trav->data == "root");
	trav = trav->right;
	CHECK(trav->data == "Right");
}

TEST_CASE("Traverse Left")
{
	CHECK(tree.data() == "root");
	tree = tree.left();
	CHECK(tree.data() == "Left");
}

//g++ -g -I/home/debian -o "unitTesting" "*.cpp" ~/catch2.o
