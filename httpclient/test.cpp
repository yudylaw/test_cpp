/*
 * test.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: yudylaw
 */

#include <iostream>
#include <string>
#include <curl/curl.h>

#include "HttpClient.h"

using namespace std;
using std::string;

//  libcurl variables for error strings and returned data

static char errorBuffer[CURL_ERROR_SIZE];
static std::string buffer;

//
//  libcurl write callback function
//

//writerData is a pointer->[buffer]
static int writer(char *data, size_t size, size_t nmemb, std::string *writerData)
{
  if(writerData == NULL)
    return 0;

  writerData->append(data, size*nmemb);

  return size * nmemb;
}

//
//  libcurl connection initialization
//

bool init(CURL *&conn, char *url)
{
  CURLcode code;

  conn = curl_easy_init();

  if(conn == NULL) {
    fprintf(stderr, "Failed to create CURL connection\n");
    exit(EXIT_FAILURE);
  }

  code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set error buffer [%d]\n", code);
    return false;
  }

  code = curl_easy_setopt(conn, CURLOPT_URL, url);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set URL [%s]\n", errorBuffer);
    return false;
  }

  //支持重定向
  code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set redirect option [%s]\n", errorBuffer);
    return false;
  }

  code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set writer [%s]\n", errorBuffer);
    return false;
  }

  code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set write data [%s]\n", errorBuffer);
    return false;
  }

  return true;
}

//
//  libcurl connection initialization
//

bool initPost(CURL *&conn, char *url)
{
  CURLcode code;

  conn = curl_easy_init();

  if(conn == NULL) {
    fprintf(stderr, "Failed to create CURL connection\n");
    exit(EXIT_FAILURE);
  }

  code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set error buffer [%d]\n", code);
    return false;
  }

  code = curl_easy_setopt(conn, CURLOPT_URL, url);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set URL [%s]\n", errorBuffer);
    return false;
  }

  //支持重定向
  code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set redirect option [%s]\n", errorBuffer);
    return false;
  }

  /* Now specify the POST data */
  curl_easy_setopt(conn, CURLOPT_POSTFIELDS, "{\"uid\":\"110002\",\"feed_id\":\"300017\",\"weight\":\"7\",\"code\":\"100\"}");

  code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set writer [%s]\n", errorBuffer);
    return false;
  }

  code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
  if(code != CURLE_OK) {
    fprintf(stderr, "Failed to set write data [%s]\n", errorBuffer);
    return false;
  }

  return true;
}

void testGet() {
	  CURL *conn = NULL;
	  CURLcode code;

	  curl_global_init(CURL_GLOBAL_DEFAULT);

	  // Initialize CURL connection

	  char url[] = "http://www.baidu.com";

	  if(!init(conn, url)) {
	    fprintf(stderr, "Connection initializion failed\n");
	    exit(EXIT_FAILURE);
	  }

	  cout<<"init conn success"<<endl;

	  // Retrieve content for the URL

	  code = curl_easy_perform(conn);
	  curl_easy_cleanup(conn);

	  if(code != CURLE_OK) {
		  fprintf(stderr, "error_msg=[%s]\n", errorBuffer);
	  } else {
		  fprintf(stdout, "result=[%s]\n", buffer.c_str());
	  }
	  //curl_global_init
	  curl_global_cleanup();
}

void testPost() {
	  CURL *conn = NULL;
	  CURLcode code;

	  curl_global_init(CURL_GLOBAL_DEFAULT);

	  // Initialize CURL connection

	  char url[] = "http://127.0.0.1:9070/feeds_tab/more";

	  if(!initPost(conn, url)) {
	    fprintf(stderr, "Connection initializion failed\n");
	    exit(EXIT_FAILURE);
	  }

	  cout<<"init conn success"<<endl;

	  // Retrieve content for the URL

	  code = curl_easy_perform(conn);
	  curl_easy_cleanup(conn);

	  if(code != CURLE_OK) {
		  fprintf(stderr, "error_msg=[%s]\n", errorBuffer);
	  } else {
		  fprintf(stdout, "result=[%s]\n", buffer.c_str());
	  }
	  //curl_global_init
	  curl_global_cleanup();
}

int main() {
	cout<<"hello curl"<<endl;
//	testGet();
//	testPost();

	HttpClient *httpClient = new HttpClient(100, 1000, 500);

	string result;
	double costTime = 0;
//	string url = "127.0.0.1:9070/feeds_tab/recommends?uid=33425736&start=0&limit=10";
	string url = "http://127.0.0.1:9070/feeds_tab/more";
	string post = "{\"uid\":\"110002\",\"feed_id\":\"300017\",\"weight\":\"7\",\"code\":\"100\"}";
//	httpClient->httpGet(url, result, costTime);
	httpClient->httpPost(url, post, result, costTime);
	cout<<"result="<<result<<", costTime="<<costTime<<endl;
	cout<<"end"<<endl;
	delete httpClient;
	return 0;
}
