Crawler: Crawler.o Simple.o Linkstorer.o
	g++ -o Crawler Crawler.o Simple.o Linkstorer.o -ltidy -L/usr/local/lib -lcurlplusplus-1.2 -ltidypp-1.0

Crawler.o: Crawler.cpp
	g++ -c -o Crawler.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Crawler.cpp

Linkstorer.o: Linkstorer.cpp
	g++ -c -o Linkstorer.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Linkstorer.cpp

Simple.o: Simple.cpp
	g++ -c -o Simple.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Simple.cpp

clean:
	rm -f *.o
