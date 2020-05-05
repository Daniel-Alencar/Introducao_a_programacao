#include<stdio.h>
#include<stdlib.h>
main()
{
	int l, c, i;
	float *matriz;
	scanf("%i %i", &l, &c);
	
	matriz=(float*)malloc(l*c*sizeof(float));
	
	if(matriz==NULL)
	{
		printf("Não há espaço suficiente para alocar...\n");
		return 0;
	}
	for(i=0;i<l*c;i++)
		scanf("%f", matriz+i);
	for(i=0;i<l*c;i++)
	{
		if((i+1) % c == 0)
			printf("%.2f\n", *(matriz+i));
		else
			printf("%.2f  ", *(matriz+i));
	}
}
