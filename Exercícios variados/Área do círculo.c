#include <stdio.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float raio;
	printf("Digite o raio: ");
	scanf("%f", &raio);
		if(raio>=0)
			printf("A área do círculo é : %.4f", 3.14159 * (raio * raio));
		else
			printf("Não tem como ter um valor negativo para o raio...");
}
