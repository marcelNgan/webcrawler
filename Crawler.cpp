#include <tidypp/document.hpp>
#include <tidypp/attribute.hpp>
#include <tidypp/buffer.hpp>
#include <tidypp/node.hpp>
#include <curlplusplus/easy.hpp>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include "Linkstorer.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string url = "";                // url of the site
    list<string> links;             // list of links from the site
    list<Linkstorer> storerLinks;   // 
    int level;                      // crawl level
    string parent;                  // url of the parent site
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "Please enter the page you wish to crawl" << endl;
        cin >> url;
        cout << "How many levels do you want to crawl?" << endl;
        cin >> level;
        parent = "NULL";
            cout << "Crawling: " << url << endl;
            Linkstorer storer (url, parent);        
            storer.printLink();
            parent = url;
            links = storer.getLinks();
        cout << "Do you wish to crawl another site? (Y|N)";
        cin >> cont;
    }
    return 1;
}













