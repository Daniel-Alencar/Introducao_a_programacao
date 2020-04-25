#include <stdio.h>
#include<locale.h>
main()
{
	int num, cont;
	unsigned int fatorial=1;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o valor que você quer ver o fatorial: ");
	setbuf(stdin, NULL);
	scanf("%i", &num);
	if(num>=0)
	{
		cont = num;
		printf("%i! = ", num);
		while(cont)
		{
			if(cont == 1)
			{
				printf("1 = ");
			}
			else
			{
				printf("%i x ", cont);
				fatorial = fatorial * cont;
			}
			cont-=1;
		}
		printf("%i", fatorial);
	}
	else
		printf("Não há fatorial para um número negativo...");
}
