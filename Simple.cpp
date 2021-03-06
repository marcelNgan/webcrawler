#include <tidypp/document.hpp>
#include <tidypp/attribute.hpp>
#include <tidypp/buffer.hpp>
#include <tidypp/node.hpp>
#include <curlplusplus/easy.hpp>
#include <string>
#include <list>
#include <iostream>

using namespace std;
using namespace tidypp;
using namespace curlpp;

void dumphrefs(node &node, list<string> *dst);
static int writer(char *data, size_t size, size_t nmemb, buffer *dst);
 
list<string> extractor(string url)
{
    char *urlCharArray = new char[url.size()+1];    
    list<string> links;  // list of links from the site
	
    //used for downloading the page with curl and parsing the page with tidy
    document doc; // tidy html document
    buffer html; // will store our html code
    buffer errbuf; // will store the warnings and errors encountered by html tidy
    node root; // will store the root node of the document
	
    urlCharArray[url.size()] = 0;
    memcpy(urlCharArray,url.c_str(), url.size());
	
    // taken from the curlplusplus example
    try
    {
        easy curl; // handle to the curl easy interface
        long http_status; // will store the result of the curl request
 
        cout << "Obtaining page..." << endl;
        curl.setopt(CURLOPT_URL, urlCharArray); // assign URL
        curl.setopt(CURLOPT_FOLLOWLOCATION, 1);
        curl.setopt(CURLOPT_WRITEFUNCTION, writer); // assign write callback
        curl.setopt(CURLOPT_WRITEDATA, &html); // assign write buffer (our tidypp buffer)
        curl.perform(); // perform curl
        curl.getinfo(CURLINFO_RESPONSE_CODE, &http_status); // get result http status
 
        if (http_status != 200)
        {
            cerr << "Expecting HTTP 200 OK, got " << http_status << endl;
            links.clear();
            return links;
        }
    }
    catch (const curlpp::exception &e) // catch exceptions and print the error on screen
    {
        cerr << e.what() << endl;
        links.clear();
        return links;
    }
 
    // parser
    try
    {
        doc.seterrorbuffer(errbuf); // assign error buffer
        doc.optsetbool(TidyForceOutput, true); // output document even if errors were found
        doc.optsetint(TidyWrapLen, 4096); // wrap margin
        doc.parsebuffer(html); // parse the html in our buffer
        doc.cleanandrepair(); // cleans up and repairs errors
    }
    catch (const tidypp::exception &e) // catch exceptions and print the error on screen
    {
        cerr << e.what() << endl;
        links.clear();
        return links;
    }
 
    root = doc.root(); // get root node
    dumphrefs(root, &links); // dump links to our list
}
 
/**
* Dumps all the links in the document into an std::list<std::string>
* by walking the document tree of a tidy html document.
*
* @param[in] node the root node of the document.
* @param[out] dst the destination array of strings.
*/
void dumphrefs(node &node, list<string> *dst)
{
    // iterate all children nodes
    for (tidypp::node child = node.child(); child.valid(); child = child.next())
    {
        tagid id = node.id(); // obtain tag id to check if it's a link
 
        // if the node is an <a> tag...
        if (id == TidyTag_A)
        {
            attribute href = node.attrgetbyid(TidyAttr_HREF); // get the href attribute
            ctmbstr hrefval = href.value(); // the string of the actual link
 
            if (hrefval) // if the link is not empty...
            {
                string link(hrefval); // convert to std::string
                dst->push_back(link); // append link to the list
            }
        }
 
        // walk all the children of each children recursively
        dumphrefs(child, dst);
    }
}
 
/** From curlplusplus example
* Write callback called by cURL every time it obtains some data.
*
* @param[in] data the data that has just been obtained.
* @param size the size of each data block.
* @param nmemb the number of data blocks. multiply this by size to obtain the
*              total size of data.
* @param[out] dst the destination buffer that was assigned to CURLOPT_WRITEDATA
*
* [USER=16172]Return[/USER] the amount of bytes that were dispatched to the destination buffer.
*/
static int writer(char *data, size_t size, size_t nmemb, buffer *dst)
{
    size_t len;
 
    if (!data)
        return 0;
 
    len = size * nmemb;
    dst->append(data, len); // append recieved data to the buffer
 
    return len; // must return the amount of written bytes
}
