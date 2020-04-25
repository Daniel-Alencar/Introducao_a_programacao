#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float vetor[10], menor_valor;int indice, posicao_menor;
	for(indice=0;indice<10;indice++)
	{
		printf("vetor[%i]: ", indice);
		scanf("%f", &vetor[indice]);
	}
	for(indice=0;indice<10;indice++)
		printf("%.2f...", vetor[indice]);
	for(indice=0;indice<=9;indice++)
		if(!indice)
		{
			menor_valor=vetor[0];
			posicao_menor=0;
		}
		else
			if(vetor[indice] <= menor_valor)
			{
				menor_valor=vetor[indice];
				posicao_menor=indice;
			}
	printf("\nA posição do menor elemento do vetor é: %i!!!", posicao_menor+1);
}
