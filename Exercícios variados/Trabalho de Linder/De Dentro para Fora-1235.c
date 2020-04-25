/*
OBJETIVO:
A string deve ser exibida de forma que apareça na tela do usuário da
seguinte forma:
- Da metade da string até o seu início.
- Do final da string até a sua metade.

ESTRATÉGIA:
Ler-se uma string do usuário a partir da entrada padrão
Dividimos esta string em duas outras strings (string2 e string3)
Invertemos a ordem do elementos que estão na string2 e string3
copiamos a string2 para a string
concatenamos a string com a string3
printamos a string na saída padrão.
*/

#include<stdio.h>
#include<string.h>
/*
Inclusão das bibliotecas necessárias para a resolução do exercício
*/

void dividir_string(char string[]);
void inversao_string(char string[], int elementos);
/*Protótipo das funções que usaremos mais tarde*/

int i=0;
/*Criação de uma variável global(que usaremos mais tarde) atribuída com o valor 0*/

int main()
{
	/*
	Criação das variáveis: 
	- int casos(guardar a quantidade de casos de teste que o usuário deseja executar) 
	- char string[101](Que será a string que o usuário irá digitar com no máximo 100 caracteres)
	*/
	int casos;
	char string[101];
	scanf("%i", &casos);
	getchar();
	//getchar "pega" a quebra de linha(\n) para não corromper a próxima entrada
	while(casos--)
	{
		gets(string);
		dividir_string(string);
		//dividir_string recebe como parâmetro a string que se quer dividir em duas(string2 e string3)
	}
}

void dividir_string(char string[])
{
	int metade, cont;
	/*
	variáveis locais:
	- int metade
	- cont(contador)
	*/
	metade = (strlen(string)/2);
	/*
	metade recebe a quantidade de elementos(da string informada) dividida por 2,
	para que possa-se criar duas strings com o tamanho metade+1 (pois, tem que 
	ter no final de cada string '\0')
	*/
	char string2[metade+1], string3[metade+1];
	/*
	No for() Copia-se do início até a metade da string e coloca na string2 e 
	copia da metade da string até o final e coloca na string3.
	*/
	for(cont=0;cont<metade;)
	{
		string2[cont] = string[cont];
		string3[cont] = string[cont + metade];
		cont++;
		if(cont==metade)
		{
			string2[cont]='\0';
			string3[cont]='\0';
		}
	}
	//Queremos inverter os elementos da string2 e da string3
	inversao_string(string2, metade);
	inversao_string(string3, metade);
	//Copia-se a string2 para a string
	strcpy(string, string2);
	//Concatena-se a string com a string3
	strcat(string, string3);
	//Exibe-se a string na saída padrão
	puts(string);
}

//A função inversao_string recebe como parâmetro a string e a sua quantidade de elementos

void inversao_string(char string[], int elementos)
{
	//Declaramos uma variável char para atuar como um auxiliar na troca dos elementos
	char aux;
	/*
	Usamos a variável global antes mencionada para
	Verificar se o tamanho da string dividido por 2 é maior do que a variável global i
	*/
	if(i<(elementos/2))
	{
		/*
		Basicamente, pegamos o 1º elemento e colocamos no aux
		*/
		aux=*(string+i);
		//o 1º elemento da string recebe o último elemento da string
		*(string+i)=*(string+(elementos-1)-i);
		//o último elemento recebe o valor que está contido no aux
		*(string+(elementos-1)-i)=aux;
		/*
		incrementamos o i para que possamos fazer isto com todos os elementos da string
		(e não somente com o 1º e o último elemento)
		*/
		i++;
		//chamamos a função novamente até que todos os elementos da string estejam trocados de posição
		inversao_string(string, elementos);
	}
	else
	{
		//Zeramos a variável i para que assim possamos utilizar a função novamente
		i=0;
		return;
	}
}
