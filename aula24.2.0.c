#include<stdio.h>
main()
{
	FILE *p;
	p = fopen("Daniel.txt", "r");
	printf("%c\n", getc(p));
}

#include <stdio.h>
int main()
{
	FILE *fp;
	int c;
	fp = fopen("arquivo.txt","r");
	if(!fp)
	{
		printf( "Erro na abertura do arquivo");
		exit(1);
	}
	while((c = getc(fp) ) != EOF)
	printf("%c", (char)c);
	fclose(fp);
	return 0;
}
