#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float n1, n2, media, maior;
	unsigned int alunos, cont=1;
	printf("Quantos alunos t�m em sua sala? ");
	scanf("%i", &alunos);
	printf("------------------------------------------------------------\n");
	while(cont<=alunos)
	{
		printf("Digite a 1� nota do(a) %i� aluno(a): ", cont);
		scanf("%f", &n1);
		printf("Digite a 2� nota do(a) %i� aluno(a): ", cont);
		scanf("%f", &n2);
		printf("\n");
		media=(n1+n2)/2;
		if(cont==1)
			maior = media;
		else
		{
			if(media > maior)
				maior = media;
		}
		cont++;
	}
	printf("------------------------------------------------------------\n");
	printf("\nA maior m�dia da classe foi: %.2f", maior);
}
