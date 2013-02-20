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
    string url = "";  //url of the site
    list<string> links;  // list of links from the site
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "Please enter the page you wish to crawl" << endl;
        cin >> url;
        cout << "Crawling: " << url << endl;
        Linkstorer storer (url);        
        storer.printLink();
        cout << "Do you wish to crawl another site? (Y|N)";
        cin >> cont;
    }
    return 1;
}














