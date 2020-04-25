#include<stdio.h>
#include<string.h>

int grau=1;

int multiplo(char str[])
{
	int i, tam, soma=0;
	char str1[4];
	strcpy(str1, str);
	tam = strlen(str1);
	if(tam != 1)
		for(i=0;i<tam;i++)
		{
			soma += str1[i] - '0';
			sprintf(str1, "%i", soma);
			grau++;
			multiplo(str1);
		}
	else
	{
		sscanf(str1, "%i", &i);
		return i;
	}
}

main()
{
	char str[51];
	int n;
	
	gets(str);
	n = multiplo(str);
	
	if(n == 9)
		printf("o número %s é múltiplo de 9 e seu grau é %i\n", str, grau);
	else
		printf("o número %s não é múltiplo de 9\n", str);
}
