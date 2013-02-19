#include <tidypp/document.hpp>
#include <tidypp/attribute.hpp>
#include <tidypp/buffer.hpp>
#include <tidypp/node.hpp>
#include <curlplusplus/easy.hpp>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include "simple.cpp"

list<string> extractor(string url);
void linksprinter (list<string> links, string url);

int main(int argc, char *argv[])
{
    string url = "";  //url of the site
    list<string> links;  // list of links from the site
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "Please enter the page you wish to crawl" << endl;
        cin >> url;
        cout << "Crawling: " << url << endl;
        links = extractor(url);
        linksprinter(links, url);
        cout << "Do you wish to crawl another site? (Y|N)";
        cin >> cont;
    }
    return 1;
}

void linksprinter (list<string> links, string url)
{
    // if the list is empty...
    if (!links.size())
    {
        cerr << "No links found!" << endl;
    } else
    {
        ofstream crawlFile;
        crawlFile.open("crawl.txt", ios::app);
        cout << "Written to crawl.txt" << endl; 
        crawlFile << "There are " << links.size() << " links for " << url << ":"  << endl;
 
        // iterate the links list
        for (list<string>::iterator it = links.begin(); it != links.end(); it++)
            crawlFile << *it << endl;
        crawlFile << endl ;
        crawlFile.close();
    }
}














