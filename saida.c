#include <stdio.h>

/* arquivo para completar no ex3.c depois com a saida do programa */ 

if(debug==0)
{
    for(i=0;i<VMAX;i++)
        for(j=0;j<VMAX;j++)
            if (tl[i][j]==0)
                print("Erro. Nenhuma transicao habilitada");
}

if(debug==1)
{
    for(i=0;i<VMAX;i++)
        for(j=0;j<VMAX;j++)
            if (tl[i][j]==0)
                printf("Erro. Os tokens dos lugares nao sao o suficiente para habilitar todas as transicoes");
}

