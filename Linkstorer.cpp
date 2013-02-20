#include "Linkstorer.hpp"
#include "Simple.cpp"
#include <iostream>
#include <fstream>

using namespace std;
list<string> extractor(string url);

void Linkstorer::printLink()
{
    // assert(!links.size())
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

Linkstorer:Linkstorer(string s)
{
    url = s;
    links = extractor(url);
}

Linkstorer:~Linkstorer()
{
}

