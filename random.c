#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int y,k;
	int passagens=0, temporario;
	int peca[28] = {0,10,20,30,40,50,60,11,21,31,41,51,61,22,32,42,52,62,33,43,53,63,44,54,64,55,65,66};
	int jafoi[28]={0};
	int jogador1[7];
	srand(time(NULL));
	
	while(passagens!=7)
	{
		temporario= rand()%28;
		if(jafoi[temporario]==0)
		{

			jogador1[y]=peca[temporario];
			jafoi[temporario]=1;
			passagens++;
			y++;
		}
	}
	
	printf("Sua mao:\n");
	printf("{");
	for(k=0;k<7;k++)
	{
		if(jogador1[k]==0)
			printf("00,");
		else
			printf("%d,", jogador1[k]);
	}
	printf("}");
	printf("\n");
	return 0;
}

