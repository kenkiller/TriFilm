#include "classMovie.h"
#include <string>
#include <curl/curl.h>

using namespace std;

string xml("");

//=====================================================================================================================================================
//==============================================================Les constructeurs======================================================================
//=====================================================================================================================================================


movie::movie() : m_name("") , m_director("") , m_year(0) , m_IMDBrating(0.)
{
}//END MOVIE

movie::movie(string name, string director, int year , double IMDBrating): m_name(name) , m_director(director) , m_year(year) , m_IMDBrating(IMDBrating) 
{
}//END MOVIE

movie::movie(string IMDB_id)
{
	//On commence par placer le XML dans un string global nommé xml
     
	string urlAPI("http://www.deanclatworthy.com/imdb/?id=tt0454921");
	
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
			
		}  //END IF_CURL
	
	//Maintenant, on va parser le xml et mettre les données qui nous intéressent dans les attributs
	
		
}//END MOVIE


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

//=====================================================================================================================================================
//==============================================================Les accesseurs=========================================================================
//=====================================================================================================================================================

string movie::getName() const
{
 return m_name;
}

string getDirector() const
{
	return m_director;
}

int getYear() const
{
	return m_year;
}

double getIMDBrating() const
{
	return m_IMDBrating;
}


