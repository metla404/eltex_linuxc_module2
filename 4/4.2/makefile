all: main

clean:
	rm -rf main *.o

main: queuefunc.o main.o
	gcc -o main queuefunc.o main.o

queuefunc.o: queuefunc.c
	gcc -c -o queuefunc.o queuefunc.c

main.o: main.c
	gcc -c -o main.o main.c


	