/*
OBJETIVO:
Comparar duas strings e verificar a quantidade da maior substring que está 
contida nas duas strings mencionadas.

ESTRATÉGIA:
Pegar as duas strings do usuário e verificar cada elemento da string1 em
relação a cada elemento da string2, se forem iguais incrementa-se em um 
contador(sempre que forem iguais) e analisa-se o próximo elemento das duas
strings, se forem iguais incrementa-se no contador e analisa o próximo ele-
mento das duas strings...E assim por diante.
Se os elementos não forem iguais guardamos o valor do contador em outra 
variável e zeramos o nosso contador(para que nos próximos elementos que 
forem iguais possamos contar a partir do 0 no nosso contador).
Sendo que o maior valor do contador será guardado e exibido na saída padrão.
*/

#include<stdio.h>
/*
Inclusão da biblioteca <stdio.h> que é necessária para a resolução do exercício(printf, scanf etc)
*/
int main()
{
	/*
	Criação das strings:
	- char str1[51] e str2[51](strings a serem comparadas)
	- int i e j(contadores)
	- int quant_igual(contar a quantidade da substring contida nas outras)
	- int maior(para guardar a maior quantidade da substring contida nas outras)
	- int cont e cont2(contadores)
	*/
	char str1[51], str2[51];
	int i, j, quant_igual=0, maior=0, cont, cont2;
	/*
	Lemos a 1ª string do usuário como uma confirmação na condição do while.
	Antes da leitura, sempre limpamos o buffer.
	*/
	while(setbuf(stdin, NULL), gets(str1)!=NULL)	
	{
		setbuf(stdin, NULL);
		gets(str2);
		/*
		Como dito anteriormente, a estratégia é verificar cada elemento da string1 em
		relação a cada elemento da string2(por isto a utilização de dois for())
		*/
		for(i=0;i<strlen(str1);i++)
		{
			for(j=0;j<strlen(str2);j++)
			{
				/*
				Agora verificamos se um determinado elemento da string1 é o mesmo
				elemento da string2.
				*/
				if(str1[i]==str2[j])
				{
					/*
					Se a condição for satisfeita, então entramos no for, ao qual te-
					mos cont e cont2 que recebem os índices da posição do elemento 
					que é o mesmo na string1 e na string2
					*/
					/*
					O objetivo aqui é incrementar no
					contador quant_igual sempre que os valores analizados nas
					strings sejam iguais(ou seja, se forem iguais, incrementamos 
					no contador e incrementamos também no cont e cont2 para que 
					possamos analisar o próximo elemento das string1 e string2).
					*/
					/*
					Se os elementos analisados forem diferentes	saimos do for, e 
					saimos do for também quando chegarmos no '\0' de cada string,
					pois a string já acabou e não tem mais nenhum elemento dela 
					que pode ser analizado depois disso.
					*/
					for (cont = i, cont2 = j; str1[cont]==str2[cont2];)
					{
						quant_igual++;
						cont++;
						cont2++;
						if(str2[cont2]=='\0')
							break;
						if(str1[cont]=='\0')
							break;
					}
					/*
					É claro que queremos guardar o número de elementos da maior 
					substring que está contida na string1 e string2, então, 
					através desse if guardamos na variável maior esta informação
					*/
					if (quant_igual > maior)
						maior = quant_igual;
					/*
					Zeramos a variável quant_igual para que se tiver mais de uma
					substring contida na string1 e string2, comecemos a contá-la
					do 0 (e não de qualquer outro valor que venha a existir na variável).
					*/
					quant_igual=0;
				}
			}
		}
		printf("%i\n", maior);
		maior=0;
		/*
		Zeramos a variável para que o valor dela não interfira na próxima
		execução da contagem da maior substring contida. 
		*/
	}
}

