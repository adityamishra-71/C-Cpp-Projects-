#include <iostream>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include <gumbo.h>

// Callback to handle curl write
typedef size_t (*curl_write)(char*, size_t, size_t, std::string*);

// Function to perform HTTP request
std::string request(const std::string& word) {
    CURLcode res_code = CURLE_FAILED_INIT;
    CURL* curl = curl_easy_init();
    std::string result;
    std::string url = "https://www.merriam-webster.com/dictionary/" + word;

    curl_global_init(CURL_GLOBAL_ALL);

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, static_cast<curl_write>(
            [](char* contents, size_t size, size_t nmemb, std::string* data) -> size_t {
                size_t new_size = size * nmemb;
                if (data == nullptr) {
                    return 0;
                }
                data->append(contents, new_size);
                return new_size;
            }
        ));

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "simple scraper");

        res_code = curl_easy_perform(curl);

        if (res_code != CURLE_OK) {
            return "Error: " + std::string(curl_easy_strerror(res_code));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return result;
}

// Function to convert string to lowercase
std::string strtolower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to extract text from a Gumbo node
std::string extract_text(GumboNode* node) {
    if (node->type == GUMBO_NODE_TEXT) {
        return std::string(node->v.text.text);
    }
    else if (node->type == GUMBO_NODE_ELEMENT &&
             node->v.element.tag != GUMBO_TAG_SCRIPT &&
             node->v.element.tag != GUMBO_TAG_STYLE) {
        std::string contents = "";
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            std::string text = extract_text((GumboNode*)children->data[i]);
            contents.append(text);
        }
        return contents;
    }
    return "";
}

// Function to find definitions within the HTML structure
std::string find_definitions(GumboNode* node) {
    std::string res = "";
    if (node->type != GUMBO_NODE_ELEMENT) {
        return res;
    }

    GumboAttribute* attr = gumbo_get_attribute(&node->v.element.attributes, "class");
    if (attr && strstr(attr->value, "dtText") != NULL) {
        res += extract_text(node);
        res += "\n";
    }

    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        res
