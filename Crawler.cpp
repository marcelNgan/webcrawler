#include <tidypp/document.hpp>
#include <tidypp/attribute.hpp>
#include <tidypp/buffer.hpp>
#include <tidypp/node.hpp>
#include <curlplusplus/easy.hpp>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Linkstorer.hpp"

using namespace std;

vector<string> allURL;          // list of all URl that has been crawled

void crawling(string, int);

int main(int argc, char *argv[])
{
    string url = "";                // url of the site
    list<Linkstorer> storerLinks;   // 
    int level;                      // crawl level
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "Please enter the page you wish to crawl" << endl;
        cin >> url;
        cout << "How many levels do you want to crawl?" << endl;
        cin >> level;
        crawling (url, level);
        cout << "Do you wish to crawl another site? (Y|N)";
        cin >> cont;
    }
    ofstream crawlFile;
    crawlFile.open("crawl.txt", ios::app);
    crawlFile << "Total links crawled: " << allURL.size() << endl;
    for (vector<string>::iterator it = allURL.begin(); it != allURL.end(); it++)
            crawlFile << *it << endl;
    return 1;
}

void crawling (string url, int level)
{
    list<string> links;             // list of links from the site
    list<string> tempLinks;         // list of all the links from the crawled site
    list<string> mergeLinks;        // list of all the links from one crawled site
    links.push_back(url);
    for (int i = 0; i < level; i++)
    {
        while (!links.empty())
        {
            url = links.front();
            links.pop_front();
            if (find(allURL.begin(), allURL.end(), url) == allURL.end())
            {
                cout << "Crawling: " << url << endl;
                Linkstorer storer (url);
                allURL.push_back(url);
                storer.printLink();
                mergeLinks = storer.getLinks();
                tempLinks.splice(tempLinks.begin(), mergeLinks);
            }
        }
        links = tempLinks;
    }







       
}












