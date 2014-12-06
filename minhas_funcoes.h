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
 *\file minhas_funcoes.h
 *\ingroup GrupoÚnico
 *\brief Lista os protótipos para funções usadas no arquivo domino001.c
 *\details  
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

/**
 *\ingroup GrupoÚnico
 *\brief Mostra a mão de um jogador.
 *\details Imprime na tela a mão de um jogador.
 *\param[in] mao Armazena as peças da mão de um jogador.
 *
 */
int mostra_mao(int mao[]);

/**
 *\ingroup GrupoÚnico
 *\brief Monta as pontas da mesa.
 *\details Imprime na tela os valores das pontas das peças localizadas nas duas
 *extremidades da cadeia de peças.
 *\param[in] rodada Armazena a rodada corrente.
 *\param[in] jogador Armazena o jogador corrente.
 *\param[in] p_jog Registra o jogador que inicia a partida.
 *\param[in] peca Armazena a peça.
 *\param[in] pm	Armazena separadamente o valor das extremidades da mesa.
 *\param[in] ver_b Contém a versão do jogo, se é a beta ou não.
 * 
 */
int monta_pm(int rodada,int jogador,int p_jog,int peca,int pm[]);

/**
 *\ingroup GrupoÚnico
 *\brief Testa o se o jogador corrente tocou.
 *\details Verifica se existe alguma peça na mão do jogador que possa ser 
 *lançada numa das extremidades da mesa.
 *\param[in] mao Armazena as peças da mão do jogador corrente.
 *\param[in] pm  Armazena separadamente o valor das extremidades da mesa.
 * 
 */
int teste_toque(int mao[],int pm[]);

/**
 *\ingroup GrupoÚnico
 *\brief Testa se o jogador corrente venceu a partida.
 *\details Função que verifica se o jogador corrente ainda tem alguma peça na
 *sua mão, encontrando assim o jogador vitorioso.
 *\param[in] mao Armazena as peças da mão do jogador corrente.
 *\param[in] jogador Armazena o jogador corrente.
 * 
 */
int teste_final(int mao[],int jogador);

/**
 *\ingroup GrupoÚnico
 *\brief Testa a viabilidade da peça escolhida pelo usuário.
 *\details Verifica se a peça escolhida existe, e existindo se ela pode ser 
 *lançada numa das extremidades da mesa.
 *\param[in] *peca Apontador para a peça.
 *\param[in] rodada Armazena a rodada corrente.
 *\param[in] p_jog Registra o jogador que inicia a partida.
 *\param[in] pm	Armazena separadamente o valor das extremidades da mesa.
 *\param[in] mao Armazena as peças da mão do jogador corrente.
 *\param[in] jogador Armazena o jogador corrente.
 * 
 */
int teste_peca(int *peca,int rodada,int p_jog,int pm[],int mao[],int jogador);

/**
 *\ingroup GrupoÚnico
 *\brief Conta o total de pontos, para cada jogador, contigo na sua mão.
 *\details Essa função verifica qual jogador tem menos pontos (e portanto
 *o vencedor) após todos os quatro terem tocado.
 *\param[in] mao_1 Armazena as peças da mão do jogador 1.
 *\param[in] mao_2 Armazena as peças da mão do jogador 2.
 *\param[in] mao_3 Armazena as peças da mão do jogador 3.
 *\param[in] mao_4 Armazena as peças da mão do jogador 4.
 * 
 */
int contagem_maos(int mao_1[], int mao_2[], int mao_3[], int mao_4[]);

/**
 *\ingroup GrupoÚnico
 *\brief Distribui as peças aleatoriamente.
 *\details Essa função simula o sorteio de peças feito no início de
 *uma partida de xadrez.
 *\param[in] mao_1 Armazena as peças da mão do jogador 1.
 *\param[in] mao_2 Armazena as peças da mão do jogador 2.
 *\param[in] mao_3 Armazena as peças da mão do jogador 3.
 *\param[in] mao_4 Armazena as peças da mão do jogador 4.
 *\param[in] ver_b Contém a versão do jogo, se é a beta ou não.
 * 
 */
int sorteio_maos(int mao_1[],int mao_2[],int mao_3[],int mao_4[]);
