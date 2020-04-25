#include<stdio.h>
#include<string.h>
main()
{
	int n, i, j, cont=0, tam, comida=0, maior;
	scanf("%i", &n);
	char matriz[n][n+1];
	for(i=0;i<n;i++)
	{
		scanf(" %s", matriz[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(cont % 2 ==0)
		{
			tam = strlen(matriz[i]);
			for(j=0;j<tam;j++)
			{
				if(matriz[i][j] == 'o')
				{
					comida++;
					if(comida>maior)
						maior = comida;
				}
				if(matriz[i][j] == 'A')
				{
					comida=0;
				}
			}
		}
		else
		{
			tam = strlen(matriz[i]);
			for(j=tam;j>=0;j--)
			{
				if(matriz[i][j] == 'o')
				{
					comida++;
					if(comida>maior)
						maior = comida;
				}
				if(matriz[i][j] == 'A')
				{
					comida=0;
				}
			}
		}
		cont++;
	}
	printf("%i\n", maior);
	
}
