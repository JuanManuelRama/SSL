#include "graficadora.h"
extern const int MAX_LEN;
void graficar(int* longitudes){
    printf("longitudes");
    for(int i=1; i<=MAX_LEN; i++){
        printf("\n %d: ", i);
        for(int j=0; j<longitudes[i]; j++)
            printf("-");
    }
}