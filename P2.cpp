//Felipe Soares Pereira
//11811ECP014

#include <stdio.h>

int pow2(int i){
	int resp=1, j;
	for(j=0; j<i; j++)
		resp= resp*2;
	return resp;
}

void inverter (char vet[])
{
	int aux = 0, i, cont = 0, total = 0;
	for (i=0; vet[i] != '\0'; i++)
		cont++;
	total = cont;
	cont--;
	for (i=0; i<cont; i++)
	{
		aux = vet[i];
		vet[i] = vet[cont];
		vet[cont] = aux;
		cont--;
	}
	vet[total] = '\0';
}

int bindec(char bits[]){
	inverter(bits);
	int i, soma, j;
	for(i=0; bits[i]!= '\0' ; i++){
		if(bits[i]=='1')
			soma = soma+bits[i]*pow2(i);
	}
	return soma/49;
}

void decbin (int num)
{
	int vet_bin[256], i, j, resto, cont=0;
	resto = num;
	for (i=0; cont<1 ; i++)
	{
		vet_bin[i] = resto % 2;
		resto = resto/2;
		if (resto == 1 || resto == 0)
		{
			vet_bin[i+1] = resto;
			j=i+1;
			cont++;
		}
	}
	printf ("Resultado: ");
	for (i=j; i>=0; i--)
		printf ("%d", vet_bin[i]);
}

int main(){
	int e, num;
	char bits[256];
	printf("1. Binario para Decimal\n2. Binario para Hexadecimal\n3. Hexadecimal para Decimal\n4. Hexadecimal para Binario\n5. Decimal para Binario\n6. Decimal para Hexadecimal\n7. Octal para Decimal\n8. Decimal para Octal\n\nEscolha: ");
	scanf("%i", &e);
	getchar();
	switch(e)
	{
		case 1:
			printf("\nDigite o numero: ");
			scanf("%s", bits);
			getchar();
			printf("\nResultado: %i", bindec(bits));
			break;
		case 2:
			printf ("Digite o numero: ");
			scanf ("%s", bits);
			getchar();
			printf ("\nResultado: %x", bindec(bits));
			break;
		case 3:
			printf ("Digite o numero: ");
			scanf ("%x", &num);
			getchar();
			printf ("\nResultado: %d", num);
			break;
		case 4:
			printf ("Digite o numero: ");
			scanf ("%x", &num);
			getchar();
			decbin(num);
			break;
		case 5:
			printf ("Digite o numero: ");
			scanf("%d", &num);
			getchar();
			decbin(num);
			break;
		case 6:
			printf ("Digite o numero: ");
			scanf("%d", &num);
			getchar();
			printf ("\nResultado: %x", num);
			break;
		case 7:
			printf ("Digite o numerol: ");
			scanf("%o", &num);
			getchar();
			printf("\nResultado: %d", num);
			break;
		case 8:
			printf ("Digite o numero: ");
			scanf("%d", &num);
			getchar();
			printf ("\nResultado: %o", num);
			break;
	}
	return 0;
}
