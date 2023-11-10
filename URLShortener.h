#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class URLShortener
{
public:
    URLShortener() : counter(100000000000) {} // constructor list initialization of counter

    string shortenURL(const string &longURL)
    {
        if (urlToID.find(longURL) != urlToID.end())
        { // if already available return encoded value
            return encodeBase62(urlToID[longURL]);
        }
        else
        { // else encode store and then return value
            string shortURL = encodeBase62(counter);
            while (shortURL.length() != 7)
            {
                shortURL = '0' + shortURL;
            }
            urlToID[longURL] = counter;
            idToURL[counter] = longURL;
            counter++; // increment counter by 1
            return "http://tiny.url/" + shortURL;
        }
    }
    

private:
    long long int counter;
    unordered_map<string, int> urlToID;
    unordered_map<int, string> idToURL;

    string base62 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //

    string encodeBase62(int num)
    {
        if (num == 0)
        {
            return string(1, base62[0]);
        }

        string shortURL;
        while (num > 0)
        {
            shortURL = base62[num % 62] + shortURL;
            num /= 62;
        }
        return shortURL;
    }

    
};