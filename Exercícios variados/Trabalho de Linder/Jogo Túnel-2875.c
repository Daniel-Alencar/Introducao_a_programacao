/*
OBJETIVO:
Dada uma matriz de caracteres composta por 0s e 1s e um elemento dela sendo 'X'.
Representando os 0s como os "caminhos" que o 'X' pode passar e os 1s como obstáculos
que impedem a passagem do 'X', descreva um caminho na saída padrão.

ESTRATÉGIA:
(A estratégia esta sendo desenvolvida de acordo com a linha de execução do código)
*/

/*
Consideremos mais tarde que:
- vetor_direcional==1, sentido norte
- vetor_direcional==2, sentido sul
- vetor_direcional==3, sentido oeste
- vetor_direcional==4, sentido leste
*/
#include<stdio.h>
/*
Inclusão da biblioteca <stdio.h> que é necessária para a resolução do exercício(printf, scanf etc)
*/
int main()
{
	int l, c, acu, cont, contador_de_x=0, i, j, tem_0, vetor_direcional;
	/*
	Variáveis necessárias para a resolução:
	- l representa a linhas da matriz
	- c representa a colunas da matriz
	- acu é uma acumulador
	- cont é um a acumulador
	- contador_de_x (sua utilidade será apresentada mais para frente)
	- i e j serão os índices da posição onde estará o 'X' informado pelo usuário
	- tem_0 (sua utilidade será apresentada mais para frente)
	- vetor_direcional (sua utilidade será apresentada mais para frente)
	*/
	/*
	Enquanto o que o scanf não chegar no fim do arquivo, 
	a linha de execução sempre estará dentro do while.
	*/
	while(setbuf(stdin, NULL), scanf("%i %i", &l, &c)!=EOF)
	{
		/*
		Cria-se uma matriz de caracteres(vetor de strings)
		de acordo com a quantidade de linhas e colunas fornecidas pelo usuário
		*/
		char matriz[l][c];
		/*
		Nessa parte lê-se cada um dos caracteres informados pelo usuário
		*/
		for(cont=0;cont<l;cont++)
			for(acu=0;acu<c;acu++)
			{
				scanf(" %c", &matriz[cont][acu]);
				/*
				Encontramos onde está o 'X', guardamos sua posição nas variáveis i e j e 
				incrementamos no contador_de_x (Para indicar que o encontramos o 'X').
				*/
				if(matriz[cont][acu]=='X')
				{
					i=cont;
					j=acu;
					contador_de_x++;
				}
			}
		/*
		Entra-se no laço de repetição;
		Basicamente a variável tem_0 vai servir para verificar se 
		ainda resta algum 0 na matriz de caracteres, pois, se tiver 
		pelo menos um 0, quer dizer que o 'X' ainda tem um caminho 
		para percorrer
		*/
		/*
		tem_0 é inicializado com 1(só para entrar no laço de repetição).
		Enquanto tem_0 for maior do que 0, o laço continuará se repetindo.
		*/
		for(tem_0=1;tem_0>0;)
		{
			tem_0=0;
			//Verifica-se se i é diferente de 0 (ou seja, se a linha logo acima onde tem o nosso 'X' 
			//é uma linha que pertence a matriz de caracteres declarada, para que assim não acessemos
			//uma área da memória que não é ocupada pela nossa matriz).
			if(i!=0)
				//Verificamos se acima do nosso 'X' temos um número 0
				if(matriz[i-1][j]=='0')
				{
//(1)				//Se houver, isto significa que temos que fazer com que o 'X' "passe" por aquele 0
					/*
					No entanto, Se for a primeira vez que o X irá se movimentar(contador_de_x==1), significa que ele irá 
					imediatamente para frente sem precisar "virar" para a direita ou para a esquerda.
					Pois, antes da 1ª movimentação o 'X' não tinha nenhuma direção, porém, a partir do momento
					que ele faz essa movimentação (para frente na direção do 0), assumimos que sua direção
					(vetor_direcional) assume o valor 1 (Norte);
					*/
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=1;
					}
					/*
//(2)				Contudo, se não for a 1ª movimentação do 'X', significa que ele já tem uma direção que está "direcionado".
					Então, precisamos testar para saber qual é esta direção...
					*/
					else
					{
						/*
//(3)					vetor_direcional 1 significa que na movimentação anterior do 'X' ele se moveu para o "norte"
						Então, se achamos um outro valor de 0 que está no norte, andamos pra frente sem precisar mudar 
						a direção que estávamos para ir em direção ao 0
						*/
						if(vetor_direcional==1)
							printf("F ");
						/*
//(4)					vetor_direcional 3 significa que na movimentação anterior do 'X' ele se moveu para o "oeste"
						Então, se achamos um valor de 0 que está no norte, primeiramente viramos a direita e andamos 
						pra frente mudando assim a direção em comparação a que estávamos antes, temos que atualizar a
						direção do 'X'(vetor_direcional=1)
						*/
						if(vetor_direcional==3)
						{
							printf("R F ");
							vetor_direcional=1;
						}
						/*
//(5)					vetor_direcional 4 significa que na movimentação anterior do 'X' ele se moveu para o "leste"
						Então, se achamos um valor de 0 que está no norte, primeiramente viramos a esquerda e andamos 
						pra frente mudando assim a direção em comparação a que estávamos antes, temos que atualizar a
						direção do 'X'(vetor_direcional=1)
						*/
						if(vetor_direcional==4)
						{
							printf("L F ");
							vetor_direcional=1;
						}
						/*
//(6)					E quando o vetor_direcional == 2 (ou seja, na movimentação anterior o 'X' foi para o "sul")?
						RESPOSTA = Não tem como isto acontecer, pois isso significaria que:
						- Não é a primeira movimentação do 'X' na matriz.
						- Então isso quer dizer que na movimentação anterior, o 'X' se movimentou para o "sul", ou seja, o 'X'
						estava no "norte" e foi para o "sul"(sendo que isto não é possível, pois no "norte" agora temos o '0' e 
						não temos a indicação de que foi um caminho percorrido(no caso, um 'X')).
						*/
					}
					/*
//(7)				Agora atualizamos os nossos valores:
					- Um 'X' vai para o lugar onde tinha o '0' para se indicar
					que aquele foi um caminho já percorrido
					- contador_de _x indica por quantos "lugares" o 'X' já passou, para que assim
					o 'X' não passe pelo mesmo caminho mais de uma vez
					- Atualizamos a variável i, para que matriz[i][j] represente o caminho que 'X' está exatamente neste momento
					- tem_0 incrementado indicando que encontramos um '0' na posição matriz[i][j]
					*/
					matriz[i-1][j]='X';
					contador_de_x++;
					i=i-1;
					tem_0++;
				}
			//Verifica-se se i é diferente da quantidade de linhas -1 (ou seja, se a linha logo abaixo onde tem o nosso 'X' 
			//é uma linha que pertence a matriz de caracteres declarada, para que assim não acessemos
			//uma área da memória que não é ocupada pela nossa matriz).
			if(i!=l-1)
				//Verificamos se abaixo do nosso 'X' temos um número 0
				if(matriz[i+1][j]=='0')
				{
					//Análogo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=2;
					}
					//Análogo ao (2)
					else
					{
						//Análogo ao (3)
						if(vetor_direcional==2)
							printf("F ");
						//Análogo ao (4)
						if(vetor_direcional==3)
						{
							printf("L F ");
							vetor_direcional=2;
						}
						//Análogo ao (5)
						if(vetor_direcional==4)
						{
							printf("R F ");
							vetor_direcional=2;
						}
						//Análogo ao (6)
					}
					//Análogo ao (7)
					matriz[i+1][j]='X';
					contador_de_x++;
					i=i+1;
					tem_0++;
				}
			//Verifica-se se j é diferente de 0 (ou seja, se a coluna que está a esquerda do nosso 'X' 
			//é uma coluna que pertence a matriz de caracteres declarada, para que assim não acessemos
			//uma área da memória que não é ocupada pela nossa matriz).
			if(j!=0)
				//Verificamos se no lado esquerdo do nosso 'X' temos um número 0
				if(matriz[i][j-1]=='0')
				{
					//Análogo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=3;
					}
					//Análogo ao (2)
					else
					{
						//Análogo ao (3)
						if(vetor_direcional==3)
							printf("F ");
						//Análogo ao (4)
						if(vetor_direcional==1)
						{
							printf("L F ");
							vetor_direcional=3;
						}
						//Análogo ao (5)
						if(vetor_direcional==2)
						{
							printf("R F ");
							vetor_direcional=3;
						}
						//Análogo ao (6)
					}
					//Análogo ao (7)
					matriz[i][j-1]='X';
					contador_de_x++;
					j=j-1;
					tem_0++;
				}
			//Verifica-se se j é diferente do número de colunas - 1 (ou seja, se a coluna que está a direita do nosso 'X' 
			//é uma coluna que pertence a matriz de caracteres declarada, para que assim não acessemos
			//uma área da memória que não é ocupada pela nossa matriz).
			if(j!=c-1)
				//Verificamos se no lado direito do nosso 'X' temos um número 0
				if(matriz[i][j+1]=='0')
				{
					//Análogo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=4;
					}
					//Análogo ao (2)
					else
					{
						//Análogo ao (3)
						if(vetor_direcional==4)
							printf("F ");
						//Análogo ao (4)
						if(vetor_direcional==1)
						{
							printf("R F ");
							vetor_direcional=4;
						}
						//Análogo ao (5)
						if(vetor_direcional==2)
						{
							printf("L F ");
							vetor_direcional=4;
						}
						//Análogo ao (6)
					}
					//Análogo ao (7)
					matriz[i][j+1]='X';
					contador_de_x++;
					j=j+1;
					tem_0++;
				}
			}
		/*
		Como não há nenhum caminho mais a ser percorrido(tem_0==0),
		Chegamos no final do caminho e exibimos E (END).
		*/
		printf("E\n");
		/*
		Zeramos as seguintes variáveis para que o ciclo se inicie novamente.
		*/
		contador_de_x=0;
		tem_0=0;
	}
}
