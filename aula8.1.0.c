#include <stdio.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int idade;
	printf("Qual � a sua idade? ");
	scanf("%i", &idade);
	if (idade<12)
		printf("Voc� � uma crian�a!!!");
	else
		if (idade<=18)
			printf("Voc� � um adolescente!!!");
		else
			printf("Voc� � um adulto!!!");
}
