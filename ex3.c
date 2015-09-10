#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VMAX 1000
#define ITER 1000
#ifdef(DEBUG)
    #define DEBUG 0
#endif

void vzeros(unsigned v[VMAX]);
void mzeros(unsigned m[VMAX][VMAX]);

int main(void)
{
    unsigned l[VMAX], lt[VMAX][VMAX], tl[VMAX][VMAX], qt, ql;
    unsigned checklt[VMAX][VMAX], checktl[VMAX][VMAX];
    unsigned i, j, k, m;
    /*deixara de existir*/
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
    /*deixara de existir*/

    for(k=0;k<ITER;k++)
    {

        /*varredura*/
        for(i=0;i<ql;i++)
            for(j=0;j<qt;j++)
                if(l[i] >= lt[i][j])
                    checklt[i][j] = 1;
                else
                    checklt[i][j] = 0;
        for(i=0;i<qt;i++)
            for(j=0;j<ql;j++)
                if(tl[i][j])
                {
                    checktl[i][j] = 1;
                    for(m=0;m<ql;m++)
                        if((checklt[m][i] == 0 && l[m]) != 0 || (checklt[m][i] != 0 && l[m] == 0))
                        {
                            checktl[i][j] = 0;
                            break;
                        }
                }
        /*fim da varredura*/

        /*transicao de valores*/
        for(i=0;i<qt;i++)
            for(j=0;j<ql;j++)
                if(checktl[i][j])
                {
                    ;
                }
        /*fim da transicao*/

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
