/*
OBJETIVO:
processe um texto de entrada representando um inteiro, que aceite o caractere 'l' como '1'
e o caractere 'o' ou 'O' como '0'. Vírgulas e espaços são permitidos, mas não são processados.
Se, mesmo com as regras acima, o usuário não entrou com um número não-negativo, imprima a string "error".
Overflow (um valor maior que 2147483647) é considerado inválido e "error" deve ser impresso.
Se todas as exigência forem atendidas o número deverá ser exibido na saída padrão.

ESTRATÉGIA:
Pegar a string do usuário, retirar vírgulas e espaços com uma fução EV_retira, logo depois, verificamos 
o tamanho da string agora, Se o tamanho a string for 0, isso significa que o usuário não digitou nada ou somente 
digitou vírgulas e/ou espaços.
Se o tamanho da string for maior que 0, então verificamos agora se o usuário digitou 'l', 'O' e/ou 'o'(para
transformar os valores em '1' e/ou '0').
Agora, verificamos se somente existem números na nossa string(comparando com a string numeros = {0,1,2,3,4,5,6,7,8,9}).
Se existir algo na string que não seja um número, deve-se printar a mensagem "error", no entanto, 
se houverem somente números na string convertemos aquele valor para um número inteiro e verificamos se o número 
é um overflow. Se for, mensagem "error" na saída padrão, senão printamos o número final na saída padrão.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Inclusão das bibliotecas que serão necessárias para a resolução do exercício
*/
void EV_retira(char string[]);
/*Protótipo da função que usaremos mais tarde*/

int main()
{
	char string[51], numeros[]={"0123456789"};
	int i;
	unsigned long int numero;
	/*
	Criação das variáveis que precisam para a resolução do exercício:
	- char string[51](a string que o usuário irá digitar)
	- char numeros[](inicializado com os seguintes valores {“0123456789”});
	- int i(contador)
	- unsigned long int numero(para armazenar o número que deve ser impresso na saída padrão)
	*/
	while(setbuf(stdin, NULL), gets(string) != NULL)
	{
		/*
		- Enquanto a função gets receber uma string o while continuará em execução.
		- Sempre antes de ler a string limpa-se o buffer.
		*/
		EV_retira(string);
		/*Função para retirar vírgulas e espaços*/
		if(!strlen(string))
			printf("error\n");
			/*
			Depois de retirar todos os espaços e vírgulas, temos que analisar o tamanho da string agora;
			Se o tamanho da string for 0, então isso significa que o usuário somente digitou vírgulas e/ou espaços
			ou não digitou nada, então a mensagem apresentada deve ser “error”.
			*/
		else
		{
			/*
			Porém, se o tamanho da string for maior do que 0, através da estrutura condicional 
			verificamos se o usuário digitou um ‘l’, ‘o’ e/ou ‘O’. 
			Verificando isto, trocamos os valores de ‘l’ por ‘1’ e os valores de ‘o’ ou ‘O’ por ‘0’ na estrutura de repetição abaixo.
			*/
			for(i=0;i<strlen(string);i++)
			{
				if(string[i]=='o' || string[i]=='O')
					string[i]='0';
				if(string[i]=='l')
					string[i]='1';
			}
			/*
			Logo depois, verificamos se tem alguma ocorrência de um caractere que 
			não seja um número dentro da string em um laço de repetição.
			*/
			for(i=0;i<strlen(string);i++)
				if(strchr(numeros, string[i])==NULL)
					break;
			/*
			Se houver, então irá sair do laço de repetição através do break 
			e logo depois exibirá na tela a mensagem “error”. 
			*/
			if(i!=strlen(string))
				printf("error\n");
			/*
			No entanto, se o laço de repetição for até o final isso significa que 
			só há a ocorrência de números (0,1,2,3,4,5,6,7,8 e/ou 9) dentro da string agora.
			*/
			else
			{
				/*
				Agora, converteremos o número que está na string para um único valor inteiro com o sscanf().
				*/
				sscanf(string,"%u", &numero);
				/*
				Verifica-se se o número gerado é Overflow (ou seja, maior do que 2147483647).  
				Se for, então printa-se na tela a mensagem “error”. Senão, printa-se o número em questão.
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
A função recebe como parâmetro a string que se deseja retirar as vírgulas e os espaços
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
		Se encontrar, a posição que antes havia um espaço recebe o valor da próxima posição, 
		a próxima posição recebe o valor que está na próxima posição e assim em diante...
		*/
		if(string[i] == ',' || string[i] == ' ')
		{
			for(j=i; j<strlen(string); j++)
			{
				string[j] = string[j+1];
			}
			/*Decrementamos 1 da variável i para que nenhuma posição da string não seja verificada...*/
			i--;
		}
	}
	/*Após retirar todos os espaços, finalizamos a função*/
	return;
}
