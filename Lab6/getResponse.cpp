/*	getResponse.cpp	*/
/********************************************/
/********************************************/

#include <iostream>
#include <string>
#include "binaryTree.hpp"

/*this fuction gets the users response. Its for a CLI not fltk.*/
std::string getResponse(BinaryTree t)
{
	std::string r;
	do
	{
		cout << t.data() << " (y/n): ";
		cin >> r;
	} while (r != "y" && r != "n");
	return r;
}

/********************************************/
/********************************************/
