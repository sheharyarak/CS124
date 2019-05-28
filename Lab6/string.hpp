/*
This file contains all the function declarations for the string.cpp file.
*/

#ifndef STRING_HPP
#define STRING_HPP

#include <string>
using namespace std;

int find(string str, string substr, int start);
string substr(string str, int start, int length);
string clean(string str, char c);

#endif

