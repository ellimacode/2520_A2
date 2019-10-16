all: main.o text.o 
	gcc -Wall -ansi -pedantic main.o text.o -o a2
	
main.o: main.c
	gcc -Wall -ansi -pedantic -c main.c -o main.o
	
text.o: text.c
	gcc -Wall -ansi -pedantic -c text.c -o text.o
