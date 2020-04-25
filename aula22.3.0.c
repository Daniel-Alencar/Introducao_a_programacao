#include<stdio.h>

typedef struct
{
	char nome[21];
	char nasc[11];
	int matricula;
	int cpf;
	float rendimento;
}aluno;

inicia(aluno inf[]);
imprimir_cpf(aluno inf[], int cpf);
imprimir_posicao(aluno inf[], int posicao);

main()
{
	aluno inf[5];
	int opcao, cpf, posicao;
	inicia(inf);
	printf("Você quer imprimir o regitro com base ...\n[ 1 ] no CPF\n[ 2 ] na posição\nEscolha [ ]\b\b");
	scanf("%i", &opcao);
	
	switch(opcao)
	{
		case 1:
			scanf("%i", &cpf);
			imprimir_cpf(inf, cpf);
			break;
		case 2:
			scanf("%i", &posicao);
			imprimir_posicao(inf, posicao);
			break;
		default:
			break;
			
	}
}

inicia(aluno inf[])
{
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%20s", inf[i].nome);
		scanf("%11s", inf[i].nasc);
		scanf("%i", &inf[i].matricula);
		scanf("%i", &inf[i].cpf);
		scanf("%f", &inf[i].rendimento);
	}
}

imprimir_cpf(aluno inf[], int cpf)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(cpf==inf[i].cpf)
		{
			printf("--------------------------------\n");
			printf("%s\n", inf[i].nome);
			printf("%s\n", inf[i].nasc);
			printf("%i\n", inf[i].matricula);
			printf("%i\n", inf[i].cpf);
			printf("%.2f\n", inf[i].rendimento);
			printf("--------------------------------\n");
		}
	}
}

imprimir_posicao(aluno inf[], int posicao)
{
	printf("--------------------------------\n");
	printf("%s\n", inf[posicao-1].nome);
	printf("%s\n", inf[posicao-1].nasc);
	printf("%i\n", inf[posicao-1].matricula);
	printf("%i\n", inf[posicao-1].cpf);
	printf("%.2f\n", inf[posicao-1].rendimento);
	printf("--------------------------------\n");
}
