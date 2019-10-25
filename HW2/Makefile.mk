Solitaire: Solitaire.o
	g++ -o Solitaire Solitaire.o

Solitaire.o: Solitaire.cpp
	g++ -c Solitaire.cpp

clean:
	rm -f Solitaire.o Solitaire.exe
