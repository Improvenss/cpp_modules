#include <iostream>
#include <curl/curl.h>

using namespace std;

static string readBuffer;

static size_t writer(char *data, size_t size, size_t nmemb, string *writerData) {
    if (writerData == NULL) {
        return 0;
    }

    writerData->append(data, size * nmemb);

    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    string url = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest?symbol=BTC&convert=USD&CMC_PRO_API_KEY=65bc3511-b1df-432d-8634-43afbf7b90ff";
    // curl_global_init(CURL_GLOBAL_DEFAULT);
	curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    cout << readBuffer << endl;
    return 0;
}
