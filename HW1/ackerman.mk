ackerman: ackerman.o
	g++ -o ackerman ackerman.o

ackerman.o: ackerman.cpp
	g++ -c ackerman.cpp

clean:
	rm -f ackerman.o ackerman.exe

