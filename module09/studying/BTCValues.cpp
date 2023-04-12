#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <curl/curl.h>
// #include <jsoncpp/json/json.h>
#include <json/json.h>
// #include <json/ ... >
// #include "/opt/homebrew/Cellar/jsoncpp/1.9.5/include/json/json.h"

using namespace std;

//  c++ BTCValues.cpp -lcurl && ./a.out

#define MY_API_KEY "65bc3511-b1df-432d-8634-43afbf7b90ff"

const string API_KEY = MY_API_KEY;
const string API_URL = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest?symbol=BTC&convert=USD&CMC_PRO_API_KEY=" + API_KEY;
const int REFRESH_INTERVAL = 60; // in seconds
const string CSV_FILE = "bitcoin_prices.csv";

int main() {
    CURL *curl;
    CURLcode res;
    string readBuffer;
    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader *reader = builder.newCharReader();

    ofstream csvFile(CSV_FILE);
    csvFile << "Timestamp,Price" << endl;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    while (true) {
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, API_URL.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            if (res == CURLE_OK) {
                string errors;
                bool parsedSuccess = reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.size(), &root, &errors);
                if (parsedSuccess) {
                    double price = root["data"]["BTC"]["quote"]["USD"]["price"].asDouble();
                    long timestamp = root["data"]["BTC"]["quote"]["USD"]["last_updated"].asInt64();
                    csvFile << timestamp << "," << price << endl;
                    cout << "Price updated: " << price << endl;
                } else {
                    cerr << "Error parsing JSON: " << errors << endl;
                }
            } else {
                cerr << "Error fetching Bitcoin price data: " << curl_easy_strerror(res) << endl;
            }
        }
        this_thread::sleep_for(chrono::seconds(REFRESH_INTERVAL));
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    csvFile.close();
    return 0;
}

static size_t writer(char *data, size_t size, size_t nmemb, string *writerData) {
    if (writerData == NULL) {
        return 0;
    }

    writerData->append(data, size * nmemb);

    return size * nmemb;
}
