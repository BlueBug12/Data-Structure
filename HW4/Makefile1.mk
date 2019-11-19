solitaire: solitaire.o
	g++ -o solitaire solitaire.o

solitaire.o: solitaire.cpp
	g++ -c solitaire.cpp

clean:
	rm -f solitaire.o solitaire.exe
