#include<stdio.h>
void troca(int aux,int *a,int *b)
{
	aux=*a;
	*a=*b;
	*b=aux;
}
main()
{
	int num1, num2, aux;
	scanf("%i %i", &num1, &num2);
	troca(aux ,&num1,&num2);
	printf ("\nValor dos numeros depois da chamada da funcao: %i, %i... ", num1, num2);
}
