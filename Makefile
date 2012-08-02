all: main.o 
	g++ -lcurl -o main main.o
	make clean
	
main.o: Src/main.cpp
	g++ -lcurl -o main.o -c -L/opt/local/include/curl Src/main.cpp -W -Wall -ansi -pedantic
	

clean:
	rm *.o