#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num, cont=0, soma=0;
	while(num>=0)
	{	printf("Digite um n�mero natural (Digite um n�mero negativo para sair!!!): ");
		scanf("%i", &num);
		if (num>=0)
		{	soma += num;
			cont-=-1;
		}
	}
	printf("A soma foi %i e foram %i n�meros digitados!!!\n", soma, cont);
	cont != 0 ? printf("A m�dia foi %.2f!!!", soma/(float)cont) : printf("Divis�o por 0 inv�lida.");
}
