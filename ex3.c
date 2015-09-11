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

int main(void)
{
    unsigned l[VMAX], lt[VMAX][VMAX], tl[VMAX][VMAX], qt, ql, chosen[VMAX];
    unsigned i, j, k, m;
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
    //deixara de existir
    for(k=0;k<ITER;k++)
    {
        rlist(chosen,qt);
    }

    return EXIT_SUCCESS;
}

void vzeros(unsigned v[VMAX])
{
    unsigned i;
    for(i=0;i<VMAX;i++)
        v[i] = 0;
    return;
}

void mzeros(unsigned m[VMAX][VMAX])
{
    unsigned i, j;
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
    return;
}
