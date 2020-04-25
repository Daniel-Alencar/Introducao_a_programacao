/*
OBJETIVO:
Comparar duas strings e verificar a quantidade da maior substring que est� 
contida nas duas strings mencionadas.

ESTRAT�GIA:
Pegar as duas strings do usu�rio e verificar cada elemento da string1 em
rela��o a cada elemento da string2, se forem iguais incrementa-se em um 
contador(sempre que forem iguais) e analisa-se o pr�ximo elemento das duas
strings, se forem iguais incrementa-se no contador e analisa o pr�ximo ele-
mento das duas strings...E assim por diante.
Se os elementos n�o forem iguais guardamos o valor do contador em outra 
vari�vel e zeramos o nosso contador(para que nos pr�ximos elementos que 
forem iguais possamos contar a partir do 0 no nosso contador).
Sendo que o maior valor do contador ser� guardado e exibido na sa�da padr�o.
*/

#include<stdio.h>
/*
Inclus�o da biblioteca <stdio.h> que � necess�ria para a resolu��o do exerc�cio(printf, scanf etc)
*/
int main()
{
	/*
	Cria��o das strings:
	- char str1[51] e str2[51](strings a serem comparadas)
	- int i e j(contadores)
	- int quant_igual(contar a quantidade da substring contida nas outras)
	- int maior(para guardar a maior quantidade da substring contida nas outras)
	- int cont e cont2(contadores)
	*/
	char str1[51], str2[51];
	int i, j, quant_igual=0, maior=0, cont, cont2;
	/*
	Lemos a 1� string do usu�rio como uma confirma��o na condi��o do while.
	Antes da leitura, sempre limpamos o buffer.
	*/
	while(setbuf(stdin, NULL), gets(str1)!=NULL)	
	{
		setbuf(stdin, NULL);
		gets(str2);
		/*
		Como dito anteriormente, a estrat�gia � verificar cada elemento da string1 em
		rela��o a cada elemento da string2(por isto a utiliza��o de dois for())
		*/
		for(i=0;i<strlen(str1);i++)
		{
			for(j=0;j<strlen(str2);j++)
			{
				/*
				Agora verificamos se um determinado elemento da string1 � o mesmo
				elemento da string2.
				*/
				if(str1[i]==str2[j])
				{
					/*
					Se a condi��o for satisfeita, ent�o entramos no for, ao qual te-
					mos cont e cont2 que recebem os �ndices da posi��o do elemento 
					que � o mesmo na string1 e na string2
					*/
					/*
					O objetivo aqui � incrementar no
					contador quant_igual sempre que os valores analizados nas
					strings sejam iguais(ou seja, se forem iguais, incrementamos 
					no contador e incrementamos tamb�m no cont e cont2 para que 
					possamos analisar o pr�ximo elemento das string1 e string2).
					*/
					/*
					Se os elementos analisados forem diferentes	saimos do for, e 
					saimos do for tamb�m quando chegarmos no '\0' de cada string,
					pois a string j� acabou e n�o tem mais nenhum elemento dela 
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
					� claro que queremos guardar o n�mero de elementos da maior 
					substring que est� contida na string1 e string2, ent�o, 
					atrav�s desse if guardamos na vari�vel maior esta informa��o
					*/
					if (quant_igual > maior)
						maior = quant_igual;
					/*
					Zeramos a vari�vel quant_igual para que se tiver mais de uma
					substring contida na string1 e string2, comecemos a cont�-la
					do 0 (e n�o de qualquer outro valor que venha a existir na vari�vel).
					*/
					quant_igual=0;
				}
			}
		}
		printf("%i\n", maior);
		maior=0;
		/*
		Zeramos a vari�vel para que o valor dela n�o interfira na pr�xima
		execu��o da contagem da maior substring contida. 
		*/
	}
}

