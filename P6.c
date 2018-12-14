/* P6.c */
/* Felipe Soares Pereira */
/* 11811ECP014 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto
{
	double x;
	double y;
};

struct ponto *gera (int n)
{
	struct ponto *p = (struct ponto*) malloc(n*sizeof(struct ponto));
	int i;
	printf ("\n\nOs pontos gerados sao: \n");
	for (i=0; i<n; i++)
	{
		(*p).x = cos(i*2.0*M_PI/(n-1));
		(*p).y = sin(i*2.0*M_PI/(n-1));
		printf ("(%.3lf, %.3lf) \n", (*p).x, (*p).y);
	}
	return p;
}

int main ()
{
	struct ponto *p;
	int ndp;
	printf ("Digite o numero de pontos que deseja encontrar: ");
	scanf ("%d", &ndp);
	getchar();
	p = gera(ndp);
	free(p);
	return 0;
}
