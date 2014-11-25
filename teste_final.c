#include <stdio.h>

int teste_final(int player[],int jogador)
{
	int soma=0;
	int i;
	for(i=0;i<=6;i++)
		soma+=player[i];
	if(soma == 693)
	{
		printf("Fim de jogo, o jogador %d venceu!\n",jogador);
		return 1;
	}
	return 0;
}
