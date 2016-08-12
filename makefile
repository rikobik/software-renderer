CC=g++
FLAGS=-std=c++14

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

2d_draw:
	$(CC) 2d_draw.cpp -o draw.o -c $(FLAGS)

renderer: 2d_draw
	$(CC) renderer.cpp 2d_draw.cpp -c $(LIBS) $(FLAGS)

all: renderer
	$(CC) main.cpp -o main.o renderer.cpp 2d_draw.cpp $(FLAGS) $(LIBS)

clean:
	rm -f *.o
	echo "Cleaned"
