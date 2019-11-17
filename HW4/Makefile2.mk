queueing: queueing.o
	g++ -o queueing queueing.o

queueing.o: queueing.cpp
	g++ -c queueing.cpp

clean:
	rm -f queueing.o queueing.exe
