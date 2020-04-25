#include<stdio.h>
#include<string.h>
main()
{
	char string1[100], string2[100], string3[100], string4[200];int n, i;
	gets(string1);
	gets(string2);
	n = strlen(string1) - strlen(string2);
	for(i=0;i<=n-1;i++)
	{
		string3[i]=string1[i];
	}
	strcpy(string4, strcat(string3, string2));
	if(!strcmp(string4, string3))
		printf("E");
}
