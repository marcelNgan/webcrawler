#include <tidypp/document.hpp>
#include <tidypp/attribute.hpp>
#include <tidypp/buffer.hpp>
#include <tidypp/node.hpp>
#include <curlplusplus/easy.hpp>
#include <string>
#include <list>
#include <iostream>
#include <string>
#include "simple.cpp"

list<string> extractor(string url);
void linksprinter (list<string> links);

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
        linksprinter(links);
        cout << "Do you wish to crawl another site? (Y|N)";
        cin >> cont;
    }
    return 1;
}

void linksprinter (list<string> links)
{
    // if the list is empty...
    if (!links.size())
    {
        cerr << "No links found!" << endl;
        return;
    }
 
    cout << "There are " << links.size() << " links:" << endl;
 
    // iterate the links list
    for (list<string>::iterator it = links.begin(); it != links.end(); it++)
        cout << *it << endl;
}
