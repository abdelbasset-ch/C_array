test.out : main_f.o tools.o intarray.o astr.o
	gcc main_f.o tools.o intarray.o astr.o -o test.out

main_f.o : main_f.c tools.h intarray.h astr.h
	gcc -c main_f.c

tools.o : tools.c tools.h
	gcc -c tools.c

intarray.o : intarray.c intarray.h tools.h
	gcc -c intarray.c

astr.o : astr.c astr.h tools.h intarray.h
	gcc -c astr.c
	
	
