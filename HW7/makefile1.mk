bipartite: bipartite.o
	g++ -o bipartite bipartite.o

bipartite.o: bipartite.cpp
	g++ -c bipartite.cpp

clean:
	rm -f bipartite.o bipartite.exe
