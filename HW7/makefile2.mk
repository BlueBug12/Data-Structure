bridge: bridge.o
	g++ -o bridge bridge.o

bridge.o: bridge.cpp
	g++ -c bridge.cpp

clean:
	rm -f bridge.o bridge.exe
