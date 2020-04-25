#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printf_file(char string[], char nome[])
{
	int i;
	FILE *p;
	p = fopen(nome, "w");
	if(!p)
	{
		printf("Erro na abertura do arquivo...");
		exit(1);
	}
	for(i=0;i<strlen(string);i++)
	{
		if(string[i] != (char)putc(string[i], p))
			printf("Erro ao colocar o caractere %c no arquivo...\n", string[i]);
	}
}

int main()
{
	char string[1001], nome[51];
	
	printf("Entre com uma string: ");
	gets(string);
	printf("Nome do arquivo: ");
	gets(nome);
	
	printf_file(string, nome);
}
