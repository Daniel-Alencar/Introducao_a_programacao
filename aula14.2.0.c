#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "portuguese");
	char string1[21], string2[21]; int i;
	scanf("%s", string1);
	for(i=0; i<21; i++)
	{
		string2[i]=string1[i];
		if(string1[i]=='\0')
			break;
	}
	printf(string2);
}
