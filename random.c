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
 *\file random.c
 *\ingroup GrupoÚnico
 *\brief Distribui as peças aleatoriamente.
 *\details Essa função simula o sorteio de peças feito no início de
 *uma partida de xadrez.
 *\version 3.0
 *\date 03/12/2014
 *\author LUCAS CANEJO, RODRIGO BORBA 
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
#include <stdlib.h>
#include <time.h>

int sorteio_maos(int mao_1[],int mao_2[],int mao_3[],int mao_4[], char ver_b)
{
	int y=0,x=0,z=0,v=0,k;
	int passagens=0, temporario;
	int pecas[28]= {0,10,20,30,40,50,60,11,21,31,41,51,61,22,32,42,52,62,33,43,53,63,44,54,64,55,65,66};
	int jafoi[28]={0};

 	srand(time(NULL));

	// sorteio das maos
	while(passagens!=7)
	{
		temporario= rand()%28;
		if(jafoi[temporario]==0)
		
		{
			mao_1[y]=pecas[temporario];
			jafoi[temporario]=1;
			passagens++;
			y++;
		}
	}
	if (ver_b =='s')
	{
		printf("jogador 1:\n");
		printf("{");
		for(k=0;k<7;k++)
		{
			if(mao_1[k]==0)
				printf("00,");
			else
				printf("%d,", mao_1[k]);
		}
		printf("}");
		printf("\n");
	}

	passagens=0;
	while(passagens!=7)
	{
		temporario= rand()%28;
		if(jafoi[temporario]==0)
		{
			mao_2[x]=pecas[temporario];
			jafoi[temporario]=1;
			passagens++;
			x++;
		
		}
	}

	if (ver_b =='s')
	{
		printf("jogador 2:\n");
		printf("{");
		for(k=0;k<7;k++)
		{
			if(mao_2[k]==0)
				printf("00,");
			else
				printf("%d,", mao_2[k]);
		}
		printf("}");
		printf("\n");
	}

	passagens=0;
	while(passagens!=7)
	{
		temporario = rand()%28;
		if(jafoi[temporario]==0)
		
		{
			mao_3[z]=pecas[temporario];
			jafoi[temporario]=1;
			passagens++;
			z++;
		}
	}

	if (ver_b =='s')
	{
		printf("Jogador 3:\n");
		printf("{");
		for(k=0;k<7;k++)
		{
			if(mao_3[k]==0)
				printf("00,");
			else
				printf("%d,", mao_3[k]);
		}
		printf("}");
		printf("\n");
	}

	passagens=0;
	while(passagens!=7)
	{
		temporario = rand()%28;
		if(jafoi[temporario]==0)
		{
			mao_4[v]=pecas[temporario];
			jafoi[temporario]=1;
			passagens++;
			v++;

		}
	}

	if (ver_b =='s')
	{
		printf("Jogador 4:\n");
		printf("{");
		for(k=0;k<7;k++)
		{
			if(mao_4[k]==0)
				printf("00,");
			else
				printf("%d,", mao_4[k]);
		}
		printf("}");
		printf("\n");
	}
	
	return 0;
}
