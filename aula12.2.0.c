#include <stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int mdc=1, n1, n2, divisor=2;
	printf("Digite um n�mero: ");
	scanf("%i", &n1);
	printf("Digite outro n�mero: ");
	scanf("%i", &n2);
	while(!(n1 == 1 && n2 == 1))
	{
		if ((n1 % divisor == 0) || (n2 % divisor == 0))
		{
			if(n1 % divisor == 0)
				if(n2 % divisor == 0)
					mdc = mdc * divisor;
			if(n1 % divisor == 0)
				n1 = n1 / divisor;
			if(n2 % divisor == 0)
				n2 = n2 / divisor;
		}
		else
			divisor++;
	}
	printf("O MDC entres os n�meros �: %i", mdc);
}
