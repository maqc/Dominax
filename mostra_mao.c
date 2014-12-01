#include <stdio.h>

int mostra_mao(int mao[])
{
    int i,j;
	int UIV; //ultimo indice valido (entendade-se peca existente)

	printf("Sua mao: {");
	for(i=0;i<=6;i++) 
	{
		for(j=0;j<=6;j++) 
			if(mao[j]!=99) UIV=j;

        if (mao[i] ==0) printf("00"); 
		if (mao[i] !=99 && mao[i] !=0)
			printf ("%d",mao[i]);
		if (i < UIV && mao[i]!=99) 
			printf(",");
		else if (i==6) printf("}\n");
	}
	return 0;
}
