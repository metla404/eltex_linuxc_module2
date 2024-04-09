all: main

clean:
	rm -rf main *.o

main: func.o main.o
	gcc -o main func.o main.o

func.o: func.c
	gcc -c -o func.o func.c

main.o: main.c
	gcc -c -o main.o main.c


	