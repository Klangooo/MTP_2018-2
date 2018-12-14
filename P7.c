/* P7.c */
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

struct ponto *gerar (int n) 
{

	struct ponto *p = (struct ponto*) malloc(n*sizeof(struct ponto));
	int i;

	for (i=0; i<n; i++)
	{
		p[i].x = cos(i*2.0*M_PI/(n-1));
		p[i].y = sin(i*2.0*M_PI/(n-1));
	}

	return p;
}

void salvar (struct ponto *p, int n)
{
	FILE *arq;
	arq = fopen("pontos.dat", "w");
	
	
	int i, j;
	for(i = 0; i < n; i++) 
	{
        for(j = 0; j < 20; j++) 
		{
            fprintf(arq, "%d\t%d\t\t", p[i].x, p[i].y);
        }    
        fprintf(arq, "\n");
    }
    
    fclose(arq);
}


void arqembin (struct ponto *p, int n)
{
    FILE * arq;
    arq = fopen("pontos.dat", "wb");
    fwrite (p, n, sizeof(struct ponto), arq);
    fclose (arq);
}

struct ponto *read (unsigned int *pn)
{
    struct ponto *p = (struct ponto *) malloc(sizeof(struct ponto));
    
    unsigned int n = 0;
    
    FILE *arq;
    arq = fopen("pontos.dat", "rb");
    
    while(1) 
	{
        fread(p, 1, sizeof(struct ponto), arq);
        if(feof(arq)) 
			break;
        n++;
    }
    
    rewind(arq);
    
    p = (struct ponto *) realloc(p, n*sizeof(struct ponto));
    fread(p, n, sizeof(struct ponto), arq);
    
    fclose(arq);
    
    *pn = n;
    
    return p;
}

void show (struct ponto *p, struct ponto *pf)
 {
    if(p < pf)
	{
		printf("(%.3lf , %.3lf) \n", (*p).x, (*p).y);
		show (p+1, pf);
	}
}

int main ()
{
	struct ponto *p;
	int ndp, opcao;

	do
	    {
		system ("cls");
		printf("            MENU \n\n1) Gerar arquivo com pontos. \n2) Recuperar pontos de arquivo. \
			\n3) Sair do programa.\n\n");
		scanf("%d", &opcao);
		switch (opcao)
		{
		    case 1:
			printf ("\nDigite o numero de pontos que deseja encontrar: ");
			scanf ("%d", &ndp);
			getchar();
			p = gerar(ndp);

			salvar (p, ndp);
			arqembin(p, ndp);

			printf ("\nArquivo gravado!");
			getch();
			break;
		    case 2:
			p = read(&ndp);
			show(p, p+ndp);
			getch ();
			break;
		    default:
			if (opcao != 3)
			    printf("Opcao invalida!");
			getch();
			break;
		}
	    } while(opcao != 3);

	printf ("Bye bye!");
	free(p);
	return 0;
}
