#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VMAX 1000
#define ITER 1000
#ifndef DEBUG
#define DEBUG 0
#endif

void vzeros(unsigned v[VMAX]);
void mzeros(unsigned m[VMAX][VMAX]);
void rlist(unsigned v[VMAX], unsigned n);
void printv(unsigned v[VMAX], unsigned n);
void printm(unsigned x[VMAX][VMAX], unsigned n, unsigned m);

int main(void)
{
    unsigned l[VMAX], lt[VMAX][VMAX], tl[VMAX][VMAX], qt, ql, chosen[VMAX];
    unsigned i, j, k, m, flag, it_escape;
    srand(time(NULL));
    //deixara de existir
    vzeros(l);
    mzeros(lt);
    mzeros(tl);
    qt = 2;
    ql = 2;
    l[0] = 4;
    lt[0][0] = 2;
    lt[1][1] = 1;
    tl[0][1] = 1;
    tl[1][0] = 1;
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
    //deixara de existir
    printf("======= INICIO DA SIMULACAO =======\n");
    for(k=0;k<ITER;k++)
    {
        if(DEBUG>1) printf("\nIteracao %u:\n",k+1);
        rlist(chosen,qt);
        it_escape = 0;
        printf("Ordem de tentativa:");
        printv(chosen,qt);
        printf("\n");
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
                if(DEBUG>1) printf("Transicao %u ativou!\n",i);
                it_escape = 1; //alguma transicao ativou
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
        }
        if(it_escape == 0) //se nada aconteceu com nenhuma transicao
            break;
    }
    printf("======= FIM DA SIMULACAO ==========\n");
    return EXIT_SUCCESS;
}

void vzeros(unsigned v[VMAX])
{
    unsigned i;
    if(DEBUG>4) printf("funcao vzeros chamada. Zerando um vetor...\n");
    for(i=0;i<VMAX;i++)
        v[i] = 0;
    return;
}

void mzeros(unsigned m[VMAX][VMAX])
{
    unsigned i, j;
    if(DEBUG>4) printf("funcao mzeros chamada. Zerando uma matriz...\n");
    for(i=0;i<VMAX;i++)
        for(j=0;j<VMAX;j++)
            m[i][j] = 0;
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
