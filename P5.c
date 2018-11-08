/* P5.c */
/* Felipe Soares Pereira */
/* 11811ECP014 */

#include <stdio.h>

typedef
	unsigned long long int
		Bytes8;
typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual; }
		LCG;
		
void semente(LCG * r, Bytes8 seed) {
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) {
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) {
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) {
int i;
for(i = 0; i < tam; i++)
	vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor){
	if(inicio_vetor != fim_vetor + 1)
		return(*inicio_vetor + soma(inicio_vetor+1, fim_vetor));
}

float produto(float *inicio_vetor, float *fim_vetor)
{
	if (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor * produto(inicio_vetor + 1, fim_vetor));
	return 1;
}

int main(){
	LCG random; 
	semente(&random,123456);
	int opcao;
	float vet[50];
	gera_numeros(vet, 50, 0.5, 1.5, &random);
	printf("A partir de 50 numeros aleatorios gerados, escolha uma das opcoes:\n1-Soma dos numeros\n2-Produto dos numeros\n");
	scanf("%i", &opcao);
	getchar();
	if(opcao == 1)
		printf("\nSOMA: %f", soma(&vet[0], &vet[50]));
	else if(opcao == 2)
		printf ("\nPRODUTO: %f \n\n", produto (&vet[0], &vet[49]));
	return 0;
}
