#include <stdio.h>
#include <stdlib.h>

int monta_pm(int rodada, int jogador, int p_jog, int peca, int pm[],char ver_b)
{
	int pp_1,pp_2; //pontas de peca
	char lado;
	char command[50]; //recebe comando para o sistema

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
			printf("Digite \"d\" para escolher o lado direito da mesa"
				   " ou \"e\" para o lado esquerdo.\n");
			scanf("%c",&lado);
			while(getchar() != '\n') getchar(); //esvaziamento de buffer

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
	//rolagem de tela
	if(ver_b=='n')
	{
		sprintf(command,"clear");
		system(command);
	}	

	printf("Pontas da mesa: %d | %d\n\n",pm[0], pm[1]);
	return 0;
}
