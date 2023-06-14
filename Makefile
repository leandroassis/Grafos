SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++11 -Wall

all: grafo
	@echo "Compilação finalizada."

%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

grafo: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) grafo