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
 *\file contagem_maos.c
 *\ingroup GrupoÚnico
 *\brief Conta o total de pontos, para cada jogador, contigo na sua mão.
 *\details Essa função verifica qual jogador tem menos pontos (e portanto
 *o vencedor) após todos os quatro terem tocado.
 *\version 3.0
 *\date 03/12/2014
 *\author MAXIMILIANO ADOLFO
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

int contagem_maos(int mao_1[], int mao_2[], int mao_3[], int mao_4[],int n_jog)
{
	int menor=10000; // menor mao
	int jog_ven=1; //jogador vencedor
	int soma_m[4]={0}; //soma da mao 
	int pp_1,pp_2; //pontas de peca
	int j; //contador para trocar jogadores
	int i; //contador para varrer a mão de um jogador
	int t_mao=28/n_jog;
	int *mao_c;

	for(j=1;j<=n_jog;j++)
	{
		switch(j)
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

		for(i=0; i<t_mao;i++)
			if(mao_c[i] != 99)
			{
				pp_1=mao_c[i]/10;
				pp_2=mao_c[i]-pp_1*10;
				soma_m[j] +=pp_1+pp_2;
			}

    	if (menor > soma_m[j]) 
		{
			 menor =soma_m[j];
			 jog_ven=j;
		}
	
	}

	for(j=1;j<=n_jog;j++)
	{
		printf("Jogador %d\n",j);
		if (j==1) mostra_mao(mao_1,t_mao);
		else if(j==2) mostra_mao(mao_2,t_mao);
		else if(j==3) mostra_mao(mao_3,t_mao);
		else mostra_mao(mao_4,t_mao);
		printf("Soma =%d\n\n", soma_m[j]);
	}
	printf("\nO JOGADOR %d VENCEU!\n", jog_ven);

	return 0;
}
