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
 *\file monta_pm.c
 *\ingroup GrupoÚnico
 *\brief Monta as pontas da mesa.
 *\details Imprime na tela os valores das pontas das peças localizadas nas duas
 *extremidades da cadeia de peças.
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
