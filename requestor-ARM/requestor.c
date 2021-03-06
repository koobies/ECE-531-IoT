#include <stdio.h>
#include <curl/curl.h>

#define OK          0
#define INIT_ERR    1
#define REQ_ERR     2

#define URL         "http://localhost:8000"
#define HOST_IP     "http://10.0.2.15:8000"

int main(void) {
  
    printf("helllo world");
    CURL    *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, HOST_IP);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            return REQ_ERR;
        }
        curl_easy_cleanup(curl);
    }
    else {
        return INIT_ERR;
    }

    return OK;

}
