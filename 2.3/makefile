all: calcnew

clean:
	rm -rf calcnew *.o

calcnew: calcaddfunc.o calcdivfunc.o calcmultfunc.o calcsubfunc.o calcnewfunc.o calcmenufunc.o calcnew.o
	gcc -o calcnew calcaddfunc.o calcdivfunc.o calcmultfunc.o calcsubfunc.o calcnewfunc.o calcmenufunc.o calcnew.o

calcaddfunc.o: calcaddfunc.c
	gcc -c -o calcaddfunc.o calcaddfunc.c

calcdivfunc.o: calcdivfunc.c
	gcc -c -o calcdivfunc.o calcdivfunc.c

calcmultfunc.o: calcmultfunc.c
	gcc -c -o calcmultfunc.o calcmultfunc.c

calcsubfunc.o: calcsubfunc.c
	gcc -c -o calcsubfunc.o calcsubfunc.c

calcnewfunc.o: calcnewfunc.c
	gcc -c -o calcnewfunc.o calcnewfunc.c

calcmenufunc.o: calcmenufunc.c
	gcc -c -o calcmenufunc.o calcmenufunc.c

calcnew.o: calcnew.c
	gcc -c -o calcnew.o calcnew.c


	