/*
This is the file I used to test my parseJson and string functions.
*/

#include "mashap.hpp"
#include "string.hpp"
#include <iostream>

std::string getImageURL(std::string k);
void getImage(std::string k);

using namespace std;

int main(void)
{
	string query = "cat";
	string json = getImageURL(query);
	std::string originalUrl = "\"original\":{\"url\":\"";
	int start = find(json, originalUrl, 0);
	int end = find(json, ".gif", start + 1);
	int length = end - start + 4 - originalUrl.length();
	string parsedUrl = substr(json, start + originalUrl.length(), length);
	string cleanedUrl = clean(parsedUrl, '\\');
	
	cout << "start, end, length: " << start << ", " << end <<", " << length <<endl;
	cout << "Query: " << query << endl;
	cout << "parsedUrl: " << parsedUrl << endl;
	cout << "cleanedUrl: " << cleanedUrl << endl;
	cout << json;
	
}
