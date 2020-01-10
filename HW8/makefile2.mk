Single\ source: Single\ source.o
	g++ -o Single\ source Single\ source.o

Single\ source.o: Single\ source.cpp
	g++ -c Single\ source.cpp

clean:
	rm -f Single\ source.o Single\ source.exe
