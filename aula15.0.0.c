#include<stdio.h>
#include<string.h>
main()
{
	char string1[100], string2[100], copia[100];
	gets(string1);
	gets(string2);
	if(strlen(string1)==strlen(string2))
		printf("Estas strings possuem o mesmo tamanho!!!");
	else
		puts(strcat(string1, string2));
}
