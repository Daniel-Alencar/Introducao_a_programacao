#include <stdio.h>
main()
{
	float n1, n2, menor, maior;
	printf("Digite um valor real: ");
	scanf("%f", &n1);
	printf("Digite outro valor real: ");
	scanf("%f", &n2);
	if (n1<n2)
	{
		menor = n1;
		maior = n2;
	}
	else
	{
		menor = n2;
		maior = n1;
	}
	printf("O %.0f representa %.0f%% do valor de %.0f!", menor, (100 * menor) / maior, maior);
}
