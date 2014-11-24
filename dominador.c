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

int main(void)
{
	
	int jogador;
	int peca=1;
	int pp_1,pp_2; //pontas de peca  
	int pm_1,pm_2; //pontas de mesa
	int rodada=1;
	char lado;     
  	int i; //contador

	// escolha das maos
	
	int jogador1[7]={50,54,64,55,60,31,20};
	int jogador2[7]={11,21,52,42,66,62,44};
	int jogador3[7]={32,63,00,41,53,51,65};
	int jogador4[7]={61,22,30,10,40,43,33};

	// escolha do iniciante
	
	printf("Qual jogador iniciara o jogo? \n");
	scanf("%d", &jogador);

	while(rodada <= 4)
	{
		printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
		scanf("%d",&peca);

		//separacao das pontas da peca
		pp_1=peca/10;
		pp_2=peca-pp_1*10;

		//montagem das pontas de mesa
 		if(rodada ==1)
		printf("Rodada %d\n",rodada);

		//mostrar a mao do jogador
		for(i=0;i<=6;i++) 
			if (jogador2[i] ==peca) jogador2[i]=99;

		printf("Sua mao: {");
		for(i=0;i<=6;i++) 
		{
			if (jogador2[i] !=99) printf ("%d",jogador2[i]);
			if (i <6 && jogador2[i]!=99) printf(",");
			else if (i==6) printf("}\n");
		}

		//escolha da peca
		printf("%s, qual peca vc quer jogar?\n","jogador");
		scanf("%d",&peca);

	
		//separacao das pontas da peca
		pp_1=peca/10;
		pp_2=peca-pp_1*10;

		//montagem das pontas de mesa

 		if(rodada ==1)
		{
			pm_1=pp_1;
			pm_2=pp_2;
		}
		else
		{
    	if((pp_1==pm_1 || pp_1==pm_2) && (pp_2==pm_1 || pp_2==pm_2))
		{
			printf("Escolha o lado direito ou esquerdo(d ou e): ");
			scanf("%c",&lado);
			if(lado=='d')
			{
				pm_1=pp_1;
				pm_2=pp_2;
			}
			else
			{
    			if((pp_1==pm_1 || pp_1==pm_2) && (pp_2==pm_1 || pp_2==pm_2))
				{
					printf("Escolha o lado direito ou esquerdo(d ou e): ");
					scanf("%c",&lado);
					if(lado=='d')
					{
						if(pm_2 == pp_1)	pm_2=pp_2;
						else pm_2=pp_1;
					}
				else
				{
					if(pm_1 == pp_1) pm_1=pp_2;
					else pm_1=pp_1;
				}
			}
			else if((pp_1!=pm_1 && pp_1!=pm_2)&&(pp_2!=pm_1 && pp_2 !=pm_2))
		 	{
		 	// temporariamente vazio	
		 	}
		 	else
		 	{
				if(pm_1==pp_1) pm_1=pp_2;
			 	else if(pm_1==pp_2) pm_1=pp_1;
			 	else if(pm_2==pp_1) pm_2=pp_2;
		     	else pm_2=pp_1;	
		 	}
		}
		printf("Rodada %d\n",rodada);
		printf("Pontas: %d | %d\n\n",pm_1, pm_2);
    
		// Teste de fim de jogo


		rodada +=1;
	}//fim do while
	return 0;
}
