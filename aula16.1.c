#include<stdio.h>
main()
{
	char string1[100], string2[100], parte[100];int i, n;
	gets(string1);
	gets(string2);
	n = strlen(string1)-strlen(string2);
	for(i=0;i<n;i++)
	{
		parte[i]=string1[i];
	}
	strcat(parte, string2);
	if(!strcmp(string1, parte))
		printf("SIM, O FINAL DA 2º MATRIZ ESTÁ CONTIDA NO FINAL DA 1º");
}
