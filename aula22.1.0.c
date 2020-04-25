#include<stdio.h>
#include<locale.h>
recursividade(int num)
{
	if(num==1)
		return 1;
	else
		return (num*(recursividade(num-1)));
}
main()
{
	setlocale(LC_ALL, "");
	int num;
	while(1)
	{
		printf("Posição da sequência: ");
		scanf("%i", &num);
		if(!num)
			break;
		printf("%i\n\n", recursividade(num));
	}
	
}
