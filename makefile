test.exe : main_f.o operations.o intarray.o astr.o
	gcc main_f.o operations.o intarray.o astr.o -o test.exe

main_f.o : main_f.c operations.h intarray.h astr.h
	gcc -c main_f.c

operations.o : operations.c operations.h
	gcc -c operations.c

intarray.o : intarray.c intarray.h operations.h
	gcc -c intarray.c

astr.o : astr.c astr.h operations.h intarray.h
	gcc -c astr.c
	
	