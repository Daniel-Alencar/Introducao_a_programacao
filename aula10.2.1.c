#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num, cont;
	printf("Digite um número natural: ");
	scanf("%i", &num);
	cont=num;
	printf("%i é divisível por: ", num);
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
