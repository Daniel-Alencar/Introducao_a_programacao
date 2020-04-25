#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "portuguese");
	char string[100];int i=0;
	scanf("%s", &string);
	while(string[i] != '\0')
		i++;
	printf("\nHá %i caracteres na string!!!", i);
}
