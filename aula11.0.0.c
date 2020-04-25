#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int c,d,u,num=1, x;
	while(num)
	{
		printf("Digite um número natural de 3 dígitos (EX.: 012)(Digite 0 para parar...)");
		scanf(" %i", &num);
		if (num==0)
			break;
		u = num % 10;
		d = (num % 100)-u;
		c = num - d - u;
		u = u * 100;
		c = c / 100;
		x = c+d+u;
		printf("O número invertido é: %03i\n", x);
	}
}
