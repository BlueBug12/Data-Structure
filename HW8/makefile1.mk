all\ pair: all\ pair.o
	g++ -o all\ pair all\ pair.o

all\ pair.o: all\ pair.cpp
	g++ -c all\ pair.cpp

clean:
	rm -f all\ pair.o all\ pair.exe
