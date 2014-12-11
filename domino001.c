/* ************************************************************************ *
 *    Domino001, versão 3.0                                                 *
 *    Programa feito para jogar domino                                      *
 *                                                                          *
 *    Copyright (C) 2014 by LUCAS CANEJO, RODRIGO BORBA, MARCUS VINICIUS,   *
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
 *    To contact the authors, please write to:                              *
 *    Maximiliano Costa                                                     *
 *    Email: maxquirinog@gmail.com                                          *
 * ************************************************************************ *
 *
 */

/**
 *\file domino001.c
 *\ingroup GrupoÚnico
 *\brief Programa Domino001.
 *\details Esse é o arquivo principa do programa Dominó 1.
 *Ela permite iniciamente a escolha entre a versão de desenvolvimento (beta) ou a
 *versão para um usuário final. 
 *\version 3.0
 *\date 03/12/2014
 *\author LUCAS CANEJO, RODRIGO BORBA, MARCUS VINICIUS,   
 *    REGINA GOMES, LUCAS CALADO, LUCAS BORGES, MAXIMILIANO ADOLFO,         
 *    VIVIANE SANGUINETT, GABRIEL ALFAYA, ANORLD FELIX
 *\copyright (c) 2014 GNU GPL v3
 *This program is free software; you can redistribute it and/or modify  
 *it under the terms of the GNU General Public License as published by  
 *the Free Software Foundation; either version 2 of the License, or     
 *(at your option) any later version.                                   
 *                                                                         
 *This program is distributed in the hope that it will be useful,       
 *but WITHOUT ANY WARRANTY; without even the implied warranty of        
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
 *GNU General Public License for more details.                          
 *                                                                          
 *You should have received a copy of the GNU General Public License     
 *along with this program; if not, write to the                         
 *Free Software Foundation, Inc.,                                       
 *59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             
 *Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 */

#include <stdio.h>
#include "minhas_funcoes.h"
#include <stdlib.h>

///\cond DEBUG
#define HOUVE_TOQUE 99 ///Constante para indicar a ocorrência de toque.
#define SEM_TOQUE 0
#define PECA_RETIRADA 99
#define N_PECAS 28 // Número de peças de um jogo de dominó.
#define PECA_INEXISTENTE 9
#define PMV 9 //ponta de mesa vazia
#define SEM_JOGADOR 50
#define MAX_RODADAS 100 //numero maximo de rodadas
///\endcond

/**
 *\ingroup GrupoÚnico
 *\brief Função Principal
 *\details Função que controla o fluxo de dados do programa.
 *\retval EXIT_FAILURE se tudo der certo
 *\retval EXIT_FAILURE Se ocorreu um erro.
 *
 *\bug Desconhecido
 */

int main(void)
{
	int jogador;
	int p_jog= SEM_JOGADOR;//primeiro jogador
	int t_peca=0; //testes de peca
	int peca=PECA_INEXISTENTE;
	int rodada=1;
	int pm[2]={PMV,PMV}; //pontas de mesa
	int i,j; //contadores
	int tt=SEM_TOQUE;//teste de toque
	int *mao_c; //apontador para a mao corrente
	int mem_toq[4]={0,0,0,0}; //memoria de toque
	int mao_1[14]; 
	int mao_2[14];
	int mao_3[7];
	int mao_4[7];
	int t_mao; //tamanho da mão de um jogador
	int n_jog= SEM_JOGADOR; //Número de jogadores
	char t_jog[3];//tipo de jogador(humano ou máquina)
	char tj;// armazena o tipo de jogador corrente
	int njh=1;//número de jogadores humanos
	char nomes[4][20];//Registra os nomes dos jogadores
	char *nome; //Aponta para o nome do jogador corrente
	
	printf("\nSeja bem vindo ao Domino001!\n");
	printf("\nVoce ira jogar um jogo de domino, no qual voce\npodera jogar de tres maneiras diferentes:\n\nCom mais 3 amigos (4 jogadores), contra um amigo (2 jogadores)\ne contra maquina (2 jogadores).\nPrepare-se e divirta-se!");
	printf("\n\nVamos iniciar o jogo!\n\n");

	printf("Sera uma partida com 2 ou com 4 jogadores?\n");
	scanf("%d",&n_jog);
	
	while(n_jog !=2 && n_jog !=4)
	{
		printf("Sera uma partida com 2 ou com 4 jogadores?\n");
		scanf("%d", &n_jog);
		while(getchar()!= '\n')
			getchar();
	}

	t_mao= N_PECAS/n_jog;

	//Seleção do tipo de jogador, humano ou máquina.
	for(j=1;j<=n_jog;j++)
	{
		printf("Escreva o nome do jogador %d:\n",j);
			scanf("%s",nomes[j-1]); printf("O nome escolhido foi %s\n",nomes[j-1]);
		if(j>1)
		{
			while(t_jog[j-2] !='h' && t_jog[j-2]!='m')
			{
				printf("O jogador %d sera humano? Digite h para sim e m para nao.\n",j);
				while( getchar() != '\n' ) getchar(); //descarregamento de buffer
				t_jog[j-2]=getchar();

				if(t_jog[j-2]=='h')
					njh+=1;	
				if(t_jog[j-2] !='h' && t_jog[j-2]!='m') 
					printf("Voce digitou um caracter diferente de h e m.\n");
			}
		}
	}

	//escolha do iniciante
	while(p_jog < 1 || p_jog > n_jog )
	{
		printf("Qual jogador iniciara? Digite qualquer numero de 1 a %d. \n", n_jog);
		scanf("%d", &p_jog);
		while( getchar() != '\n' ) getchar(); //descarregamento de buffer
		if (p_jog < 1 || p_jog > n_jog ) 
			printf("Voce escolheu uma opcao invalida.\n\n");
	}
	jogador = p_jog;

	//Sorteio das maos
	sorteio_maos(mao_1,mao_2,mao_3,mao_4,n_jog);

	// rodadas
	while(rodada <= MAX_RODADAS)
	{
		printf("Rodada %d\n",rodada);

		//troca de jogadores dentro de uma rodada
		for(i=1;i<=n_jog;i++) 
		{
			
			switch(jogador)
			{
				case 1:
					mao_c =mao_1;
					tj='h';
					nome=nomes[0];
					break;
				case 2:
					mao_c =mao_2;
					tj=t_jog[0];
					nome=nomes[1];
					break;
				case 3:
					mao_c =mao_3;
					tj=t_jog[1];
					nome=nomes[2];
					break;
				case 4:
					mao_c =mao_4;
					tj=t_jog[2];
					nome=nomes[3];
					break;
				default:
					break;
			}

			//teste de toque	
			if ( (rodada !=1) || (jogador != p_jog))
			{
				if (teste_toque(mao_c,pm,t_mao)) 
				{
					printf("\n%s TOCOU!\n\n",nome);		
					mem_toq[jogador-1]=1;
					t_peca =1; //ignora o teste de peca
					tt= HOUVE_TOQUE; // variavel para ignorar etapas
				}
				else mem_toq[jogador-1]=0;
			}
			int soma=0;
			for (j=0; j< n_jog ;j++)
				soma+=mem_toq[j];
			if (soma == n_jog) 
			{
				contagem_maos(mao_1,mao_2,mao_3,mao_4,n_jog);	
				return 0;
			}

			//protecao da mao
			if (tt != HOUVE_TOQUE)
			{
				if (!DEBUG && tj=='h' && njh>1)
				{
					printf("%s, posso mostrar sua mao agora? "
						   "Pressione \"<ENTER>\" quando estiver pronto.\n",nome);
					getchar();
				}
				else printf("%s\n",nome);

				if(tj=='h' || DEBUG)
					mostra_mao(mao_c,t_mao);
			}

			//leitura e testes de peca (existencia e compatibilidade com pontas de mesa)
			j=0;
			while(t_peca != 1)
			{
				if(tj=='h')
				{
					printf("\nDigite a peca que vc quer jogar: ");
					scanf("%d",&peca);
					while( getchar() != '\n' ) getchar(); //descarregamento de buffer
				}
				else 
				{
					peca=mao_c[j];
					j++;
				}
				t_peca = teste_peca(&peca,rodada,p_jog,pm,mao_c,jogador,t_mao,tj);
				if(t_peca==1 && tj=='m')
				{
					if(peca!=0) 
						printf("A peca escolhida foi %d.\n",peca);
					else
						printf("A peca escolhida foi 00.\n");
				}
			}
			t_peca=0;

			if (tt != HOUVE_TOQUE)
			{
				//"Retira" peca escolhida da mao
				for(j=0;j< t_mao;j++)
					if (mao_c[j] ==peca) mao_c[j]=PECA_RETIRADA;

				//montagem das pontas de mesa
				monta_pm(rodada,jogador,p_jog,peca,pm,tj,njh);

				//teste de fim de jogo
				if (teste_final(mao_c,jogador,t_mao)) return 0;
			}
			tt=SEM_TOQUE;

			jogador= (jogador % n_jog) +1; //troca de jogador	
		} //fim do "for" para troca de jogadores	
		rodada +=1;
	}//fim do while
	return 0;
} // main
