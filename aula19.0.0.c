#include<stdio.h>
int EDivisivel(int a, int b)
{
	if(a%b==0)
		return 1;
	else
		return 0;
}
main()
{
	int a, b;
	scanf("%i %i", &a, &b);
	if(EDivisivel(a,b))
		printf("%i é divisivel por %i...", a,b);
	else
		printf("%i não é divisivel por %i...", a,b);
}
