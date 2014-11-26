# Dr. Beco Modified - 2014-09-05
.PHONY : exec_auto clean copy

exec_auto: domino001.x 
	./domino001.x  

domino001.x : domino001.c mostra_mao.c monta_pm.c teste_toque.c teste_final.c
	gcc -Wall -Wextra -O0 -g domino001.c mostra_mao.c monta_pm.c teste_toque.c teste_final.c -o domino001.x  2>&1 | tee errors_domino001.txt


clean :
	rm *.x errors*.txt

copy :
	cp domino001.c domino001.x makefile ../../trabalhos/domino001
