#include <stdio.h>

int teste_peca(int peca,int rodada,int p_jog,int pm[],int mao[],int jogador)
{
	int pp_1,pp_2; //pontas de peca
	int t_peca=0;
	int j; //contador

	//teste de pertencimento da peca a mao
	for(j=0;j<=6;j++)
		if(peca == mao[j]) t_peca=1;
				
	//teste de coincidencia com as pontas de mesa
	pp_1=peca/10;
	pp_2=peca-pp_1*10;

	if(rodada==1 && jogador==p_jog) pm[0]=pp_1;

	if(pp_1==pm[0]||pp_1==pm[1]||pp_2==pm[0]||pp_2==pm[1])
		t_peca +=1;

	if (t_peca !=2) 
		printf("A peca que voce escolheu nao esta na sua mao"
			   " ou nao coincide com as pontas de mesa.\n");
	return t_peca;
}
