
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Inclusão das bibliotecas necessárias para a resolução do exercício
*/
int compara( const void *, const void *);
int func(void *p1, void *p2);
/*Protótipo de uma função que usaremos mais tarde*/

struct Aluno
{
	char nome[100];
	char cor[9];
	char tam;
}; 
/*criação do tipo struct Aluno
*/

int main()
{
	int camisetas, i;
	struct Aluno *p1, *p2;
	
	
	scanf("%i\n", &camisetas);
	/*
	camisetas representa o número de camisetas para serem feitas para aquela turma
	O número de camisetas não pode ser 0, porque senão o programa já vai parar
	*/
	while(camisetas)
	{
		struct Aluno aluno[camisetas];
		/*
		vetor do tipo: struct Aluno
		vetor de quantidade: camisetas
		*/
		for(i=0;i<camisetas;i++)
		{
			/*
			Nesta parte do código, apenas o usuário informa o nome da pessoa,
			a cor da camisa que ela prefere e o tamanho da camisa que ela pediu
			*/
			scanf(" %[^\n]", aluno[i].nome);
			scanf(" %s %c", &aluno[i].cor, &aluno[i].tam);
		}
		/*
		qsort é uma função que recebe como parâmetros:
		- o nome do vetor/struct(que é um ponteiro para o 1º elemento) a ser organizado
		- a quantidade de elementos que tem esse vetor/struct
		- tamanho em bytes de cada elemento do vetor/struct
		- uma função de comparação que o programador cria para organizar do jeito
		que o mesmo prefere.
		*/
		p1 = aluno;
		p2 = aluno + (camisetas -1);
		func(p1,p2);
		//Printa-se os valores do struct já organizados pela função anterior
		for(i=0;i<camisetas;i++)
			printf("%s %c %s\n", aluno[i].cor, aluno[i].tam, aluno[i].nome);
		//Leio o número de camisetas mais uma vez
        scanf("%i\n", &camisetas);
        /*
        Se o número de camisetas informado for 0, a linha de execução sai do while
        e logo depois o programa para por causa do return 0;
        Se não for 0, continua a execução no while.
        */
        if(!camisetas)
			break;
        printf("\n");
	}
	return 0;
}

int func(void *p1, void *p2)
{
	p1=(struct Aluno*)p1;
	p2=(struct Aluno*)p2;
	int trocas=0;
	char aux1[100];
	char aux2[9];
	char aux3;
	int resultado;
	
	while(p1!=p2)
	{
		resultado = compara(p1, p2);
		if(resultado>0)
		{
			strcpy(aux1, (*p1).nome);
			strcpy(aux2, (*p1).cor);
			aux3 = (*p1).tam;
			
			strcpy((*p1).nome, (*p2).nome);
			strcpy((*p1).cor, (*p2).cor);
			(*p1).tam = (*p2).tam;
			
			strcpy((*p2).nome, aux1);
			strcpy((*p2).cor, aux2);
			(*p2).tam = aux3;
			
			trocas++;
			
			p1=p2;
			if(trocas % 2 != 0)
				p2=p1+1;
			else
				p2=p1-1;
		}
		else
			if(trocas % 2 != 0)
				p2=p2+1;
			else
				p2=p2-1;
	}
	if(trocas)
	{
		p1=aluno;
		p2=p2-1;
		func(p1,p2);
		
		p1=p1+1;
		p2=aluno + (camisetas -1);
		func(p1,p2);
	}
	else
		return 0;
}



/*
Função compara(que é usada como parâmetro) para a função qsort

É const void porque os ponteiros são constantes dentro da função(ou seja,
não vão ser alterados).
*/
int compara(const void *p1, const void *p2)
{
	struct Aluno *i, *j;
	/*
	i e j serão ponteiros que apontam
	para diferentes elementos do vetor aluno[n].
	Assim, os endereços referenciados de i e j mudam (através da função "qsort")
	após cada comparação e mudança de posições que foi determinada na função compara.
	*/
	int teste;
	i = (struct Aluno *)p1;
	j = (struct Aluno *)p2;
	/*
	Foi necessário fazer a conversão do ponteiro para o tipo struct Aluno
	para que aí sim ele pudesse "apontar" para o vetor que eu tenho como tipo struct Aluno
	*/
	
	/*
	i->cor == (*i).cor
	j->cor == (*j).cor
	i->cor == (*i).tam
	j->cor == (*j).tam
	i->cor == (*i).nome
	j->cor == (*j).nome
	*/
	teste = strcmp((*i).cor, (*j).cor);
	/*
	Somente se as cores(dos elementos que estou comparando) forem iguais
	que eu ordeno o vetor de struct em relação ao tamanho das camisetas
	*/
	if(teste==0)
	{
		/*
		Verificando a ordem que a variável "tam" aparece, para podermos organizar
		*/
		if((*i).tam > (*j).tam)
		{
			return -1;
			/*
			Nos indexamentos "cor" e "nome" quero que seja em ordem crescente
			(exatamente do jeito como a função compara está definida):
			
			EX.:Então, sendo a, b elementos que pertencem ao {branco, vermelho};
				 Eu quero que se a>b: return 1 e a<b: return -1
			
			No caso do "tam" eu quero que seja ao contrário, em vez de ser em ordem crescente,
			quero que seja na ordem descrescente:
			
			EX.: G vem de antes de M que vem antes de P, porém eu quero exatamente nessa ordem(P,M e depois G).
				 Então, sendo a, b elementos que pertencem ao {P, M, G};
				 Eu quero que se a>b: return -1 e a<b: return 1
				 Ao invés de que a>b: return 1 e a<b: return -1
			*/
		}
		else
		{
			if((*i).tam < (*j).tam)
			{
				return 1;
			}
			else
			/*
			Somente se os tamanhos das camisetas(dos elementos que estou comparando)
			forem iguais que eu ordeno o vetor de struct em relação ao nome...
			*/
			{
				return strcmp((*i).nome, (*j).nome);
			}
		}
	}
	else
		/*
		Quando as cores(dos elementos que estou comparando) forem diferentes
		ordenamos o vetor de struct em relação as cores das camisetas(cor)
		*/
		return strcmp((*i).cor, (*j).cor);
}
