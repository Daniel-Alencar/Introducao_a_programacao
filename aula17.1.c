#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	char matriz[5][100], vetor[100];int i, posicao=-1;
	printf("Digite 5 strings:\n");
	for(i=0;i<5;i++)
	{
		scanf("%s", matriz[i]);
	}
	printf("\nvetor de verificação:\n");
	scanf("%s", vetor);
	for(i=0;i<5;i++)
		if(!strcmp(matriz[i], vetor))
			posicao=i;
	if(posicao!=-1)
		printf("\n\nHá uma string igual na matriz...\nA posição da string na matriz é: matriz[%i]", posicao);
	else
		printf("\n\nNão há nenhuma string igual na matriz!!!");
}
