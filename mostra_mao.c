#include <stdio.h>

int mostra_mao(int mao[])
{
    int i;
	printf("Sua mao: {");
	for(i=0;i<=6;i++) 
	{
        if (mao[i] ==0) printf("00"); 
		if (mao[i] !=99 && mao[i] !=0) printf ("%d",mao[i]);
		if (i <6 && mao[i]!=99) printf(",");
		else if (i==6) printf("}\n");
	}
	return 0;
}
