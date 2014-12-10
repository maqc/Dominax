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
 *\version 4.0
 *\date 03/12/2014
 *\author LUCAS CANEJO, RODRIGO BORBA, MAXIMILIANO COSTA
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

int sorteio_maos(int mao_1[],int mao_2[],int mao_3[],int mao_4[],int n_jog)
{
	int passagens=0;
	int temporario;
	int pecas[28]= {0,10,20,30,40,50,60,11,21,31,41,51,61,22,32,42,52,62,33,43,53,63,44,54,64,55,65,66};
	int jafoi[28]={0};
	int *mao_c;
	int t_mao= 28/n_jog; //tamanho da mao
 	int j,k,y; //contadores 

	//Seleção do jogador
	for(j=1; j <= n_jog; j++)
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
		
		// sorteio das maos
		srand(time(NULL));
    	passagens=0;
		y=0;
		while(passagens!= t_mao)
		{
			temporario= rand()%28;
			if(jafoi[temporario]==0)
			{
				mao_c[y]=pecas[temporario];
				jafoi[temporario]=1;
				passagens++;
				y++;
			}
		}
		if (DEBUG)
		{
			printf("jogador %d:\n{",j);
			for(k=0;k<t_mao;k++)
			{
				if(mao_c[k]==0)
					printf("00,");
				else
					printf("%d,", mao_c[k]);
			}
			printf("}\n");
		}
	}
	return 0;
}
