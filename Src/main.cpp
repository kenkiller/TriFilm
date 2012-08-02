#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	
	string url = "http://www.deanclatworthy.com/imdb/?id=";
	string id = "";
	cin >> id;
	
	url+=id;
	
	cout << url << endl;
	
	CURL *curl;
	CURLcode res;
	
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		res = curl_easy_perform(curl);
		
		/* always cleanup */ 
		curl_easy_cleanup(curl);
	}
  return 0;
}