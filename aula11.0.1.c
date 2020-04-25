#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	while(num){
	printf("Digite um número positivo inteiro de 3 dígitos (Digite 0 para sair): ");
	scanf("%i", &num);
	if(num)
		printf("O número invertido é :%03i\n", (num%10)*100 + (num%100)-(num%10) + (num/100));}

}
