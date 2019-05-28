#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include "mashap.hpp"


/* callback function to receive the image */
size_t handleData(char* p, size_t s, size_t n, std::string* u)
{
    *u += p;

    return s * n; //indicates if there is more data or not
    //zero means no more packets to receive
}


//"https://media3.giphy.com/media/wPud2z0g029Xy/200.gif"

/*
This function finds a gif image with a matching keyword k. and returns the image as a JSON object in string format.
*/
std::string getImageURL(std::string k)
{
    CURL *curl;
    CURLcode res;
    std::string s = "gif: ";
    
    //~ struct curl_slist * slist1 = NULL;
    //~ slist1 = curl_slist_append(slist1, key.c_str());
    //~ slist1 = curl_slist_append(slist1, js.c_str());
/*
This part shortens the string to the last word by iterating throught string from the end until it reaches a space. or the start of the string.    
*/
    int start = k.length();
    while(k[start] != ' ' && start >= 0) start--;
    k = k.substr(start + 1, k.length() - 2);
/*the "\&limit=1" limits the search results to 1 json object*/
    std::string r = url + api + "&q=" + k + "&limit=1";

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl,
                         CURLOPT_URL, r.c_str());
		
		//~ curl\_easy\_setopt(curl,
                         //~ CURLOPT_HTTPHEADER, slist1);
		
		std::cout << r << std::endl;
		
        curl_easy_setopt(curl,
                         CURLOPT_WRITEFUNCTION, handleData);

        curl_easy_setopt(curl,
                         CURLOPT_WRITEDATA, &s);

/* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

/* Check for errors */
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

/* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return s;
}

/********************************************/
/********************************************/
