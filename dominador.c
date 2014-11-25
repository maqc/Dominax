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
#include "minhas_funcoes.h"

int main(void)
{
	int jogador;
	int p_jog; //primeiro jogador
	int peca=1;
	int rodada=1;
    int pm[2]={9,9}; //pontas de mesa
  	int i,j; //contadores
	int *player;

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
	while(rodada <= 7)
	{
		printf("Rodada %d\n",rodada);
	
		//troca de jogadores dentro de uma rodada
		for(i=1;i<=4;i++) 
		{
			switch(jogador)
			{
				case 1:
					player=jogador1;
					break;
				case 2:
					player=jogador2;
					break;
				case 3:
					player=jogador3;
					break;
				case 4:
					player=jogador4;
					break;
				default:
					break;
			}
			
			if ( (rodada !=1) || (jogador != p_jog))
				if (teste_toque(player,pm)) 
				{
					printf("O jogador %d tocou!\n\n",jogador);		
				}
			printf("Jogador %d, qual peca vc quer jogar?\n",jogador);
			mostra_mao(player);
			scanf("%d",&peca);

			// "retira" peca escolhida da mao
			for(j=0;j<=6;j++)
	 			if (player[j] ==peca) player[j]=99;

			//montagem das pontas de mesa
			monta_pm(rodada,jogador,p_jog,peca,pm);

			//teste de fim de jogo
			if (teste_final(player,jogador)) return 0;
		    
			jogador= (jogador % 4) +1;	
		} //fim do "for" para troca de jogadores	
		rodada +=1;
	}//fim do while
	return 0;
} // main
