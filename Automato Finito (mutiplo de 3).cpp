//Felipe Soares Pereira
//11811ECP014

//Automato Finito p/ verificar se um número é multipl de 3

#include <stdio.h>

int main(){
	int estado=0, i=0;
	char bits[256];
	printf("Digite o numero: ");
	scanf("%s", bits);
	while(bits[i] != '\0'){
		if(estado==0 && bits[i]=='1')
			estado = 1;
		else if(estado==1 && bits[i]=='1')
			estado = 0;
		else if(estado==1 && bits[i]=='0')
			estado = 2;
		else if(estado==2 && bits[i]=='0')
			estado = 1;

		i++;
		//printf("%i", estado);	(Teste de estados)
	}
	printf("\nEstado = %i", estado);
	printf("\n%s ", bits);
	if(estado == 0)
		printf("E multiplo de 3");
	else
		printf("Nao e");
	return 0;
}
