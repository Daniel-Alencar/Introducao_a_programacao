#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL,"");
	float x, conta;
	printf("Digite um valor para x: ");
	scanf("%f", &x);
	printf("O resultado da expressão v((3+x)³ * 5)\nSendo x = %.2f é...\n", x);
	conta=("%f", x+3);
	conta=pow(conta, 3);
	conta=conta*5;
	conta=sqrt(conta);
	printf("%.2f", conta);
}
