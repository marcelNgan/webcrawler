#ifndef LINKSTORER_HPP
#define LINKSTORER_HPP
#include <string>
#include <list>

using namespace std;

class Linkstorer
{
    string url;
    list<string> links;
public:
    void printLink ();
    list<string> getLinks();
    Linkstorer(string url);
    ~Linkstorer();
};
#endif
