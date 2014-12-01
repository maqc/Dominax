#include <stdio.h>

int monta_pm(int rodada, int jogador, int p_jog, int peca, int pm[])
{
	int pp_1,pp_2; //pontas de peca
	char lado;

	//separacao das pontas de peca
	pp_1=peca/10;
	pp_2=peca-pp_1*10;

 	if(rodada ==1 && jogador== p_jog)
		{
			pm[0]=pp_1;
			pm[1]=pp_2;
		}
	else
	{
    	if((pp_1==pm[0] && pp_2==pm[1]) || (pp_1==pm[1] && pp_2==pm[0]))
		{
			printf("Escolha o lado direito ou esquerdo(d ou e): \n");
			scanf("%c",&lado);
			if(lado=='d')
			{
				if(pm[1] ==pp_1) pm[1]=pp_2;
				else pm[1]=pp_1;
			}
			else
			{
				if(pm[0] == pp_1) pm[0]=pp_2;
				else pm[0]=pp_1;
			}
		}
	 	else
	 	{
		
			if(pm[0]==pp_1) pm[0]=pp_2;
			else if(pm[0]==pp_2) pm[0]=pp_1;
			else if(pm[1]==pp_1) pm[1]=pp_2;
	   		else pm[1]=pp_1;	
	 	}
	}
	printf("Pontas da mesa: %d | %d\n\n",pm[0], pm[1]);
	return 0;
}
