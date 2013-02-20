Crawler: Crawler.o Simple.o
	libtool --mode=link g++ -g -O -o Crawler Crawler.o /usr/local/lib/libcurlplusplus-1.2.la /usr/local/lib/libtidypp-1.0.la -ltidy -lm

Crawler.o: Crawler.cpp
	g++ -c -o Crawler.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Crawler.cpp

Linkstorer.o: Linkstorer.cpp
	g++ -c -o Crawler.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Linkstorer.cpp

Simple.o: Simple.cpp
	g++ -c -o Simple.o -I/usr/local/include/curlplusplus-1.2/ -I/usr/local/include/tidypp-1.0/ Simple.cpp

clean:
	rm -f *.o
