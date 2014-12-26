# Dr. Beco Modified - 2014-09-05
.PHONY : exec_auto clean copy debug instrucoes

exec_auto: domino001.x 
	./domino001.x  

domino001.x : domino001.c mostra_mao.c monta_pm.c teste_toque.c teste_final.c teste_peca.c contagem_maos.c random.c
	gcc -D DEBUG=0 -Wall -Wextra -O0 -g domino001.c mostra_mao.c monta_pm.c teste_toque.c teste_final.c teste_peca.c contagem_maos.c random.c -o domino001.x  2>&1 | tee errors.err

debug : 
	gcc -D DEBUG=$(d) -Wall -Wextra -O0 -g domino001.c mostra_mao.c monta_pm.c teste_toque.c teste_final.c teste_peca.c contagem_maos.c random.c -o domino001.x  2>&1 | tee errors.err

instrucoes :
	@echo Para ativar o modo debug digite: make debug d=1 
	@echo Caso contrario: make debug d=0
	@echo Digite \"make\" para rodar o executavel
	@echo Digite \"make domino001.x\" para compilar o programa levando em conta os conceitos de regra e dependencia do make.

clean :
	rm *.x errors.err

copy :
	cp -r *.c minhas_funcoes.h LICENSE README.md domino001.x doxdomino001.cfg ./doc makefile ../../trabalhos/domino001
