#include <stdio.h>
#include<math.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num, raiz;
	for(;1;)
	{
		do
		{
			printf("Digite um n�mero natural: ");
			scanf("%i", &num);
			if(num<0)
				printf("valor inv�lido...");
			else
				if(num==0)
					exit(0);
		}
		while(num<=0);
		raiz=sqrt(num);
		if(pow(raiz, 2) == num)
		{
			printf("%i � um quadrado perfeito!!!\n\n", num);
		}
		else
			printf("%i n�o � um quadrado perfeito!!!\n\n", num);
	}
}
