#include <assert.h>
#include "histograma.h"
#include <stdbool.h>


char* texto = "a ho\nse\t  \n me ferrt\tsdrta   holsartolsdertowt4e2fdgsi igobeiubreioubbruibei xactamente15car ";
const int MAX_LEN = 15;


int* valorEsperado ();
bool compararArrays(int*, int*);


int main(){
    int* arrayEsperado = valorEsperado();
    FILE* archivo = fopen("test.txt", "w");
    fprintf(archivo, texto);
    fclose(archivo);
    freopen("test.txt","r", stdin);
    int* array = contar();
    assert(compararArrays(arrayEsperado, array));
    free(array);
    free(arrayEsperado);
    fclose(stdin);
    remove("test.txt");
    return 0;
}


int*  valorEsperado(){
    int* arrayEsperado = calloc(MAX_LEN+1, sizeof *arrayEsperado);
    arrayEsperado[1]=1;
    arrayEsperado[2]=3;
    arrayEsperado[5]=2;
    arrayEsperado[15]=3;
    return arrayEsperado;
}
bool compararArrays(int* array1, int* array2){
    static int i = 0;
    ++i;
    if(i>MAX_LEN)
        return true;
    if(array1[i]==array2[i])
        return compararArrays(array1, array2);
    else 
        return false;
}