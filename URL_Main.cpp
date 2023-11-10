#include <iostream>
#include "URLShortener.h"
using namespace std;
int main()
{
    URLShortener shortener;
    string longURL = "www.abc.com";
    string shortURL = shortener.shortenURL(longURL);
    cout << "Short URL: " << shortURL << endl;
    string originalURL = shortener.expandURL(shortURL);
    cout << "Original URL: " << originalURL << endl;
    return 0;
}