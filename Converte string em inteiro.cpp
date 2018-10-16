#include <stdio.h>

int main()
{
	int i, inteiro[256], j=0;
	char str[256];
	printf("Digite o numero: ");
	scanf("%s", str);
	for(i=0; str[i]!='\0'; i++){
		if(str[i]>=48 && str[i]<=57){
			inteiro[j]=str[i]%48;
			j++;
		}
	}
	printf("Novo numero: ");
	if(j==0)
		printf("%i", j);
	else{
		for(i=0; i<j; i++)
			printf("%i", inteiro[i]);
			}
}
