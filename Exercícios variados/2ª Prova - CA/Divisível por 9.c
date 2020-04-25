#include<stdio.h>
#include<string.h>

int grau=1;

int multiplo(char str[])
{
	int i, tam, soma=0;
	char string[4];
	tam = strlen(str);
	if(tam != 1)
	{
		for(i=0;i<tam;i++)
		{
			soma += str[i] - '0';
		}
		sprintf(string, "%i", soma);
		grau++;
		multiplo(string);
	}
	else
	{
		sscanf(str, "%i", &i);
		return i;
	}
}

main()
{
	char str[51];
	
	gets(str);
	
	if(multiplo(str) == 9)
		printf("O numero %s eh multiplo de 9 e seu grau e %i\n", str, grau);
	else
		printf("o numero %s nao e multiplo de 9\n", str);
}
