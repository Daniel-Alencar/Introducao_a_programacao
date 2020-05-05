#include<stdio.h>
main()
{
	int matriz[5][5], l, c, soma=0, maiorc=0, maiorl=0;
	for(l=0;l<5;l++)
		for(c=0;c<5;c++)
			do{
			scanf("%i", &matriz[l][c]);
			}while(matriz[l][c]<0);
	for(l=0;l<5;l++)
		for(c=0;c<5;c++)
		{
			if(l>c)
				soma=soma+matriz[l][c];
		}
	printf("%i", soma);
}
