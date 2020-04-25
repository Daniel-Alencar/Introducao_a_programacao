#include<stdio.h>
#define n 18
int i=0;
void inversao(int vetor[])
{
	int aux;
	if(i<(n/2))
	{
		aux=*(vetor+i);
		*(vetor+i)=*(vetor+(n-1)-i);
		*(vetor+(n-1)-i)=aux;
		i++;
		inversao(vetor);
	}
	else
		return 0;
}
main()
{
	int c=0, vetor[n];
	for(c=0;c<n;c++){
		printf("vetor[%i]: ", c+1);
		scanf("%i", &vetor[c]);
	}
	inversao(vetor);
	for(c=0;c<n;c++)
		printf("%i...", vetor[c]);
}
