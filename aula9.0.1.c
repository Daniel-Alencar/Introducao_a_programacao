#include <stdio.h>
main()
{
	int n1,n2,resultado;
	char opcao;
	printf("\nEntre com o primeiro valor inteiro: ");
	scanf("%d",&n1);
	printf("\nEntre com o segundo valor inteiro: ");
	scanf("%d",&n2);
	printf("Digite:\n1 -para somar os inteiros\n2 -para subtrair os inteiros\n3 -para multiplicar os inteiros\n");
	printf("4 -para dividir os inteiros\nOpcao: ");
	setbuf(stdin, NULL);
	scanf("%c",&opcao);
	switch (opcao)
	{
		case '1' : 
			resultado=n1+n2;
			break;
		case '2' : 
			resultado=n1-n2;
			break;
		case '3' : 
			resultado=n1*n2;
			break;
		case '4' : 
			if (n2)
				resultado=n1/n2;
			else
			{
				printf("Divisao por zero!");
				exit(2);
			}
			break;
		default: 
			printf("Opcao invalida!");
			exit(1);
	}
	printf("\nO resultado da operacao foi %d\n",resultado);
}
