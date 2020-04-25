/*
OBJETIVO:
A string deve ser exibida de forma que apare�a na tela do usu�rio da
seguinte forma:
- Da metade da string at� o seu in�cio.
- Do final da string at� a sua metade.

ESTRAT�GIA:
Ler-se uma string do usu�rio a partir da entrada padr�o
Dividimos esta string em duas outras strings (string2 e string3)
Invertemos a ordem do elementos que est�o na string2 e string3
copiamos a string2 para a string
concatenamos a string com a string3
printamos a string na sa�da padr�o.
*/

#include<stdio.h>
#include<string.h>
/*
Inclus�o das bibliotecas necess�rias para a resolu��o do exerc�cio
*/

void dividir_string(char string[]);
void inversao_string(char string[], int elementos);
/*Prot�tipo das fun��es que usaremos mais tarde*/

int i=0;
/*Cria��o de uma vari�vel global(que usaremos mais tarde) atribu�da com o valor 0*/

int main()
{
	/*
	Cria��o das vari�veis: 
	- int casos(guardar a quantidade de casos de teste que o usu�rio deseja executar) 
	- char string[101](Que ser� a string que o usu�rio ir� digitar com no m�ximo 100 caracteres)
	*/
	int casos;
	char string[101];
	scanf("%i", &casos);
	getchar();
	//getchar "pega" a quebra de linha(\n) para n�o corromper a pr�xima entrada
	while(casos--)
	{
		gets(string);
		dividir_string(string);
		//dividir_string recebe como par�metro a string que se quer dividir em duas(string2 e string3)
	}
}

void dividir_string(char string[])
{
	int metade, cont;
	/*
	vari�veis locais:
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
	No for() Copia-se do in�cio at� a metade da string e coloca na string2 e 
	copia da metade da string at� o final e coloca na string3.
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
	//Exibe-se a string na sa�da padr�o
	puts(string);
}

//A fun��o inversao_string recebe como par�metro a string e a sua quantidade de elementos

void inversao_string(char string[], int elementos)
{
	//Declaramos uma vari�vel char para atuar como um auxiliar na troca dos elementos
	char aux;
	/*
	Usamos a vari�vel global antes mencionada para
	Verificar se o tamanho da string dividido por 2 � maior do que a vari�vel global i
	*/
	if(i<(elementos/2))
	{
		/*
		Basicamente, pegamos o 1� elemento e colocamos no aux
		*/
		aux=*(string+i);
		//o 1� elemento da string recebe o �ltimo elemento da string
		*(string+i)=*(string+(elementos-1)-i);
		//o �ltimo elemento recebe o valor que est� contido no aux
		*(string+(elementos-1)-i)=aux;
		/*
		incrementamos o i para que possamos fazer isto com todos os elementos da string
		(e n�o somente com o 1� e o �ltimo elemento)
		*/
		i++;
		//chamamos a fun��o novamente at� que todos os elementos da string estejam trocados de posi��o
		inversao_string(string, elementos);
	}
	else
	{
		//Zeramos a vari�vel i para que assim possamos utilizar a fun��o novamente
		i=0;
		return;
	}
}
