#include <stdio.h>
main()
{
	float n1, n2, menor, maior;
	printf("Digite um valor real: ");
	scanf("%f", &n1);
	printf("Digite outro valor real: ");
	scanf("%f", &n2);
	menor = n1<n2?n1:n2;
	maior = n1>n2?n1:n2;
	printf("O %.0f representa %.0f%% de %.0f!", menor, (100 * menor) / maior, maior);
}

