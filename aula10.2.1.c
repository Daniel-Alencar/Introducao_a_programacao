#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num, cont;
	printf("Digite um n�mero natural: ");
	scanf("%i", &num);
	cont=num;
	printf("%i � divis�vel por: ", num);
	do
	{
		if (num % cont == 0)
		{	
			printf("%i...", cont);
		}
		cont-= 1;
	}
	while(cont>0);
}
