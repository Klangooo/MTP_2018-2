/* P2.c */
/* Felipe Soares Pereira */
/* 11811ECP014 */

#include <stdio.h>

int potencia (int n1, int n2)
{
	int i, res = 1;
	for (i=0; i<n2; i++)
		res = res * n1;
	return res;
}

void inverter (char vet[])
{
	int aux = 0, i, cont = 0, conttotal = 0;
	for (i=0; vet[i] != '\0'; i++)
		cont++;
	conttotal = cont;
	cont--;
	for (i=0; i<cont; i++)
	{
		aux = vet[i];
		vet[i] = vet[cont];
		vet[cont] = aux;
		cont--;
	}
	vet[conttotal] = '\0';
}

int bipd (char num[])
{
	inverter(num);
	int i, soma = 0;
	for (i = 0; num[i] != '\0'; i++)
		if (num[i] == '1')
			soma = soma + num[i] * potencia(2, i);
	return soma/49;
}

void dpbi (int num)
{
	int vet[256], i, j, res, flag=0;
	res = num;
	for (i=0; flag<1 ; i++)
	{
		vet[i] = res % 2;
		res = res/2;
		if (res == 1 || res == 0)
		{
			vet[i+1] = res;
			j=i+1;
			flag++;
		}
	}
	printf ("O valor em binario eh ");
	for (i=j; i>=0; i--)
		printf ("%d", vet[i]);
}


int main()
{
	int menu;
	char num[256];
	printf ("1) Binario para decimal \n2) Binario para hexadecimal \
	\n3) Hexadecimal para decimal \n4) Hexadecimal para binario \n5) Decimal para binario \
	\n6) Decimal para hexadecimal \n7) Octal para decimal \n8) Decimal para octal");
	printf ("\n\nDigite sua opcao: ");
	scanf ("%d", &menu);
	if(op==1)
	{
		printf ("Digite o numero em binario: ");
		scanf ("%s", num);
		printf ("O valor em decimal eh %d", bipd(num));
	}
	if(menu==2)
	{
		printf ("Digite o numero em binario: ");
		scanf ("%s", num);
		printf ("O valor em hexadecimal eh %x", bipd(num));
	}
	if(menu==3)
	{
		int(num);
		printf ("Digite o numero em hexadecimal: ");
		scanf ("%x", &num);
		printf ("O valor em decimal eh %d", num);
	}
	if(menu==4)
	{
		int(num);
		printf ("Digite o numero em hexadecimal: ");
		scanf ("%x", &num);
		dpbi(num);
	}
	if(menu==5)
	{
		int(num);
		printf ("Digite o numero em decimal: ");
		scanf("%d", &num);
		dpbi(num);
	}
	if(menu==6)
	{
		int(num);
		printf ("Digite o numero em decimal: ");
		scanf("%d", &num);
		printf ("O valor em hexadecimal eh %x", num);
	}
	if(menu==7)
	{
		int(num);
		printf ("Digite o numero em octal: ");
		scanf("%o", &num);
		printf("O valor em decimal eh %d", num);
	}		
	if(menu==8)
	{
		int(num);
		printf ("Digite o numero em decimal: ");
		scanf("%d", &num);
		printf ("O valor em octal eh %o", num);
	}
	return 0;
}
