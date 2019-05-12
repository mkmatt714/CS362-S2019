CFLAGS= -Wall -fpic -coverage -lm -std=c99

file: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

testme: file
	
	./testme &> quiztestresult.out
	gcov testme.c -b
	gcov testme.c -b >> quiztestresult.out
	cat testme.c.gcov >> quiztestresult.out



