/*********************************************************************************************************
g++ -g -I/home/debian -o "lab" "lab.cpp" -lcurl getImage.cpp -I/home/debian/fltk-1.3.4-2 `fltk-config --cxxflags --ldflags --use-images --use-cairo`
*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*	mashape.hpp	*/

/*
this file contains all the constants used in the other files.
*/
/********************************************/
/********************************************/
#ifndef MASHAP_HPP
#define MASHAP_HPP

#include <string>

const std::string url = "https://api.giphy.com";
const std::string key = 
"X-RapidAPI-Key: DrFjbSmOJnmshTt0NowBkUY1WpcXp1bDqRvjsn4MrMqadGpwlM";
const std::string js = "Accept: application/json";
const std::string api = "/v1/gifs/search?api_key=evJNRw4gT9hrC9P2hfQPe22czt629zPa";

/********************************************/
/********************************************/

#endif
