#include <string> 
#include <iostream> 
#include <curl/curl.h> 

using namespace std; 

string contents; 

string url = "http://www.deanclatworthy.com/imdb/?id=tt0454921";

// 
// This is the callback function that is called by 
// curl_easy_perform(curl) 
// 
size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream) 
{ 
    int numbytes = size*nmemb; 
    // The data is not null-terminated, so get the last character, and replace 
    // it with '\0'. 
    char lastchar = *((char *) ptr + numbytes - 1); 
    *((char *) ptr + numbytes - 1) = '\0'; 
    contents.append((char *)ptr); 
    contents.append(1,lastchar); 
    *((char *) ptr + numbytes - 1) = lastchar;  // Might not be necessary. 
    return size*nmemb; 
}  // END HANDLE_DATA

int main() 
{ 
    CURL* curl = curl_easy_init(); 
    if(curl) 
	{ 
        // Tell libcurl the URL 
        curl_easy_setopt(curl,CURLOPT_URL, url.c_str()); 
		
        // Tell libcurl what function to call when it has data 
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data); 
		
        // Do it! 
        CURLcode res = curl_easy_perform(curl); 
        curl_easy_cleanup(curl); 

        cout << contents << endl; 
		
	}  //END IF_CURL
    return 0; 
}  //END MAIN