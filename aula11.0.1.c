#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	while(num){
	printf("Digite um n�mero positivo inteiro de 3 d�gitos (Digite 0 para sair): ");
	scanf("%i", &num);
	if(num)
		printf("O n�mero invertido � :%03i\n", (num%10)*100 + (num%100)-(num%10) + (num/100));}

}
