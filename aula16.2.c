#include<stdio.h>
main()
{
	float matriz[7][4];int i, j;
	for(i=0;i<7;i++)
		for(j=0;j<4;j++)
			scanf("%f", &matriz[i][j]);
	for(i=0;i<7;i++)
	{
		printf("\n|");
		for(j=0;j<4;j++)
			printf("%10.2f", matriz[i][j]);
		printf(" |");
	}
}
