CPPFLAGS = -Wall -std=c++11 -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

all: grafo

src/Aresta.o: src/Aresta.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/Grafo.o: src/Grafo.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/Vertice.o: src/Vertice.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/main.o: src/main.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

grafo: src/Aresta.o src/Grafo.o src/Vertice.o src/main.o
	g++ -o $@ src/*.o

clean:
	rm -rf src/*.o ./grafo
