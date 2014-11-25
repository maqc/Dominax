#include <stdio.h>

int mostra_mao(int jog[])
{
    int i;
	printf("Sua mao: {");
	for(i=0;i<=6;i++) 
	{
		if (jog[i] !=99) printf ("%d",jog[i]);
		if (i <6 && jog[i]!=99) printf(",");
		else if (i==6) printf("}\n");
	}
	return 0;
}
