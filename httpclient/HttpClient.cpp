/*
 * HttpClient.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: yudylaw
 */

#include "HttpClient.h"

int HttpClient::httpGet(const string &url, string &result, double &costTime) {
    CURLcode code;
    CURL* conn = curl_easy_init();
    if (NULL == conn)
    {
        return CURLE_FAILED_INIT;
    }

    char errorBuffer[CURL_ERROR_SIZE];
    curl_easy_setopt(conn, CURLOPT_HTTPGET, 1);
    //设置header属性
    struct curl_slist *slist = NULL;
    slist = curl_slist_append(slist, "Connection: keep-alive");
    curl_easy_setopt(conn, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
    curl_easy_setopt(conn, CURLOPT_URL, url);
    //支持重定向
    curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(conn, CURLOPT_WRITEDATA, &result);
    curl_easy_setopt(conn, CURLOPT_NOSIGNAL, 1);//支持多线程、毫秒级超时，存在DNS解析超时不受控制问题
    curl_easy_setopt(conn, CURLOPT_CONNECTTIMEOUT_MS, conn_timeout);
    curl_easy_setopt(conn, CURLOPT_TIMEOUT_MS, rw_timeout);
    curl_easy_setopt(conn, CURLOPT_MAXCONNECTS, max_connection);
	code = curl_easy_perform(conn);
	curl_easy_cleanup(conn);
	curl_slist_free_all(slist);

	if(code != CURLE_OK) {
	  fprintf(stdout, "http get error_msg=[%s]\n", errorBuffer);
	  return code;
	}

    long int http_code = 0;
    curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_getinfo(conn, CURLINFO_TOTAL_TIME, &costTime);

	return http_code;
}

int HttpClient::httpPost(const string &url, const string &post, string &result, double &costTime) {
    CURLcode code;
    CURL* conn = curl_easy_init();
    if (NULL == conn)
    {
        return CURLE_FAILED_INIT;
    }

    char errorBuffer[CURL_ERROR_SIZE];
    //设置header属性
    struct curl_slist *slist = NULL;
    slist = curl_slist_append(slist, "Connection: keep-alive");
    curl_easy_setopt(conn, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(conn, CURLOPT_HTTPPOST, 1);
    curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
    curl_easy_setopt(conn, CURLOPT_URL, url);
    //支持重定向
    curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(conn, CURLOPT_WRITEDATA, &result);
    curl_easy_setopt(conn, CURLOPT_POSTFIELDS, &post);
    curl_easy_setopt(conn, CURLOPT_NOSIGNAL, 1);//支持多线程、毫秒级超时，存在DNS解析超时不受控制问题
    curl_easy_setopt(conn, CURLOPT_CONNECTTIMEOUT_MS, conn_timeout);
    curl_easy_setopt(conn, CURLOPT_TIMEOUT_MS, rw_timeout);
    curl_easy_setopt(conn, CURLOPT_MAXCONNECTS, max_connection);
	code = curl_easy_perform(conn);
	curl_easy_cleanup(conn);
	curl_slist_free_all(slist);

	if(code != CURLE_OK) {
	  fprintf(stdout, "http get error_msg=[%s]\n", errorBuffer);
	  return code;
	}

    long int http_code = 0;
    curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_getinfo(conn, CURLINFO_TOTAL_TIME, &costTime);

	return http_code;
}


