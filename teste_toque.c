int teste_toque(int mao[],int pm[])
{
	int peca;
	int i, contador=0; //contadores
	int pp_1, pp_2; //pontas de peca

	for(i=0;i<=6;i++)
	{
		peca = mao[i];

		//separacao das pontas de peca
		pp_1=peca/10;
		pp_2=peca-pp_1*10;

		if(pp_1 == pm[0] || pp_1 == pm[1] || pp_2 == pm[0] || pp_2 == pm[1])
			contador +=1;
		if (contador != 0) return 0;
	}
	return 1;
}
