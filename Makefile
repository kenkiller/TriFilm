all: main.o 
	g++ -o main main.o

main.o: src/main.cpp
	g++ -o main.o -c src/main.cpp -W -Wall -ansi -pedantic
