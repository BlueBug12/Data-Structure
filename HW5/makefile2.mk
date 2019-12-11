height_union: height_union.o
	g++ -o height_union height_union.o

height_union.o: height_union.cpp
	g++ -c height_union.cpp

clean:
	rm -f height_union.o height_union.exe
