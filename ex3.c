#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef VMAX
#define VMAX 1000
#endif

#ifndef ITER
#define ITER 1000
#endif

#ifndef PCT
#define PCT 50
#endif

#ifndef DEBUG
#define DEBUG 0
#endif


void vzeros(unsigned v[VMAX], unsigned n);
void mzeros(unsigned x[VMAX][VMAX], unsigned m, unsigned n);
void rlist(unsigned v[VMAX], unsigned n);
void printv(unsigned v[VMAX], unsigned n);
void printm(unsigned x[VMAX][VMAX], unsigned n, unsigned m);


int main(void)
{
    unsigned t = time(NULL);
    unsigned l[VMAX], lt[VMAX][VMAX], tl[VMAX][VMAX], qt, ql, chosen[VMAX];
    unsigned i, j, k, m, flag, it_escape, lctk, alt, atl;
    srand(time(NULL));
    vzeros(l, VMAX);
    mzeros(lt, VMAX, VMAX);
    mzeros(tl, VMAX, VMAX);
    scanf("%u",&ql);
    scanf("%u",&qt);
    scanf("%u",&lctk);
    scanf("%u",&alt);
    scanf("%u",&atl);
    for(k=0;k<lctk;k++)
    {
        scanf("%u %u", &i, &j);
        l[i]=j;
    }
    for(k=0;k<alt;k++)
    {
        scanf("%u %u %u", &i, &lctk, &j);
        lt[i][j]= lctk;
    }
    for(k=0;k<atl;k++)
    {
        scanf("%u %u %u", &i, &lctk, &j);
        tl[i][j] = lctk;
    }

    if(DEBUG>1) printf("Quantidade de lugares: %u\n",ql);
    if(DEBUG>1) printf("Quantidade de transicoes: %u\n",qt);
    if(DEBUG>1) printf("Token em cada lugar:[");
    if(DEBUG>1) printv(l,ql);
    if(DEBUG>1) printf(" ]\n");
    if(DEBUG>1) printf("Matriz lt:");
    if(DEBUG>1) printm(lt,ql,qt);
    if(DEBUG>1) printf("\nMatriz tl:");
    if(DEBUG>1) printm(tl,qt,ql);
    if(DEBUG>1) printf("\n");
    printf("======= INICIO DA SIMULACAO =======\n");
    for(k=0;k<ITER;k++)
    {
        if(DEBUG>1) printf("\nInteracao %u:\n",k+1);
        rlist(chosen,qt);
        it_escape = 0;
        if(DEBUG>1) printf("Ordem de tentativa:");
        if(DEBUG>1) printv(chosen,qt);
        if(DEBUG>1) printf("\n");
        for(m=0;m<qt;m++)
        {
            i = chosen[m]; //sorteio i
            if(DEBUG>1) printf("Tentativa %u: numero sorteado: [%u]\n",m+1,i);
            flag = 1;
            for(j=0;j<ql;j++)
                if(lt[j][i] != 0)
                    if(l[j] < lt[j][i])
                    {
                        flag = 0;
                        break;
                    }
            if(flag)
            {
                it_escape = 1; //alguma transicao ativou
                if((rand()%100 + 1) <= PCT)
                {
                    if(DEBUG>1) printf("Transicao %u ativou!\n",i);
                    for(j=0;j<ql;j++)
                        if(lt[j][i] != 0)
                            l[j] -= lt[j][i];
                    for(j=0;j<ql;j++)
                        if(tl[i][j] != 0)
                            l[j] += tl[i][j];
                    if(DEBUG>1) printf("Token em cada lugar:[");
                    if(DEBUG>1) printv(l,ql);
                    if(DEBUG>1) printf(" ]\n");
                }
                else
                    if(DEBUG>1) printf("Transicao %u decidiu nao ativar.\n",i);
            }
        }
        if(it_escape == 0) //se nada aconteceu com nenhuma transicao
            break;
    }
    printf("======= FIM DA SIMULACAO ==========\n");
    t = time(NULL) - t;
    printf("Tempo de reprodução do programa: %u segundo(s).\n",t);
    printf("Numero de iteracoes: %u.\n",k);
    printf("Lugares com token: \n");
    for(j=0;j<ql;j++)
        if(l[j] != 0)
            printf("Lugar %u: %u tokens \n",j,l[j]);

    return EXIT_SUCCESS;
}


void vzeros(unsigned v[VMAX], unsigned n)
{
    unsigned i;
    if(DEBUG>4) printf("funcao vzeros chamada. Zerando um vetor...\n");
    for(i=0;i<n;i++)
        v[i] = 0;
    return;
}

void mzeros(unsigned x[VMAX][VMAX], unsigned m, unsigned n)
{
    unsigned i, j;
    if(DEBUG>4) printf("funcao mzeros chamada. Zerando uma matriz...\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            x[i][j] = 0;
    return;
}

void rlist(unsigned v[VMAX], unsigned n)
{
    unsigned i = n, j, f;
    while(i)
    {
        v[n-i] = rand()%n;
        if(DEBUG>4) printf("Vetor[%u]: %u (",n-i,v[n-i]);
        f = 1;
        for(j=0;j<(n-i);j++)
            if(v[j] == v[n-i])
                f = 0;
        if(f)
        {
            if(DEBUG>4) printf("OK)\n");
            i--;
        }
        else
            if(DEBUG>4) printf("Falhou)\n");
    }
    if(DEBUG>4) printf("retorno do rlist: [");
    if(DEBUG>4) printv(v,n);
    if(DEBUG>4) printf(" ]\n");
    return;
}

void printv(unsigned v[VMAX], unsigned n)
{
    unsigned i;
    for(i=0;i<n;i++)
        printf(" %u",v[i]);
    return;
}

void printm(unsigned x[VMAX][VMAX], unsigned n, unsigned m)
{
    unsigned i, j;
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%u ",x[i][j]);
    }
    return;
}


