#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int c,d,u,num=1, x;
	while(num)
	{
		printf("Digite um n�mero natural de 3 d�gitos (EX.: 012)(Digite 0 para parar...)");
		scanf(" %i", &num);
		if (num==0)
			break;
		u = num % 10;
		d = (num % 100)-u;
		c = num - d - u;
		u = u * 100;
		c = c / 100;
		x = c+d+u;
		printf("O n�mero invertido �: %03i\n", x);
	}
}
