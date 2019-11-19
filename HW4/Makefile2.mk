costco: costco.o
	g++ -o costco costco.o

costco.o: costco.cpp
	g++ -c costco.cpp

clean:
	rm -f costco.o costco.exe
