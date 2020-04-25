#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num, cont=0, soma=0;
	while(num>=0)
	{	printf("Digite um número natural (Digite um número negativo para sair!!!): ");
		scanf("%i", &num);
		if (num>=0)
		{	soma += num;
			cont-=-1;
		}
	}
	printf("A soma foi %i e foram %i números digitados!!!\n", soma, cont);
	cont != 0 ? printf("A média foi %.2f!!!", soma/(float)cont) : printf("Divisão por 0 inválida.");
}
