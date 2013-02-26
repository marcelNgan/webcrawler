#include "Linkstorer.hpp"
//#include "Simple.cpp"
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
        crawlFile << "URL: " << url << endl;
        if (parentURL == "NULL")
            crawlFile << "Parent: no parent" << endl;
        else
            crawlFile << "Parent: " << parentURL << endl;
        
        crawlFile << "There are " << links.size() << " links:"  << endl;
 
        // iterate the links list
        for (list<string>::iterator it = links.begin(); it != links.end(); it++)
            crawlFile << *it << endl;
        crawlFile << endl ;
        crawlFile.close();
    }
}

list<string> Linkstorer::getLinks()
{
    return links;
}

Linkstorer::Linkstorer(string s, string p)
{
    parentURL = p;
    url = s;
    links = extractor(url);
}

Linkstorer::~Linkstorer()
{
}

