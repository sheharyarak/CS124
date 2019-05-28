/*
parseFile.hpp
*/

/*
This file contains all the headers for the functions used in parseFile.cpp
*/

#ifndef PARSEFILE_H
#define PARSEFILE_H

#include "binaryTree.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void writeNode(BinaryTree tree, ofstream * file);
void writeTree(BinaryTree tree, string filename);
void addNode(BinaryTree &tree, ifstream *file);
BinaryTree readFile(string filename);

#endif
