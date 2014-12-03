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

int contagem_maos(int mao_1[], int mao_2[], int mao_3[], int mao_4[])
{
	int menor=0; // menor mao
	int jog_ven=1; //jogador vencedor
	int soma_m1=0,soma_m2=0,soma_m3=0,soma_m4=0; //soma da mao i, i=1...4
	int pp_1,pp_2; //pontas de peca
	int j; //contador

	for(j=0; j<=6;j++)
		if(mao_1[j] != 99)
		{
			pp_1=mao_1[j]/10;
			pp_2=mao_1[j]-pp_1*10;
			soma_m1 +=pp_1+pp_2;
		}
	for(j=0; j<=6;j++)
		if(mao_2[j] != 99)
		{
			pp_1=mao_2[j]/10;
			pp_2=mao_2[j]-pp_1*10;
			soma_m2 +=pp_1+pp_2;
		}
	for(j=0; j<=6;j++)
		if(mao_3[j] != 99)
		{
			pp_1=mao_3[j]/10;
			pp_2=mao_3[j]-pp_1*10;
			soma_m3 +=pp_1+pp_2;
		}
	for(j=0; j<=6;j++)
		if(mao_4[j] != 99)
		{
			pp_1=mao_4[j]/10;
			pp_2=mao_4[j]-pp_1*10;
			soma_m4 +=pp_1+pp_2;
		}

	menor =soma_m1;
				
    if (menor > soma_m2) 
	{
		 menor =soma_m2;
		 jog_ven=2;
	}
	if (menor > soma_m3)
	{
		menor =soma_m3;
		jog_ven=3;
	}
	if (menor > soma_m4)
	{
		 menor=soma_m4;
		 jog_ven=4;
	}

	printf("Jogador 1\n");
	mostra_mao(mao_1);
	printf("Soma =%d\n\n", soma_m1);

	printf("Jogador 2\n");
	mostra_mao(mao_2);
	printf("Soma =%d\n\n", soma_m2);	

	printf("Jogador 3\n");
	mostra_mao(mao_3);
	printf("Soma =%d\n\n", soma_m3);

	printf("Jogador 4\n");
	mostra_mao(mao_4);
	printf("Soma =%d\n\n", soma_m4);

	printf("\nO JOGADOR %d VENCEU!\n", jog_ven);

	return 0;
}
