# Dr. Beco Modified - 2014-09-05
.PHONY : exec_auto clean copy

exec_auto: dominador.x 
	./dominador.x  

dominador.x : dominador.c
	gcc -Wall -Wextra -O0 -g dominador.c -o dominador.x  2>&1 | tee errors_dominador.txt

clean :
	rm *.x errors*.txt

copy :
	cp dominador.c dominador.x makefile ../../trabalhos/domino001
