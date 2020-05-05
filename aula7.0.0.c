#include <stdio.h>
main()
{
	int desloca, valor_byte, aux=1;
	printf("Digite um numero pertencente ao intervalo [0,255]: ");
	scanf("%d", &valor_byte);
	printf("Digite o bit a testar (0 a 7): ");
	scanf("%d", &desloca);
	aux = aux << desloca;
	valor_byte = valor_byte & aux;
	valor_byte = valor_byte >> desloca;
	printf("O bit tem valor: %i", valor_byte);
}
