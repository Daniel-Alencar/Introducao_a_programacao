#include<stdio.h>
#include<locale.h>
main()
{
	int n1, n2, quociente, resto;
	setlocale(LC_ALL, "Portuguese");
	do{
	if(n1<0)
		printf("Valor inv�lido...");
	printf("Digite um n�mero natural: \n");
	scanf("%i", &n1);
	}
	while(n1<0);
	do{
	if(n2<2)
		printf("Valor inv�lido...");
	printf("Digite outro n�mero natural: \n");
	scanf("%i", &n2);
	}
	while(n2<0);
	if(!n2){
		printf("Indetermina��o na divis�o...");
		exit(0);
	}
	for(quociente=0; n1>=n2; n1=n1-n2, quociente++);
	resto=n1;
	printf("O quociente da divis�o �: %i\nO resto �: %i ", quociente, resto);
}
