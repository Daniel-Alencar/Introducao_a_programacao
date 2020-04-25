#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, i, c, *numeros=0;
	for(i=1 ; scanf("%i", &x), x ; i++)
	{
		numeros = (int*)realloc(numeros, i*sizeof(int));
		*(numeros+i-1) = x;
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
}
