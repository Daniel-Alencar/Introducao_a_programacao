#include <stdio.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int desloca, valor_byte, aux=1;
	printf("Digite um número pertencente ao intervalo [0,255]: ");
	scanf("%d", &valor_byte);
	printf("Digite o bit a testar(0 a 7): ");
	scanf("%d", &desloca);
	aux = aux << desloca;
	valor_byte = valor_byte & aux;
	if (valor_byte)
		printf("O bit está ativado!!!");
	else
		printf("O bit está desativado!!!");
}
