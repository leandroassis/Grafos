SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++11 -Wall

all: grafo clean
	@echo "Compilando..."

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

grafo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) grafo