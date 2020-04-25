#include<stdio.h>
#include<string.h>
main()
{
	int matriz[3][4], i, *p, n=1;
	for(i=0, p = matriz; i < 12 ; i++)
		*(p++)=n++;
	for(i=0, p = matriz; i < 12 ; i++){
		printf("|%02d", *(p++));
		if ( (i + 1) % 4 == 0) printf ("|\n");
	}
}
