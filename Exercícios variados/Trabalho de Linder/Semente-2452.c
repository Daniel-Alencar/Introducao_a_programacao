
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	int comprimento, gotas, i, maior_d1=0, maior_d2=0, *posicao_gotas;
	scanf("%i %i", &comprimento, &gotas);
	
	posicao_gotas = (int*)calloc(gotas, sizeof(int));
	for(i=0;i<gotas;i++)
		scanf("%i", &posicao_gotas[i]);
	
	for(i=1;i<gotas;i++)
		if((posicao_gotas[i] - posicao_gotas[i-1]) > maior_d1)
			maior_d1 = (posicao_gotas[i] - posicao_gotas[i-1]);
	
	maior_d2 = posicao_gotas[0] - 1;
	if(((comprimento) - posicao_gotas[gotas - 1]) > maior_d2)
		maior_d2 = (comprimento) - posicao_gotas[gotas - 1];
	
	if((maior_d1)/2 > maior_d2)
	
		printf("%i\n", (maior_d1)/2);
	else
		printf("%i\n", maior_d2);
}
