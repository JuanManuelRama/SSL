#include "graficadora.h"

int maxVal(int*);
void printFila(int);

void graficar(int* len, MODO modo){
    if(modo == HORIZONTAL){
        for (int i = 1; i < MAX_LEN; i++)
    {
        printf("%3d: ", i);
        printFila(len[i]);
    }
    printf("%d+: ", MAX_LEN);
    printFila(len[MAX_LEN]);
    }
    else{
        for(int i = maxVal(len); i>=1; i--){
            for(int j=1; j<=MAX_LEN; j++)
                if(len[j]>=i)
                    printf("   |");
                else
                    printf("    ");
            printf("\n");
        }
        for(int i=1; i<=MAX_LEN; i++)
            printf("%4d", i);
    }
    free(len);
}

void printFila(int len){
    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");
}

int maxVal(int* len){
    int max=0;
    for(int i=1; i<=MAX_LEN; i++)
        if(len[i]>max)
            max=len[i];
    return max;
}