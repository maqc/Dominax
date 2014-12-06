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
 *\file teste_peca.c
 *\ingroup GrupoÚnico
 *\brief Testa a viabilidade da peça escolhida pelo usuário.
 *\details Verifica se a peça escolhida existe, e existindo se ela pode ser 
 *lançada numa das extremidades da mesa.
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

int teste_peca(int *peca,int rodada,int p_jog,int pm[],int mao[],int jogador)
{
	int pp_1,pp_2; //pontas de peca
	int t_peca=0;
	int peca2;
	int j; //contador

	//teste de pertencimento da peca a mao
	for(j=0;j<=6;j++)
		if(*peca == mao[j]) t_peca=1;
	
	pp_1= *peca/10;
	pp_2= *peca-pp_1*10;
	
	if(t_peca==0)
	{
		peca2 = pp_1 + pp_2*10;
		for(j=0;j<=6;j++)
			if(peca2 == mao[j])
			{
				t_peca=1;
				*peca = peca2;
			}
	}

	//teste de coincidencia com as pontas de mesa
	if(rodada==1 && jogador==p_jog) pm[0]=pp_1;

	if(pp_1==pm[0]||pp_1==pm[1]||pp_2==pm[0]||pp_2==pm[1])
		t_peca +=1;

	if (t_peca !=2) 
		printf("A peca que voce escolheu nao esta na sua mao"
			   " ou nao coincide com as pontas de mesa.\n");
	return t_peca;
}
