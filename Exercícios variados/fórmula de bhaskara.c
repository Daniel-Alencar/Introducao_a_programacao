#include <stdio.h>
#include <math.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float a, b, c, x1, x2;
	printf("Digite os valores de a, b e c para calcularmos suas ra�zes...\n");
	scanf("%f%f%f", &a, &b, &c);
	x1 = ((-1*b) - sqrt(pow(b, 2) + (-4*(a*c))))/(2*a);
	x2 = ((-1*b) + sqrt(pow(b, 2) + (-4*(a*c))))/(2*a);
	if ((pow(b, 2) + (-4*(a*c))) >= 0 && a!=0)
	{
		if ((pow(b, 2) + (-4*(a*c))) > 0)
		{
		printf("x tem dois valores poss�veis...\nx1 = %.5f e x2 = %.5f!", x1, x2);
		}
		else
		printf("O valor de x � %.5f", x1);
	}
	else
		printf("N�o h� uma ra�z real existente para os valores dados...");
}
