test: test.o pile_char.o
	gcc -o test test.o pile_char.o 

test.o: test.c pile_char.h
	gcc -c test.c

pile_char.o: pile_char.c pile_char.h
	gcc -c pile_char.c


