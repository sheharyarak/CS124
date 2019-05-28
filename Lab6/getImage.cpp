/*	getImage.cpp	*/
/********************************************/
/********************************************/

#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include "mashap.hpp"

/* callback function to receive the image */
size_t handleData2(char* p, size_t s, size_t n, std::ofstream* u)
{
    size_t ns = s * n;
    
    u->write(p, ns);
    
    return s * n; //indicates if there is more data or not
    //zero means no more packets to receive
}

//"https://media3.giphy.com/media/wPud2z0g029Xy/200.gif"

//expect s is a valid URL of a gif and we want to save it in a file
/*
	This function uses curl to get an image and save it to the animal.gif file..
*/
void getImage(std::string k)
{
    CURL *curl;
    
    CURLcode respcode = CURLE_OK;
   
	std::ofstream ofs("animal.gif", std::ios::binary);
    
    //std::string r = url + api;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    
    if(curl)
    {
        curl_easy_setopt(curl,
                         CURLOPT_URL, k.c_str());
		
		//std::cout << r << std::endl;
		
		curl_easy_setopt(curl,
                         CURLOPT_WRITEFUNCTION, handleData2);
                         
        curl_easy_setopt(curl,
                         CURLOPT_WRITEDATA, &ofs);//change to write to a file
		
		/* Perform the request, res will get the return code */
        respcode = curl_easy_perform(curl);
		
		/* Check for errors */
        if(respcode != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(respcode));
            
        }
		
		/* always cleanup */
        curl_easy_cleanup(curl);
        
    }

    curl_global_cleanup();
    
    //return;
}


/********************************************/
/********************************************/
