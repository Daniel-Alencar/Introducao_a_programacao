/*
OBJETIVO:
Dada uma matriz de caracteres composta por 0s e 1s e um elemento dela sendo 'X'.
Representando os 0s como os "caminhos" que o 'X' pode passar e os 1s como obst�culos
que impedem a passagem do 'X', descreva um caminho na sa�da padr�o.

ESTRAT�GIA:
(A estrat�gia esta sendo desenvolvida de acordo com a linha de execu��o do c�digo)
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
Inclus�o da biblioteca <stdio.h> que � necess�ria para a resolu��o do exerc�cio(printf, scanf etc)
*/
int main()
{
	int l, c, acu, cont, contador_de_x=0, i, j, tem_0, vetor_direcional;
	/*
	Vari�veis necess�rias para a resolu��o:
	- l representa a linhas da matriz
	- c representa a colunas da matriz
	- acu � uma acumulador
	- cont � um a acumulador
	- contador_de_x (sua utilidade ser� apresentada mais para frente)
	- i e j ser�o os �ndices da posi��o onde estar� o 'X' informado pelo usu�rio
	- tem_0 (sua utilidade ser� apresentada mais para frente)
	- vetor_direcional (sua utilidade ser� apresentada mais para frente)
	*/
	/*
	Enquanto o que o scanf n�o chegar no fim do arquivo, 
	a linha de execu��o sempre estar� dentro do while.
	*/
	while(setbuf(stdin, NULL), scanf("%i %i", &l, &c)!=EOF)
	{
		/*
		Cria-se uma matriz de caracteres(vetor de strings)
		de acordo com a quantidade de linhas e colunas fornecidas pelo usu�rio
		*/
		char matriz[l][c];
		/*
		Nessa parte l�-se cada um dos caracteres informados pelo usu�rio
		*/
		for(cont=0;cont<l;cont++)
			for(acu=0;acu<c;acu++)
			{
				scanf(" %c", &matriz[cont][acu]);
				/*
				Encontramos onde est� o 'X', guardamos sua posi��o nas vari�veis i e j e 
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
		Entra-se no la�o de repeti��o;
		Basicamente a vari�vel tem_0 vai servir para verificar se 
		ainda resta algum 0 na matriz de caracteres, pois, se tiver 
		pelo menos um 0, quer dizer que o 'X' ainda tem um caminho 
		para percorrer
		*/
		/*
		tem_0 � inicializado com 1(s� para entrar no la�o de repeti��o).
		Enquanto tem_0 for maior do que 0, o la�o continuar� se repetindo.
		*/
		for(tem_0=1;tem_0>0;)
		{
			tem_0=0;
			//Verifica-se se i � diferente de 0 (ou seja, se a linha logo acima onde tem o nosso 'X' 
			//� uma linha que pertence a matriz de caracteres declarada, para que assim n�o acessemos
			//uma �rea da mem�ria que n�o � ocupada pela nossa matriz).
			if(i!=0)
				//Verificamos se acima do nosso 'X' temos um n�mero 0
				if(matriz[i-1][j]=='0')
				{
//(1)				//Se houver, isto significa que temos que fazer com que o 'X' "passe" por aquele 0
					/*
					No entanto, Se for a primeira vez que o X ir� se movimentar(contador_de_x==1), significa que ele ir� 
					imediatamente para frente sem precisar "virar" para a direita ou para a esquerda.
					Pois, antes da 1� movimenta��o o 'X' n�o tinha nenhuma dire��o, por�m, a partir do momento
					que ele faz essa movimenta��o (para frente na dire��o do 0), assumimos que sua dire��o
					(vetor_direcional) assume o valor 1 (Norte);
					*/
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=1;
					}
					/*
//(2)				Contudo, se n�o for a 1� movimenta��o do 'X', significa que ele j� tem uma dire��o que est� "direcionado".
					Ent�o, precisamos testar para saber qual � esta dire��o...
					*/
					else
					{
						/*
//(3)					vetor_direcional 1 significa que na movimenta��o anterior do 'X' ele se moveu para o "norte"
						Ent�o, se achamos um outro valor de 0 que est� no norte, andamos pra frente sem precisar mudar 
						a dire��o que est�vamos para ir em dire��o ao 0
						*/
						if(vetor_direcional==1)
							printf("F ");
						/*
//(4)					vetor_direcional 3 significa que na movimenta��o anterior do 'X' ele se moveu para o "oeste"
						Ent�o, se achamos um valor de 0 que est� no norte, primeiramente viramos a direita e andamos 
						pra frente mudando assim a dire��o em compara��o a que est�vamos antes, temos que atualizar a
						dire��o do 'X'(vetor_direcional=1)
						*/
						if(vetor_direcional==3)
						{
							printf("R F ");
							vetor_direcional=1;
						}
						/*
//(5)					vetor_direcional 4 significa que na movimenta��o anterior do 'X' ele se moveu para o "leste"
						Ent�o, se achamos um valor de 0 que est� no norte, primeiramente viramos a esquerda e andamos 
						pra frente mudando assim a dire��o em compara��o a que est�vamos antes, temos que atualizar a
						dire��o do 'X'(vetor_direcional=1)
						*/
						if(vetor_direcional==4)
						{
							printf("L F ");
							vetor_direcional=1;
						}
						/*
//(6)					E quando o vetor_direcional == 2 (ou seja, na movimenta��o anterior o 'X' foi para o "sul")?
						RESPOSTA = N�o tem como isto acontecer, pois isso significaria que:
						- N�o � a primeira movimenta��o do 'X' na matriz.
						- Ent�o isso quer dizer que na movimenta��o anterior, o 'X' se movimentou para o "sul", ou seja, o 'X'
						estava no "norte" e foi para o "sul"(sendo que isto n�o � poss�vel, pois no "norte" agora temos o '0' e 
						n�o temos a indica��o de que foi um caminho percorrido(no caso, um 'X')).
						*/
					}
					/*
//(7)				Agora atualizamos os nossos valores:
					- Um 'X' vai para o lugar onde tinha o '0' para se indicar
					que aquele foi um caminho j� percorrido
					- contador_de _x indica por quantos "lugares" o 'X' j� passou, para que assim
					o 'X' n�o passe pelo mesmo caminho mais de uma vez
					- Atualizamos a vari�vel i, para que matriz[i][j] represente o caminho que 'X' est� exatamente neste momento
					- tem_0 incrementado indicando que encontramos um '0' na posi��o matriz[i][j]
					*/
					matriz[i-1][j]='X';
					contador_de_x++;
					i=i-1;
					tem_0++;
				}
			//Verifica-se se i � diferente da quantidade de linhas -1 (ou seja, se a linha logo abaixo onde tem o nosso 'X' 
			//� uma linha que pertence a matriz de caracteres declarada, para que assim n�o acessemos
			//uma �rea da mem�ria que n�o � ocupada pela nossa matriz).
			if(i!=l-1)
				//Verificamos se abaixo do nosso 'X' temos um n�mero 0
				if(matriz[i+1][j]=='0')
				{
					//An�logo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=2;
					}
					//An�logo ao (2)
					else
					{
						//An�logo ao (3)
						if(vetor_direcional==2)
							printf("F ");
						//An�logo ao (4)
						if(vetor_direcional==3)
						{
							printf("L F ");
							vetor_direcional=2;
						}
						//An�logo ao (5)
						if(vetor_direcional==4)
						{
							printf("R F ");
							vetor_direcional=2;
						}
						//An�logo ao (6)
					}
					//An�logo ao (7)
					matriz[i+1][j]='X';
					contador_de_x++;
					i=i+1;
					tem_0++;
				}
			//Verifica-se se j � diferente de 0 (ou seja, se a coluna que est� a esquerda do nosso 'X' 
			//� uma coluna que pertence a matriz de caracteres declarada, para que assim n�o acessemos
			//uma �rea da mem�ria que n�o � ocupada pela nossa matriz).
			if(j!=0)
				//Verificamos se no lado esquerdo do nosso 'X' temos um n�mero 0
				if(matriz[i][j-1]=='0')
				{
					//An�logo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=3;
					}
					//An�logo ao (2)
					else
					{
						//An�logo ao (3)
						if(vetor_direcional==3)
							printf("F ");
						//An�logo ao (4)
						if(vetor_direcional==1)
						{
							printf("L F ");
							vetor_direcional=3;
						}
						//An�logo ao (5)
						if(vetor_direcional==2)
						{
							printf("R F ");
							vetor_direcional=3;
						}
						//An�logo ao (6)
					}
					//An�logo ao (7)
					matriz[i][j-1]='X';
					contador_de_x++;
					j=j-1;
					tem_0++;
				}
			//Verifica-se se j � diferente do n�mero de colunas - 1 (ou seja, se a coluna que est� a direita do nosso 'X' 
			//� uma coluna que pertence a matriz de caracteres declarada, para que assim n�o acessemos
			//uma �rea da mem�ria que n�o � ocupada pela nossa matriz).
			if(j!=c-1)
				//Verificamos se no lado direito do nosso 'X' temos um n�mero 0
				if(matriz[i][j+1]=='0')
				{
					//An�logo ao (1)
					if(contador_de_x==1)
					{
						printf("F ");
						vetor_direcional=4;
					}
					//An�logo ao (2)
					else
					{
						//An�logo ao (3)
						if(vetor_direcional==4)
							printf("F ");
						//An�logo ao (4)
						if(vetor_direcional==1)
						{
							printf("R F ");
							vetor_direcional=4;
						}
						//An�logo ao (5)
						if(vetor_direcional==2)
						{
							printf("L F ");
							vetor_direcional=4;
						}
						//An�logo ao (6)
					}
					//An�logo ao (7)
					matriz[i][j+1]='X';
					contador_de_x++;
					j=j+1;
					tem_0++;
				}
			}
		/*
		Como n�o h� nenhum caminho mais a ser percorrido(tem_0==0),
		Chegamos no final do caminho e exibimos E (END).
		*/
		printf("E\n");
		/*
		Zeramos as seguintes vari�veis para que o ciclo se inicie novamente.
		*/
		contador_de_x=0;
		tem_0=0;
	}
}
