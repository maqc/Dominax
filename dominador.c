/* ************************************************************************ *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 20XX by AUTHORs_NAME                                    *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *    Or read it online at <<http://www.gnu.org/licenses/>>.                *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    AUTHORs_NAME <AUTHORs_EMAIL>                                          *
 *    Webpage: WEB_PAGE                                                     *
 *    Phone: PHONE_NUMBER                                                   *
 * ************************************************************************ *
 *
 */

#include <stdio.h>

int mostra_mao(int jog[]);
int monta_pm(int rodada, int jogador, int p_jog, int peca,int pm[]);
int teste_toque(int player[],int pm[]);

int main(void)
{
	int jogador;
	int p_jog; //primeiro jogador
	int peca=1;
	int rodada=1;
    int pm[2]={9,9}; //pontas de mesa
  	int i,j; //contadores

	// escolha das maos
	int jogador1[7]={50,54,64,55,60,31,20};
	int jogador2[7]={11,21,52,42,66,62,44};
	int jogador3[7]={32,63,00,41,53,51,65};
	int jogador4[7]={61,22,30,10,40,43,33};

	// escolha do iniciante
	printf("Qual jogador iniciara o jogo? \n");
	scanf("%d", &p_jog);
	jogador = p_jog;

	// rodadas
	while(rodada <= 4)
	{
		printf("Rodada %d\n",rodada);
	
		//troca de jogadores dentro de uma rodada
		for(i=1;i<=4;i++) 
		{
			//testa o toque e mostra a mao do jogador
			switch(jogador)
			{
			case 1:
				if ( (rodada !=1) || (jogador != p_jog))
					if (teste_toque(jogador1,pm)) 
					{
						printf("O jogador %d tocou!\n",jogador);		
						break;
					}
				printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
				mostra_mao(jogador1);
				scanf("%d",&peca);

				// "retira" peca escolhida da mao
				for(j=0;j<=6;j++)
	 				if (jogador1[j] ==peca) jogador1[j]=99;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm);

				break;
			case 2:
				if ( (rodada !=1) || (jogador != p_jog))
					if (teste_toque(jogador2,pm)) 
					{
						printf("O jogador %d tocou!\n",jogador);		
						break;
					}
				printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
				mostra_mao(jogador2);
				scanf("%d",&peca);

				// "retira" peca escolhida da mao
				for(j=0;j<=6;j++)
	 				if (jogador2[j] ==peca) jogador2[j]=99;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm);
		
				break;
			case 3:
				if ( (rodada !=1) || (jogador != p_jog))
					if (teste_toque(jogador3,pm)) 
					{
						printf("O jogador %d tocou!\n",jogador);		
						break;
					}
				printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
				mostra_mao(jogador3);
				scanf("%d",&peca); 

				// "retira" peca escolhida da mao
				for(j=0;j<=6;j++)
	 				if (jogador3[j] ==peca) jogador3[j]=99;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm);
				break;
			case 4:
				if ( (rodada !=1) || (jogador != p_jog))
					if (teste_toque(jogador3,pm)) 
					{
						printf("O jogador %d tocou!\n",jogador);		
						break;
					}
				printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
				mostra_mao(jogador4);
				scanf("%d",&peca);

				// "retira" peca escolhida da mao
				for(j=0;j<=6;j++)
	 				if (jogador4[j] ==peca) jogador4[j]=99;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm);

				break;
			default:
				break;
			} //fim do switch
		    
			// Teste de fim de jogo

			jogador= (jogador % 4) +1;	
		} //fim do "for" para troca de jogadores	
		rodada +=1;
	}//fim do while
	return 0;
} // main

int mostra_mao(int jog[])
{
    int i;
	printf("Sua mao: {");
	for(i=0;i<=6;i++) 
	{
		if (jog[i] !=99) printf ("%d",jog[i]);
		if (i <6 && jog[i]!=99) printf(",");
		else if (i==6) printf("}\n");
	}
	return 0;
}

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
    	if((pp_1==pm[0] || pp_1==pm[1]) && (pp_2==pm[0] || pp_2==pm[1]))
		{
			printf("Escolha o lado direito ou esquerdo(d ou e): ");
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

int teste_toque(int player[],int pm[])
{
	int peca;
	int i, contador=0; //contadores
	int pp_1, pp_2; //pontas de peca

	for(i=0;i<=6;i++)
	{
		peca = player[i];

		//separacao das pontas de peca
		pp_1=peca/10;
		pp_2=peca-pp_1*10;

		if(pp_1 == pm[0] || pp_1 == pm[1] || pp_2 == pm[0] || pp_2 == pm[1])
			contador +=1;
		if (contador != 0) return 0;
	}
	return 1;
}
