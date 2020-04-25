#include<stdio.h>
main()
{
	char string1[100], string2[100];
	gets(string1);
	gets(string2);
	if(strlen(string1)==strlen(string2))
	{
		if(!strcmp(string1, string2))
			printf("As strings são idênticas!");
	}
	else
	{
		strcat(string1, string2);
		puts(string1);
	}
}
