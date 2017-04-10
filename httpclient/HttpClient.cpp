/*
 * HttpClient.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: yudylaw
 */

#include "HttpClient.h"

namespace inke_base {
namespace http_client {

int HttpClient::httpGet(const std::string &url, HttpResponse &response) {
    CURLcode code;
    CURL* conn = curl_easy_init();
    if (NULL == conn)
    {
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(conn, CURLOPT_HTTPGET, 1);
    //设置header属性
    struct curl_slist *slist = NULL;
    slist = curl_slist_append(slist, "Connection: keep-alive");
    curl_easy_setopt(conn, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, response.error_msg);
    curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    //支持重定向
    curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(conn, CURLOPT_WRITEDATA, (void *)&response.result);
    curl_easy_setopt(conn, CURLOPT_NOSIGNAL, 1);//支持多线程、毫秒级超时，存在DNS解析超时不受控制问题
    curl_easy_setopt(conn, CURLOPT_CONNECTTIMEOUT_MS, conn_timeout);
    curl_easy_setopt(conn, CURLOPT_TIMEOUT_MS, rw_timeout);
    curl_easy_setopt(conn, CURLOPT_MAXCONNECTS, max_connection);
    code = curl_easy_perform(conn);

    if(code != CURLE_OK) {
        curl_easy_cleanup(conn);
        curl_slist_free_all(slist);
        fprintf(stdout, "http get error_msg=[%s]\n", response.error_msg);
        return code;
    }

    curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &response.http_code);
    curl_easy_getinfo(conn, CURLINFO_TOTAL_TIME, &response.cost_time);

    curl_easy_cleanup(conn);
    curl_slist_free_all(slist);

    return 0;
}

int HttpClient::httpPost(const std::string &url, const std::string &post, HttpResponse &response) {
    CURLcode code;
    CURL* conn = curl_easy_init();
    if (NULL == conn)
    {
        return CURLE_FAILED_INIT;
    }

    //设置header属性
    struct curl_slist *slist = NULL;
    slist = curl_slist_append(slist, "Connection: keep-alive");
    curl_easy_setopt(conn, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(conn, CURLOPT_HTTPPOST, 1);
    curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, response.error_msg);
    curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    //支持重定向
    curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(conn, CURLOPT_WRITEDATA, (void *)&response.result);
    curl_easy_setopt(conn, CURLOPT_POSTFIELDS, post.c_str());
    curl_easy_setopt(conn, CURLOPT_NOSIGNAL, 1);//支持多线程、毫秒级超时，存在DNS解析超时不受控制问题
    curl_easy_setopt(conn, CURLOPT_CONNECTTIMEOUT_MS, conn_timeout);
    curl_easy_setopt(conn, CURLOPT_TIMEOUT_MS, rw_timeout);
    curl_easy_setopt(conn, CURLOPT_MAXCONNECTS, max_connection);
    code = curl_easy_perform(conn);

    if(code != CURLE_OK) {
        curl_easy_cleanup(conn);
        curl_slist_free_all(slist);
        fprintf(stdout, "http post error_msg=[%s]\n", response.error_msg);
        return code;
    }

    curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &response.http_code);
    curl_easy_getinfo(conn, CURLINFO_TOTAL_TIME, &response.cost_time);

    curl_easy_cleanup(conn);
    curl_slist_free_all(slist);

    return 0;
}

}
}

