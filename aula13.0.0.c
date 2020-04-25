#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float vetor[10];int indice;
	for(indice=0;indice<10;indice++)
	{
		printf("vetor[%i]: ", indice);
		scanf("%f", &vetor[indice]);
	}
	for(indice=0;indice<10;indice++)
		printf("%.2f...", vetor[indice]);
}
