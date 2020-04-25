#include<stdio.h>
#include<stdlib.h>
main()
{
	int l, c, i;
	char *strings;
	scanf("%i %i", &l, &c);
	
	strings = (char*)calloc(l*(c+1), sizeof(char));
	
	if(!strings)
	{
		printf("Não há espaço suficiente para alocar...\n");
		return 0;
	}
	for(i=0;i<l;i++)
	{
		setbuf(stdin, NULL);
		scanf("%[^\n]", strings+(i*(c+1)));
	}
	
	for(i=0;i<l;i++)
		printf("%s\n",(strings+(i*(c+1))));
}
