#include <stdio.h>

int main(void)
{
	
	int peca=1;
	int pp_1,pp_2; //pontas de peca  
	int pm_1,pm_2; //pontas de mesa
	int rodada=1;
	char lado;     
  	int i; //contador

	// escolha das maos
	
	int jogador1[7]={50,54,64,55,60,31,20};
	int jogador2[7]={11,21,52,42,66,62,44};
	int jogador3[7]={32,63,00,41,53,51,65};
	int jogador4[7]={61,22,30,10,40,43,33};

	// escolha do iniciante
	
	printf("jogador 2 sai pq tem o dozao\n");

	while(rodada <= 4)
	{
	printf("Rodada %d\n",rodada);

	//mostrar a mao do jogador
	for(i=0;i<=6;i++) 
		if (jogador2[i] ==peca) jogador2[i]=99;

	printf("Sua mao: {");
	for(i=0;i<=6;i++) 
	{
		if (jogador2[i] !=99) printf ("%d",jogador2[i]);
		if (i <6 && jogador2[i]!=99) printf(",");
		else if (i==6) printf("}\n");
	}

	//escolha da peca
	printf("%s, qual peca vc quer jogar?\n","jogador");
	scanf("%d",&peca);

	
	//separacao das pontas da peca
	pp_1=peca/10;
	pp_2=peca-pp_1*10;

	//montagem das pontas de mesa

 	if(rodada ==1)
	{
		pm_1=pp_1;
		pm_2=pp_2;
	}
	else
	{
    if((pp_1==pm_1 || pp_1==pm_2) && (pp_2==pm_1 || pp_2==pm_2))
	{
		printf("Escolha o lado direito ou esquerdo(d ou e): ");
		scanf("%c",&lado);
		if(lado=='d')
		{
			if(pm_2 == pp_1)	pm_2=pp_2;
			else pm_2=pp_1;
		}
		else
		{
			if(pm_1 == pp_1) pm_1=pp_2;
			else pm_1=pp_1;
		}
	}
	else if((pp_1!=pm_1 && pp_1!=pm_2)&&(pp_2!=pm_1 && pp_2 !=pm_2))
		 {
			
		 }
		 else
		 {
			 if(pm_1==pp_1) pm_1=pp_2;
			 else if(pm_1==pp_2) pm_1=pp_1;
			 	  else if(pm_2==pp_1) pm_2=pp_2;
				  	   else pm_2=pp_1;	
		 }
	}
	
	printf("Pontas: %d | %d\n\n",pm_1, pm_2);
    
	// Teste de fim de jogo


	rodada +=1;
	}//fim do while
	return 0;
}
