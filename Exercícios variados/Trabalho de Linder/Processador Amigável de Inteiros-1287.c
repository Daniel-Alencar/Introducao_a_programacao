/*
OBJETIVO:
processe um texto de entrada representando um inteiro, que aceite o caractere 'l' como '1'
e o caractere 'o' ou 'O' como '0'. V�rgulas e espa�os s�o permitidos, mas n�o s�o processados.
Se, mesmo com as regras acima, o usu�rio n�o entrou com um n�mero n�o-negativo, imprima a string "error".
Overflow (um valor maior que 2147483647) � considerado inv�lido e "error" deve ser impresso.
Se todas as exig�ncia forem atendidas o n�mero dever� ser exibido na sa�da padr�o.

ESTRAT�GIA:
Pegar a string do usu�rio, retirar v�rgulas e espa�os com uma fu��o EV_retira, logo depois, verificamos 
o tamanho da string agora, Se o tamanho a string for 0, isso significa que o usu�rio n�o digitou nada ou somente 
digitou v�rgulas e/ou espa�os.
Se o tamanho da string for maior que 0, ent�o verificamos agora se o usu�rio digitou 'l', 'O' e/ou 'o'(para
transformar os valores em '1' e/ou '0').
Agora, verificamos se somente existem n�meros na nossa string(comparando com a string numeros = {0,1,2,3,4,5,6,7,8,9}).
Se existir algo na string que n�o seja um n�mero, deve-se printar a mensagem "error", no entanto, 
se houverem somente n�meros na string convertemos aquele valor para um n�mero inteiro e verificamos se o n�mero 
� um overflow. Se for, mensagem "error" na sa�da padr�o, sen�o printamos o n�mero final na sa�da padr�o.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Inclus�o das bibliotecas que ser�o necess�rias para a resolu��o do exerc�cio
*/
void EV_retira(char string[]);
/*Prot�tipo da fun��o que usaremos mais tarde*/

int main()
{
	char string[51], numeros[]={"0123456789"};
	int i;
	unsigned long int numero;
	/*
	Cria��o das vari�veis que precisam para a resolu��o do exerc�cio:
	- char string[51](a string que o usu�rio ir� digitar)
	- char numeros[](inicializado com os seguintes valores {�0123456789�});
	- int i(contador)
	- unsigned long int numero(para armazenar o n�mero que deve ser impresso na sa�da padr�o)
	*/
	while(setbuf(stdin, NULL), gets(string) != NULL)
	{
		/*
		- Enquanto a fun��o gets receber uma string o while continuar� em execu��o.
		- Sempre antes de ler a string limpa-se o buffer.
		*/
		EV_retira(string);
		/*Fun��o para retirar v�rgulas e espa�os*/
		if(!strlen(string))
			printf("error\n");
			/*
			Depois de retirar todos os espa�os e v�rgulas, temos que analisar o tamanho da string agora;
			Se o tamanho da string for 0, ent�o isso significa que o usu�rio somente digitou v�rgulas e/ou espa�os
			ou n�o digitou nada, ent�o a mensagem apresentada deve ser �error�.
			*/
		else
		{
			/*
			Por�m, se o tamanho da string for maior do que 0, atrav�s da estrutura condicional 
			verificamos se o usu�rio digitou um �l�, �o� e/ou �O�. 
			Verificando isto, trocamos os valores de �l� por �1� e os valores de �o� ou �O� por �0� na estrutura de repeti��o abaixo.
			*/
			for(i=0;i<strlen(string);i++)
			{
				if(string[i]=='o' || string[i]=='O')
					string[i]='0';
				if(string[i]=='l')
					string[i]='1';
			}
			/*
			Logo depois, verificamos se tem alguma ocorr�ncia de um caractere que 
			n�o seja um n�mero dentro da string em um la�o de repeti��o.
			*/
			for(i=0;i<strlen(string);i++)
				if(strchr(numeros, string[i])==NULL)
					break;
			/*
			Se houver, ent�o ir� sair do la�o de repeti��o atrav�s do break 
			e logo depois exibir� na tela a mensagem �error�. 
			*/
			if(i!=strlen(string))
				printf("error\n");
			/*
			No entanto, se o la�o de repeti��o for at� o final isso significa que 
			s� h� a ocorr�ncia de n�meros (0,1,2,3,4,5,6,7,8 e/ou 9) dentro da string agora.
			*/
			else
			{
				/*
				Agora, converteremos o n�mero que est� na string para um �nico valor inteiro com o sscanf().
				*/
				sscanf(string,"%u", &numero);
				/*
				Verifica-se se o n�mero gerado � Overflow (ou seja, maior do que 2147483647).  
				Se for, ent�o printa-se na tela a mensagem �error�. Sen�o, printa-se o n�mero em quest�o.
				*/
				if(numero <= 2147483647)
					printf("%u\n", numero);
				else
					printf("error\n");
			}
		}
	}
}
/*
A fun��o recebe como par�metro a string que se deseja retirar as v�rgulas e os espa�os
*/
void EV_retira(char string[])
{
	/*i e j como contadores*/
	int i, j;
	/*
	percorrer a string em busca de um ',' ou ' '.
	*/
	for(i=0; i<strlen(string); i++)
	{
		/*
		Se encontrar, a posi��o que antes havia um espa�o recebe o valor da pr�xima posi��o, 
		a pr�xima posi��o recebe o valor que est� na pr�xima posi��o e assim em diante...
		*/
		if(string[i] == ',' || string[i] == ' ')
		{
			for(j=i; j<strlen(string); j++)
			{
				string[j] = string[j+1];
			}
			/*Decrementamos 1 da vari�vel i para que nenhuma posi��o da string n�o seja verificada...*/
			i--;
		}
	}
	/*Ap�s retirar todos os espa�os, finalizamos a fun��o*/
	return;
}
