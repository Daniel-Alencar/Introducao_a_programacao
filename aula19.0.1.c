#include<stdio.h>
int EDivisivel(int a, int b){
	return(a%b?0:1);}
main()
{
	int a, b;
	printf("Digite um valor para a: ");
	scanf("%i",&a);
	do{
	printf("Digite um valor para b [diferente de 0]: ");
	scanf("%i", &b);
	}
	while(!b);
	if(EDivisivel(a,b))
		printf("%i é divisivel por %i...", a,b);
	else
		printf("%i não é divisivel por %i...", a,b);
	/*OU*/
	printf("\n\"a\"%seh divisivel por \"b\"",EDivisivel(a,b)?" ":" nao ");

}
