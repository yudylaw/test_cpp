# 多线程安全的 httpclient

## 特性

### 支持毫秒级超时
### 支持 keep-alive
### 仅支持 POST、GET 方法

## 用例

```c++
#include <iostream>
#include <string>
#include "HttpClient.h"

using namespace std;
using namespace inke_base::http_client;

int main() {

    HttpClient *httpClient = new HttpClient(100, 1000, 500);
    HttpResponse resp;//返回结果
    string url = "127.0.0.1:9070/feeds_tab/recommends?uid=33425736&start=0&limit=10";
    httpClient->httpGet(url, resp);
    if (retCode != 0) {
        cout<<"retCode="<<retCode<<", http_code="<<resp.http_code<<", error_msg="<<resp.error_msg<<", costTime="<<resp.cost_time<<endl;
    } else {
        cout<<"retCode="<<retCode<<", http_code="<<resp.http_code<<", result="<<resp.result<<", costTime="<<resp.cost_time<<endl;
    }
    
    delete httpClient;
    
    return 0;
}
```

