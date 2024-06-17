#include "histograma.h"
extern const int MAX_LEN;
typedef enum{
    OUT,
    IN
}estados;
int length;
int* longitudes;

void out(int);
void in();

int* contar(){
    longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int c;
    while((c=getchar()) != EOF)
        out(c);
    return longitudes;
}

void out(int c){
    if(c == ' ' || c == '\n' || c == '\t'){
        length = 0;
        return;
    }
    else{
        ++length;
        return in();
    }
}

void in(){
    int c = getchar();
        if(c == ' ' || c == '\n' || c == '\t'){
            longitudes[length]++;
        length = 0;
        return;
    }
    else{
        ++length;
        return in();
    }
        
}