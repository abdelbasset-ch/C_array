test.out : main_f.o tools.o intarray.o astr.o string_array.o charray2d.o
	gcc main_f.o tools.o intarray.o astr.o string_array.o charray2d.o -o test.out -lm

main_f.o : main_f.c tools.h intarray.h astr.h charray2d.h
	gcc -c main_f.c 

tools.o : tools.c tools.h
	gcc -c tools.c
charray2d.o :	charray2d.c charray2d.h tools.h
	gcc -c charray2d.c

intarray.o : intarray.c intarray.h tools.h
	gcc -c intarray.c

astr.o : astr.c astr.h tools.h intarray.h
	gcc -c astr.c

string_array.o : string_array.c string_array.h tools.h astr.h intarray.h
	gcc -c string_array.c
