#include <stdio.h>
main()
{
	float n1, n2, n3;
	float p1, p2, p3;
	float media;

	printf("Digite a 1� nota: ");
	scanf("%f", &n1);
	printf("Peso da nota 1: ");
	scanf("%f", &p1);
	printf("Digite a 2� nota: ");
	scanf("%f", &n2);
	printf("Peso da nota 2: ");
	scanf("%f", &p2);
	printf("Digite a 3� nota: ");
	scanf("%f", &n3);
	printf("Peso da nota 3: ");
	scanf("%f", &p3);

	media = (((n1*p1)+(n2*p2)+(n3*p3))/(p1+p2+p3));
	printf("A m�dia ponderada �: %.2f", media);
}

