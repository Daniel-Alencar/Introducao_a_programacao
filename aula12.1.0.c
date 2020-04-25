#include <stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int mmc=1, n1, n2, divisor=2;
	printf("Digite um número: ");
	scanf("%i", &n1);
	printf("Digite outro número: ");
	scanf("%i", &n2);
	while(!(n1 == 1 && n2 == 1))
	{
		if ((n1 % divisor == 0) || (n2 % divisor == 0))
		{
			if(n1 % divisor == 0)
				n1 = n1 / divisor;
			if(n2 % divisor == 0)
				n2 = n2 / divisor;
			mmc = mmc * divisor;
		}
		else
			divisor++;
	}
	printf("O MMC entres os números é: %i", mmc);
}
