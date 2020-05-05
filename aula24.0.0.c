#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *p;
	int i;
	char string[51];
	p = fopen("arquivo.txt", "w");
	if(!p)
	{
		printf("Erro na abertura do arquivo...");
		exit(1);
	}
	printf("Entre com uma string: ");
	gets(string);
	
	for(i=0;i<strlen(string);i++)
	{
		if(string[i] != (char)putc(string[i], p))
			printf("Erro ao colocar o caractere %c no arquivo...\n", string[i]);
	}
}
