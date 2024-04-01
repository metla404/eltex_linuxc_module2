all: main

clean:
	rm -rf main *.o

main: func_ip.o main.o
	gcc -o main func_ip.o main.o

func_ip.o: func_ip.c
	gcc -c -o func_ip.o func_ip.c

main.o: main.c
	gcc -c -o main.o main.c


	