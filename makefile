CC:=g++
exe:=plugin.so

plugin.so:plugin.o
	$(CC) -shared -o plugin.so plugin.o

plugin.o:plugin.c
	$(CC) -std=c++11 -Wall -Wno-literal-suffix -I`g++ -print-file-name=plugin`/include -fPIC -c -o plugin.o plugin.c


check:plugin.so
	$(CC) -fplugin=./plugin.so -c -x c++ /dev/null -o /dev/null
