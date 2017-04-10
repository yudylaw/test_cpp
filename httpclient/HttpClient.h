/*
 * HttpClient.h
 *
 *  Created on: 2017年4月9日
 *      Author: yudylaw
 */

#ifndef HTTPCLIENT_HTTPCLIENT_H_
#define HTTPCLIENT_HTTPCLIENT_H_

#include <string>
#include <iostream>
#include "curl/curl.h"

namespace inke_base {
namespace http_client {

struct HttpResponse {
    int http_code;
    std::string error_msg;
    std::string result;
    double cost_time;
};

class HttpClient {
public:
	HttpClient(int max_connection, int conn_timeout, int rw_timeout) {
		this->max_connection = max_connection;
		this->conn_timeout = conn_timeout;
		this->rw_timeout = rw_timeout;
		curl_global_init(CURL_GLOBAL_ALL);
	}
	~HttpClient() {
		curl_global_cleanup();
	}
	int httpGet(const std::string &url, HttpResponse &response);
	int httpPost(const std::string &url, const std::string &post, HttpResponse &response);

	/**
	 * libcurl write callback function
	 * writerData is a pointer->[buffer]
	 */
	static int writer(char *data, size_t size, size_t nmemb, std::string *writerData)
	{
	  if(data == NULL || writerData == NULL) {
		  return 0;
	  }
	  writerData->append(data, size * nmemb);
	  return size * nmemb;
	}
private:
	int max_connection;
	int conn_timeout;
	int rw_timeout;
};

}
}

#endif /* HTTPCLIENT_HTTPCLIENT_H_ */
