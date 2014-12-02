/* ************************************************************************ *
 *    Domino001, versão 1.0                                                 *
 *    Programa feito para jogar domino                                      *
 *                                                                          *
 *    Copyright (C) 20XX by LUCAS CANEJO, RODRIGO BORBA, MARCUS VINICIUS,   *
 *    REGINA GOMES, LUCAS CALADO, LUCAS BORGES, MAXIMILIANO ADOLFO,         *
 *    VIVIANE SANGUINETT, GABRIEL ALFAYA, ANORLD FELIX                      *
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

#define HOUVE_TOQUE 99
#define SEM_TOQUE 0
#define PECA_RETIRADA 99
#define PECA_INEXISTENTE 9
#define PMV 9 //ponta de mesa vazia
#define SEM_JOGADOR 50
#define MAX_RODADAS 100 //numero maximo de rodadas
#define SEQ_TOQUES 4  //sequencia maxima de toques consecutivos

/**
 *\file domino001.c
 *\brief Arquivo principal do programa Domino001
 *
 *Esse programa foi desenvolvido para permitir uma partida de dominó
 *entre 4 jogadores humanos. Ele permite iniciamente a escolha entre
 *a versão de desenvolvimento (beta) ou a versão usuário final. 
 *
 */
int main(void)
{
	int jogador;
	int p_jog= SEM_JOGADOR; //primeiro jogador
	int t_peca=0; //testes de peca
	int peca=PECA_INEXISTENTE;
	int rodada=1;
    int pm[2]={PMV,PMV}; //pontas de mesa
  	int i,j; //contadores
	int tt=SEM_TOQUE;//teste de toque
	int *mao_c; //apontador para a mao corrente
	int mem_toq[4]={0,0,0,0}; //memoria de toque
	char ver_b; //Versao beta

	// escolha das maos
	int mao_1[7]={50,54,64,55,60,31,20};
	int mao_2[7]={11,21,52,42,66,62,44};
	int mao_3[7]={32,63,0,41,53,51,65};
	int mao_4[7]={61,22,30,10,40,43,33};

	// escolha do iniciante
	while(p_jog < 1 || p_jog >4 )
	{
		printf("\n\nVamos iniciar uma partida de domino com 4 jogadores humanos.\n\n"
			   "Digite \"s\" para ativar a versao beta ou \"n\" caso contrario.\n");
		scanf("%c",&ver_b);
		printf("Qual jogador iniciara? Digite qualquer numero de 1 a 4. \n");
		scanf("%d", &p_jog);
		while( getchar() != '\n' ) getchar(); //descarregamento de buffer
		if (p_jog < 1 || p_jog > 4) 
			printf("Voce escolheu uma opcao invalida.\n\n");
	}
	jogador = p_jog;

	// rodadas
	while(rodada <= MAX_RODADAS)
	{
		printf("Rodada %d\n",rodada);
	
		//troca de jogadores dentro de uma rodada
		for(i=1;i<=4;i++) 
		{
			switch(jogador)
			{
				case 1:
					mao_c =mao_1;
					break;
				case 2:
					mao_c =mao_2;
					break;
				case 3:
					mao_c =mao_3;
					break;
				case 4:
					mao_c =mao_4;
					break;
				default:
					break;
			}

		    //teste de toque	
			if ( (rodada !=1) || (jogador != p_jog))
			{
				if (teste_toque(mao_c,pm)) 
				{
					printf("\nO JOGADOR %d TOCOU!\n\n",jogador);		
					mem_toq[jogador-1]=1;
					t_peca =2; //ignora o teste de peca
					tt= HOUVE_TOQUE; // variavel para ignorar etapas
				}
				else mem_toq[jogador-1]=0;
			}
			int soma=0;
			for (j=0; j<=3;j++)
				soma+=mem_toq[j];
			if (soma==SEQ_TOQUES) 
			{
				contagem_maos(mao_1,mao_2,mao_3,mao_4);	
				return 0;
			}

			//protecao da mao
			if (tt != HOUVE_TOQUE)
			{
				if (ver_b=='n')
				{
					printf("Jogador %d, posso mostrar sua mao agora?"
						   " Digite \"s\" para sim.\n",jogador);
					getchar();
				}
				else printf("Jogador %d\n",jogador);
				mostra_mao(mao_c);
			}

			//leitura e testes de peca (existencia e compatibilidade com pontas de mesa)
			while(t_peca !=2)
			{
				printf("Digite a peca que vc quer jogar: ");
				scanf("%d",&peca);
				while( getchar() != '\n' ) getchar(); //descarregamento de buffer
				t_peca = teste_peca(peca,rodada,p_jog,pm,mao_c,jogador);
			}
			t_peca=0;

			if (tt != HOUVE_TOQUE)
			{
				// "retira" peca escolhida da mao
				for(j=0;j<=6;j++)
	 				if (mao_c[j] ==peca) mao_c[j]=PECA_RETIRADA;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm,ver_b);

				//teste de fim de jogo
				if (teste_final(mao_c,jogador)) return 0;
			}
            tt=SEM_TOQUE;

			jogador= (jogador % 4) +1; //troca de jogador	
		} //fim do "for" para troca de jogadores	
		rodada +=1;
	}//fim do while
	return 0;
} // main
