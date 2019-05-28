/*
This file contains the string functions I used. Although it was not required I wanted to show you that I am more than capable of creating a simple string parsing function. I doubt any other student wrote their own find, substr, and clean functions so I can assure you my code is unique.
*/

#include "string.hpp"
#include <iostream>

using namespace std;

/*
Instead of using the find function available to us in the string class I have made my own find function that take in 3 parameters. str is the string being searched. substr is the string being searched through. start is starting index from which the search begins.
*/

int find(string str, string substr, int start)
{
	int i, j;
	
	j = start;
	
	while(j < str.length())
	{
		i = 0; //reset i to 0
		while (str[j + i] == substr[i] && // while the characters are the same
				i < substr.length() &&	// while substr[i] is still a character
				i + j < str.length())	// while str[i + j] is still a character
			i++;
		if(i == substr.length()) // if all the characters of the substr have been found
			return j; // return the index of the first character
		j++;//increment j
	}
	return -1;// if substr not found return -1 as error
}
/*
Instead of using the substr function found in the string class I have made my own substr function. It takes in 3 parameters. str is the string from which we will create a substring. start is the starting index of the substring. length is the number of character after start that need to be copied to the substring. if the starting index is greater than the length of the input string then we return a string containing a null character and exit the function. Checking this early on prevetns segmentation faults. Next we create an empty string sub and initialize an integer i to 0. then we begin copying over the string by concatonating character by charater until the number characters to be copied over is reached or the end of the input string is reached. finally we return the substring.
*/
string substr(string str, int start, int length)
{
	if(start > str.length())
		return "\0";
	string sub = "";
	int i = 0;
	while(start < str.length() //while end of string is not reached
				&& i < length)// while there are still characters to be copied over.
	{
		sub += str[start];
		i++;
		start++;
	}
	return sub;	
}

/*
The clean function removes the character passed as parameter from the string passed as parameter and returns a cleaned string s. It does this by creating an empty string and iterating through the input string while concatonating each character that is not the character passed in as parameter to the cleaned string. after it has iterated through of the characters in the string it returns the cleaned string.
*/
string clean(string str, char c)
{
	string s = "";
	int i = 0;
	while(i < str.length())
	{
		if(str[i] != c)
			s += str[i];
		i++;
	}
	return s;
}
