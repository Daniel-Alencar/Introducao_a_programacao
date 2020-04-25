#include<stdio.h>
#define tamanho 10
int maior(int inteiros[])
{
	int i, maior;
	for(i=0;i<tamanho;i++)
		if(!i)
			maior=inteiros[i];
		else
			if(inteiros[i]>maior)
				maior=inteiros[i];
	return maior;
}
int main()
{
	int vetor[tamanho],i;
	for(i=0;i<tamanho;i++)
		scanf("%i", &vetor[i]);
	printf("O maior valor do vetor %c %i...",130, maior(vetor));
}
