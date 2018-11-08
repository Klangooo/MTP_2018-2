/* P4.c */
/* Felipe Soares Pereira */
/* 11811ECP014 */

#include<stdio.h>

int A(int m, int n){
	if(m==0)
		return n=n+1;
	else if(m>0 && n==0)
		return A(m-1, 1);
	else if(m>0 && n>0)
		return A(m-1, A(m, n-1));
}

int main(){
	int m, n;
	printf("Digite m: ");
	scanf("%i", &m);
	printf("\nDigite n: ");
	scanf("%i", &n);
	printf("%i", A(m, n));
	return 0;
}
