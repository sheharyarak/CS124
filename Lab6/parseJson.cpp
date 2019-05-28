#include <iostream>
#include "string.hpp"

using namespace std;

/*This function parses a JSON object and returns the url for an animated gif image.*/
/*
The JSON Object looks like this:
\newline
\verbatiminput{json.txt}
as you can see there's more than one "original" in the string. so we can't just search for original. we must search for the original we want so we must add a few extra characters after original to find the original we want. The image we want is the "original" but the json contains "original\_still" and "original\_mp4" so we add a couple of characters. In order to make it easy for us we add characters up to right before the url begins. so the string we search for is '"original":{"url":"' and add the number of characters in the string we searched for so that start equals the index right before "http" in the string. we want to search till the end of the url. the url ends with ".gif" so we search from the start till we find ".gif" but since the find function will return the index at which ".gif" starts we must add the length of ".gif" which is 4 characters. Next we get the url using the sub string function but it contains alot of unwanted "\\" characters so we use the clean function to clean it. The transformation of the string can be seen below.
\newline
\verbatiminput{urls.txt}
*/
string parseJson(std::string j)
{
	cout <<"input: " << j <<endl;
	string original = "\"original\":{\"url\":\"";
	int start = find(j, original, 0) + original.length();
	int end = find(j, ".gif", start + 1) + 4;
	int len = end - start;
	cout << "start, end, len: " << start<<", "<< end <<", "<< len <<endl;
	j = substr(j, start, len);
	cout <<"substr: " << j <<endl;
	j = clean(j, '\\');
	cout <<"clean: " << j <<endl;
	return j;
	
}

