#include<stdio.h>
#include<locale.h>
main()
{
	setlocale(LC_ALL, "Portuguese");
	float n1, n2, media, maior;
	unsigned int alunos, cont=1;
	printf("Quantos alunos têm em sua sala? ");
	scanf("%i", &alunos);
	printf("------------------------------------------------------------\n");
	while(cont<=alunos)
	{
		printf("Digite a 1º nota do(a) %iº aluno(a): ", cont);
		scanf("%f", &n1);
		printf("Digite a 2º nota do(a) %iº aluno(a): ", cont);
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
	printf("\nA maior média da classe foi: %.2f", maior);
}
