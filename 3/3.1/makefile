all: main

clean:
	rm -rf main *.o

main: func_rwx.o main.o
	gcc -o main func_rwx.o main.o

func_rwx.o: func_rwx.c
	gcc -c -o func_rwx.o func_rwx.c

main.o: main.c
	gcc -c -o main.o main.c


	