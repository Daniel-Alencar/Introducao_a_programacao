#include<stdio.h>
#include<math.h>
#include<locale.h>
main()
{
	int n1, n2, a, b, quociente, resto;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite um n�mero: \n");
	scanf("%i", &n1);
	printf("Digite outro n�mero: \n");
	scanf("%i", &n2);
	if(!n2){
		printf("Indetermina��o na divis�o...");
		exit(1);
	}
	a=n1;
	b=n2;
	for(quociente=0; abs(n1)>=abs(n2); n1=abs(n1)-abs(n2), quociente++);
	if((a>=0 && b<0) || (a<=0 && b>0))
		quociente=0-quociente;
	if(a<=0)
		resto=0-n1;
	if(abs(a)<abs(b))
		resto=a;
	printf("O quociente da divis�o �: %i\nO resto �: %i ", quociente, resto);
}
