powerset: powerset.o
	g++ -o powerset powerset.o

powerset.o: powerset.cpp
	g++ -c powerset.cpp

clean:
	rm -f powerset.o powerset.exe
