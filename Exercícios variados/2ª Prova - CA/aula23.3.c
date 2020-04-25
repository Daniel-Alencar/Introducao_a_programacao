#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x=1, i, c, *numeros=0;
	scanf("%i", &x);
	while(x)
	{
		numeros=0;
		if(!x)
			scanf("%i", &x);
		for(i=1;x;i++)
		{
			numeros = (int*)realloc(numeros, i*sizeof(int));
			*(numeros+i-1) = x;
			scanf("%i", &x);
		}
		i=i-1;
		
		printf("Vetor = {");
		for(c=0;c<i;c++)
		{
			if(i==c+1)
				printf("%i}\n", *(numeros+c));
			else
				printf("%i, ", *(numeros+c));
		}
		free(numeros);
		scanf("%i", &x);
	}
}
