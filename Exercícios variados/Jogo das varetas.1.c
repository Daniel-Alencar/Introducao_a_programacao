#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int quan=0, varetas=0, soma=0, cont=0;
	float compri=0;
	printf("Quantos comprimentos diferentes de varetas existem? ");
	scanf("%i", &quan);
	if (quan)
	{
	while(cont < quan)
	{
		printf("Qual o comprimento? ");
		scanf("%f", &compri);
		printf("Quantas varetas têm com este comprimento? ");
		scanf("%i", &varetas);
		soma = soma + ((varetas/2)*2);
		cont-=-1;
	}
	printf("%i é o número máximo de retângulos que podem ser formados...", soma/4);
	}
}
