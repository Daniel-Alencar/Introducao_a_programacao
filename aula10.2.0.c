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
	while(cont>0)
	{
		if (num % cont == 0)
		{	
			printf("%i...", cont);
		}
		cont-= 1;
	}
}
