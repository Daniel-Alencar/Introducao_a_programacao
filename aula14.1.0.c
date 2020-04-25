#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "portuguese");
	char string1[100], string2[100], string3[100];int i;
	scanf("%s %s %s", string1, string2, string3);
	i=0;
	while(string1[i] != '\0')
		i++;
	printf("\nHá %i caracteres na string1!!!", i);
	i=0;
	while(string2[i] != '\0')
		i++;
	printf("\nHá %i caracteres na string2!!!", i);
	i=0;
	while(string3[i] != '\0')
		i++;
	printf("\nHá %i caracteres na string3!!!", i);
}
