
all: main.o 
	g++ -o main main.o
	make clean
	
main.o: Src/main.cpp
	g++ -o main.o -c Src/main.cpp -W -Wall -ansi -pedantic
	

clean:
	rm *.o