#include "reverse_geocode.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// This function receives the data coming from the API
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

Location reverseGeocode(double latitude, double longitude)
{
    Location location;

    CURL* curl;
    CURLcode res;

    string response;

    curl = curl_easy_init();

    if (curl)
    {
        string url =
            "https://nominatim.openstreetmap.org/reverse"
            "?format=json"
            "&lat=" + to_string(latitude) +
            "&lon=" + to_string(longitude);

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Receive API response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Identify our application
        curl_easy_setopt(
            curl,
            CURLOPT_USERAGENT,
            "CleanLink/1.0"
        );

        res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            try
            {
                json data = json::parse(response);

                if (data.contains("address"))
                {
                    json address = data["address"];

                    if (address.contains("city"))
                        location.cityName = address["city"];

                    if (address.contains("neighbourhood"))
                        location.localityName = address["neighbourhood"];
                    else if (address.contains("suburb"))
                        location.localityName = address["suburb"];
                    else if (address.contains("town"))
                        location.localityName = address["town"];
                }
            }
            catch (const exception& e)
            {
                cerr << "JSON parsing error: "
                     << e.what() << endl;
            }
        }
        else
        {
            cerr << "API request failed: "
                 << curl_easy_strerror(res)
                 << endl;
        }

        curl_easy_cleanup(curl);
    }

    return location;
}