#include <stdio.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int idade;
	printf("Qual é a sua idade? ");
	scanf("%i", &idade);
	if (idade<12)
		printf("Você é uma criança!!!");
	else
		if (idade<=18)
			printf("Você é um adolescente!!!");
		else
			printf("Você é um adulto!!!");
}
