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
 *\version 4.0
 *\date 09/12/2014
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

int teste_peca(int *peca,int rodada,int p_jog,int pm[],int mao[],int jogador,int t_mao,char tj)
{
	int pp_1,pp_2; //pontas de peca
	int tp=0; //teste de pertencimento
	int tc=0; //teste de coincidência
	int peca2;
	int j; //contador

	//teste de pertencimento da peça a mão
	for(j=0;j<t_mao;j++)
		if(*peca == mao[j]) tp=1;
	
	pp_1= *peca/10;
	pp_2= *peca-pp_1*10;
	
	if(tp==0)
	{
		peca2 = pp_1 + pp_2*10;
		for(j=0;j<t_mao;j++)
			if(peca2 == mao[j])
			{
				tp=1;
				*peca = peca2;
			}
	}

	if (tp ==0)
	{
		if(tj=='h')
			printf("A peca que voce escolheu nao esta na sua mao.\n");
		return 0;
	}

	//teste de coincidencia com as pontas de mesa
	if(rodada==1 && jogador==p_jog) pm[0]=pp_1;

	if(pp_1==pm[0]||pp_1==pm[1]||pp_2==pm[0]||pp_2==pm[1])
		tc =1;

	if (tc==0) 
	{
		if(tj=='h')
			printf("A peça nao coincide com as pontas de mesa.\n");
		return 0;
	}

	return 1;
}
