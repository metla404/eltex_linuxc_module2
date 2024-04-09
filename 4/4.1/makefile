all: main

clean:
	rm -rf main *.o

main: telbookfunc.o main.o
	gcc -o main telbookfunc.o main.o

telbookfunc.o: telbookfunc.c
	gcc -c -o telbookfunc.o telbookfunc.c

main.o: main.c
	gcc -c -o main.o main.c


	